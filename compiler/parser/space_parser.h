#pragma once

#include "base_parser.h"

class SpaceParser : public BaseParser<int>
{
public:
    SpaceParser() = default;
    bool match(char element) override { return std::isspace(element); }
    int transform(char element) override {}
private:
};