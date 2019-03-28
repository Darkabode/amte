#pragma once
#include <vector>
#include "pe_structures.h"
#include "pe_base.h"
#include "pe_directory.h"

namespace pelib
{
//Class representing relocation entry
//RVA of relocation is not actually RVA, but
//(real RVA) - (RVA of table)
class relocation_entry
{
public:
	//Default constructor
	relocation_entry();
	//Constructor from relocation item (WORD)
	explicit relocation_entry(uint16_t relocation_value);
	//Constructor from relative rva and relocation type
	relocation_entry(uint32_t rva, uint16_t rrva, uint16_t type);

	// Returns RVA of relocation
	uint32_t getRVA() const { return _rva; }
	// Returns real RVA of relocation (actually, relative RVA from relocation table RVA)
	uint16_t getRRVA() const { return _rrva; }
	//Returns type of relocation
	uint16_t getType() const { return _type; }

	//Returns relocation item (rrva + type)
	uint16_t getItem() const;

	//Setters do not change everything inside image, they are used by PE class
	//You can also use them to rebuild relocations using rebuild_relocations()

	// Sets RVA of relocation
	void setRVA(uint32_t rva);
	// Sets real RVA of relocation (actually, relative RVA from relocation table RVA)
	void setRRVA(uint16_t rrva);
	// Sets type of relocation
	void setType(uint16_t type);
		
	//Sets relocation item (rrva + type)
	void setItem(uint16_t item);

private:
	uint32_t _rva;
	uint16_t _rrva;
	uint16_t _type;
};

//Class representing relocation table
class relocation_table
{
public:
	typedef std::vector<relocation_entry> relocation_list;

public:
	//Default constructor
	relocation_table();
	//Constructor from RVA of relocation table
	explicit relocation_table(uint32_t rva);

	//Returns relocation list
	const relocation_list& get_relocations() const;
	//Returns RVA of block
	uint32_t get_rva() const;

public: //These functions do not change everything inside image, they are used by PE class
	//You can also use them to rebuild relocations using rebuild_relocations()

	//Adds relocation to table
	void add_relocation(const relocation_entry& entry);
	//Returns changeable relocation list
	relocation_list& get_relocations();
	//Sets RVA of block
	void set_rva(uint32_t rva);

private:
	uint32_t rva_;
	relocation_list relocations_;
};

typedef std::vector<relocation_table> relocation_table_list;

//Get relocation list of pe file, supports one-word sized relocations only
//If list_absolute_entries = true, IMAGE_REL_BASED_ABSOLUTE will be listed
const relocation_table_list get_relocations(const pe_base& pe, bool list_absolute_entries = false);

//Simple relocations rebuilder
//To keep PE file working, don't remove any of existing relocations in
//relocation_table_list returned by a call to get_relocations() function
//auto_strip_last_section - if true and relocations are placed in the last section, it will be automatically stripped
//offset_from_section_start - offset from the beginning of reloc_section, where relocations data will be situated
//If save_to_pe_header is true, PE header will be modified automatically
const image_directory rebuild_relocations(pe_base& pe, const relocation_table_list& relocs, section& reloc_section, uint32_t offset_from_section_start = 0, bool save_to_pe_header = true, bool auto_strip_last_section = true);

//Recalculates image base with the help of relocation tables
//Recalculates VAs of DWORDS/QWORDS in image according to relocations
//Notice: if you move some critical structures like TLS, image relocations will not fix new
//positions of TLS VAs. Instead, some bytes that now doesn't belong to TLS will be fixed.
//It is recommended to rebase image in the very beginning and move all structures afterwards.
void rebase_image(pe_base& pe, const relocation_table_list& tables, uint64_t new_base);

template<typename PEClassType>
void rebase_image_base(pe_base& pe, const relocation_table_list& tables, uint64_t new_base);
}
