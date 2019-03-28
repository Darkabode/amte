#ifndef __AMTE_COMMON_H_
#define __AMTE_COMMON_H_

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stddef.h>
#include <exception>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Poco\String.h"
#include "Poco/File.h"
#include "Poco\FileStream.h"
#include "Poco/Environment.h"
#include "Poco/Process.h"
#include "Poco/DirectoryIterator.h"
#include "Poco/Buffer.h"
#include "Poco\Random.h"
#include "Poco/StringTokenizer.h"
#include "Poco/NumberFormatter.h"
#include "Poco\NumberParser.h"
#include "Poco\MemoryPool.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"

#include "..\..\..\0lib\code\types.h"
#include "..\..\..\0lib\code\ntdll.h"

#include "..\..\pelib\code\pelib.h"
#include "..\..\disasm\code\engine.h"

#include "Utils.h"
#include "Delegate.h"

#define AMTE_VERSION "0.0.65"

namespace amte {

	class PEModule;
	class PECodeInfo;
	class Xref;
	class BasicBlock;

	typedef std::vector<BasicBlock*> BlockVector;
	typedef std::vector<DISASM*> InstrVector;
	typedef std::vector<Xref*> XrefVector;

    DISASM* newDISASM();
    void freeDISASM(DISASM* pInstr);

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
}

#endif // __AMTE_COMMON_H_
