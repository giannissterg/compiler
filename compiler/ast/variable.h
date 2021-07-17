#pragma once

#include <string>
#include <optional>

class Variable
{
public:
	Variable() = default;
	Variable(std::string name, std::string type) : m_name(name), m_type(type) {}
	std::string getName() const { return m_name; }
	std::optional<std::string> getType() const { return m_type; }
private:
	std::string m_name;
	std::optional<std::string> m_type;
};

