#pragma once 
#include <iostream>
#include <variant>
#include <utility>
#include <vector>
#include "stream.h"
#include "parser/result.h"
#include "parser/core/parser.h"

template <class T>
class RepeatingParser : public Parser<std::vector<T>>
{
public:
    RepeatingParser(Parser<T>* parser) : m_parser(parser) {}
    ParseResult<std::vector<T>> parse(Stream<char>* inputStream) override
    {
        std::vector<T> parsedElements;
        while (true)
        {
            std::variant<Success<T>, Failure> parsedElement = m_parser->parse(inputStream);
            if (auto success = std::get_if<0>(&parsedElement))
            {
                parsedElements.push_back(success->getData());
            }
            else
            {
                if (parsedElements.size() >= 0) { break; }
                return std::get<1>(parsedElement);
            }
        }
        return Success(parsedElements);
    }
private:
    Parser<T>* m_parser;
};