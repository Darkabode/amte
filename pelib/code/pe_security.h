#ifndef __PELIB_SECURITY_H_
#define __PELIB_SECURITY_H_

#include <vector>
#include "pe_structures.h"
#include "pe_directory.h"

namespace pelib {

class security
{
public:
	security();

	//Returns raw data from file image
	std::string& getRawData();
	//Returns raw data from file image
	const std::string& getRawData() const;

private:
	std::string _rawData;
};

}


#endif // __PELIB_SECURITY_H_