#pragma once

#include <vector>
#include <string>
#include "variable.h"
#include "function.h"

class SyntaxNode
{
public:
	~SyntaxNode() = default;
private:
};

class Statement : public SyntaxNode
{
};

class Assignment : public Statement
{
public:
	Assignment(Variable variable, int value) : m_variable(variable), m_value(value) {}
private:
	Variable m_variable;
	int m_value;
};

class Block : public SyntaxNode
{
public:
	Block(const std::vector<Assignment>& statements) : m_statements(statements) {}
private:
	std::vector<Assignment> m_statements;
};

class Program
{
public:
	Program() = default;
private:
	std::vector<Function> m_functions;
};