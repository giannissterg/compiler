#pragma once

#include <string>
#include <optional>
#include "abstract_syntax_tree.h"

class Variable
{
public:
	Variable() = default;
	Variable(std::string name, std::string type) : m_name(name), m_type(type) {}
private:
	std::string m_name;
	std::optional<std::string> m_type;
};

