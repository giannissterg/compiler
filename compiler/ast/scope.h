#pragma once

#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include "variable.h"

class Value 
{
public:
	Value(int value) : m_value(value) {}
private:
	int m_value;
};

class SymbolEntry 
{
public:
	SymbolEntry(const Variable& variable, const Value& value) : m_variable(variable), m_value(value) {}
	Variable getVariable() const { return m_variable; }
private:
	Variable m_variable;
	Value m_value;
};

class InsertResult {};

class SymbolTable 
{
public:
	SymbolEntry lookup(const std::string& name)
	{
		auto result = m_entries.find(name);
		auto symbolInfo = result->second;
		return symbolInfo;
	}

	InsertResult insert(const SymbolEntry& symbolEntry) 
	{ 
		m_entries.insert({ symbolEntry.getVariable().getName(), symbolEntry });
	}
private:
	std::unordered_map<std::string, SymbolEntry> m_entries;
};

class StackFrame {};

class Stack
{
private:
	int currentFrame;
	std::vector<StackFrame> m_frames;
};


class Heap
{

};

template <class T>
class Allocator
{

};

class StackAllocator : public Allocator<Stack>
{
public:
	StackAllocator() = default;

};



class Scope {
public:
	virtual ~Scope() = 0;
	std::string insert(const SymbolEntry& v) { return ""; }
	SymbolEntry lookup(const std::string& name) { return m_symbolTable.lookup(name); }
	void update(const SymbolEntry& v) {};
protected:
	SymbolTable m_symbolTable;
	std::stack<Scope*> m_scopes;
};

class LeafScope : public Scope {

};

class NodeScope : public Scope {
public:
	NodeScope(std::vector<Scope*> scopes) : m_scopes(scopes) {}
private:
	std::vector<Scope*> m_scopes;
};