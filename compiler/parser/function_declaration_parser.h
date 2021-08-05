#pragma once

#include <string>
#include <vector>
#include <optional>
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

class LlamaFunctionParameterParser : public OrParser<std::string, std::tuple<std::string, char, std::string>>
{
public:
	LlamaFunctionParameterParser() : OrParser<std::string, std::tuple<std::string, char, std::string>>(
		new SymbolParser(),
		new ParenthesisParser<std::tuple<std::string, char, std::string>>(
			new ChainParser<std::string, char, std::string>(
				new SymbolParser(),
				new CharacterParser(':'),
				new CTypeParser()
			)
		)
	) {}
};

class LlamaFunctionParser : public ChainParser<std::string, std::optional<std::string>, std::string, std::vector<std::variant<std::string, std::tuple<std::string, char, std::string>>>, std::optional<std::tuple<char, std::string>>, char, int>
{
public:
	LlamaFunctionParser() : ChainParser<std::string, std::optional<std::string>, std::string, std::vector<std::variant<std::string, std::tuple<std::string, char, std::string>>>, std::optional<std::tuple<char, std::string>>, char, int>(
		new StringParser("let"),
		new OptionalParser<std::string>(
			new StringParser("rec")
		),
		new SymbolParser(),
		new RepeatingParser(
			new LlamaFunctionParameterParser()
		),
		new OptionalParser(
			new ChainParser<char, std::string>(
				new CharacterParser(':'),
				new CTypeParser()
			)
		),
		new CharacterParser('='),
		new IntegerParser()
	) {}
};