#pragma once

#include <string>
#include "core/one_of_parser.h"
#include "core/string_parser.h"
#include "scope_parser.h"
#include "seperated_parser.h"

class TypeParser : public OneOfParser<std::string>
{
public:
	TypeParser(std::initializer_list<std::string> typeSymbols)
	{
		for (const std::string& typeSymbol : typeSymbols)
		{
			m_parsers.push_back(new StringParser(typeSymbol));
		}
	}
};

class CTypeParser : public TypeParser
{
public:
	CTypeParser() : TypeParser({ "int", "string", "char", }) {}
};

class ArrayTypeParser : public ChainParser<std::string, char, char>
{
public:
	ArrayTypeParser(TypeParser* typeParser) : ChainParser(typeParser, new CharacterParser('['), new CharacterParser(']')) {}
};

class LlamaArrayTypeParser : public ChainParser<std::string, std::optional<std::tuple<char, std::tuple<char, std::vector<std::tuple<char, char>>>, char>>>
{
public:
	LlamaArrayTypeParser() : ChainParser(
		new StringParser("array"),
		new OptionalParser(
			new ScopeParser('[', ']', 
				new CommaSeparatedParser(new CharacterParser('*'))
			)
		)
	) {}
};