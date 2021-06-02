#pragma once

#include "ast/abstract_syntax_tree.h"

template<class T>
class Operation : public AST
{
public:
	Operation() = default;
	virtual ~Operation() = default;
	virtual T execute() = 0;
private:
};

template <class T>
class BinaryOperation : public Operation<T>
{
public:
	BinaryOperation(T leftOperand, T rightOperand) : m_leftOperand(leftOperand), m_rightOperand(rightOperand) {}
	virtual ~BinaryOperation() = default;
	virtual T execute() = 0;
protected:
	T m_leftOperand;
	T m_rightOperand;
};

class Addition : public BinaryOperation<int>
{
public:
	Addition(int leftOperand, int rightOperand) : BinaryOperation<int>(leftOperand, rightOperand) {}
	int execute() override { return m_leftOperand + m_rightOperand; }
};

class Subtraction : public BinaryOperation<int>
{
public:
	Subtraction(int leftOperand, int rightOperand) : BinaryOperation<int>(leftOperand, rightOperand) {}
	int execute() override { return m_leftOperand - m_rightOperand; }
};

template<class T>
class Multiplication : public BinaryOperation<int>
{
public:
	Multiplication(int leftOperand, int rightOperand) : BinaryOperation<int>(leftOperand, rightOperand) {}
	int execute() override { return m_leftOperand * m_rightOperand; }
};