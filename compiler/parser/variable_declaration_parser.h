#pragma once

#include <string>
#include "parser.h"
#include "type_parser.h"
#include "symbol_parser.h"
#include "string_parser.h"
#include "parameter_parser.h"

class VariableDeclarationParser : public ChainParser<std::tuple<std::string, std::string>, char>
{
public:
	VariableDeclarationParser() : ChainParser(
		new ParameterParser(),
		new CharacterParser(';')
	) {}
};

class KotlinVariableDeclarationParser : public ChainParser<std::string, std::string, std::optional<std::tuple<char, std::string>>, char>
{
public:
	KotlinVariableDeclarationParser() : ChainParser(
		new StringParser("var"),
		new SymbolParser(),
		new OptionalParser(
			new ChainParser<char, std::string>(
				new CharacterParser(':'), 
				new CTypeParser()
			)
		),
		new CharacterParser(';')
	) {}
};