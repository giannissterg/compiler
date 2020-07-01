#pragma once 

#include "base_parser.h"

class CharacterParser : public BaseParser<char>
{
public:
    CharacterParser(char character) : m_character(character) {}
    bool match(char element) override { return element == m_character; }
    char transform(char element) override { return element; }
private:

    char m_character;
};