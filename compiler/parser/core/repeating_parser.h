#pragma once 

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
            ParseResult<T> parsedElement = m_parser->parse(inputStream);
            if (auto success = std::get_if<0>(&(parsedElement.result)))
            {
                parsedElements.push_back(success->getData());
            }
            else
            {
                if (parsedElements.size() >= 0) { break; }
                return ParseResult<std::vector<T>>(std::get<1>(parsedElement.result), inputStream);
            }
        }
        return ParseResult<std::vector<T>>(Success(parsedElements), inputStream);
    }
private:
    Parser<T>* m_parser;
};