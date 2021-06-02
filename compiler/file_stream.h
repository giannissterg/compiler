#pragma once

#include "stream.h"
#include <string>
#include <fstream>

class FileStream : public Stream<char>
{
public:
	FileStream(const std::string& filename) : m_location({ 0, 0 }), m_current(0)
	{
		std::ifstream inputStream(filename, std::ios_base::in);
		if(inputStream.good()) 
		{
			std::cout << "Good" << std::endl;
		}
		std::string line;
		while (std::getline(inputStream, line)) 
		{
			for (int i = 0; i < line.size(); i++) 
			{
				m_buffer.push_back(line[i]);
			}
		}
	}

	void next() override {
		while (m_current < this->m_buffer.size() - 1)
		{
			m_current++;
			m_location.first++;
			if (this->m_buffer[m_current] == ' ') 
			{
				continue;
			}
			else if (this->m_buffer[m_current] == '\n') 
			{
				m_location.first = 0;
				m_location.second++;
				continue;
			}
			break;
		}
	}
	char top() const override { return this->m_buffer[m_current]; }
	void add(char element) { this->m_buffer.push_back(element); }

	std::pair<int, int> getLocation() const { return m_location; }
private:
	std::pair<int, int> m_location;
	unsigned int m_current;
};