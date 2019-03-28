#include "common.h"
#include "PEDataInfo.h"
#include "PEModule.h"
#include <cmath>

namespace amte {

PEDataInfo::PEDataInfo(PEModule* pOwner)
{
	_pOwner = pOwner;
	_dataSectionVA = 0;
	_dataSectionSize = 0;
	_rdataSectionVA = 0;
	_rdataSectionSize = 0;
	_pDataSection = 0;
	_pRdataSection = 0;

	pelib::section_list& secList = _pOwner->getPEBase()->get_image_sections();
	for (pelib::section_list::iterator itr = secList.begin(); itr != secList.end(); ++itr) {
		pelib::section& section = *itr;
		if (section.get_name() == ".data") {
			_pDataSection = &section;
		}
		else if (section.get_name() == ".rdata") {
			_pRdataSection = &section;
		}
	}

	if (_pDataSection != 0) {
		_dataSectionVA = _pOwner->getSectionVA(_pDataSection);
		_dataSectionSize = _pOwner->getSectionSize(_pDataSection);
		_dataPtr = (puint_t)&_pDataSection->getRawData()[0];
	}
	if (_pRdataSection != 0) {
		_rdataSectionVA = _pOwner->getSectionVA(_pRdataSection);
		_rdataSectionSize = _pOwner->getSectionSize(_pRdataSection);
		_rdataPtr = (puint_t)&_pRdataSection->getRawData()[0];
	}
}

PEDataInfo::~PEDataInfo()
{

}

void PEDataInfo::analyze(const bool useEntireDataSections)
{
	_useEntireDataSections = useEntireDataSections;
	// Анализируем данные.
	if (useEntireDataSections) {
		if (_pDataSection != 0) {
			addData(_dataSectionVA, _dataSectionSize);
		}
		if (_pRdataSection != 0) {
			addData(_rdataSectionVA, _rdataSectionSize);
		}
	}
	else {
		for (BlockVector::iterator blockItr = _pOwner->getCodeInfo()->begin(); blockItr != _pOwner->getCodeInfo()->end(); ++blockItr) {
			BasicBlock* pBlock = *blockItr;

			for (InstrVector::iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
				DISASM* pInstr = *itr;
				uint64_t dataVA = (uint64_t)pInstr->Instruction.Immediat;
				if (dataVA != 0 && (((pInstr->Argument1.ArgType & 0xFFFF0000) & (CONSTANT_TYPE + ABSOLUTE_)) || ((pInstr->Argument2.ArgType & 0xFFFF0000) & (CONSTANT_TYPE + ABSOLUTE_)))) {
					if (_dataSectionVA > 0 && _dataSectionSize > 0 && dataVA >= _dataSectionVA && dataVA < (_dataSectionVA + _dataSectionSize)) {
						addData(dataVA, (uint32_t)(_dataSectionVA + _dataSectionSize - dataVA));
						addReference(pInstr, dataVA);
					}
					else if (_rdataSectionVA > 0 && _rdataSectionSize > 0 && dataVA >= _rdataSectionVA && dataVA < (_rdataSectionVA + _rdataSectionSize)) {
						addData(dataVA, (uint32_t)(_rdataSectionVA + _rdataSectionSize - dataVA));
						addReference(pInstr, dataVA);
					}
				}
			}
		}
	}
}

void PEDataInfo::processDataDirectory(uint32_t dirId)
{ 
	if (_pOwner->getPEBase()->directory_exists(dirId)) {
		uint64_t dirVA = _pOwner->getImageBase() + _pOwner->getPEBase()->get_directory_rva(dirId);
		uint32_t dirSize = _pOwner->getPEBase()->get_directory_size(dirId);

		if (_dataSectionVA > 0 && _dataSectionSize > 0 && dirVA >= _dataSectionVA && dirVA < (_dataSectionVA + _dataSectionSize)) {
			cutData(dirVA, dirSize);
		}
		else if (_rdataSectionVA > 0 && _rdataSectionSize > 0 && dirVA >= _rdataSectionVA && dirVA < (_rdataSectionVA + _rdataSectionSize)) {
			cutData(dirVA, dirSize);
		}
	}
}

void PEDataInfo::processDataDirectories()
{
	processDataDirectory(pelib::pe_win::image_directory_entry_export);
	processDataDirectory(pelib::pe_win::image_directory_entry_import);
	processDataDirectory(pelib::pe_win::image_directory_entry_bound_import);
	processDataDirectory(pelib::pe_win::image_directory_entry_delay_import);
	processDataDirectory(pelib::pe_win::image_directory_entry_load_config);
	processDataDirectory(pelib::pe_win::image_directory_entry_iat);
	processDataDirectory(pelib::pe_win::image_directory_entry_basereloc);
	processDataDirectory(pelib::pe_win::image_directory_entry_resource);
	processDataDirectory(pelib::pe_win::image_directory_entry_security);

	// Вычислем границы данных связанных с таблицей импорта и также исключаем её.
	pelib::imported_functions_list& importLibs = _pOwner->getImportLibs();
	uint64_t minAddr = _pOwner->getImportDirVA(), maxAddr = minAddr + _pOwner->getImportDirSize();

	for (pelib::imported_functions_list::const_iterator libItr = importLibs.begin(); libItr != importLibs.end(); ++libItr) {
		const pelib::import_library& lib = *libItr;
		uint64_t addr = _pOwner->getImageBase() + lib.getINTRVA();
		if (maxAddr < addr) {
			maxAddr = addr;
		}

		addr = _pOwner->getImageBase() + lib.getNameRVA();
		if (maxAddr < (addr + lib.getName().length() + 1)) {
			maxAddr = addr + lib.getName().length() + 1;
		}

		const pelib::import_library::imported_list& imports = lib.getImportedFunctions();
		for (pelib::import_library::imported_list::const_iterator itr = imports.begin(); itr != imports.end(); ++itr) {
			const pelib::imported_function& func = *itr;
			if (func.getName().length() > 0) {
                addr = _pOwner->getImageBase() + func.getNameRVA() + sizeof(uint16_t);
				if (maxAddr < (addr + func.getName().length() + 1)) {
					maxAddr = addr + func.getName().length() + 1;
				}
			}
		}
	}
	
	maxAddr = alignUp(maxAddr);

	cutData(minAddr, (uint32_t)(maxAddr - minAddr));
}

void PEDataInfo::processRelocs()
{
    if (_useEntireDataSections && _pOwner->hasRelocs()) {
		const pelib::relocation_table_list& relocTables = _pOwner->getRelocTables();
	
		for (pelib::relocation_table_list::const_iterator rtItr = relocTables.begin(); rtItr != relocTables.end(); ++rtItr) {
			const pelib::relocation_table& table = *rtItr;
			if (isAddrInside(_pOwner->getImageBase() + table.get_rva()) || isAddrInside(_pOwner->getImageBase() + table.get_rva() + 0x0FFF)) {
				const pelib::relocation_table::relocation_list& relocs = table.get_relocations();
				pelib::relocation_table::relocation_list::const_iterator rItr;
				for (rItr = relocs.begin(); rItr != relocs.end(); ++rItr) {
					const pelib::relocation_entry& entry = *rItr;
					uint64_t virtualAddr = _pOwner->getImageBase() + entry.getRVA();

					cutData(virtualAddr, sizeof(uint32_t));
				}
			}
		}
	}
}

uint64_t PEDataInfo::alignUp(uint64_t currentPos)
{
	uint32_t prefferedAlign = _pOwner->getPrefferedMemAlign();
	for (++currentPos; (currentPos % prefferedAlign) != 0; ++currentPos);
	return currentPos;
}

uint32_t PEDataInfo::getMaxDataSectionSize() const
{
	uint32_t maxSize;
	
	maxSize = _pOwner->getSectionSize(_pDataSection);
	if (maxSize < _pOwner->getSectionSize(_pRdataSection)) {
		maxSize = _pOwner->getSectionSize(_pRdataSection);
	}

	return maxSize;
}


void PEDataInfo::cutData(uint64_t va, uint32_t size)
{
	for (DataMap::iterator itr = _dataMap.begin(); itr != _dataMap.end(); ++itr) {
		if (va >= itr->first && va < (itr->first + itr->second)) {
            uint32_t prevDataSize = itr->second;
            itr->second = (uint32_t)(va - itr->first);

            uint64_t vaEnd = va + size;
            if (vaEnd < (itr->first + prevDataSize)) {
                addData(vaEnd, prevDataSize - itr->second - size);
                itr = _dataMap.begin();
            }
		}
		else if (itr->first > va && itr->first < (va + size)) {
			itr->second = 0;
			if ((itr->first + itr->second) > (va + size)) {
				addData(va + size, (uint32_t)((itr->first + itr->second) - (va + size)));
			}
		}
	}

	for (DataMap::iterator itr = _dataMap.begin(); itr != _dataMap.end(); ++itr) {
		if (itr->second == 0) {
			_dataMap.erase(itr);
			itr = _dataMap.begin();
		}
	}
}

void PEDataInfo::mergeContinuousBlocks()
{
	DataMap::iterator itr1 = _dataMap.begin();
	DataMap::iterator itr2 = _dataMap.begin();
	for (++itr2; itr2 != _dataMap.end(); ++itr2) {
		if ((itr1->first + itr1->second) == itr2->first || itr1->first == (itr2->first + itr2->second)) {
			std::pair<uint64_t, uint32_t> newBlock(min(itr1->first, itr2->first), itr1->second + itr2->second);
			_dataMap.erase(itr1, ++itr2);
			_dataMap.insert(newBlock);
			itr1 = _dataMap.begin();
			itr2 = _dataMap.begin();
		}
		else {
			++itr1;
		}
	}
}

void PEDataInfo::recoverData(uint64_t va, uint32_t size)
{
	// Восстанавливаемый блок может быть или концом или началом другого блока.
	for (DataMap::iterator itr = _dataMap.begin(); itr != _dataMap.end(); ++itr) {
		if ((va + size) == itr->first || va == (itr->first + itr->second)) {
			std::pair<uint64_t, uint32_t> newBlock(min(va, itr->first), itr->second + size);
			_dataMap.erase(itr);
			_dataMap.insert(newBlock);
			mergeContinuousBlocks();
			break;
		}
	}
}

void PEDataInfo::addReference(DISASM* pInstr, uint64_t dataAddr)
{
	_instrDataMap.insert(std::make_pair(pInstr, dataAddr));
}

InstrVector PEDataInfo::getReferencedInstrs(uint64_t dataVA)
{
	InstrVector instrs;
	for (InstrDataMap::iterator itr = _instrDataMap.begin(); itr != _instrDataMap.end(); ++itr) {
		if (itr->second == dataVA) {
			instrs.push_back(itr->first);
		}
	}

	return instrs;
}

void PEDataInfo::removeUnreferencedBlocks()
{
	for (DataMap::iterator itr = _dataMap.begin(); itr != _dataMap.end(); ) {
		InstrDataMap::const_iterator itr2;
		for (itr2 = _instrDataMap.begin(); itr2 != _instrDataMap.end(); ++itr2) {
			if (itr->first == itr2->second) {
				break;
			}
		}

		if (itr2 == _instrDataMap.end()) {
			_dataMap.erase(itr);
			itr = _dataMap.begin();
		}
		else {
			++itr;
		}
	}
}

uint8_t* PEDataInfo::getDataRawPtr(uint64_t dataVA)
{
	uint32_t offset;
	uint8_t* ptr = 0;
	if (_pDataSection != 0 && dataVA >= _dataSectionVA && dataVA < (_dataSectionVA + _dataSectionSize)) {
		offset = (uint32_t)(dataVA - _dataSectionVA);
		ptr = (uint8_t*)(_dataPtr + offset);
	}
	else if (_pRdataSection != 0 && dataVA >= _rdataSectionVA && dataVA < (_rdataSectionVA + _rdataSectionSize)) {
		offset = (uint32_t)(dataVA - _rdataSectionVA);
		ptr = (uint8_t*)(_rdataPtr + offset);
	}

	return ptr;
}

uint32_t PEDataInfo::getRVA(uint64_t va)
{
	if (_pRdataSection != 0 && va >= _rdataSectionVA && va < (_rdataSectionVA + _rdataSectionSize)) {
		return (uint32_t)(va - _rdataSectionVA);
	}
	else {
		return (uint32_t)(va - _dataSectionVA);
	}
}

puint_t PEDataInfo::getDataBasePtr(uint64_t va)
{
	if (_pRdataSection != 0 && va >= _rdataSectionVA && va < (_rdataSectionVA + _rdataSectionSize)) {
		return (puint_t)&_pRdataSection->getRawData()[0];
	}
	else {
		return (puint_t)&_pDataSection->getRawData()[0];
	}
}

void PEDataInfo::addData(uint64_t va, uint32_t size)
{
    if (size > 0) {
        cutData(va, size);
        _dataMap.insert(std::make_pair(va, size));
    }
}

uint32_t PEDataInfo::getTotalSize() const
{
	uint32_t totalSize = 0;
	for (DataMap::const_iterator itr = _dataMap.begin(); itr != _dataMap.end(); ++itr) {
		totalSize += itr->second;
	}

	return totalSize;
}

bool PEDataInfo::isAddrInside(int64_t addr, const bool excludeIAT) const
{
	if (addr == 0) {
		return false;
	}

	bool ret = ((_dataSectionVA > 0 && addr >= _dataSectionVA && addr < (_dataSectionVA + _dataSectionSize)) || (_rdataSectionVA > 0 && addr >= _rdataSectionVA && addr < (_rdataSectionVA + _rdataSectionSize))) &&
		(!excludeIAT || !_pOwner->isAddrInsideIAT(addr));

	return ret;
}

}
