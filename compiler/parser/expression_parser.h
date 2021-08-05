#pragma once

#include "parser.h"
#include "result.h"
#include "binary_expression_parser.h"
#include "fix.h"

template <class T>
class ExpressionParser : public OrParser<int, std::tuple<T, char, T>> {
public:
	ExpressionParser(Parser<T>* parser) : OrParser<int, std::tuple<T, char, T>>(new IntegerParser(), new BinaryExpressionParser<T>(parser)) {}
};