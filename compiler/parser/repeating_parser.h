#pragma once 
#include <iostream>
#include <variant>
#include <utility>
#include <vector>
#include "stream.h"
#include "parser/result.h"
#include "parser/parser.h"

template <class T>
class RepeatingParser : public Parser<std::vector<T>>
{
public:
    RepeatingParser(Parser<T>* parser) : m_parser(parser) {}
    bool match(char element) override { return m_parser->match(element);}
    std::variant<Success<std::vector<T>>, Failure> parse(Stream<char>& inputStream) override
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
                return Failure(Error("AAAAAAAAAAAAA"));
            }
        }
        return Success(parsedElements);
    }
private:
    Parser<T>* m_parser;
};