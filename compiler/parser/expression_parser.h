#pragma once

#include <vector>
#include <tuple>
#include "integer_parser.h"
#include "tree_parser.h"

class ExpressionParser : public TreeParser<int>
{
public:
	ExpressionParser() : TreeParser<int>(new IntegerParser()) {}
	/*int map(std::tuple<int, std::vector<std::tuple<char, int>>> elements)
	{
		int firstOperand = std::get<0>(elements);
		std::vector<std::tuple<char, int>> restElements = std::get<1>(elements);

		auto cmp = [](BinaryOperator<int>* b1, BinaryOperator<int>* b2) { return b1->getWeight() > b2->getWeight(); };
		std::priority_queue<BinaryOperator<int>*, std::vector<BinaryOperator<int>*>, decltype(cmp)> q(cmp);

		BinaryOperator<int>* operation;
		for (unsigned int i = 0; i < restElements.size(); i++)
		{
			std::tuple<char, int> nextElement = restElements[i];
			char operatorSymbol = std::get<0>(nextElement);
			int elementValue = std::get<1>(nextElement);
			switch (operatorSymbol)
			{
			case '+':
				operation = new Addition(firstOperand, elementValue);
				break;
			case '-':
				operation = new Subtraction(firstOperand, elementValue);
				break;
			case '*':
				operation = new Multiplication<int>(firstOperand, elementValue);
				break;
			default:
				throw("Bad operator symbol");
			}
			firstOperand = elementValue;
			q.push(operation);
		}

		int finalresult = 0;
		while (!q.empty())
		{
			auto a = q.top();
			q.pop();
			finalresult += a->execute();
		}
		return finalresult;
	}*/
};