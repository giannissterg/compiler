#pragma once

#include <vector>
#include <string>
#include "types/operator.h"
#include "types/type_hierarchy.h"

class AST
{
public:
	virtual ~AST() = 0;
private:
};

class Expression : public AST
{

};

class Variable2 : public AST
{

private:
	std::string m_symbol; // maybe Symbol class
	std::string m_type;
	//Expression m_value;
};

class Statement : public AST
{

};

class Block : public AST
{
private:
	std::vector<Statement> m_statements;
};