#pragma once

#include "parser.h"
#include <vector>

template <class T>
class SeparatedParser : public ChainParser<T, std::vector<std::tuple<char, T>>>
{
public:
	SeparatedParser(char separator, Parser<T>* parser) : ChainParser<T, std::vector<std::tuple<char, T>>>(
		parser,
		new RepeatingParser(
			new ChainParser<char, T>(
				new CharacterParser(separator),
				parser
			)
		)
	) {}
};

template <class T>
class CommaSeparatedParser : public SeparatedParser<T>
{
public:
	CommaSeparatedParser(Parser<T>* parser) : SeparatedParser(',', parser) {}
};