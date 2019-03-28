#include "common.h"

namespace amte {

Poco::Random Utils::_rand;

ulong_t Utils::random()
{
	ulong_t val = _rand.next();
	return val;
}

void Utils::readFile(const std::string& filePath, std::string& data)
{
	Poco::File file(filePath);
	if (!file.exists()) {
		throw Poco::FileNotFoundException(filePath);
	}
	Poco::FileInputStream iStream(filePath, std::ios::in | std::ios::binary);
	if (!iStream.good()) {
		throw Poco::FileException("Can't read " + filePath);
	}

	if (file.getSize() > 0) {
		data.resize((std::size_t)file.getSize());
		iStream.read(&data[0], (std::streamsize)file.getSize());
		iStream.close();
	}
}

void Utils::saveFile(const std::string& filePath, std::string& data)
{
	Poco::FileOutputStream oStream(filePath, std::ios::out | std::ios::binary);
	if (!oStream.good()) {
		throw Poco::FileException("Can't write " + filePath);
	}

	if (data.length() > 0) {
		oStream.write(&data[0], data.length());
		oStream.close();
	}
}

}
