#pragma once

#include "operator.h"

template <class T>
class Expression
{
public:
	virtual ~Expression() = 0;
};

class IntegerExpression : public Expression<int>
{
public:
	IntegerExpression(int data) : m_data(data) {}
private:
	int m_data;
};

template <class T>
class ParenthesisExpression : public Expression<T>
{
public:
	ParenthesisExpression(Expression<T>* expression) : m_expression(expression) {}
private:
	Expression<T>* m_expression;
};

template <class T>
class OperatorExpression : public Expression<T>
{
public:
	AddExpression(Expression<T>* e1, Expression<T>* e2, Operator op) : m_firstOperand(e1), m_secondOperand(e2), m_operator(op) {}
private:
	Expression<T>* m_firstOperand;
	Expression<T>* m_secondOperand;
	Operator op;
};