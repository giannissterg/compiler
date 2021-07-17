#pragma once

#include <string>
#include "core/one_of_parser.h"
#include "core/string_parser.h"

class BooleanParser : OneOfParser<std::string>
{
	BooleanParser() : OneOfParser({
		new StringParser("true"),
		new StringParser("false")
		}) {}
};