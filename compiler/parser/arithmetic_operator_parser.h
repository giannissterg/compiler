#pragma once

#include "core/character_parser.h"
#include "core/one_of_parser.h"

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
