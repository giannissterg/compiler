#pragma once

#include <string>
#include "parser.h"
#include "symbol_parser.h"
#include "type_parser.h"

class ParameterParser : public ChainParser<std::string, std::string>
{
public:
	ParameterParser() : ChainParser(
		new CTypeParser(),
		new SymbolParser()
	) {}
};