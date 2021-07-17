#pragma once

#include "parser.h"

template <class C>
class IfThenElseParser : public ChainParser<std::string, C, std::string, C, std::optional<std::tuple<std::string, C>>>
{
public:
	IfThenElseParser(Parser<C>* parser) : ChainParser(
		new StringParser("if"),
		parser,
		new StringParser("then"),
		parser,
		new OptionalParser<std::tuple<std::string, C>>(
			new ChainParser<std::string, C>(
				new StringParser("else"),
				parser
			)
		)
	) {}
};