#pragma once

#include <string>
#include <vector>
#include "parser.h"
#include "type_parser.h"
#include "scope_parser.h"
#include "variable_parser.h"
#include "ast/function.h"
#include "ast/variable.h"
#include "seperated_parser.h"

class FunctionArgumentsParser : public MapParser<std::tuple<Variable, std::vector<std::tuple<char, Variable>>>, ArgumentList>
{
public:
	FunctionArgumentsParser() : MapParser(
		new CommaSeparatedParser(new VariableParser())
	) {}

	ArgumentList map(std::tuple<Variable, std::vector<std::tuple<char, Variable>>> elements)
	{
		std::vector<Variable> arguments;

		Variable firstArgument = std::get<0>(elements);
		auto restArguments = std::get<1>(elements);

		arguments.emplace_back(firstArgument);
		for (auto& argument : restArguments)
		{
			arguments.emplace_back(std::get<1>(argument));
		}
		return ArgumentList(arguments);
	}
};

class FunctionDeclarationParser : public ChainParser<std::string, std::string, std::optional<ArgumentList>>
{
public:
	FunctionDeclarationParser() : ChainParser<std::string, std::string, std::optional<ArgumentList>>(
		new CTypeParser(),
		new SymbolParser(),
		new ParenthesisParser<std::optional<ArgumentList>>(
			new OptionalParser<ArgumentList>(
				new FunctionArgumentsParser()
			)
		)
	) {}
};

