#pragma once

#include <optional>
#include "base_parser.h"

template<class T>
class OptionalParser : public Parser<std::optional<T>>
{
public:
    OptionalParser(BaseParser<T>* parser) : m_parser(parser) {}    
    bool match(char inputStream) override { return true; }
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
    BaseParser<T>* m_parser;
};