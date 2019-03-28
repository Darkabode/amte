#include "common.h"
#include "UsefulInstrs.h"

namespace amte
{

UsefulInstrs::UsefulInstrs()
{
#define MAP_LENGTH 109
	uint8_t* pCode;
	_pBase = new uint8_t[MAP_LENGTH];
	pCode = _pBase;
	
	__stosb(pCode, 0, MAP_LENGTH);
	*pCode = 0xE9; pCode += 5; // jmp DWORD
	*pCode = 0xEB; pCode += 2; // jmp SHORT
	*pCode = 0x68; pCode += 5; // push DWORD
	*pCode = 0xC3; pCode += 1; // ret
	*(uint16_t*)pCode = 0x840F; pCode += 6; // jz DWORD
	*(uint16_t*)pCode = 0x850F; pCode += 6; // jnz DWORD
	*(uint16_t*)pCode = 0x800F; pCode += 6; // jo DWORD
	*(uint16_t*)pCode = 0x810F; pCode += 6; // jno DWORD
	*(uint16_t*)pCode = 0x870F; pCode += 6; // ja DWORD
	*(uint16_t*)pCode = 0x860F; pCode += 6; // jna DWORD
	*(uint16_t*)pCode = 0x820F; pCode += 6; // jb DWORD
	*(uint16_t*)pCode = 0x830F; pCode += 6; // jnb DWORD
	*(uint16_t*)pCode = 0x8F0F; pCode += 6; // jg DWORD
	*(uint16_t*)pCode = 0x8E0F; pCode += 6; // jng DWORD
	*(uint16_t*)pCode = 0x8C0F; pCode += 6; // jl DWORD
	*(uint16_t*)pCode = 0x8D0F; pCode += 6; // jnl DWORD
	*(uint16_t*)pCode = 0x880F; pCode += 6; // js DWORD
	*(uint16_t*)pCode = 0x890F; pCode += 6; // jns DWORD
	*(uint16_t*)pCode = 0x8A0F; pCode += 6; // jp DWORD
	*(uint16_t*)pCode = 0x8B0F; pCode += 6; // jnp DWORD

	pCode = _pBase;
	for (int i = 0; i < totalNum; ++i) {
		DISASM* pInstr = &_instrs[i];

		__stosb((uint8_t*)pInstr, 0, sizeof(DISASM));
		pInstr->Archi = 0;
		pInstr->EIP = (puint_t)pCode;
		pInstr->VirtualAddr = (uint64_t)pCode;
		pInstr->SecurityBlock = MAP_LENGTH - (uint32_t)(pCode - _pBase) + 1;
		pInstr->len = Disasm(pInstr);
		pCode += pInstr->len;
	}

	_jxxMap.insert(std::make_pair(0xEB, &_instrs[jmpDWORD]));
	_jxxMap.insert(std::make_pair(0x74, &_instrs[jzDWORD]));
	_jxxMap.insert(std::make_pair(0x75, &_instrs[jnzDWORD]));
	_jxxMap.insert(std::make_pair(0x70, &_instrs[joDWORD]));
	_jxxMap.insert(std::make_pair(0x71, &_instrs[jnoDWORD]));
	_jxxMap.insert(std::make_pair(0x77, &_instrs[jaDWORD]));
	_jxxMap.insert(std::make_pair(0x76, &_instrs[jnaDWORD]));
	_jxxMap.insert(std::make_pair(0x72, &_instrs[jbDWORD]));
	_jxxMap.insert(std::make_pair(0x73, &_instrs[jnbDWORD]));
	_jxxMap.insert(std::make_pair(0x7F, &_instrs[jgDWORD]));
	_jxxMap.insert(std::make_pair(0x7E, &_instrs[jngDWORD]));
	_jxxMap.insert(std::make_pair(0x7C, &_instrs[jlDWORD]));
	_jxxMap.insert(std::make_pair(0x7D, &_instrs[jnlDWORD]));
	_jxxMap.insert(std::make_pair(0x78, &_instrs[jsDWORD]));
	_jxxMap.insert(std::make_pair(0x79, &_instrs[jnsDWORD]));
	_jxxMap.insert(std::make_pair(0x7A, &_instrs[jpDWORD]));
	_jxxMap.insert(std::make_pair(0x7B, &_instrs[jnpDWORD]));
}

UsefulInstrs::~UsefulInstrs()
{
	delete[] _pBase;
}

UsefulInstrs* UsefulInstrs::getInstance()
{
	static Poco::SingletonHolder<UsefulInstrs> singleton;
	return singleton.get();
}

DISASM* UsefulInstrs::cloneInstr(int id/*, uint32_t addrVal*/)
{
	DISASM* pInstrClone = newDISASM();

	__movsb((uint8_t*)pInstrClone, (const uint8_t*)&_instrs[id], sizeof(DISASM));
	return pInstrClone;
}

DISASM* UsefulInstrs::cloneEqualDWORDJxx(int32_t opcode)
{
	DISASM* pInstrClone = 0;

	for (JxxMapConstIterator itr = _jxxMap.begin(); itr != _jxxMap.end(); ++itr) {
		if (opcode == itr->first) {
            pInstrClone = newDISASM();
			__movsb((uint8_t*)pInstrClone, (const uint8_t*)itr->second, sizeof(DISASM));
			break;
		}
	}

	return pInstrClone;
}

}
