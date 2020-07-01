#pragma once

#include <vector>
#include <variant>
#include "random_character_parser.h"
#include "chain_parser.h"
#include "repeating_parser.h"
#include "digit_parser.h"
#include "or_parser.h"

class SymbolParser : public ChainParser<char, std::vector<std::variant<int, char>> >
{
public:
	SymbolParser() :
		ChainParser(
			new RandomCharacterParser(),
			new RepeatingParser<std::variant<int, char>>(
				new OrParser<int, char>(
					new DigitParser(),
					new RandomCharacterParser()
				)
			)
		) {}
};