#pragma once

#include "parser.h"
#include "type_parser.h"
#include <string>

class LlamaConstrParser : public ChainParser<std::string, std::optional<std::tuple<std::string, std::vector<std::string>>>>
{
public:
	LlamaConstrParser() : ChainParser<std::string, std::optional<std::tuple<std::string, std::vector<std::string>>>>(
		new SymbolParser(),
		new OptionalParser(
			new ChainParser<std::string, std::vector<std::string>>(
				new StringParser("of"),
				new RepeatingParser(
					new CTypeParser()
				)
			)
		)
	) {}
};

class LlamaTDefinitionParser : public ChainParser<std::string, char, std::tuple<std::tuple<std::string, std::optional<std::tuple<std::string, std::vector<std::string>>>>, std::vector<std::tuple<char, std::tuple<std::string, std::optional<std::tuple<std::string, std::vector<std::string>>>>>>>>
{
public:
	LlamaTDefinitionParser() : ChainParser<std::string, char, std::tuple<std::tuple<std::string, std::optional<std::tuple<std::string, std::vector<std::string>>>>, std::vector<std::tuple<char, std::tuple<std::string, std::optional<std::tuple<std::string, std::vector<std::string>>>>>>>>(
		new SymbolParser(),
		new CharacterParser('='),
		new SeparatedParser(new CharacterParser('|'), new LlamaConstrParser())

	) {}
};

class LlamaTypeDefinitionParser : public ChainParser<>
{
public:
	LlamaTypeDefinitionParser() : ChainParser<std::string, >(
		new StringParser("type"),
		new SeparatedParser(
			new StringParser("and"),
			new LlamaTDefinitionParser()
		)
	) {}
};
