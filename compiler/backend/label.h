#pragma once

#include <string>

class Label
{
public:
	Label(std::string name) : m_name(name) {}
private:
	std::string m_name;
};