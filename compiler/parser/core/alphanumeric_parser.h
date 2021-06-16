#pragma once

#include "base_parser.h"

class AlphanumericParser : public BaseParser<char>
{
public:
	AlphanumericParser() = default;
	bool match(char element) override { return isalnum(element); }
	char transform(char element) override { return element; }
};