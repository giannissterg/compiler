#pragma once

#include <string>
#include "core/chain_parser.h"
#include "string_parser.h"
#include "arithmetic_operator_parser.h"

template<class T, class U>
class BinaryExpressionParser : public ChainParser<T, char, U>
{
public:
	BinaryExpressionParser(Parser<T>* rightParser, Parser<U>* leftParser) : ChainParser<T, char, U>(rightParser, new ArithmeticOperatorParser(), leftParser) {}
};