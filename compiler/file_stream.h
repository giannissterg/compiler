#pragma once

#include "stream.h"

template<class T>
class FileStream : public Stream<T>
{
	FileStream() : m_location({0, 0}) {}
	std::pair<int, int> getLocation() const { return m_location; }
private:
	std::pair<int, int> m_location;
};