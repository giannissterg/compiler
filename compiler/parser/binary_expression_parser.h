#pragma once

#include "core/chain_parser.h"
#include "arithmetic_operator_parser.h"

template<class T>
class BinaryExpressionParser : public ChainParser<T, char, T>
{
public:
	BinaryExpressionParser(Parser<T>* parser) : ChainParser<T, char, T>(parser, new ArithmeticOperatorParser(), parser) {}
};