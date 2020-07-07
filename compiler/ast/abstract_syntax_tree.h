#pragma once

#include <vector>
#include <string>
#include "types/operator.h"
#include "types/type_hierarchy.h"

class SyntaxTreeNode
{
private:
	//virtual void print() = 0;
};

class Expression : public SyntaxTreeNode
{

private:
	std::vector<BinaryOperator<int>> m_operations;
};

class Variable : public SyntaxTreeNode
{

private:
	std::string m_symbol; // maybe Symbol class
	Type m_type;
	Expression m_value;
};

class Statement : public SyntaxTreeNode
{

};

class Block : public SyntaxTreeNode
{
private:
	std::vector<Statement> m_statements;
};



class Declaration : public SyntaxTreeNode
{

};