#pragma once

#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include "chain_parser.h"
#include "arithmetic_operator_parser.h"
#include "map_parser.h"
#include "repeating_parser.h"
#include "parser.h"
#include "ast/operator.h"

template<class T>
class ExpressionParser2 : public MapParser<std::tuple<T, std::vector<std::tuple<char, T>>>, std::vector<std::tuple<Operator, T>> >
{
public:
	ExpressionParser2(Parser<T>* parser, Parser<char>* operatorParser) : MapParser<std::tuple<T, std::vector<std::tuple<char, T>>>, std::vector<std::tuple<Operator, T>> >(
		new ChainParser(
			parser,
			new RepeatingParser(
				new ChainParser(
					operatorParser,
					parser
				))
	)) {}

	std::vector<std::tuple<Operator, T>> map(std::tuple<T, std::vector<std::tuple<char, T>>> elements)
	{
		std::vector<std::tuple<Operator, T>> mappedResult;

		T firstOperand = std::get<0>(elements);
		std::vector<std::tuple<char, T>> restElements = std::get<1>(elements);

		mappedResult.push_back({ Operator("+"), firstOperand });
		for (unsigned int i = 0; i < restElements.size(); i++)
		{
			std::string operatorSymbol = std::string(1, std::get<0>(restElements[i]));
			T operand = std::get<1>(restElements[i]);
			mappedResult.push_back({ Operator(operatorSymbol), operand });
		}
		return mappedResult;
	}
};