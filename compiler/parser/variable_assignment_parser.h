#pragma once

#include "parser.h"
#include "variable_parser.h"
#include "ast/variable.h"
#include "ast/abstract_syntax_tree.h"

class VariableAssignmentParser : public MapParser<std::tuple<Variable, char, int, char>, Assignment>
{
public:
	VariableAssignmentParser(char assignmentSymbol) : MapParser(
		new ChainParser<Variable, char, int, char>(
			new KotlinVariableParser("let", ':'),
			new CharacterParser(assignmentSymbol),
			new IntegerParser(),
			new CharacterParser(';')
		)
	) {}

	Assignment map(std::tuple<Variable, char, int, char> assignment)
	{
		Variable variable = std::get<0>(assignment);
		int value = std::get<1>(assignment);
		return Assignment(variable, Value(value));
	}
};