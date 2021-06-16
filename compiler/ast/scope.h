#pragma once

#include <vector>
#include <unordered_map>
#include "variable.h"

class Value {};

class SymbolEntry 
{
	Variable m_variable;
	Value m_value;
};

class SymbolTable 
{
public:

private:
	std::unordered_map<std::string, SymbolEntry> m_entries;
};


class Scope {
public:
	virtual ~Scope() = 0;
private:
	SymbolTable m_variableMap;
};

class NodeScope : Scope {
private:
	std::vector<Scope*> m_scopes;
};

class LeafScope : Scope {};