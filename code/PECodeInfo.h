#ifndef __AMTE_PECODEINFO_H_
#define __AMTE_PECODEINFO_H_

namespace amte {

class Xref
{
public:
	Xref(BasicBlock* src, BasicBlock* tgt)
	{
		_pSourceBlock = src;
		_pSourceInstr = 0;
		_pTargetBlock = tgt;
	}

	BasicBlock* getSourceBlock() const { return _pSourceBlock; }
	void setSourceBlock(BasicBlock* pBlock) { _pSourceBlock = pBlock; }
	void setSourceInstr(DISASM* pInstr) { _pSourceInstr = pInstr; }
	DISASM* getSourceInstr() const { return _pSourceInstr; }
	BasicBlock* getTargetBlock() const { return _pTargetBlock; }
	void setTargetBlock(BasicBlock* pBlock) { _pTargetBlock = pBlock; }

    static void* operator new (size_t sz);
    static void* operator new (size_t, void* p){ return p; }
    static void operator delete (void* p);
    static void operator delete (void*, void*) {}

private:
	Xref(const Xref& other);
	const Xref& operator=(const Xref& other);

	BasicBlock* _pSourceBlock;
	DISASM* _pSourceInstr;
	BasicBlock* _pTargetBlock;
};

class BasicBlock
{
public:
	friend class PECodeInfo;

	BasicBlock();
	~BasicBlock();

	size_t getMaxInstrLength();
	size_t getInstrCount() const;
	void recalcBlockSize();
	int getBlockSize() const;

	void addInstruction(DISASM* pInstr);
	
	bool hasInstructions() const { return !_instrs.empty(); }

	InstrVector& getInstructions() { return _instrs; }
	XrefVector& getXrefs() { return _xrefs; }
	const XrefVector& getXrefs() const { return _xrefs; }
	void deleteXref(Xref* pXref);
	const InstrVector& getInstructions() const { return _instrs; }
	DISASM* getFirstInstruction() const { return _instrs.front(); }
	DISASM* getLastInstruction() const { return _instrs.back(); }
	void replaceLastInstructionWith(DISASM* pNewInsrt);
	const DISASM* const getAffectedInstr(uint64_t va);

	
	InstrVector::iterator begin() { return _instrs.begin(); }
	InstrVector::const_iterator end() const { return _instrs.end(); }
	InstrVector::const_iterator begin() const { return _instrs.begin(); }
	InstrVector::iterator end() { return _instrs.end(); }
	InstrVector::reverse_iterator rbegin() { return _instrs.rbegin(); }
	InstrVector::reverse_iterator rend() { return _instrs.rend(); }
	InstrVector::const_reverse_iterator rbegin() const { return _instrs.rbegin(); }
	InstrVector::const_reverse_iterator rend() const { return _instrs.rend(); }
	InstrVector::iterator begin(const DISASM* pInstr);
	InstrVector::const_iterator begin(const DISASM* pInstr) const;
	InstrVector::reverse_iterator rbegin(const DISASM* pInstr);
	InstrVector::const_reverse_iterator rbegin(const DISASM* pInstr) const;

	void moveInstructionsTo(BasicBlock* pBlock, InstrVector::iterator beginItr, InstrVector::iterator endItr);
	void reserve(std::size_t n);

	int getInXrefCount() const { return _inXrefCount; }
	int getOutXrefCount() const { return _outXrefCount; }
    
    static void* operator new (size_t sz);
    static void* operator new (size_t, void* p){ return p; }
    static void operator delete (void* p);
    static void operator delete (void*, void*) {}

private:
	BasicBlock(const BasicBlock& other);
	const BasicBlock& operator=(const BasicBlock& other);

	InstrVector _instrs;
	XrefVector _xrefs;
	size_t _maxInstrLength;
	uint32_t _blockSize;
	int _inXrefCount;
	int _outXrefCount;
	bool _isFunction;
};

class PECodeInfo
{
public:
	PECodeInfo(PEModule* pOwner);
	~PECodeInfo();

	void init(puint_t codePtr, uint64_t virtualCodeBase, uint32_t sectionLength);
	void analyze(uint32_t codeRRVA);

	BasicBlock* getBlockWithInstr(const DISASM* pInstr);
	BasicBlock* getBlockAtAddr(uint64_t virtAddr);
	BlockVector& getBlocks() { return _basicBlocks; }
	const BlockVector& getBlocks() const { return _basicBlocks; }
	BlockVector::iterator begin() { return _basicBlocks.begin(); }
	BlockVector::const_iterator begin() const { return _basicBlocks.begin(); }
	BlockVector::iterator end() { return _basicBlocks.end(); }
	BlockVector::const_iterator end() const { return _basicBlocks.end(); }

	BasicBlock* createBlock();
	void deleteBlock(BasicBlock* pBlock);
	BasicBlock* splitBlock(BasicBlock* pBlock, const DISASM* const pInstr);
	BasicBlock* breakBlock(BasicBlock* pBlock, uint64_t vaStart, uint64_t vaEnd);

	Xref* createXref(BasicBlock* pBlockFrom, BasicBlock* pBlockTo);
	void deleteXref(Xref* e);

	uint32_t getCodeSize() const { return _codeSize; }
	uint32_t getBlocksCount() const { return _basicBlocks.size(); }

	InstrVector& getAllInstructions() { return _allInstrs; }

	void addInstrListener(const std::string& mnemonic, DelegateBase* pDelegate);

	DISASM* searchBackInstrWithRegModifiedFor(const DISASM* pInstrFrom);
	DISASM* searchBackInstr(const DISASM* pInstrFrom, const char* mnemonic);

	void finalizeAllBlocksWithLongJumps();

	void moveTarget(Xref* e, BasicBlock* w);
	void moveSource(Xref* e, BasicBlock* w);
	Xref* searchXref(BasicBlock* v, BasicBlock* w) const;

private:
	typedef std::map<std::string, DelegateBase*> ListenersMap;
	
	PECodeInfo(const PECodeInfo& other);
	const PECodeInfo& operator=(const PECodeInfo& other);

	void scanInnerBlocks(const BasicBlock* pBlock, const uint32_t reg, InstrVector& occurs, BlockVector& visitedBlocks);

	puint_t rva2offset(uint32_t rva);
	int nextInstruction(DISASM& dasm, int len);
	BasicBlock* findBlockFor(const DISASM& dasm, bool& isFirstInstr);
	int analyzeRecursive(DISASM& dasm, BasicBlock* pBlock);
	void addInsrt(BasicBlock* pBlock, DISASM* pInstr);
	void invokeInstrListener(DISASM* pInstr);
	void addFunction(BasicBlock* pBlock);
	bool isFirstFunctionBlock(const BasicBlock* pBlock);

	uint64_t _virtualCodeBase;
	puint_t _codePtr;
	puint_t _loaderCodeEnd;
	PEModule* _pOwner;
	uint32_t _sectionLength;
	uint32_t _codeSize;
	DISASM _disasm;
	BlockVector _basicBlocks;
	BlockVector _firstFuncBlocks;
	InstrVector _allInstrs;
	ListenersMap _listeners;
};

}

#endif // __AMTE_PECODEINFO_H_
