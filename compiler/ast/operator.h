#pragma once

#include <string>

class Operator
{
public:
	Operator(std::string symbol) : m_symbol(symbol)
	{
		if (symbol == "+")
		{
			m_precedence = ADDITION_PRECEDENCE;
		}
		else if (symbol == "-")
		{
			m_precedence = SUBTRACTION_PRECEDENCE;
		}
		else if (symbol == "*")
		{
			m_precedence = MULTIPLICATION_PRECEDENCE;
		}
		else if (symbol == "/")
		{
			m_precedence = DIVISION_PRECEDENCE;
		}
		else if (symbol == "^")
		{
			m_precedence = POWER_PRECEDENCE;
		}
		else
		{
			throw("Error: wrong operator symbol");
		}
	}
	~Operator() = default;
	unsigned int getPrecedence() const { return m_precedence; }
	void increasePrecedence() { m_precedence += PARENTHESIS_PRECEDENCE; }
public:
	static constexpr unsigned int ADDITION_PRECEDENCE = 0;
	static constexpr unsigned int SUBTRACTION_PRECEDENCE = 0;
	static constexpr unsigned int MULTIPLICATION_PRECEDENCE = ADDITION_PRECEDENCE + 1;
	static constexpr unsigned int DIVISION_PRECEDENCE = SUBTRACTION_PRECEDENCE + 1;
	static constexpr unsigned int POWER_PRECEDENCE = MULTIPLICATION_PRECEDENCE + 1;
	static constexpr unsigned int PARENTHESIS_PRECEDENCE = POWER_PRECEDENCE + 1;
private:
	std::string m_symbol;
	unsigned int m_precedence;
};