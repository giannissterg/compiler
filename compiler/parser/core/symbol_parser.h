#pragma once

#include <vector>
#include <variant>
#include <string>
#include "parser.h"
#include "core/map_parser.h"

class SymbolParser : public MapParser<std::tuple<char, std::vector<std::variant<char, int>>>, std::string>
{
public:
	SymbolParser() : MapParser(
		new ChainParser<char, std::vector<std::variant<char, int>>>(
			new RandomCharacterParser(),
			new RepeatingParser<std::variant<char, int>>(
				new OrParser<char, int>(
					new RandomCharacterParser(),
					new DigitParser()
				)
			)
		)
	) {}

	std::string map(std::tuple<char, std::vector<std::variant<char, int>>> elements)
	{
		std::string mappedOutput;

		char firstOperand = std::get<0>(elements);
		mappedOutput = firstOperand;

		std::vector<std::variant<char, int>> restElements = std::get<1>(elements);
		for (std::variant<char, int> element : restElements)
		{
			if (auto charValue = std::get_if<char>(&element))
				mappedOutput += *charValue;
			else if (auto intValue = std::get_if<int>(&element))
				mappedOutput += std::to_string(*intValue);
			else
				throw("Something went wrong while parsing a symbol");
		}
		return mappedOutput;
	}
};