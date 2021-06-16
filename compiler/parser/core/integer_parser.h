#pragma once

#include "repeating_parser.h"
#include "digit_parser.h"
#include "map_parser.h"

class IntegerParser : public MapParser<std::vector<int>, int>
{
public:
    IntegerParser(uint8_t base = 10) : m_base(base), MapParser(new RepeatingParser(new DigitParser(base))) {}
private:
    int map(std::vector<int> elements) override
    {
        int outputValue = 0;
        for (unsigned int i = 0; i < elements.size(); i++)
        {
            outputValue *= m_base;
            outputValue += elements[i];
        }
        return outputValue;
    }
    uint8_t m_base;
};