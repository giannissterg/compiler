#pragma once

#include <vector>
#include <string>
#include "types/operator.h"
#include "types/type_hierarchy.h"

class AST
{
	virtual ~AST() = default;
private:
	virtual void print() = 0;
};

class Expression : public AST
{

};

class Variable : public AST
{

private:
	std::string m_symbol; // maybe Symbol class
	Type m_type;
	Expression m_value;
};

class Statement : public AST
{

};

class Block : public AST
{
private:
	std::vector<Statement> m_statements;
};



class Declaration : public AST
{

};