#ifndef __AMTE_USEFULINSTRS_H_
#define __AMTE_USEFULINSTRS_H_

namespace amte {

class UsefulInstrs
{
public:
	enum {
		jmpDWORD = 0,
		jmpSHORT,
		pushDWORD,
		retDWORD,
		jzDWORD,
		jnzDWORD,
		joDWORD,
		jnoDWORD,
		jaDWORD,
		jnaDWORD,
		jbDWORD,
		jnbDWORD,
		jgDWORD,
		jngDWORD,
		jlDWORD,
		jnlDWORD,
		jsDWORD,
		jnsDWORD,
		jpDWORD,
		jnpDWORD,
		totalNum
	};
	UsefulInstrs();
	~UsefulInstrs();

	static UsefulInstrs* getInstance();

	DISASM* cloneInstr(int id/*, uint32_t addrVal = 0*/);
	DISASM* cloneEqualDWORDJxx(int32_t opcode);
private:
	typedef std::map<int32_t, const DISASM* const> JxxMap;
	typedef JxxMap::const_iterator JxxMapConstIterator;

	DISASM _instrs[totalNum];
	//DISASM _jmpSHORT;
	//DISASM _pushDWORD;
	//DISASM _retDWORD;
	//DISASM _jzDWORD;
	//DISASM _jnzDWORD;
	//DISASM _joDWORD;
	//DISASM _jnoDWORD;
	//DISASM _jaDWORD;
	//DISASM _jnaDWORD;
	//DISASM _jbDWORD;
	//DISASM _jnbDWORD;
	//DISASM _jgDWORD;
	//DISASM _jngDWORD;
	//DISASM _jlDWORD;
	//DISASM _jnlDWORD;
	//DISASM _jsDWORD;
	//DISASM _jnsDWORD;
	//DISASM _jpDWORD;
	//DISASM _jnpDWORD;
	uint8_t* _pBase;

	JxxMap _jxxMap;
};

}

#endif // __AMTE_USEFULINSTRS_H_
