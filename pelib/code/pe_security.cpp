#include <string.h>
#include "pe_security.h"
#include "utils.h"

namespace pelib {

security::security()
{

}

std::string& security::getRawData()
{
	return _rawData;
}

const std::string& security::getRawData() const
{
	return _rawData;
}

}
