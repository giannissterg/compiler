#pragma once

#include "stream.h"

template<class T>
class FileStream : public BaseStream<T>
{
public:
	FileStream(const std::string& filename) : m_location({0, 0}) 
	{
		//open file
	}
	std::pair<int, int> getLocation() const { return m_location; }
private:
	std::pair<int, int> m_location;
};