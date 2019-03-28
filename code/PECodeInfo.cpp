#include <iostream>
#include <fstream>
#include <sstream>

#include "common.h"
#include "PECodeInfo.h"
#include "UsefulInstrs.h"
#include "PEModule.h"

namespace amte {

Poco::MemoryPool _dasmMemPool(sizeof(DISASM), 65536);
Poco::MemoryPool _bblockMemPool(sizeof(BasicBlock), 32768);
Poco::MemoryPool _xrefMemPool(sizeof(Xref), 32768);

DISASM* newDISASM()
{
    return (DISASM*)_dasmMemPool.get();
}

void freeDISASM(DISASM* pInstr)
{
    _dasmMemPool.release(pInstr);
}

void* Xref::operator new (size_t sz)
{
    return _xrefMemPool.get();
}

void Xref::operator delete (void* p)
{
    _xrefMemPool.release(p);
}

void* BasicBlock::operator new (size_t sz)
{
return _bblockMemPool.get();
}

void BasicBlock::operator delete (void* p)
{
_bblockMemPool.release(p);
}

BasicBlock::BasicBlock()
{
	_maxInstrLength = 0;
	_inXrefCount = 0;
	_outXrefCount = 0;
	_blockSize = 0;
	_isFunction = false;

}

BasicBlock::~BasicBlock()
{
	for (InstrVector::iterator itr = _instrs.begin(); itr != _instrs.end(); ++itr) {
        freeDISASM(*itr);
	}
}

size_t BasicBlock::getMaxInstrLength()
{
	if (_maxInstrLength == 0) {
		for (InstrVector::const_iterator itr = _instrs.begin(); itr != _instrs.end(); ++itr) {
			const DISASM* pInstr = *itr;
			std::stringstream ss;
			ss << std::hex << (int)pInstr->VirtualAddr << " " << (char*)&pInstr->CompleteInstr;
			size_t sLen = ss.str().length();
			if (sLen > _maxInstrLength) {
				_maxInstrLength = sLen;
			}
		}
	}
	return _maxInstrLength;
}

size_t BasicBlock::getInstrCount() const
{
	return _instrs.size();
}

void BasicBlock::recalcBlockSize()
{
	_blockSize = 0;
	for (InstrVector::const_iterator itr = _instrs.begin(); itr != _instrs.end(); ++itr) {
		_blockSize += (*itr)->len;
	}
}

int BasicBlock::getBlockSize() const
{
	return _blockSize;
}

void BasicBlock::addInstruction(DISASM* pInstr)
{
	_instrs.push_back(pInstr);
	_blockSize += pInstr->len;
	if (pInstr->Instruction.BranchType != 0 && pInstr->Instruction.BranchType != RetType && pInstr->Instruction.BranchType != CallType) {
		for (XrefVector::iterator itr = _xrefs.begin(); itr != _xrefs.end(); ++itr) {
			Xref* pXref = *itr;
			// Ищем такую ссылку, у которой отсутствует инструкция перехода.
			if (pXref->getSourceBlock() == this && pXref->getSourceInstr() == 0) {
				pXref->setSourceInstr(pInstr);
				break;
			}
		}
	}
}


void BasicBlock::deleteXref(Xref* pXref)
{
	XrefVector::iterator itr = std::find(_xrefs.begin(), _xrefs.end(), pXref);
	if (itr != _xrefs.end()) {
		Xref* pXref = *itr;
		_xrefs.erase(itr);
		if (pXref->getSourceBlock() == this) {
			--_outXrefCount;
		}
		else {
			--_inXrefCount;
		}
	}
}

InstrVector::iterator BasicBlock::begin(const DISASM* pInstr)
{
	InstrVector::iterator itr;
	for (itr = begin(); itr != end(); ++itr) {
		if (*itr == pInstr) {
			break;
		}
	}

	return itr;
}

InstrVector::const_iterator BasicBlock::begin(const DISASM* pInstr) const
{
	InstrVector::const_iterator itr;
	for (itr = begin(); itr != end(); ++itr) {
		if (*itr == pInstr) {
			break;
		}
	}

	return itr;
}

InstrVector::reverse_iterator BasicBlock::rbegin(const DISASM* pInstr)
{
	InstrVector::reverse_iterator ritr;
	for (ritr = rbegin(); ritr != rend(); ++ritr) {
		if (*ritr == pInstr) {
			break;
		}
	}

	return ritr;
}

InstrVector::const_reverse_iterator BasicBlock::rbegin(const DISASM* pInstr) const
{
	InstrVector::const_reverse_iterator ritr;
	for (ritr = rbegin(); ritr != rend(); ++ritr) {
		if (*ritr == pInstr) {
			break;
		}
	}

	return ritr;
}

void BasicBlock::moveInstructionsTo(BasicBlock* pBlock, InstrVector::iterator beginItr, InstrVector::iterator endItr)
{
	std::move(beginItr, endItr, pBlock->begin());
	_instrs.erase(beginItr, endItr);
	// Пересчитываем размер блока.
	_blockSize = 0;
	for (InstrVector::const_iterator itr = _instrs.begin(); itr != _instrs.end(); ++itr) {
		_blockSize += (*itr)->len;
	}
}

void BasicBlock::reserve(std::size_t n)
{
	_instrs.resize(n);
}

void BasicBlock::replaceLastInstructionWith(DISASM* pNewInsrt)
{
	DISASM* pLastInstr = _instrs.back();
	_instrs.pop_back();
	_blockSize -= pLastInstr->len;
	if (pLastInstr->Instruction.BranchType != 0 && pLastInstr->Instruction.BranchType != RetType && pLastInstr->Instruction.BranchType != CallType) {
		for (XrefVector::iterator itr = _xrefs.begin(); itr != _xrefs.end(); ++itr) {
			Xref* pXref = *itr;
			if (pXref->getSourceInstr() == pLastInstr) {
				pXref->setSourceInstr(pNewInsrt);
				break;
			}
		}
	}

    freeDISASM(pLastInstr);
	_instrs.push_back(pNewInsrt);
	_blockSize += pNewInsrt->len;
}

const DISASM* const BasicBlock::getAffectedInstr(uint64_t va)
{
	for (InstrVector::const_iterator itr = _instrs.begin(); itr != _instrs.end(); ++itr) {
		const DISASM* const pInstr = *itr;
		if (va >= pInstr->VirtualAddr && va < (pInstr->VirtualAddr + pInstr->len)) {
			return pInstr;
		}
	}

	return 0;
}

Xref* PECodeInfo::createXref(BasicBlock* pSourceBlock, BasicBlock* pTargetBlock)
{
	Xref* pXref = new Xref(pSourceBlock, pTargetBlock);

	pSourceBlock->_xrefs.push_back(pXref);
	++pSourceBlock->_outXrefCount;

	pTargetBlock->_xrefs.push_back(pXref);
	++pTargetBlock->_inXrefCount;

	if (pSourceBlock->getOutXrefCount() == 1) {
		DISASM* pSourceLastIntr = pSourceBlock->getLastInstruction();
		if (pSourceLastIntr->Instruction.BranchType != 0 && pSourceLastIntr->Instruction.BranchType != RetType && pSourceLastIntr->Instruction.BranchType != CallType) {
			pXref->setSourceInstr(pSourceLastIntr);
		}
	}

	return pXref;
}

void PECodeInfo::deleteXref(Xref* pXref)
{
	pXref->getSourceBlock()->deleteXref(pXref);
	pXref->getTargetBlock()->deleteXref(pXref);
}

void PECodeInfo::moveTarget(Xref* pXref, BasicBlock* pBlock)
{
	XrefVector& xrefs = pXref->getTargetBlock()->getXrefs();
	XrefVector::iterator itr = std::find(xrefs.begin(), xrefs.end(), pXref);
	if (itr != xrefs.end()) {
		Xref* pXref = *itr;
		pXref->getTargetBlock()->getXrefs().erase(itr);
		--pXref->getTargetBlock()->_inXrefCount;
		++pBlock->_inXrefCount;
		pBlock->getXrefs().push_back(pXref);
		pXref->setTargetBlock(pBlock);
	}
}

void PECodeInfo::moveSource(Xref* pXref, BasicBlock* pBlock)
{
	XrefVector& xrefs = pXref->getSourceBlock()->getXrefs();
	XrefVector::iterator itr = std::find(xrefs.begin(), xrefs.end(), pXref);
	if (itr != xrefs.end()) {
		Xref* pXref = *itr;
		pXref->getSourceBlock()->getXrefs().erase(itr);
		--pXref->getSourceBlock()->_outXrefCount;
		++pBlock->_outXrefCount;
		pBlock->getXrefs().push_back(pXref);
		pXref->setSourceBlock(pBlock);
	}
}

Xref* PECodeInfo::searchXref(BasicBlock* pSourceBlock, BasicBlock* pTargetBlock) const
{
	XrefVector& xrefs = pSourceBlock->getXrefs();
	for (XrefVector::iterator itr = xrefs.begin(); itr != xrefs.end(); ++itr) {
		Xref* pXref = *itr;
		if (pXref->getSourceBlock() == pSourceBlock && pXref->getTargetBlock() == pTargetBlock) {
			return pXref;
		}
	}

	return 0;
}

PECodeInfo::PECodeInfo(PEModule* pOwner)
{
	_pOwner = pOwner;
	_codeSize = 0;
	__stosb((uint8_t*)&_disasm, 0, sizeof(_disasm));
}

PECodeInfo::~PECodeInfo()
{
	for (BlockVector::iterator itr = _basicBlocks.begin(); !_basicBlocks.empty(); ) {
		deleteBlock(*itr);
		itr = _basicBlocks.begin();
	}

	for (ListenersMap::iterator itr = _listeners.begin(); itr != _listeners.end(); ++itr) {
		delete itr->second;
	}
}

void PECodeInfo::init(puint_t codePtr, uint64_t virtualCodeBase, uint32_t sectionLength)
{
	_codePtr = codePtr;
	_virtualCodeBase = virtualCodeBase;
	_sectionLength = sectionLength;
	_disasm.Archi = 0;
}

void PECodeInfo::addInstrListener(const std::string& mnemonic, DelegateBase* pDelegate)
{
	for (ListenersMap::iterator itr = _listeners.begin(); itr != _listeners.end(); ++itr) {
		if (itr->first == mnemonic) {
			itr->second = pDelegate;
			return;
		}
	}
	_listeners.insert(std::make_pair(mnemonic, pDelegate));
}

void PECodeInfo::invokeInstrListener(DISASM* pInstr)
{
	for (ListenersMap::iterator itr = _listeners.begin(); itr != _listeners.end(); ++itr) {
		if (itr->first == pInstr->Instruction.Mnemonic || itr->first == "*") {
			(*itr->second)(pInstr);
			break;
		}
	}
}

void PECodeInfo::addFunction(BasicBlock* pBlock)
{
	BlockVector::iterator itr = std::find(_firstFuncBlocks.begin(), _firstFuncBlocks.end(), pBlock);
	if (itr == _firstFuncBlocks.end()) {
		_firstFuncBlocks.push_back(pBlock);
	}
}


bool PECodeInfo::isFirstFunctionBlock(const BasicBlock* pBlock)
{
	for (BlockVector::iterator itr = _firstFuncBlocks.begin(); itr != _firstFuncBlocks.end(); ++itr) {
		if (pBlock == *itr) {
			return true;
		}
	}

	return false;
}

void PECodeInfo::scanInnerBlocks(const BasicBlock* pBlock, const uint32_t reg, InstrVector& occurs, BlockVector& visitedBlocks)
{
	const XrefVector& xrefs = pBlock->getXrefs();

	for (XrefVector::const_iterator xrefItr = xrefs.begin(); xrefItr != xrefs.end(); ++xrefItr) {
		Xref* pXref = *xrefItr;
		if (pXref->getTargetBlock() == pBlock) {
			const BasicBlock* pInnerBlock = pXref->getSourceBlock();

			BlockVector::const_iterator extBlockItr = std::find(visitedBlocks.begin(), visitedBlocks.end(), pBlock);
			if (extBlockItr == visitedBlocks.end()) {
				visitedBlocks.push_back(const_cast<BasicBlock*>(pBlock));
				if (pInnerBlock != pBlock) {
					for (InstrVector::const_reverse_iterator ritr = pInnerBlock->rbegin(); ritr != pInnerBlock->rend(); ++ritr) {
						const DISASM* pInstr = *ritr;

						if ((pInstr->Argument1.ArgType & 0xFFFF0000) == (REGISTER_TYPE + GENERAL_REG) && (pInstr->Argument1.ArgType & 0x0000FFFF) == reg && pInstr->Argument1.AccessMode == WRITE) {
							occurs.push_back((DISASM*)pInstr);
							break;
						}
					}

					if (!isFirstFunctionBlock(pInnerBlock)) {
						scanInnerBlocks(pInnerBlock, reg, occurs, visitedBlocks);
					}
				}
			}
		}
	}
}

DISASM* PECodeInfo::searchBackInstrWithRegModifiedFor(const DISASM* pInstrFrom)
{
	// Поиск инструкции в которой меняется регистр используемый в инструкции, переданной в качестве первого аргумента.
	// Поиск должен осуществляться в пределах одной функции.
	uint32_t reg = 0;
	BasicBlock* pBlock = getBlockWithInstr(pInstrFrom);
	DISASM* pInstr;

	if ((pInstrFrom->Argument1.ArgType & 0xFFFF0000) == (REGISTER_TYPE + GENERAL_REG) && pInstrFrom->Argument1.AccessMode == READ) {
		reg = pInstrFrom->Argument1.ArgType & 0x0000FFFF;
	}
	else if ((pInstrFrom->Argument2.ArgType & 0xFFFF0000) == (REGISTER_TYPE + GENERAL_REG) && pInstrFrom->Argument2.AccessMode == READ) {
		reg = pInstrFrom->Argument2.ArgType & 0x0000FFFF;
	}

	for (InstrVector::reverse_iterator ritr = pBlock->rbegin(pInstrFrom) + 1; ritr != pBlock->rend(); ++ritr) {
		pInstr = *ritr;

		if ((pInstr->Argument1.ArgType & 0xFFFF0000) == (REGISTER_TYPE + GENERAL_REG) && (pInstr->Argument1.ArgType & 0x0000FFFF) == reg && pInstr->Argument1.AccessMode == WRITE) {
			return pInstr;
		}
	}

	InstrVector occurs;
	BlockVector visitedBlocks;

	scanInnerBlocks(pBlock, reg, occurs, visitedBlocks);

	pInstr = 0;
	uint64_t maxAddr = 0;

	for (InstrVector::iterator itr = occurs.begin(); itr != occurs.end(); ++itr) {
		DISASM* pOccurDasm = *itr;
		if (pOccurDasm->VirtualAddr > maxAddr) {
			maxAddr = pOccurDasm->VirtualAddr;
			pInstr = pOccurDasm;
		}
	}

	return pInstr;
}

DISASM* PECodeInfo::searchBackInstr(const DISASM* pInstrFrom, const char* mnemonic)
{
	BasicBlock* pBlock = getBlockWithInstr(pInstrFrom);

	for (InstrVector::const_reverse_iterator ritr = pBlock->rbegin(pInstrFrom) + 1; ritr != pBlock->rend(); ++ritr) {
		DISASM* pInstr = *ritr;

		if (lstrcmpA(pInstr->Instruction.Mnemonic, mnemonic) == 0) {
			return pInstr;
		}
	}

	return 0;
}

void PECodeInfo::finalizeAllBlocksWithLongJumps()
{
	// Если в конце блока нет инструкции перехода, то
	// добавляем в конец каждого блока безусловный переход на следующий блок:
	// в качестве безусловного перехода могут быть следующие варианты:
	// - jmp dword/qword <addr>; (x32: 5 байтов).
	// - push dword/qword <addr>; ret; (x32: 6 байтов).
	// Иначе заменяем интрукции с короткими прыжками на аналогичные инструкции с длинными прыжками.
	UsefulInstrs* pUsefulInstrs = UsefulInstrs::getInstance();

	for (BlockVector::iterator blockItr = _basicBlocks.begin(); blockItr != _basicBlocks.end(); ++blockItr) {
		BasicBlock* pBlock = *blockItr;
		DISASM* pInstr = pBlock->getLastInstruction();
		int32_t branchType = pInstr->Instruction.BranchType;

		if (branchType == 0 || branchType == CallType) {
			pBlock->addInstruction(pUsefulInstrs->cloneInstr(UsefulInstrs::jmpDWORD));
		}
		else if (branchType != RetType) {
			if (pInstr->len < 5) { // короткие Jxx 
				DISASM* pNewDasm = pUsefulInstrs->cloneEqualDWORDJxx(pInstr->Instruction.Opcode);
				if (pNewDasm == 0) {
					std::string err = "No equal long instruction for ";
					err += pInstr->CompleteInstr;
					throw Poco::RuntimeException(err);
				}
				pBlock->replaceLastInstructionWith(pNewDasm);
				pInstr = pBlock->getLastInstruction();
			}
			if (pInstr->Instruction.BranchType != JmpType) {
				pBlock->addInstruction(pUsefulInstrs->cloneInstr(UsefulInstrs::jmpDWORD));
			}
		}
	}
}

bool predLowerAddr(DISASM* pInstr1, DISASM* pInstr2)
{
	return pInstr1->VirtualAddr < pInstr2->VirtualAddr;
}

void PECodeInfo::analyze(uint32_t codeRRVA)
{
	_disasm.EIP = _codePtr + codeRRVA;
	_loaderCodeEnd = _codePtr + _sectionLength;
	_disasm.VirtualAddr = _virtualCodeBase + codeRRVA;

	if (getBlockAtAddr(_disasm.VirtualAddr) == 0) {
		// Создаём самый первый блок кода.
		BasicBlock* pBlock = createBlock();
		//std::cout << "Func: 0x" << std::hex << _disasm.VirtualAddr << std::endl;
		analyzeRecursive(_disasm, pBlock);

		// Сортируем все инструкции по возрастанию адреса.
		std::sort(_allInstrs.begin(), _allInstrs.end(), predLowerAddr);
	}
}

puint_t PECodeInfo::rva2offset(uint32_t rva)
{
	return _codePtr + rva;
}

int PECodeInfo::nextInstruction(DISASM& dasm, int len)
{
	int err = 0;
	// Переходим к следующей инструкции
	dasm.EIP = dasm.EIP + (uintptr_t)len;
	dasm.VirtualAddr = dasm.VirtualAddr + (uintptr_t)len;
	if (dasm.EIP >= (uintptr_t)_loaderCodeEnd) {
		std::cout << "End of buffer reached!" << std::endl;
		err = 1;
	}

	return err;
}

BasicBlock* PECodeInfo::getBlockWithInstr(const DISASM* pInstr)
{
	bool isFirstInstr;
	return findBlockFor(*pInstr, isFirstInstr);
}

BasicBlock* PECodeInfo::getBlockAtAddr(uint64_t virtAddr)
{
	for (BlockVector::iterator itr = _basicBlocks.begin(); itr != _basicBlocks.end(); ++itr) {
		BasicBlock* pBlock = *itr;
		if (pBlock->hasInstructions()) {
			DISASM* pFirstInstr = pBlock->getFirstInstruction();
			if (virtAddr == pFirstInstr->VirtualAddr) {
				return pBlock;
			}
		}
	}

	return 0;
}

BasicBlock* PECodeInfo::findBlockFor(const DISASM& dasm, bool& isFirstInstr)
{
	isFirstInstr = false;
	for (BlockVector::const_iterator itr = _basicBlocks.begin(); itr != _basicBlocks.end(); ++itr) {
		BasicBlock* pBlock = *itr;
		if (pBlock->hasInstructions()) {
			const DISASM* pFirstInstr = pBlock->getFirstInstruction();
			const DISASM* pLastInstr = pBlock->getLastInstruction();
			if ((dasm.EIP >= pFirstInstr->EIP && dasm.VirtualAddr >= pFirstInstr->VirtualAddr) && (dasm.EIP <= pLastInstr->EIP && dasm.VirtualAddr <= pLastInstr->VirtualAddr)) {
				if (dasm.EIP == pFirstInstr->EIP && dasm.VirtualAddr == pFirstInstr->VirtualAddr) {
					isFirstInstr = true;
				}
				return pBlock;
			}
		}
	}

	return 0;
}

BasicBlock* PECodeInfo::splitBlock(BasicBlock* pBlock, const DISASM* const pBreakInstr)
{
	BasicBlock* pNewBlock = 0;

	for (InstrVector::iterator itr = pBlock->begin(); itr != pBlock->end(); ++itr) {
		const DISASM* pInstr = *itr;
		
		if (pInstr->EIP == pBreakInstr->EIP && pInstr->VirtualAddr == pBreakInstr->VirtualAddr) {
			pNewBlock = createBlock();
			pNewBlock->reserve(pBlock->end() - itr);
			pBlock->moveInstructionsTo(pNewBlock, itr, pBlock->end());
			pNewBlock->recalcBlockSize();

			// Т. к. у оригинального блока могли быть исходящие связи с другим(и) блоками, то мы должны их переопределить.
			// Для этого нужно получить все блоки, с которыми есть исходящие связи, удалить их и создать новые, связав новый блок с полученными блоками.
			XrefVector& xrefs = pBlock->getXrefs();
			for (XrefVector::iterator xrefItr = xrefs.begin(); xrefItr != xrefs.end(); ) {
				Xref* pXref = *xrefItr;
				if (pXref->getSourceBlock() == pBlock) {
					moveSource(pXref, pNewBlock);
					xrefItr = xrefs.begin();
				}
				else {
					++xrefItr;
				}
			}

			// Создаём связь между блоками (оставшимся старым и отделённым от него новым).
			createXref(pBlock, pNewBlock);
			break;
		}
	}
	return pNewBlock;
}

BasicBlock* PECodeInfo::createBlock()
{
	BasicBlock* pBlock = new BasicBlock();
	_basicBlocks.push_back(pBlock);
	return pBlock;
}

void PECodeInfo::deleteBlock(BasicBlock* pBlock)
{
	BlockVector::iterator blockItr = std::find(_basicBlocks.begin(), _basicBlocks.end(), pBlock);
	if (blockItr != _basicBlocks.end()) {
		_basicBlocks.erase(blockItr);

		XrefVector& xrefs = pBlock->getXrefs();
		for (XrefVector::iterator itr = xrefs.begin(); !xrefs.empty();) {
			deleteXref(*itr);
			itr = xrefs.begin();
		}
		delete pBlock;
	}
}

BasicBlock* PECodeInfo::breakBlock(BasicBlock* pBlock, uint64_t vaStart, uint64_t vaEnd)
{
	const DISASM* pDasmStart = pBlock->getAffectedInstr(vaStart);
	const DISASM* pDasmEnd = pBlock->getAffectedInstr(vaEnd);
	BasicBlock* pAffectedBlock;

	if (pDasmStart == pBlock->getFirstInstruction()) {
		if (pDasmEnd != 0 && (pDasmEnd != pBlock->getLastInstruction() || vaEnd == pDasmEnd->VirtualAddr)) {
			if (vaEnd == pDasmEnd->VirtualAddr) {
				splitBlock(pBlock, pDasmEnd);
			}
			else {
				splitBlock(pBlock, *(pBlock->begin(pDasmEnd) + 1));
			}
		}
		pAffectedBlock = pBlock;
	}
	else if (pDasmEnd == 0 || (pDasmEnd == pBlock->getLastInstruction() && vaEnd > pDasmEnd->VirtualAddr && vaEnd < (pDasmEnd->VirtualAddr + pDasmEnd->len))) {
		if (pDasmStart != pBlock->getFirstInstruction()) {
			pAffectedBlock = splitBlock(pBlock, pDasmStart);
		}
		else {
			pAffectedBlock = pBlock;
		}
	}
	else {
		pAffectedBlock = splitBlock(pBlock, pDasmStart);
		if (vaEnd == pDasmEnd->VirtualAddr) {
			splitBlock(pAffectedBlock, pDasmEnd);
		}
		else {
			splitBlock(pAffectedBlock, *(pAffectedBlock->begin(pDasmEnd) + 1));
		}
		
	}

	return pAffectedBlock;
}

void PECodeInfo::addInsrt(BasicBlock* pBlock, DISASM* pInstr)
{
	pBlock->addInstruction(pInstr);
	_codeSize += pInstr->len;
	_allInstrs.push_back(pInstr);

	invokeInstrListener(pInstr);
}

int PECodeInfo::analyzeRecursive(DISASM& dasm, BasicBlock* pBlock)
{
	int err = 0;
	bool isFirstInstruction;

	// Дизассемблируем.
	while (!err) {
		dasm.SecurityBlock = _loaderCodeEnd - dasm.EIP;

		dasm.len = Disasm(&dasm);
		if (dasm.len == OUT_OF_BLOCK) {
			std::cout << "disasm engine is not allowed to read more memory" << std::endl;
			err = 1;
		}
		else if (dasm.len == UNKNOWN_OPCODE) {
			throw pelib::pe_exception("unknown opcode");
		}
		else {
#if 0
				std::cout << std::hex << (int)dasm.VirtualAddr << "   " << (char*)&dasm.CompleteInstr << std::endl;
#endif
				/*
				if (dasm.VirtualAddr == 0x4025B4) {
					std::cout << "break1" << std::endl;
				}
				*/
			// Прежде чем добавлять инструкцию, надо убедиться, что она не принадлежит никакому из существующих блоков.
			BasicBlock* pExtBlock = findBlockFor(dasm, isFirstInstruction);
			if (pExtBlock != 0) {
				// Найден блок, содержащий данную инструкцию, важно, чтобы в блоке это была первая инструкция.
				if (!isFirstInstruction) {
					std::stringstream ss;
					ss << "instruction at address " << std::hex << dasm.VirtualAddr << " is not the first instrution in block";
					throw pelib::pe_exception(ss.str());
				}

				createXref(pBlock, pExtBlock);
				// Т. к. мы упёрлись в блок, завершаем текущую рекурсивную итерацию.
				return err;
			}
			else {
                DISASM* pInstrClone = newDISASM();
				__movsb((uint8_t*)pInstrClone, (const uint8_t*)&dasm, sizeof(DISASM));

				if (dasm.Instruction.BranchType != 0) {
					// У нас инструкция перехода.
					DISASM jxxDasm;

					// Добавляем инструкцию в блок.
					addInsrt(pBlock, pInstrClone);

					if (dasm.Instruction.BranchType == RetType) {
						// Завершаем дизассемблирование блока.
						return err;
					}

					BasicBlock* pJxxBlock;

					__movsb((uint8_t*)&jxxDasm, (const uint8_t*)pInstrClone, sizeof(DISASM));

					if (jxxDasm.Instruction.BranchType == JmpType && (jxxDasm.Argument1.ArgType & 0xFFFF0000) == MEMORY_TYPE && jxxDasm.Argument1.Memory.IndexRegister != 0 &&
						(_pOwner->isAddrInsideCode(jxxDasm.Argument1.Memory.Displacement) || _pOwner->isAddrInsideData(jxxDasm.Argument1.Memory.Displacement, true))) {
						// switch/case
						uint32_t rva = (uint32_t)(jxxDasm.Argument1.Memory.Displacement - _virtualCodeBase);
						uint64_t someAddr = *((uint32_t*)(_codePtr + rva));
lCaseCounter:
						if (_pOwner->isAddrInsideCode(someAddr)) {
							do {
								jxxDasm.EIP = rva2offset((uint32_t)(someAddr - _virtualCodeBase));
								jxxDasm.VirtualAddr = someAddr;
								pJxxBlock = findBlockFor(jxxDasm, isFirstInstruction);
								if (pJxxBlock == 0) {
									// Создаём новый блок, куда будет ссылаться jxx,call,jmp.
									pJxxBlock = createBlock();

									createXref(pBlock, pJxxBlock);

									// дизассемблируем блок по переходу.
									err = analyzeRecursive(jxxDasm, pJxxBlock);
									if (err) {
										std::cout << std::endl;
									}

									// Т. к. в процессе анализа, блоки на момент инициации предыдущей рекурсивной итерации могли быть разбиты, необходимо осуществить заного поиск блока для текущей инструкции.
									pBlock = findBlockFor(dasm, isFirstInstruction);
								}
								else if (!isFirstInstruction) {
									// Текущая инструкция является не первой в найденном блоке, и значит следует разбить блок и создать между текущим и новым связь.
									splitBlock(pJxxBlock, &jxxDasm);

									// Ищем блок, к которому принадлежит текущая инструкция, т. к. после разбиения блока, текущая инструкция может уже быть вв разделённом блоке.
									pBlock = findBlockFor(dasm, isFirstInstruction);

									// Ищем блок, куда указывает инструкция перехода.
									pJxxBlock = findBlockFor(jxxDasm, isFirstInstruction);
									createXref(pBlock, pJxxBlock);

									//std::cout << "Not first instructio bin switch/case code at address " << std::hex << jxxDasm.VirtualAddr << std::endl;
								}
								else {
									Xref* e = searchXref(pBlock, pJxxBlock);
									if (e == 0) {
										createXref(pBlock, pJxxBlock);
									}
								}
								rva += _pOwner->getPrefferedMemAlign();
								someAddr = *((uint32_t*)(_codePtr + rva));
							} while (_pOwner->isAddrInsideCode(someAddr));
							
							return err;
						}
						else {
							someAddr = *((uint32_t*)(_codePtr + _pOwner->getPrefferedMemAlign() + rva));
							if (_pOwner->isAddrInsideCode(someAddr)) {
								goto lCaseCounter;
							}
							else if (_pOwner->isAddrInsideCode(jxxDasm.Argument1.Memory.Displacement)) {
								jxxDasm.EIP = rva2offset((uint32_t)(jxxDasm.Argument1.Memory.Displacement - _virtualCodeBase));
								jxxDasm.VirtualAddr = jxxDasm.Argument1.Memory.Displacement;
							}
							else {
								return err;
							}
						}
					}
					else {
						if ((jxxDasm.Argument1.ArgType & 0xFFFF0000) == MEMORY_TYPE && (_pOwner->isAddrInsideCode(jxxDasm.Argument1.Memory.Displacement) || _pOwner->isAddrInsideData(jxxDasm.Argument1.Memory.Displacement, true))) {
							uint32_t rva;
							uint64_t someAddr;
							if (_pOwner->isAddrInsideCode(jxxDasm.Argument1.Memory.Displacement)) {
								rva = (uint32_t)(jxxDasm.Argument1.Memory.Displacement - _virtualCodeBase);
								someAddr = *((uint32_t*)(_codePtr + rva));
							}
							else {
								rva = _pOwner->getDatas()->getRVA(jxxDasm.Argument1.Memory.Displacement);
								someAddr = *((uint32_t*)(_pOwner->getDatas()->getDataBasePtr(jxxDasm.Argument1.Memory.Displacement) + rva));
							}
							
							if (_pOwner->isAddrInsideCode(someAddr)) {
								jxxDasm.EIP = rva2offset((uint32_t)(someAddr - _virtualCodeBase));
								jxxDasm.VirtualAddr = someAddr;
							}
							else {
								jxxDasm.VirtualAddr = 0;
							}
						}
						else {
							jxxDasm.EIP = rva2offset((uint32_t)(jxxDasm.Instruction.AddrValue - _virtualCodeBase));
							jxxDasm.VirtualAddr = jxxDasm.Instruction.AddrValue;
						}
					}

					// Ищем блок среди уже существующих, на который ссылается инструкция перехода.
					pJxxBlock = findBlockFor(jxxDasm, isFirstInstruction);
					if (pJxxBlock == 0) {
						bool isFunctionCall = (dasm.Instruction.BranchType == CallType);
						if (isFunctionCall || dasm.Instruction.BranchType == JmpType) {
							if (jxxDasm.VirtualAddr < _virtualCodeBase || jxxDasm.VirtualAddr >= (_virtualCodeBase + _sectionLength)) {
								// Адрес за пределами секции кода (вызов нелокальной функции), просто добавляем инструкцию в текущий блок.
								if (dasm.Instruction.BranchType == JmpType) {
									return err;
								}
								err = nextInstruction(dasm, dasm.len);
								continue;
							}
						}

						// Создаём новый блок, куда будет ссылаться jxx,call,jmp.
						pJxxBlock = createBlock();

						if (!isFunctionCall) {
							createXref(pBlock, pJxxBlock);
						}
						else {
							//std::cout << "Func: 0x" << std::hex << jxxDasm.VirtualAddr << std::endl;
							addFunction(pJxxBlock);
						}

						// дизассемблируем блок по переходу.
						err = analyzeRecursive(jxxDasm, pJxxBlock);

						// Т. к. в процессе анализа, блоки на момент инициации предыдущей рекурсивной итерации могли быть разбиты, необходимо осуществить заного поиск блока для текущей инструкции.
						pBlock = findBlockFor(dasm, isFirstInstruction);

						if (dasm.Instruction.BranchType == CallType) {
							// Продолжаем формировать блок.
							err = nextInstruction(dasm, dasm.len);
							continue;
						}
					}
					else if (!isFirstInstruction) {
						// Текущая инструкция является не первой в найденном блоке, и значит следует разбить блок и создать между текущим и новым связь.
						splitBlock(pJxxBlock, &jxxDasm);

						// Ищем блок, к которому принадлежит текущая инструкция, т. к. после разбиения блока, текущая инструкция может уже быть вв разделённом блоке.
						pBlock = findBlockFor(dasm, isFirstInstruction);

						// Ищем блок, куда указывает инструкция перехода.
						pJxxBlock = findBlockFor(jxxDasm, isFirstInstruction);
						createXref(pBlock, pJxxBlock);
					}
					else {
						Xref* e = searchXref(pBlock, pJxxBlock);
						if (e == 0) {
							createXref(pBlock, pJxxBlock);
						}
					}

					if (dasm.Instruction.BranchType == JmpType) {
						return err;
					}

					// Переходим к следующей инструкции.
					err = nextInstruction(dasm, dasm.len);
					if (!err) {
						// Ищем инструкцию среди существующих блоков.
						BasicBlock* pContBlock = findBlockFor(dasm, isFirstInstruction);

						if (pContBlock == 0) {
							// Создаём новый блок, который будет начинаться с инструкции сразу за jmp.
							pContBlock = createBlock();

							createXref(pBlock, pContBlock);

							// Анализируем новый блок.
							err = analyzeRecursive(dasm, pContBlock);
						}
						else {
							Xref* e = searchXref(pBlock, pContBlock);
							if (e == 0) {
								createXref(pBlock, pContBlock);
							}
						}

						return err;
					}
				}
				else {
					addInsrt(pBlock, pInstrClone);

					err = nextInstruction(dasm, dasm.len);
				}
			}
		}
	}

	return err;
}

}
