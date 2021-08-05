#pragma once

class Operator
{
public:
	Operator(unsigned int precedence) : m_precedence(precedence) {}
	virtual ~Operator() = 0;
protected:
	static constexpr unsigned int ADDITION_PRECEDENCE = 0;
	static constexpr unsigned int SUBTRACTION_PRECEDENCE = 0;
	static constexpr unsigned int MULTIPLICATION_PRECEDENCE = ADDITION_PRECEDENCE + 1;
	static constexpr unsigned int DIVISION_PRECEDENCE = SUBTRACTION_PRECEDENCE + 1;
	static constexpr unsigned int POWER_PRECEDENCE = MULTIPLICATION_PRECEDENCE + 1;
private:
	unsigned int m_precedence;
};

class AdditionOperator : public Operator
{
public:
	AdditionOperator() : Operator(ADDITION_PRECEDENCE) {}
private:
};

class SubtractionOperator : public Operator
{
public:
	SubtractionOperator() : Operator(SUBTRACTION_PRECEDENCE) {}
};

class MultiplicationOperator : public Operator
{
public:
	MultiplicationOperator() : Operator(MULTIPLICATION_PRECEDENCE) {}
};

class DivisionOperator : public Operator
{
public:
	DivisionOperator() : Operator(DIVISION_PRECEDENCE) {}
};

class PowerOperator : public Operator
{
public:
	PowerOperator() : Operator(POWER_PRECEDENCE) {}
};