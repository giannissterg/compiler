#pragma once

#include <optional>
#include "parser.h"

template<class T>
class OptionalParser : public Parser<std::optional<T>>
{
public:
    OptionalParser(Parser<T>* parser) : m_parser(parser) {}    
    ParseResult<std::optional<T>> parse(Stream<char>* inputStream) override
    { 
        std::variant<Success<std::optional<T>>, Failure> parseResult;
        std::variant<Success<T>, Failure> result = m_parser->parse(inputStream);
        if (auto pval = std::get_if<0>(&result))
        {
            std::optional<T> a = std::make_optional(pval->getData());
            parseResult = Success(a);
        }
        else
        {
            parseResult = Success<std::optional<T>>(std::nullopt);
        }
        return parseResult;
    }
private:
    Parser<T>* m_parser;
};