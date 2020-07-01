#pragma once

#include <vector>
#include <variant>
#include <string>
#include "random_character_parser.h"
#include "chain_parser.h"
#include "repeating_parser.h"
#include "digit_parser.h"
#include "or_parser.h"
#include "map_parser.h"

class SymbolParser : public MapParser<std::tuple<char, std::vector<std::variant<int, char>>>, std::string>
{
public:
	SymbolParser() : MapParser(
		new ChainParser<char, std::variant<int, char>>(
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
		return 
	}
};