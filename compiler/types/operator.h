#pragma once

#include "ast/abstract_syntax_tree.h"

template<class T>
class Operator : public SyntaxTreeNode
{
public:
	Operator(unsigned int weight) : m_weight(weight) {}
	virtual ~Operator() = default;
	virtual T execute() = 0;
	unsigned int getWeight() const { return m_weight; }
private:
	unsigned int m_weight;
};

template <class T>
class BinaryOperator : public Operator<T>
{
public:
	BinaryOperator(T leftOperand, T rightOperand, unsigned int weight) : m_leftOperand(leftOperand), m_rightOperand(rightOperand), Operator<T>(weight) {}
	virtual ~BinaryOperator() = default;
	virtual T execute() = 0;
protected:
	T m_leftOperand;
	T m_rightOperand;
};

class Addition : public BinaryOperator<int>
{
public:
	Addition(int leftOperand, int rightOperand, unsigned int priority=0) : BinaryOperator<int>(leftOperand, rightOperand, 0 + priority) {}
	int execute() override { return m_leftOperand + m_rightOperand; }
};

class Subtraction : public BinaryOperator<int>
{
public:
	Subtraction(int leftOperand, int rightOperand, unsigned int priority=0) : BinaryOperator<int>(leftOperand, rightOperand, 0 + priority) {}
	int execute() override { return m_leftOperand - m_rightOperand; }
};

template<class T>
class Multiplication : public BinaryOperator<int>
{
public:
	Multiplication(int leftOperand, int rightOperand, unsigned int priority=0) : BinaryOperator<int>(leftOperand, rightOperand, 1 + priority) {}
	int execute() override { return m_leftOperand * m_rightOperand; }
};