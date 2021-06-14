#pragma once

#include <utility>
#include <string>
#include "result.h"
#include "core/parser.h"

class StringParser : public Parser<std::string>
{
public:
    StringParser() = delete;
    StringParser(std::string symbol) : m_symbol(symbol) {}
    ParseResult<std::string> parse(Stream<char>* inputStream) override
    {
        std::string resultString = "";
        // TODO: Implement Stream<T> interface with get(n) as std::istringstream 
        for (unsigned int i = 0; i < m_symbol.size(); i++)
        {
            char element = inputStream->top();
            if (element == m_symbol[i])
            {
                inputStream->next();
                resultString += element;
            }
            else
            {
                return ParseResult<std::string>(Failure(Error("String did not match!")), inputStream);
            }
        }
        return ParseResult<std::string>(Success(resultString), inputStream);
    }
private:
    std::string m_symbol;
};