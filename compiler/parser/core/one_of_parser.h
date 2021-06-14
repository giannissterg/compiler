#pragma once
#include <vector>
#include "parser.h"
#include "stream.h"
#include "../result.h"

template <class T>
class OneOfParser : public Parser<T>
{
public:
    OneOfParser(const std::initializer_list<Parser<T>*>& parsers) : m_parsers(parsers) {}
    ~OneOfParser()
    {
        for (Parser<T>* parser : m_parsers)
        {
            delete parser;
        }
        m_parsers.clear();
    }

    ParseResult<T> parse(Stream<char>* inputStream) override 
    { 
        T parseResult;
        for (Parser<T>* parser : m_parsers)
        {
            ParseResult<T> result = parser->parse(inputStream);
            if (auto pval = std::get_if<0>(&(result.result)))
            {
                parseResult = pval->getData();
                return ParseResult<T>(Success(parseResult), inputStream);
            }

        }
        return ParseResult<T>(Failure(Error("AAAAAAAAAAAAA")), inputStream);
        throw std::out_of_range("Variant did not contain matched value");
    }
protected:
    OneOfParser() = default;
    std::vector<Parser<T>*> m_parsers;
};