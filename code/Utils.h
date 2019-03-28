#ifndef __AMTE_UTILS_H_
#define __AMTE_UTILS_H_

namespace amte {

class Utils
{
public:
	static ulong_t random();
	static void readFile(const std::string& filePath, std::string& data);
	static void saveFile(const std::string& filePath, std::string& data);

private:
	static Poco::Random _rand;
};

}

#endif // __AMTE_UTILS_H_
