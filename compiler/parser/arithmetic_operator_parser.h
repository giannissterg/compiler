#pragma once

#include "character_parser.h"
#include "one_of_parser.h"

class ArithmeticOperatorParser : public OneOfParser<char>
{
public:
    ArithmeticOperatorParser() :
        OneOfParser<char>({
            new CharacterParser('^'),
            new CharacterParser('%'),
            new CharacterParser('+'),
            new CharacterParser('-'),
            new CharacterParser('/'),
            new CharacterParser('*')
            }) {}
};
