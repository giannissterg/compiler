#pragma once

#include <vector>
#include <algorithm>
#include <tuple>
#include "chain_parser.h"
#include "arithmetic_operator_parser.h"
#include "map_parser.h"
#include "repeating_parser.h"
#include "parser.h"

template<class T>
class ExpressionParser2 : public MapParser<std::tuple<T, std::vector<std::tuple<char, T>>>, std::vector<std::tuple<char, T>> >
{
public:
	ExpressionParser2(Parser<T>* parser, Parser<char>* operatorParser) : MapParser<std::tuple<T, std::vector<std::tuple<char, T>>>, std::vector<std::tuple<char, T>> >(
		new ChainParser(
			parser,
			new RepeatingParser(
				new ChainParser(
					operatorParser,
					parser
				))
	)) {}

	std::vector<std::tuple<char, T>> map(std::tuple<T, std::vector<std::tuple<char, T>>> elements)
	{
		T firstOperand = std::get<0>(elements);
		std::vector<std::tuple<char, T>> restElements = std::get<1>(elements);
		restElements.push_back({ '+', firstOperand });
		std::rotate(restElements.rbegin(), restElements.rbegin() + 1, restElements.rend());
		return restElements;
	}
};