#pragma once

#include <string>
#include "parser.h"
#include "type_parser.h"
#include "ast/variable.h"

class VariableParser : public MapParser<std::tuple<std::string, std::string>, Variable>
{
public:
	VariableParser() : MapParser(
		new ChainParser<std::string, std::string>(
			new CTypeParser(),
			new SymbolParser()
		)
	) {}

	Variable map(std::tuple<std::string, std::string> variable)
	{
		std::string type = std::get<0>(variable);
		std::string name = std::get<1>(variable);
		return Variable(name, type);
	}

};