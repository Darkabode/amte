#ifndef __AMTE_PEMODULE_H_
#define __AMTE_PEMODULE_H_

#include "PECodeInfo.h"
#include "PEDataInfo.h"
#include "Permutatator.h"

#include "..\..\pelib\code\pelib.h"

namespace amte {

class PEModule
{
public:
    typedef std::map<const DISASM* const, const BasicBlock* const> InstrBlockMap;

	PEModule(const std::string& pathName, const bool collectDataReferences);
	~PEModule();

	// Анализ кода и данных.
	void analyze(const bool analyzeData, const bool useEntireDataSections, const bool analyzeExports);
	void save(const std::string& pathName);
	void saveAsShellcode(const std::string& pathName);

	uint32_t getPrefferedMemAlign() const;

	//void permutateAllCodeBlocks();
	std::ifstream& getPEIStream() { return _file; }
	pelib::pe_base* getPEBase();
	PECodeInfo* getCodeInfo();
	PEDataInfo* getDatas();
	uint64_t getImageBase() const { return _imageBase; }
	uint64_t getImportDirVA() const { return _importDirVA; }
	uint32_t getImportDirSize() const { return _importDirSize; }
	pelib::imported_functions_list& getImportLibs() { return _importLibs; }

	bool isAddrInsideCode(int64_t addr);
	bool isAddrInsideData(int64_t addr, const bool excludeIAT = false);
	bool isAddrInsideIAT(int64_t addr);
	
	const pelib::relocation_entry* getRelocForInstr(const DISASM* const pInstr) const;

	void permutate();

	const pelib::imported_function* const getRefToImportTable(const DISASM* pInstr) const;
	const pelib::imported_function* const searchImportFunction(const std::string& name, uint64_t& realVA) const;

	bool hasRelocs() const;
    bool relocsInOwnSections() const { return _relocsInOwnSection; }
	pelib::relocation_table_list& getRelocTables() { return _relocTables; }
	const pelib::relocation_table_list& getRelocTables() const { return _relocTables; }

	uint64_t getSectionVA(pelib::section* pSection) const;
	uint32_t getSectionSize(pelib::section* pSection) const;

	uint64_t getCodeBase() const { return _codeBase; }

    InstrBlockMap& getBlockRefs() { return _insrtBlockMap; }

protected:
	typedef std::map<const DISASM* const, const pelib::imported_function* const> InstrImportMap;

	PEModule(const PEModule& other);
	const PEModule& operator=(const PEModule& other);

	void searchAndAnalyzeCallbackFunctions();
	void processDirectoryData(uint32_t dirId);
	const pelib::imported_function* const getImportedFunctionByAddr(uint64_t addr);
	const pelib::imported_function* const getImportedFunctionByDISASM(const DISASM* pInstr);
	const DISASM* getPushFromCall(const BasicBlock* pBlock, const DISASM* pCallDasm, int num);
	uint32_t countPushesBeforeCall(const BasicBlock* pBlock, const DISASM* pDasmFrom);
	void correctEspDisp(int64_t& lpfnWndProcDisp, const BasicBlock* pBlock, const DISASM* pInstr);
	void onInstr(void* param);

	uint64_t _imageBase;
	uint64_t _codeBase;
	uint64_t _iatDirVA;
	uint64_t _importDirVA;
	pelib::pe_base* _pImage;
	pelib::section* _pCodeSection;
	PECodeInfo* _pCode;
	PEDataInfo* _pDatas;
	uint32_t _codeSectionSize;
	uint32_t _epRVA;
	uint32_t _iatDirSize;
	uint32_t _importDirSize;
	pelib::relocation_table_list _relocTables;
	pelib::imported_functions_list _importLibs;
	std::ifstream _file;
	std::vector<std::string> _apiFuncsWithCb;
	InstrImportMap _apiCallMap;
	InstrImportMap _instrImportMap;
    InstrBlockMap _insrtBlockMap;
	Permutatator _permutator;
	bool _collectDataReferences;
    bool _relocsInOwnSection;
};

}

#endif // __AMTE_PEMODULE_H_
