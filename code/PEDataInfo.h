#ifndef __AMTE_PEDATAINFO_H_
#define __AMTE_PEDATAINFO_H_

namespace amte {

class PEModule;

class PEDataInfo {
public:
	friend class PEModule;

	typedef std::map<uint64_t, uint32_t> DataMap;
	typedef std::map<DISASM*, uint64_t> InstrDataMap;

	PEDataInfo(PEModule* pOwner);
	~PEDataInfo();

	void analyze(const bool useEntireDataSections);
	void processDataDirectories();
	void processRelocs();
	void addData(uint64_t va, uint32_t size);
	void cutData(uint64_t va, uint32_t size);
	void recoverData(uint64_t va, uint32_t size);

	void addReference(DISASM* pInstr, uint64_t dataVA);
	InstrVector getReferencedInstrs(uint64_t dataVA);
	void removeUnreferencedBlocks();

	uint8_t* getDataRawPtr(uint64_t dataVA);

	uint32_t getRVA(uint64_t va);
	puint_t getDataBasePtr(uint64_t va);

	bool isAddrInside(int64_t addr, const bool excludeIAT = false) const;

	uint32_t getMaxDataSectionSize() const;
	std::size_t getBlocksCount() const { return _dataMap.size(); }
	uint32_t getTotalSize() const;

	DataMap& getMap() { return _dataMap; }
	uint64_t alignUp(uint64_t currentPos);
	DataMap::iterator begin() { return _dataMap.begin(); }
	DataMap::iterator end() { return _dataMap.end(); }
	DataMap::const_iterator begin() const { return _dataMap.begin(); }
	DataMap::const_iterator end() const { return _dataMap.end(); }

private:
	PEDataInfo(const PEDataInfo& other);
	const PEDataInfo& operator=(const PEDataInfo& other);

	void processDataDirectory(uint32_t dirId);
	void mergeContinuousBlocks();

	uint64_t _dataSectionVA;
	uint64_t _rdataSectionVA;
	puint_t _rdataPtr;
	puint_t _dataPtr;
	PEModule* _pOwner;
	uint32_t _dataSectionSize;
	uint32_t _rdataSectionSize;
	pelib::section* _pDataSection;
	pelib::section* _pRdataSection;
	DataMap _dataMap;
	InstrDataMap _instrDataMap;
	bool _useEntireDataSections;
};

}

#endif // __AMTE_PEDATAINFO_H_
