#pragma once

#include "parser.h"
#include "scope_parser.h"
#include "ast/abstract_syntax_tree.h"
#include "variable_assignment_parser.h"

class BlockParser : public MapParser<std::vector<Assignment>, Block>
{
public:
	BlockParser() : MapParser(new CurlyBraceParser(
			new RepeatingParser<Assignment>(
				new VariableAssignmentParser('=')
			)
		) 
	){}

	Block map(std::vector<Assignment> assignments)
	{
		return Block(assignments);
	}
};