#pragma once

#include <string>
#include "one_of_parser.h"
#include "string_parser.h"

class BooleanParser : OneOfParser<std::string>
{
	BooleanParser() : OneOfParser(
		new StringParser("true"),
		new StringParser("false")
	) {}
};