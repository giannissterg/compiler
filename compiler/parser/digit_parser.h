#pragma once

#include "base_parser.h"

// Parses digits from base 1 to base 10
class DigitParser : public BaseParser<int>
{
public:
    DigitParser(uint8_t base = 10) : m_base(base) {}
    bool match(char element) override { return isdigit(element); }
    int transform(char element) override { return static_cast<int>(element) - '0'; }
private:

    bool isdigit(unsigned char element) const { return ((uint32_t)element - '0') < m_base; }
    uint8_t m_base;
};