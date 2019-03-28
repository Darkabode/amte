#ifndef __AMTE_APIFUNCTIONSHELPER_H_
#define __AMTE_APIFUNCTIONSHELPER_H_

namespace amte {

class ApiFunctionsHelper
{
public:
	ApiFunctionsHelper();
	~ApiFunctionsHelper();

	static ApiFunctionsHelper* getInstance();

	uint32_t getFunctionArgsNum(const std::string& funcName);

private:
	typedef std::map<std::string, uint32_t> FuncParamsMap;
	typedef FuncParamsMap::iterator FuncParamsIterator;
	typedef FuncParamsMap::const_iterator FuncParamsConstIterator;

	FuncParamsMap _funcParamsMap;
};

}

#endif // __AMTE_APIFUNCTIONSHELPER_H_
