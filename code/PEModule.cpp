#include "common.h"
#include "PEModule.h"
#include "ApiFunctionsHelper.h"

namespace amte {

PEModule::PEModule(const std::string& pathName, const bool collectDataReferences) :
_pCodeSection(0),
_collectDataReferences(collectDataReferences),
_relocsInOwnSection(false),
_pImage(0),
_pCode(0),
_pDatas(0),
_file(pathName, std::ios::in | std::ios::binary)
{
	if (!_file) {
		throw std::exception(("Cannot open " + pathName).c_str());
	}

	_pImage = pelib::pe_factory::create_pe(_file);

	// Ищем секцию, где находится точка входа.
	_pImage->get_image_base(_imageBase);
    _pCodeSection = &_pImage->section_from_rva(_pImage->get_ep());
	_codeSectionSize = _pImage->section_data_length_from_rva(_pImage->get_ep());
	_codeBase = _imageBase + _pImage->get_base_of_code();
	_epRVA = (uint32_t)(_imageBase + _pImage->get_ep() - _codeBase);

	if (hasRelocs()) {
		_relocTables = pelib::get_relocations(*_pImage);
        pelib::section_list& secList = _pImage->get_image_sections();
        for (pelib::section_list::iterator itr = secList.begin(); itr != secList.end(); ++itr) {
            pelib::section& section = *itr;
            if (section.get_name() == ".reloc") {
                _relocsInOwnSection = true;
                break;
            }
        }
	}

	_importLibs = pelib::get_imported_functions(*_pImage);
	_iatDirVA = _imageBase + _pImage->get_directory_rva(pelib::pe_win::image_directory_entry_iat);
	_iatDirSize = _pImage->get_directory_size(pelib::pe_win::image_directory_entry_iat);
	_importDirVA = _imageBase + _pImage->get_directory_rva(pelib::pe_win::image_directory_entry_import);
	_importDirSize = _pImage->get_directory_size(pelib::pe_win::image_directory_entry_import);

	_pCode = new PECodeInfo(this);
	_pDatas = new PEDataInfo(this);

	// Функции, которые используют в качестве входных параметров callback-функции.
	_apiFuncsWithCb.push_back("EnumSystemCodePagesW"); // kernel32.dll
	_apiFuncsWithCb.push_back("EnumSystemCodePagesA"); // kernel32.dll
	_apiFuncsWithCb.push_back("RegisterClassA"); // user32.dll
	_apiFuncsWithCb.push_back("RegisterClassW"); // user32.dll
	_apiFuncsWithCb.push_back("RegisterClassExA"); // user32.dll
	_apiFuncsWithCb.push_back("RegisterClassExW"); // user32.dll
	_apiFuncsWithCb.push_back("CreateDialogParamA"); // user32.dll
	_apiFuncsWithCb.push_back("CreateDialogParamW"); // user32.dll
	_apiFuncsWithCb.push_back("EnumChildWindows"); // user32.dll
	_apiFuncsWithCb.push_back("DialogBoxIndirectParamA"); // user32.dll
	_apiFuncsWithCb.push_back("DialogBoxIndirectParamW"); // user32.dll
	_apiFuncsWithCb.push_back("EnumFontFamiliesExA"); // gdi32.dll
	_apiFuncsWithCb.push_back("EnumFontFamiliesExW"); // gdi32.dll
	
	//_user32FuncsWithCb.push_back("SetTimer");
	_pCode->addInstrListener("*", MakeDelegate(this, &PEModule::onInstr).Copy());
}

PEModule::~PEModule()
{
	if (_pCode != 0) {
		delete _pCode;
	}
	if (_pDatas != 0) {
		delete _pDatas;
	}
	if (_pImage != 0) {
		delete _pImage;
	}
}

bool PEModule::hasRelocs() const
{
	return _pImage->has_reloc();
}

pelib::pe_base* PEModule::getPEBase()
{
	return _pImage;
}

PECodeInfo* PEModule::getCodeInfo()
{
	return _pCode;
}

PEDataInfo* PEModule::getDatas()
{
	return _pDatas;
}

void PEModule::permutate()
{
	_permutator.useModule(this);
	_permutator.permutate();

	if (hasRelocs()) {
		_relocTables = pelib::get_relocations(*_pImage);
	}
}

const pelib::imported_function* const PEModule::getRefToImportTable(const DISASM* pInstr) const
{
	// Оптимизация, которая учитывает длину инструкции, которая должна быть не меньше 5 байтов (верно для x32 и x64).
	if (pInstr->len < 5) {
		return 0;
	}
	for (InstrImportMap::const_iterator itr = _instrImportMap.begin(); itr != _instrImportMap.end(); ++itr) {
		if (itr->first == pInstr) {
			return itr->second;
		}
	}

	return 0;
}

const pelib::imported_function* const PEModule::searchImportFunction(const std::string& name, uint64_t& realVA) const
{
	for (pelib::imported_functions_list::const_iterator libItr = _importLibs.begin(); libItr != _importLibs.end(); ++libItr) {
		const pelib::import_library& lib = *libItr;
		const pelib::import_library::imported_list& imports = lib.getImportedFunctions();
		for (pelib::import_library::imported_list::const_iterator itr = imports.begin(); itr != imports.end(); ++itr) {
			const pelib::imported_function& importFunc = *itr;
			if (importFunc.getName() == name) {
				realVA = _imageBase + (uint64_t)lib.getIATRVA() + (itr - imports.begin()) * sizeof(uint32_t);
				return &importFunc;
			}
		}
	}

	return 0;
}

uint64_t PEModule::getSectionVA(pelib::section* pSection) const
{
	return _imageBase + pSection->get_virtual_address();
}

uint32_t PEModule::getSectionSize(pelib::section* pSection) const
{
	uint32_t sectionSize = 0;	
	if (pSection != 0) {
		sectionSize = pSection->get_size_of_raw_data();
		if (sectionSize > pSection->get_virtual_size()) {
			sectionSize = pSection->get_virtual_size();
		}
	}
	return sectionSize;
}

const pelib::imported_function* const PEModule::getImportedFunctionByAddr(uint64_t addr)
{
	int counter = 0;

	for (pelib::imported_functions_list::const_iterator libItr = _importLibs.begin(); libItr != _importLibs.end(); ++libItr) {
		const pelib::import_library& lib = *libItr;
		uint64_t tableVA = _imageBase + lib.getIATRVA();
		if (addr >= tableVA && addr < (tableVA + sizeof(uint32_t) * lib.getImportedFunctions().size())) {
			uint32_t index = (uint32_t)((addr - tableVA) / sizeof(uint32_t));
			const pelib::import_library::imported_list& imports = lib.getImportedFunctions();
			for (pelib::import_library::imported_list::const_iterator itr = imports.begin(); itr != imports.end(); ++itr) {
				const pelib::imported_function& importFunc = *itr;
				if (counter++ == index) {
					return &importFunc;
				}
			}
		}
	}

	return 0;
}

const pelib::imported_function* const PEModule::getImportedFunctionByDISASM(const DISASM* pInstr)
{
	for (InstrImportMap::const_iterator itr = _apiCallMap.begin(); itr != _apiCallMap.end(); ++itr) {
		if (itr->first == pInstr) {
			return itr->second;
		}
	}

	return 0;
}

bool PEModule::isAddrInsideCode(int64_t addr)
{
	return ((uint64_t)addr >= _codeBase && (uint64_t)addr < (_codeBase + _codeSectionSize));
}

bool PEModule::isAddrInsideData(int64_t addr, const bool excludeIAT)
{
	return _pDatas->isAddrInside(addr, excludeIAT);
}

bool PEModule::isAddrInsideIAT(int64_t addr)
{
	return ((uint64_t)addr >= _iatDirVA && (uint64_t)addr < (_iatDirVA + _iatDirSize));
}	

const pelib::relocation_entry* PEModule::getRelocForInstr(const DISASM* const pInstr) const
{
	for (pelib::relocation_table_list::const_iterator rtItr = _relocTables.begin(); rtItr != _relocTables.end(); ++rtItr) {
		const pelib::relocation_table& table = *rtItr;
		const pelib::relocation_table::relocation_list& relocs = table.get_relocations();
		pelib::relocation_table::relocation_list::const_iterator rItr;
		for (rItr = relocs.begin(); rItr != relocs.end(); ++rItr) {
			const pelib::relocation_entry& entry = *rItr;
			uint64_t virtualAddr = _imageBase + entry.getRVA();

			if (virtualAddr > pInstr->VirtualAddr && virtualAddr < (pInstr->VirtualAddr + pInstr->len)) {
				return &entry;
			}
		}
	}

	return 0;
}

void PEModule::onInstr(void* param)
{
	DISASM* pInstr = static_cast<DISASM*>(param);

	if (lstrcmpA(pInstr->Instruction.Mnemonic, "call ") == 0) {
		DISASM* pInstr1 = 0;
		uint64_t callAddr = 0;

		if ((pInstr->Argument1.ArgType & 0xFFFF0000) == (REGISTER_TYPE + GENERAL_REG)) {
			pInstr1 = _pCode->searchBackInstrWithRegModifiedFor(pInstr);
			if (pInstr1 != 0) {
				callAddr = (uint64_t)pInstr1->Argument2.Memory.Displacement;
			}
		}
		else {
			callAddr = (uint64_t)pInstr->Argument1.Memory.Displacement;
		}

		if (isAddrInsideIAT(callAddr)) {
			_apiCallMap.insert(std::make_pair(pInstr, getImportedFunctionByAddr(callAddr)));
			if (pInstr1 != 0) {
				_instrImportMap.insert(std::make_pair(pInstr1, getImportedFunctionByAddr(callAddr)));
			}
			else {
				_instrImportMap.insert(std::make_pair(pInstr, getImportedFunctionByAddr(callAddr)));
			}
		}
	}
    else if (/*lstrcmpA(pInstr->Instruction.Mnemonic, "mov ") == 0 && */pInstr->Instruction.Immediat != 0 && isAddrInsideCode(pInstr->Instruction.Immediat)) {
        // Сбор данных ссылок больше расчитан на случаи, когда в исходном коде встречаются последовательности:
        // uint8_t* ptr = &someFunc;
        // ... использование ptr в качестве константного итератора.
        BasicBlock* pRefBlock = _pCode->getBlockAtAddr(pInstr->Instruction.Immediat);
        if (pRefBlock != 0) {
            _insrtBlockMap.insert(std::make_pair(pInstr, pRefBlock));
        }
    }
	else if (_collectDataReferences) {
        int64_t memRef = pInstr->Argument2.Memory.Displacement;
		
        if (pInstr->Instruction.Opcode == 0x0FFC) {
			if (_pDatas->isAddrInside(memRef) || isAddrInsideCode(memRef)) {
				_pDatas->addData(memRef, pInstr->Prefix.OperandSize == 0x08 ? 16 : 8);
				_pDatas->addReference(pInstr, memRef);
			}
		}
	}
}

const DISASM* PEModule::getPushFromCall(const BasicBlock* pBlock, const DISASM* pCallDasm, int num)
{
	const DISASM* pInstr;
	uint32_t counter = 0;
	for (InstrVector::const_reverse_iterator instrItr = pBlock->rbegin(pCallDasm) + 1; instrItr != pBlock->rend(); ++instrItr) {
		pInstr = *instrItr;

		if (lstrcmpA(pInstr->Instruction.Mnemonic, "push ") == 0) {
			if (++counter == num) {
				return pInstr;
			}
		}
	}

	return 0;
}

uint32_t PEModule::countPushesBeforeCall(const BasicBlock* pBlock, const DISASM* pDasmFrom)
{
	uint32_t count = 0;
	for (InstrVector::const_reverse_iterator instrItr = pBlock->rbegin(pDasmFrom) + 1; instrItr != pBlock->rend(); ++instrItr) {
		const DISASM* pInstr = *instrItr;

		if (lstrcmpA(pInstr->Instruction.Mnemonic, "call ") == 0) {
			break;
		}
		else if (lstrcmpA(pInstr->Instruction.Mnemonic, "push ") == 0) {
			++count;
		}
	}

	return count;
}

void PEModule::correctEspDisp(int64_t& lpfnWndProcDisp, const BasicBlock* pBlock, const DISASM* pInstr)
{
	ApiFunctionsHelper* apiFuncsHelper = ApiFunctionsHelper::getInstance();
	const DISASM* pCallDasm = 0;

	for (InstrVector::const_iterator itr = pBlock->begin(pInstr) + 1; itr != pBlock->end(); ++itr) {
		pCallDasm = *itr;
		if (lstrcmpA(pCallDasm->Instruction.Mnemonic, "call ") == 0) {
			break;
		}
	}

	const pelib::imported_function* const pImportFunc = getImportedFunctionByDISASM(pCallDasm);
	uint32_t argsNum = apiFuncsHelper->getFunctionArgsNum(pImportFunc->getName());

	// От инструкции call пробегаемся в обратном порядке до первого push-а.
	const DISASM* pPushDasm = getPushFromCall(pBlock, pCallDasm, 1);
	if (pPushDasm->VirtualAddr < pInstr->VirtualAddr) {
		lpfnWndProcDisp -= 4 * argsNum;
	}
}

void PEModule::searchAndAnalyzeCallbackFunctions()
{
	std::vector<const DISASM*> _processedCalls;
	std::vector<uint32_t> rvas;

	do {
		rvas.clear();
		for (InstrImportMap::iterator apiItr = _apiCallMap.begin(); apiItr != _apiCallMap.end(); ++apiItr) {
			for (std::vector<std::string>::iterator itr = _apiFuncsWithCb.begin(); itr != _apiFuncsWithCb.end(); ++itr) {
				const std::string& apiName = *itr;
				if (apiItr->second->getName() == apiName) {
					const DISASM* pInstr = apiItr->first;
					const BasicBlock* pBlock;

					if ((apiName == "EnumSystemCodePagesA" || apiName == "EnumSystemCodePagesW") && std::find(_processedCalls.begin(), _processedCalls.end(), pInstr) == _processedCalls.end()) {
						pBlock = _pCode->getBlockWithInstr(pInstr);
						_processedCalls.push_back(pInstr);

						const DISASM* pPushDasm = getPushFromCall(pBlock, pInstr, 1);
						if (pPushDasm == 0) {
							std::cout << "No push with number 1 for call at " << std::hex << pInstr->VirtualAddr << std::endl;
						}
						else {
							rvas.push_back((uint32_t)((uint64_t)pPushDasm->Instruction.Immediat - _codeBase));
						}
					}
					else if ((apiName == "CreateDialogParamA" || apiName == "CreateDialogParamW") && std::find(_processedCalls.begin(), _processedCalls.end(), pInstr) == _processedCalls.end()) {
						pBlock = _pCode->getBlockWithInstr(pInstr);
						_processedCalls.push_back(pInstr);

						const DISASM* pPushDasm = getPushFromCall(pBlock, pInstr, 4);
						if (pPushDasm == 0) {
							std::cout << "No push with number 1 for call at " << std::hex << pInstr->VirtualAddr << std::endl;
						}
						else {
							rvas.push_back((uint32_t)((uint64_t)pPushDasm->Instruction.Immediat - _codeBase));
						}
					}
					else if ((apiName == "DialogBoxIndirectParamA" || apiName == "DialogBoxIndirectParamW") && std::find(_processedCalls.begin(), _processedCalls.end(), pInstr) == _processedCalls.end()) {
						pBlock = _pCode->getBlockWithInstr(pInstr);
						_processedCalls.push_back(pInstr);

						const DISASM* pPushDasm = getPushFromCall(pBlock, pInstr, 4);
						if (pPushDasm == 0) {
							std::cout << "No push with number 1 for call at " << std::hex << pInstr->VirtualAddr << std::endl;
						}
						else {
							rvas.push_back((uint32_t)((uint64_t)pPushDasm->Instruction.Immediat - _codeBase));
						}
					}
					else if ((apiName == "RegisterClassA" || apiName == "RegisterClassExA" || apiName == "RegisterClassW" || apiName == "RegisterClassExW") && std::find(_processedCalls.begin(), _processedCalls.end(), pInstr) == _processedCalls.end()) {
						pBlock = _pCode->getBlockWithInstr(pInstr);
						_processedCalls.push_back(pInstr);

						// Ищем последний push перед call, это будет у нас адрес начала структуры.
						const DISASM* pPushDasm = _pCode->searchBackInstr(pInstr, "push ");

						if (pPushDasm != 0) {
							// Как правило, адрес загружается сначала в регистр, ищем последнюю инстурукцию, которая изменяет наш регистр.
							const DISASM* pModDasm = _pCode->searchBackInstrWithRegModifiedFor(pPushDasm);

							if (pModDasm != 0) {
								int64_t lpfnWndProcDisp = 0;

								if (lstrcmpA(pModDasm->Instruction.Mnemonic, "lea ") == 0) {
									lpfnWndProcDisp = (int64_t)pModDasm->Argument2.Memory.Displacement;
									if (apiName == "RegisterClassA") {
										lpfnWndProcDisp += offsetof(WNDCLASSA, lpfnWndProc);
									}
									else if (apiName == "RegisterClassW") {
										lpfnWndProcDisp += offsetof(WNDCLASSW, lpfnWndProc);
									}
									else if (apiName == "RegisterClassExA") {
										lpfnWndProcDisp += offsetof(WNDCLASSEXA, lpfnWndProc);
									}
									else if (apiName == "RegisterClassExW") {
										lpfnWndProcDisp += offsetof(WNDCLASSEXW, lpfnWndProc);
									}
								}

								if ((pModDasm->Argument2.Memory.BaseRegister & 0x0000FFFF) == REG4) {
									// Корректируем disp в зависимости от контекста функции.
									correctEspDisp(lpfnWndProcDisp, pBlock, pModDasm);
								}


								// Ищем инструкцию mov [reg + lpfnWndProcDisp], cbFunc
								for (InstrVector::const_reverse_iterator instrItr = pBlock->rbegin(pInstr) + 1; instrItr != pBlock->rend(); ++instrItr) {
									const DISASM* pCbDasm = *instrItr;

									if (pCbDasm->Argument1.Memory.Displacement != 0 && lstrcmpA(pCbDasm->Instruction.Mnemonic, "mov ") == 0) {
										uint32_t pushesCount = 0;
										int64_t cbFuncDisp = pCbDasm->Argument1.Memory.Displacement;
										if (pCbDasm->Argument1.Memory.BaseRegister == REG4) {
											correctEspDisp(cbFuncDisp, pBlock, pCbDasm);
											//pushesCount = countPushesBeforeCall(pBlock, pCbDasm);
										}

										if (cbFuncDisp == lpfnWndProcDisp) {
											uint64_t addrVal = 0;
											if ((pCbDasm->Argument2.ArgType & 0xFFFF0000) == (REGISTER_TYPE + GENERAL_REG)) {
												const DISASM* pModDasm = _pCode->searchBackInstrWithRegModifiedFor(pCbDasm);
												if (pModDasm != 0) {
													addrVal = pModDasm->Argument2.Memory.Displacement;
													if (isAddrInsideIAT(addrVal)) {
														addrVal = 0;
													}
												}
											}
											else {
												addrVal = pCbDasm->Instruction.Immediat;
											}

											if (isAddrInsideCode(addrVal)) {
												rvas.push_back((uint32_t)(addrVal - _codeBase));
											}

											break;
										}
									}
								}
							}
						}
						else {
							std::cout << "No push for call at " << std::hex << pInstr->VirtualAddr << std::endl;
						}
					}
					else if (apiName == "EnumChildWindows" && std::find(_processedCalls.begin(), _processedCalls.end(), pInstr) == _processedCalls.end()) {
						pBlock = _pCode->getBlockWithInstr(pInstr);
						_processedCalls.push_back(pInstr);

						const DISASM* pPushDasm = getPushFromCall(pBlock, pInstr, 2);
						if (pPushDasm == 0) {
							std::cout << "No push with number 1 for call at " << std::hex << pInstr->VirtualAddr << std::endl;
						}
						else {
							rvas.push_back((uint32_t)((uint64_t)pPushDasm->Instruction.Immediat - _codeBase));
						}
					}
					else if ((apiName == "EnumFontFamiliesExA" || apiName == "EnumFontFamiliesExW") && std::find(_processedCalls.begin(), _processedCalls.end(), pInstr) == _processedCalls.end()) {
						pBlock = _pCode->getBlockWithInstr(pInstr);
						_processedCalls.push_back(pInstr);

						const DISASM* pPushDasm = getPushFromCall(pBlock, pInstr, 3);
						if (pPushDasm == 0) {
							std::cout << "No push with number 1 for call at " << std::hex << pInstr->VirtualAddr << std::endl;
						}
						else {
							rvas.push_back((uint32_t)((uint64_t)pPushDasm->Instruction.Immediat - _codeBase));
						}
					}
				}
			}
		}

		for (std::vector<uint32_t>::const_iterator itr = rvas.begin(); itr != rvas.end(); ++itr) {
			_pCode->analyze(*itr);
		}
	} while (rvas.size() > 0);
}

void PEModule::analyze(const bool analyzeData, const bool useEntireDataSections, const bool analyzeExports)
{
	_pCode->init((puint_t)&_pCodeSection->getRawData()[0], _codeBase, _codeSectionSize);
	_pCode->analyze(_epRVA);
	
	searchAndAnalyzeCallbackFunctions();

	if (analyzeExports) {
		pelib::exported_functions_list exportedFuncs = pelib::get_exported_functions(*_pImage);
		for (pelib::exported_functions_list::const_iterator itr = exportedFuncs.begin(); itr != exportedFuncs.end(); ++itr) {
			const pelib::exported_function& ef = *itr;
			_pCode->analyze((uint32_t)(_imageBase + ef.get_rva() - _codeBase));
		}
	}

	if (analyzeData) {
		_pDatas->analyze(useEntireDataSections);
		_pDatas->processDataDirectories();
		_pDatas->processRelocs();

		// Обрабатываем адреса функций в vtable.
		// Ссылку на vtable можно получить, обнаружив следующую конструкцию.
		//  mov dword [REG1], absolute_value
		// где absolute_value - адрес начала виртуальной таблицы.
		// Помимо вышеприведённой инструкции нужно найти ещё инструкцию:
		// mov [REG1 + 4], imm_value или
		// mov [REG1 + 4], REG2
		for (BlockVector::const_iterator blockItr = _pCode->begin(); blockItr != _pCode->end(); ++blockItr) {
			BasicBlock* pBlock = *blockItr;
			int signalVal = 0; // В случае обнаружения подходящей конструкции, значение этой переменной должно быть равно 2.
			uint64_t vtableAddr = 0;
			uint32_t baseReg1 = 0;
			for (InstrVector::const_iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
				const DISASM* pInstr = *itr;
				/*
				if (pInstr->VirtualAddr == 0x0100AB1F) {
					std::cout << std::endl;
				}
				*/
				if (pInstr->Instruction.Opcode == 0xC7 && (pInstr->Argument1.Memory.BaseRegister & 0xFFFF) != 0 && pInstr->Argument1.Memory.IndexRegister == 0 && pInstr->Argument1.Memory.Displacement == 0 && pInstr->Argument1.Memory.Scale == 0 && pInstr->Instruction.Immediat != 0 && ((pInstr->Argument2.ArgType & 0xFFFF0000) & (CONSTANT_TYPE + ABSOLUTE_))) {
					++signalVal;
					baseReg1 = pInstr->Argument1.Memory.BaseRegister & 0xFFFF;
					vtableAddr = pInstr->Instruction.Immediat;
					continue;
				}

				if (pInstr->Instruction.Opcode == 0xC7 && (pInstr->Argument1.Memory.BaseRegister & 0xFFFF) != 0 && pInstr->Argument1.Memory.IndexRegister == 0 && pInstr->Argument1.Memory.Displacement == 4 && pInstr->Argument1.Memory.Scale == 0) {
					if (baseReg1 == 0) {
						++signalVal;
						baseReg1 = pInstr->Argument1.Memory.BaseRegister & 0xFFFF;
					}
					else if (baseReg1 == (pInstr->Argument1.Memory.BaseRegister & 0xFFFF)) {
						++signalVal;
					}
				}
			}
		}
	}	
}

void PEModule::save(const std::string& pathName)
{
	std::ofstream newPeFile(pathName, std::ios::out | std::ios::binary | std::ios::trunc);
	pelib::rebuild_pe(*_pImage, newPeFile, false, false);
}

void PEModule::saveAsShellcode(const std::string& pathName)
{
	std::string shellcode;
	shellcode.resize(_pCode->getCodeSize());
	uint8_t* bufferItr = (uint8_t*)&shellcode[0];

	// Сохраняем только код. При этом в коде должна присутствовать только одна функция.
	// Следовательно, адрес начала функции должен находиться в самом начале секции кода.
	uint64_t va = _codeBase;
	const BasicBlock* pBlock = _pCode->getBlockAtAddr(va);
	while (pBlock != 0) {
		for (InstrVector::const_iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
			const DISASM* pInstr = *itr;
			__movsb(bufferItr, (const uint8_t*)pInstr->EIP, pInstr->len);
			bufferItr += pInstr->len;
			va += pInstr->len;
		}
		
		pBlock = _pCode->getBlockAtAddr(va);
	} 
	
	Utils::saveFile(pathName, shellcode);
}

uint32_t PEModule::getPrefferedMemAlign() const
{
	return (_pImage->get_pe_type() == pelib::pe_type_32) ? 4 : 8;
}

}
