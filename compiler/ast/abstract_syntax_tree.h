#pragma once

class SyntaxTreeNode
{
	virtual void print() = 0;
};

class Expression : public SyntaxTreeNode
{

private:

};

class Statement : public SyntaxTreeNode
{

};

class Block : public SyntaxTreeNode
{

};

