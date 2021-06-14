#pragma once

#include <vector>
#include <variant>
#include <string>
#include "parser.h"
#include "map_parser.h"

class SymbolParser : public MapParser<std::tuple<char, std::vector<std::variant<int, char>>>, std::string>
{
public:
	SymbolParser() : MapParser(
		new ChainParser<char, std::vector<std::variant<int, char>>>(
			new RandomCharacterParser(),
			new RepeatingParser<std::variant<int, char>>(
				new OrParser<int, char>(
					new DigitParser(),
					new RandomCharacterParser()
				)
			)
		)
	) {}

	std::string map(std::tuple<char, std::vector<std::variant<int, char>>> elements)
	{
		std::string mappedOutput;

		char firstOperand = std::get<0>(elements);
		mappedOutput = firstOperand;

		std::vector<std::variant<int, char>> restElements = std::get<1>(elements);
		for (std::variant<int,char> element : restElements)
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