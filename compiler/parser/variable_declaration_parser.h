#pragma once

#include <string>
#include "parser.h"
#include "type_parser.h"
#include "variable_parser.h"
#include "types/product_type.h"
#include "ast/variable.h"

class VariableDeclarationParser : public ChainParser<Variable, char>
{
public:
	VariableDeclarationParser() : ChainParser<Variable, char>(
		new VariableParser(),
		new CharacterParser(';')
	) {}
};

class KotlinVariableDeclarationParser : public ChainParser<std::string, std::string, std::optional<std::tuple<char, std::string>>, char>
{
public:
	KotlinVariableDeclarationParser() : ChainParser(
		new StringParser("let"),
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