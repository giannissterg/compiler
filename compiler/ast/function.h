#pragma once

#include "abstract_syntax_tree.h"
#include "variable.h"
#include "types/product_type.h"
#include <string>
#include <vector>
#include <optional>

class ArgumentList
{
public:
	ArgumentList() = default;
	ArgumentList(std::vector<Variable> arguments) : m_arguments(arguments) {}
private:
	std::vector<Variable> m_arguments;
};

class Function : public Variable
{
public:
	Function(std::string name, std::string returnType) : Variable(name, returnType), m_arguments(std::nullopt) {}
	Function(std::string name, ArgumentList arguments, std::string returnType) : Variable(name, returnType), m_arguments(arguments) {}
private:
	std::optional<ArgumentList> m_arguments;
};

