#pragma once

#include <string>
#include "core/one_of_parser.h"
#include "string_parser.h"

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