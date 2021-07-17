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

class KotlinVariableParser : public MapParser<std::tuple<std::string, std::string, char, std::string>, Variable>
{
public:
	KotlinVariableParser(const std::string& variableDeclarationKeyword, char typeAssignmentKeyword) : MapParser(
		new ChainParser<std::string, std::string, char, std::string>(
			new StringParser(variableDeclarationKeyword),
			new SymbolParser(),
			new CharacterParser(typeAssignmentKeyword),
			new CTypeParser()
		)
	) {}

	Variable map(std::tuple<std::string, std::string, char, std::string> variable)
	{
		std::string type = std::get<3>(variable);
		std::string name = std::get<1>(variable);
		return Variable(name, type);
	}
};