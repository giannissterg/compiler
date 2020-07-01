#pragma once

class SyntaxTreeNode
{
private:
	virtual void print() = 0;
};

class Expression : public SyntaxTreeNode
{

private:

};

class Block : public SyntaxTreeNode
{

};


class Statement : public SyntaxTreeNode
{

};

class Declaration : public SyntaxTreeNode