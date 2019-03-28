#pragma once
#include <istream>
#include "..\..\..\0lib\code\types.h"

namespace pelib
{
//Calculate checksum of image (performs no checks on PE structures)
uint32_t calculate_checksum(std::istream& file);
}
