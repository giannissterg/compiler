#pragma once

#include <string>
#include "parser.h"
#include "result.h"
#include "symbol_parser.h"
#include "binary_expression_parser.h"
#include "fix.h"

template <class T>
class ExpressionParser : public OrParser<T, std::tuple<T, char, T>> {
public:
	ExpressionParser(Parser<Ô>* parser) : OrParser<int, std::tuple<T, char, T>>(parser, new BinaryExpressionParser<T>(parser)) {}
};