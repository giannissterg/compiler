#pragma once

#include <vector>
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
	Type m_type;
};

class Statement : public SyntaxTreeNode
{

};

class Block : public SyntaxTreeNode
{
private:
	std::vector<Statement> m_liveVariables;
};



class Declaration : public SyntaxTreeNode
{

};