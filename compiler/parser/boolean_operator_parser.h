#pragma once

#include <string>
#include "core/one_of_parser.h"
#include "core/string_parser.h"

class BooleanOperatorParser : public OneOfParser<std::string>
{
public:
    BooleanOperatorParser() :
        OneOfParser<std::string>({
            new StringParser("<"),
            new StringParser(">"),
            new StringParser("=="),
            new StringParser("<="),
            new StringParser(">="),
            new StringParser("!="),
            }) {}
};
