#pragma once

#include <string>
#include <vector>
#include "parser.h"
#include "type_parser.h"
#include "symbol_parser.h"
#include "scope_parser.h"
#include "parameter_parser.h"

class FunctionDeclarationParser : ChainParser<std::tuple<std::string, std::string>, std::optional<std::tuple<std::tuple<std::string, std::string>, std::optional<std::vector<std::tuple<char, std::tuple<std::string, std::string>>>>>>>
{
public:
	FunctionDeclarationParser() : ChainParser(
		new ParameterParser(),
		new ParenthesisParser(
			new FunctionParametersParser()
		)
	) {}
};

class FunctionParametersParser : public OptionalParser<std::tuple<std::tuple<std::string, std::string>, std::optional<std::vector<std::tuple<char, std::tuple<std::string, std::string>>>>>>
{
public:
	FunctionParametersParser() : OptionalParser(
		new ChainParser<std::tuple<std::string, std::string>, std::optional<std::vector<std::tuple<char, std::tuple<std::string, std::string>>>>>(
			new ParameterParser(),
			new OptionalParser<std::vector<std::tuple<char, std::tuple<std::string, std::string>>>>(
				new RepeatingParser(
					new ChainParser<char, std::tuple<std::string, std::string>>(
						new CharacterParser(','),
						new ParameterParser()
					)
				)
			)
		)
	) {}
};