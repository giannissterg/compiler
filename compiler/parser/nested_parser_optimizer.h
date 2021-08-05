#pragma once

#include "parser/parser.h"

class NestedParserOptimizer
{
	template<typename... T, typename U>
	Parser<U> optimize(ChainParser<T...> parser) {
		std::tuple<Parser<T>*...> innerParsers = parser.getParsers();
		std::apply([](auto&&... innerParser) {
			((
				if (dynamic_cast<ChainParser<U...>*>(innerParser) 
				{

				}
			)),
			...); 
		}, innerParsers);
	}
};