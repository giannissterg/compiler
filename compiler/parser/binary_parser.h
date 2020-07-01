#pragma once

#include "parser/integer_parser.h"

class BinaryParser : public IntegerParser
{
public:
    BinaryParser() : IntegerParser(2) {}
};

class OctalParser : public IntegerParser
{
public:
    OctalParser() : IntegerParser(8) {}
};

class DecimalParser : IntegerParser
{
    DecimalParser() : IntegerParser(10) {}
};