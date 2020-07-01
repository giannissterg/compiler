#pragma once

#include <utility>
#include <string>
#include "result.h"
#include "parser.h"

class StringParser : public Parser<std::string>
{
public:
    StringParser() = delete;
    StringParser(std::string symbol) : m_index(0), m_symbol(symbol) {}
    bool match(char element) override 
    { 
        return m_symbol[m_index++] == element;
        
    }
    std::variant<Success<std::string>, Failure> parse(Stream<char>& inputStream) override
    {
        std::variant<Success<std::string>, Failure> parseResult;
        std::string resultString = "";
        for (unsigned int i = 0; i < m_symbol.size(); i++)
        {
            char element = inputStream.top();
            if (match(element))
            {
                inputStream.next();
                resultString += element;
            }
            else
            {
                parseResult = Failure(Error("Not right string"));
            }
        }
        parseResult = Success(resultString);
        return parseResult;
    }
private:
    unsigned int m_index;
    std::string m_symbol;
};