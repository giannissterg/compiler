#pragma once

#include <optional>
#include "parser.h"
#include "../result.h"

template<class T>
class OptionalParser : public Parser<std::optional<T>>
{
public:
    OptionalParser(Parser<T>* parser) : m_parser(parser) {}
    ~OptionalParser() { delete m_parser; }
    ParseResult<std::optional<T>> parse(Stream<char>* inputStream) override
    { 
        ParseResult<std::optional<T>> parseResult;
        ParseResult<T> result = m_parser->parse(inputStream);
        if (auto pval = std::get_if<0>(&(result.result)))
        {
            std::optional<T> a = std::make_optional(pval->getData());
            parseResult = ParseResult(Success(a), inputStream);
        }
        else
        {
            parseResult = ParseResult(Success<std::optional<T>>(std::nullopt), inputStream);
        }
        return parseResult;
    }
private:
    Parser<T>* m_parser;
};