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
        std::variant<Success<std::string>, Failure> parseResult;
        std::string resultString = "";
        for (unsigned int i = 0; i < m_symbol.size(); i++)
        {
            char element = inputStream->top();
            if (element == m_symbol[i])
            {
                auto newStream = inputStream->next();
                resultString += element;
            }
            else
            {
                parseResult = Failure(Error("String did not match!"));
            }
        }
        parseResult = Success(resultString);
        return ParseResult(parseResult, inputStream);
    }
private:
    std::string m_symbol;
};