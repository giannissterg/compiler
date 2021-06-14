#pragma once

#include "base_parser.h"

class RandomCharacterParser : public BaseParser<char>
{
public:
	RandomCharacterParser() = default;
	bool match(char element) override { return isalpha(element); }
	char transform(char element) override { return element; }
private:
};