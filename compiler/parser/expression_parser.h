#pragma once

#include "parser.h"
#include "result.h"
#include "binary_expression_parser.h"
#include "fix.h"

template <class T>
class ExpressionParser : public OrParser<T, std::tuple<T, char, T>> {
public:
	ExpressionParser(Parser<T>* parser) : OrParser<T, std::tuple<T, char, T>>(parser, new BinaryExpressionParser<T>(parser)) {}
};