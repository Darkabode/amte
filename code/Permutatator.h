#ifndef __AMTE_PERMUTATATOR_H_
#define __AMTE_PERMUTATATOR_H_

#include "PECodeInfo.h"

namespace amte {

class PEModule;

class Permutatator
{
public:
	Permutatator();
	~Permutatator();
	
	void useModule(PEModule* pModule);

	bool isPermutated() const { return _permutated; }
	void permutate();

private:
	void permutateBlock(InstrVector& block, int permutateTimes);
	bool checkCompatible(const DISASM* pInstr, const DISASM* pOtherDasm);
	void searchInterval(const InstrVector& block, InstrVector::const_iterator& startItr, InstrVector::const_iterator& endItr);
	bool isConflictFlags(uint8_t flag, uint8_t flagOther);
	void fixRelocEntry(uint32_t startRVA, uint32_t endRVA, int off);

	PEModule* _pModule;
	pelib::relocation_table_list _newRelocTables;
	bool _permutated;
};

}

#endif // __AMTE_PERMUTATATOR_H_
