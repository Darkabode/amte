#include "common.h"
#include "PEModule.h"
#include "Permutatator.h"

// TODO:
// - Замена инструкций на идентичные по семантике и по размеру.
//   - xor rer, reg <-> sub reg,reg
//   - mov reg1,reg2 <-> push reg2;pop reg1
//   - 
// - Перестановка блоков местами.
// - Перестановка функций.

namespace amte {

bool rrvaSmaller(pelib::relocation_entry& entry1, pelib::relocation_entry& entry2)
{
	return entry1.getRRVA() < entry2.getRRVA();
}

Permutatator::Permutatator()
{

}

Permutatator::~Permutatator()
{

}

void Permutatator::useModule(PEModule* pModule)
{
	_pModule = pModule;
	const pelib::relocation_table_list& relocTables = _pModule->getRelocTables();
	_newRelocTables.clear();
	// Дублируем релокации.
	for (pelib::relocation_table_list::const_iterator itr = relocTables.begin(); itr != relocTables.end(); ++itr) {
		const pelib::relocation_table& table = *itr;
		pelib::relocation_table newTable(table.get_rva());
		const pelib::relocation_table::relocation_list& relocs = table.get_relocations();
		for (pelib::relocation_table::relocation_list::const_iterator relItr = relocs.begin(); relItr != relocs.end(); ++relItr) {
			newTable.add_relocation(*relItr);
		}
		_newRelocTables.push_back(newTable);
	}
}

void Permutatator::permutate()
{
	if (!_permutated) {
		for (BlockVector::const_iterator itr = _pModule->getCodeInfo()->begin(); itr != _pModule->getCodeInfo()->end(); ++itr) {
			BasicBlock* pBlock = *itr;
			//		if (pBlock->getInstrCount() > 1 && (*pBlock->begin())->VirtualAddr == 0x00401127) {
			//			for (int i = 0; i < 10; ++i) {
			permutateBlock(pBlock->getInstructions(), pBlock->getInstrCount() - 1);
#if 0
			for (BasicBlock::InstrConstIterator iItr = pBlock->begin(); iItr != pBlock->end(); ++iItr) {
				const DISASM* pInstr = *iItr;
				std::cout << std::hex << (int)pInstr->VirtualAddr << "   " << (char*)&pInstr->CompleteInstr << std::endl;
			}
#endif
			//				std::cout << std::endl;
			//				Sleep(1000);
			//			}
			//		}
		}

		if (_pModule->getPEBase()->has_reloc()) {
			// Сортируем релоки.
			for (pelib::relocation_table_list::iterator itr = _newRelocTables.begin(); itr != _newRelocTables.end(); ++itr) {
				pelib::relocation_table& table = *itr;
				pelib::relocation_table::relocation_list& relocs = table.get_relocations();
				// Сортируем таблицу.
				std::sort(relocs.begin(), relocs.end(), rrvaSmaller);
			}

			pelib::pe_base* pImage = _pModule->getPEBase();
			pelib::rebuild_relocations(*pImage, _newRelocTables, pImage->section_from_rva(pImage->get_directory_rva(pelib::pe_win::image_directory_entry_basereloc)));
		}

		_permutated = true;
	}
}

bool Permutatator::isConflictFlags(uint8_t flag, uint8_t flagOther)
{
	if (flag != 0 && flagOther != 0) {
		return false;
	}
	/*
	if (flag & 0x3E) { // Флаг изменяется.
		// В этом случае, использование этого флага другой инструкцией запрещает смену позиции.
		if (flagOther != 0) {
			return false;
		}
	}
	else if (flag & 1) { // Запрашивается статус флага.
		// В этом случае, изменение позиции инструкции возможно только в случае, если она не использует флаг или просто запрашивает его статус.
		if (flagOther & 0x3E) {
			return false;
		}
	}
	*/
	return true;
}

bool Permutatator::checkCompatible(const DISASM* pInstr, const DISASM* pOtherDasm)
{
	int reg1Mod = 0, reg2Mod = 0, reg1ModOther = 0, reg2ModOther = 0;
	uint16_t reg1 = 0, memBaseReg1 = 0, memIndexReg1 = 0, reg2 = 0, memBaseReg2 = 0, memIndexReg2 = 0, regImplicit = 0, reg1Other = 0, memBaseReg1Other = 0, memIndexReg1Other = 0, reg2Other = 0, memBaseReg2Other = 0, memIndexReg2Other = 0, regImplicitOther = 0;

	reg1 = pInstr->Argument1.ArgType & 0xFFFF;
	reg1Mod = pInstr->Argument1.AccessMode;
	memBaseReg1 = pInstr->Argument1.Memory.BaseRegister & 0xFFFF;
	memIndexReg1 = pInstr->Argument1.Memory.IndexRegister & 0xFFFF;

	reg2 = pInstr->Argument2.ArgType & 0xFFFF;
	reg2Mod = pInstr->Argument2.AccessMode;
	memBaseReg2 = pInstr->Argument2.Memory.BaseRegister & 0xFFFF;
	memIndexReg2 = pInstr->Argument2.Memory.IndexRegister & 0xFFFF;

	regImplicit = pInstr->Instruction.ImplicitModifiedRegs & 0xFFFF;
	if (pInstr->Prefix.RepPrefix || pInstr->Prefix.RepnePrefix) {
		regImplicit |= REG1; // Добавляем регистр *CX, который изменяется
	}

	reg1Other = pOtherDasm->Argument1.ArgType & 0xFFFF;
	reg1ModOther = pOtherDasm->Argument1.AccessMode;
	memBaseReg1Other = pOtherDasm->Argument1.Memory.BaseRegister & 0xFFFF;
	memIndexReg1Other = pOtherDasm->Argument1.Memory.IndexRegister & 0xFFFF;

	reg2Other = pOtherDasm->Argument2.ArgType & 0xFFFF;
	reg2ModOther = pOtherDasm->Argument2.AccessMode;
	memBaseReg2Other = pOtherDasm->Argument2.Memory.BaseRegister & 0xFFFF;
	memIndexReg2Other = pOtherDasm->Argument2.Memory.IndexRegister & 0xFFFF;

	regImplicitOther = pOtherDasm->Instruction.ImplicitModifiedRegs & 0xFFFF;
	if (pOtherDasm->Prefix.RepPrefix || pOtherDasm->Prefix.RepnePrefix) {
		regImplicitOther |= REG1; // Добавляем регистр *CX, который изменяется
	}
	
	if (pOtherDasm->Instruction.BranchType != 0 ||
		(reg1ModOther == READ && reg2ModOther == READ && regImplicitOther == 0) ||
		(reg1Mod == WRITE && (reg1 & reg1Other || reg1 & reg2Other || reg1 & memBaseReg1Other || reg1 & memBaseReg2Other || reg1 & memIndexReg1Other || reg1 & memIndexReg2Other || reg1 & regImplicitOther)) ||
		(reg1Mod == READ && (reg1 & regImplicitOther || (reg1ModOther == WRITE && reg1 & reg1Other) || (reg2ModOther == WRITE && reg1 & reg2Other))) ||
		(reg1ModOther == WRITE && (reg1Other & reg1 || reg1Other & reg2 || reg1Other & memBaseReg1 || reg1Other & memBaseReg2 || reg1Other & memIndexReg1 || reg1Other & memIndexReg2 || reg1Other & regImplicit)) ||
		(reg1ModOther == READ && (reg1Other & regImplicit || (reg1Mod == WRITE && reg1Other & reg1) || (reg2Mod == WRITE && reg1Other & reg2))) ||
		(reg2Mod == WRITE && (reg2 & reg1Other || reg2 & reg2Other || reg2 & memBaseReg1Other || reg2 & memBaseReg2Other || reg2 & memIndexReg1Other || reg2 & memIndexReg2Other || reg2 & regImplicitOther)) ||
		(reg2Mod == READ && (reg2 & regImplicitOther || (reg1ModOther == WRITE && reg2 & reg1Other) || (reg2ModOther == WRITE && reg2 & reg2Other))) ||
		(reg2ModOther == WRITE && (reg2Other & reg1 || reg2Other & reg2 || reg2Other & memBaseReg1 || reg2Other & memBaseReg2 || reg2Other & memIndexReg1 || reg2Other & memIndexReg2 || reg2Other & regImplicit)) ||
		(reg2ModOther == READ && (reg2Other & regImplicit || (reg1Mod == WRITE && reg2Other & reg1) || (reg2Mod == WRITE && reg2Other & reg2))) ||
		regImplicit & reg1Other || regImplicit & reg2Other || regImplicit & memBaseReg1Other || regImplicit & memBaseReg2Other || regImplicit & memIndexReg1Other || regImplicit & memIndexReg2Other ||
		regImplicitOther & reg1 || regImplicitOther & reg2 || regImplicitOther & memBaseReg1 || regImplicitOther & memBaseReg2 || regImplicitOther & memIndexReg1 || regImplicitOther & memIndexReg2 ||
		regImplicit & regImplicitOther ||
		((memBaseReg1 != 0 || memIndexReg1 != 0 || pInstr->Argument1.Memory.Displacement != 0) && (memBaseReg1Other != 0 || memIndexReg1Other != 0 || pOtherDasm->Argument1.Memory.Displacement != 0)) ||
		((memBaseReg1 != 0 || memIndexReg1 != 0 || pInstr->Argument1.Memory.Displacement != 0) && (memBaseReg2Other != 0 || memIndexReg2Other != 0 || pOtherDasm->Argument2.Memory.Displacement != 0)) ||
		((memBaseReg2 != 0 || memIndexReg2 != 0 || pInstr->Argument2.Memory.Displacement != 0) && (memBaseReg1Other != 0 || memIndexReg1Other != 0 || pOtherDasm->Argument1.Memory.Displacement != 0)) ||
		!isConflictFlags(pInstr->Instruction.Flags.CF_, pOtherDasm->Instruction.Flags.CF_) ||
		!isConflictFlags(pInstr->Instruction.Flags.PF_, pOtherDasm->Instruction.Flags.PF_) ||
		!isConflictFlags(pInstr->Instruction.Flags.AF_, pOtherDasm->Instruction.Flags.AF_) ||
		!isConflictFlags(pInstr->Instruction.Flags.ZF_, pOtherDasm->Instruction.Flags.ZF_) ||
		!isConflictFlags(pInstr->Instruction.Flags.SF_, pOtherDasm->Instruction.Flags.SF_) ||
		!isConflictFlags(pInstr->Instruction.Flags.DF_, pOtherDasm->Instruction.Flags.DF_) ||
		!isConflictFlags(pInstr->Instruction.Flags.OF_, pOtherDasm->Instruction.Flags.OF_)) {
		return false;
	}
	
	return true;
}

void Permutatator::searchInterval(const InstrVector& block, InstrVector::const_iterator& startItr, InstrVector::const_iterator& endItr)
{
	InstrVector::const_iterator itr;
	InstrVector::const_iterator beginItr = block.begin();
	const DISASM* pInstr = *startItr;

	endItr = startItr +  1;

	if (startItr > beginItr) {
		// Ищем в обратном порядке.
		for (itr = startItr - 1; 1; --itr) {
			const DISASM* pOtherDasm = *itr;

			if (!checkCompatible(pInstr, pOtherDasm)) {
				break;
			}
			else {
				startItr = itr;
			}

			if (itr == beginItr) {
				break;
			}
		}
	}

	if (endItr < block.end() - 1) {
		// Ищем в прямом порядке.
		for (itr = endItr; itr < block.end(); ++itr) {
			const DISASM* pOtherDasm = *itr;

			if (!checkCompatible(pInstr, pOtherDasm)) {
				break;
			}
			else {
				endItr = itr + 1;
			}
		}
	}
}

void Permutatator::fixRelocEntry(uint32_t startRVA, uint32_t endRVA, int off)
{
	const pelib::relocation_table_list& relocTables = _pModule->getRelocTables();

	for (pelib::relocation_table_list::const_iterator itr = relocTables.begin(); itr != relocTables.end(); ++itr) {
		const pelib::relocation_table& table = *itr;
		pelib::relocation_table& newTable = *(_newRelocTables.begin() + (itr - relocTables.begin()));
		if ((startRVA & 0xFFFFF000) >= table.get_rva()) {
			const pelib::relocation_table::relocation_list& relocs = table.get_relocations();
			pelib::relocation_table::relocation_list& newRelocs = newTable.get_relocations();
			for (pelib::relocation_table::relocation_list::const_iterator relItr = relocs.begin(); relItr != relocs.end(); ++relItr) {
				const pelib::relocation_entry& entry = *relItr;
				uint32_t rva = entry.getRVA();
				if (entry.getType() == 3 || entry.getType() == 10) {
					if (rva > startRVA && rva < endRVA) {
						uint16_t newRRVA = entry.getRRVA() + off;
						/*
						if (newRRVA > 0xFFF) {
							// Релок вышел за пределы страницы.
							newRRVA -= 0x1000;
							pelib::relocation_entry newEntry(newRRVA, entry.get_type());
							// Проверяем существует ли у нас следующая таблица с релоками.
							if ((itr + 1) < _relocTables.end()) {
								pelib::relocation_table& nextTable = *(itr + 1);
								nextTable.add_relocation(newEntry);
								
								// Сортируем таблицу.
								std::sort(nextTable.get_relocations().begin(), nextTable.get_relocations().end(), rrvaSmaller);
							}
							else {
								// Создаём новую таблицу релоков и добавляем в неё элемент.
								pelib::relocation_table newTable(table.get_rva() + 0x1000);
								newTable.add_relocation(newEntry);
							}
						}
						else
						*/
						{
							pelib::relocation_entry& extEntry = (*(newRelocs.begin() + (relItr - relocs.begin())));
							extEntry.setRRVA(newRRVA);
							extEntry.setRVA(table.get_rva() + newRRVA);
						}
						return;
					}
				}
			}
		}
	}
}

void Permutatator::permutateBlock(InstrVector& block, int permutateTimes)
{
	std::size_t sz = block.size();
	// Алгоритм пермутации достаточно простой.
	// 1. Берём очерендую инструкцию.
	// 2. Если инструкция уже обработана/переставлена, возвращаемся к шагу 1.
	// 3. Если это инструкция перехода (call,ret,smp,jxx), то переходим к шагу 1. (Получается, все перстановки касаются только опкодов, модифицирующих регистры и память, включая стек, а также опкодов логических проверок).
	// 4. Ищем диапазон в котором инструкция может быть перемещена. (Как правило это непрерывный диапазон, в котором уже находится инструкция).
	// 5. Случайным образом определяем позицию внутри этого лиапазона и перемещаем туда инструкцию. Помечаем её, как обработанную и переходим к шагу 1.
	std::vector<uint64_t> _virtualAddrs;

	for (int i = 0; i < permutateTimes; ++i) {
		std::vector<uint64_t>::const_iterator addrItr;
		InstrVector::iterator itr, startItr, endItr;
		ulong_t rndVal;

		DISASM* pInstr;
		bool accepted = false;
		int counter = 0;
		do {
#if 1
			rndVal = Utils::random() % sz;
#else
			rndVal = 7;
#endif
			itr = block.begin() + rndVal;
			pInstr = *itr;
			addrItr = _virtualAddrs.begin();
			// Если инструкция перехода, или инструкция сравнения (CMP) то игнорируем её.
			if (pInstr->Instruction.BranchType == 0 && !(pInstr->Argument1.AccessMode == READ && pInstr->Argument2.AccessMode == READ && (pInstr->Instruction.ImplicitModifiedRegs & 0xFFFF) == 0)) {
				for (; addrItr != _virtualAddrs.end(); ++addrItr) {
					if (*addrItr == pInstr->VirtualAddr) {
						break;
					}
				}
				if (addrItr == _virtualAddrs.end()) {
					accepted = true;
				}
			}
			if (!accepted) {
				++counter;
			}
		} while (!accepted && counter < permutateTimes);

		if (counter < permutateTimes) {
			// Формируем допустимый для переставноки инструкции диапазон.
			startItr = itr;
			searchInterval(block, startItr, endItr);
			std::size_t cnt = endItr - startItr;
			if (cnt > 1) {
				std::size_t origPos = itr - startItr;
				InstrVector region(cnt);
				std::copy(startItr, endItr, region.begin());

#if 0//_DEBUG
				std::cout << std::endl;
				if (startItr > block.begin()) {
					DISASM* pInstr = *(startItr - 1);
					std::cout << std::hex << pInstr->VirtualAddr << " " << pInstr->CompleteInstr << std::endl;
				}
				for (BasicBlock::InstrIterator rItr = region.begin(); rItr != region.end(); ++rItr) {
					DISASM* pInstr = *rItr;
					if (rItr == region.begin() + origPos) {
						std::cout << "> ";
					}
					std::cout << std::hex << pInstr->VirtualAddr << " " << pInstr->CompleteInstr << std::endl;
				}
				if (endItr != block.end() && (endItr + 1) <  block.end()) {
					DISASM* pInstr = *(endItr + 1);
					std::cout << std::hex << pInstr->VirtualAddr << " " << pInstr->CompleteInstr << std::endl;
				}
#endif
				region.erase(region.begin() + origPos);
				do {
					rndVal = Utils::random() % cnt;
				} while (rndVal == origPos);
				region.insert(region.begin() + rndVal, pInstr);
#if 0//_DEBUG
				std::cerr << std::endl;
				if (startItr > block.begin()) {
					DISASM* pInstr = *(startItr - 1);
					std::cerr << std::hex << pInstr->VirtualAddr << " " << pInstr->CompleteInstr << std::endl;
				}
				for (BasicBlock::InstrIterator rItr = region.begin(); rItr != region.end(); ++rItr) {
					DISASM* pInstr = *rItr;
					if (rItr == region.begin() + rndVal) {
						std::cerr << "> ";
					}
					std::cerr << std::hex << pInstr->VirtualAddr << " " << pInstr->CompleteInstr << std::endl;
				}
				if (endItr != block.end() && (endItr + 1) <  block.end()) {
					DISASM* pInstr = *(endItr + 1);
					std::cerr << std::hex << pInstr->VirtualAddr << " " << pInstr->CompleteInstr << std::endl;
				}
#endif
				std::move(region.begin(), region.end(), startItr);

				_virtualAddrs.push_back(pInstr->VirtualAddr);
			}
//			else {
//				--i;
//			}
		}
	}

	uint64_t currVA = (uint64_t)-1;
	puint_t minEIP = (puint_t)-1;
	uint32_t totalLen = 0;
	
	// Ищем минимальный виртуальный адрес
	for (InstrVector::iterator itr = block.begin(); itr != block.end(); ++itr) {
		DISASM* pInstr = *itr;
		if (pInstr->VirtualAddr < currVA) {
			currVA = pInstr->VirtualAddr;
			minEIP = pInstr->EIP;
		}
		totalLen += pInstr->len;
	}

	uint8_t* pOldCode = new uint8_t[totalLen];
	memcpy(pOldCode, (const void*)minEIP, totalLen);

	// Корректируем виртуальные адреса инструкций в соответствии с длиной предыдущих.
	for (InstrVector::iterator itr = block.begin(); itr != block.end(); ++itr) {
		DISASM* pInstr = *itr;
		int off = (int)(currVA - pInstr->VirtualAddr);
		if (off != 0) {
			// Корректируем релок, если он попадает под инструкцию, которая была перемещена.
			fixRelocEntry((uint32_t)(pInstr->VirtualAddr - _pModule->getImageBase()), (uint32_t)(pInstr->VirtualAddr + pInstr->len - _pModule->getImageBase()), off);

			memcpy((void*)(pInstr->EIP + (pint_t)off), (const void*)(pOldCode + pInstr->EIP - minEIP), pInstr->len);
			pInstr->VirtualAddr += (int64_t)off;
			pInstr->EIP += (pint_t)off;
			
		}
		currVA += pInstr->len;
	}

	delete[] pOldCode;
}

}
