#pragma once

#include <vector>
#include <string>
#include "types/operator.h"
#include "types/type_hierarchy.h"
#include "variable.h"
#include "scope.h"

class SyntaxNode
{
public:
	~SyntaxNode() = default;
private:
};

class Expression : public SyntaxNode
{

};

class Statement : public SyntaxNode
{
};

class Assignment : public Statement
{
public:
	Assignment(Variable variable, Value value) : m_variable(variable), m_value(value) {}
private:
	Variable m_variable;
	Value m_value;
};

class Block : public SyntaxNode
{
public:
	Block(const std::vector<Assignment>& statements) : m_statements(statements) 
	{
		
	}
private:
	std::vector<Assignment> m_statements;
};