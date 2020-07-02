#pragma once

#include "string_parser.h"
#include "one_of_parser.h"

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
