#pragma once

#include <string>
#include "core/chain_parser.h"
#include "type_parser.h"
#include "symbol_parser.h"
#include "string_parser.h"
#include "integer_parser.h"

class AssignmentParser : public ChainParser<std::string, std::string, std::string, int>
{
public:
	AssignmentParser(std::string assignmentOperator) : ChainParser(
		new TypeParser({
			"int",
			"bool",
			"char"
		}),
		new SymbolParser(),
		new StringParser(assignmentOperator),
		new IntegerParser()
	) {}
};