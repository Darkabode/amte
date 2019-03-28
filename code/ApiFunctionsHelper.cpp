#include "common.h"
#include "ApiFunctionsHelper.h"

namespace amte {

ApiFunctionsHelper::ApiFunctionsHelper()
{
	std::string data;
	Utils::readFile("apis.args", data);

	Poco::StringTokenizer lines(data, "\r\n", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
	for (int n = 0; n < lines.count(); ++n) {
		Poco::StringTokenizer parts(lines[n], ":", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
		if (parts.count() == 2) {
			_funcParamsMap.insert(std::make_pair(parts[0], Poco::NumberParser::parseUnsigned(parts[1])));
		}
	}
}

ApiFunctionsHelper::~ApiFunctionsHelper()
{

}

ApiFunctionsHelper* ApiFunctionsHelper::getInstance()
{
	static Poco::SingletonHolder<ApiFunctionsHelper> singleton;
	return singleton.get();
}

uint32_t ApiFunctionsHelper::getFunctionArgsNum(const std::string& funcName)
{
	uint32_t num = 0;
	for (FuncParamsConstIterator itr = _funcParamsMap.begin(); itr != _funcParamsMap.end(); ++itr) {
		if (itr->first == funcName) {
			num = itr->second;
			break;
		}
	}

	return num;
}

}
