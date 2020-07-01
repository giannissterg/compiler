#pragma once
#include <vector>
#include "result.h"
#include "base_parser.h"
#include "stream.h"

template <class T>
class OneOfParser : public Parser<T>
{
public:
    OneOfParser(std::initializer_list<Parser<T>*> parsers) : m_parsers(parsers) {}
    bool match(char element) override 
    { 
        for (Parser<T>* parser : m_parsers)
        {
            if (parser->match(element))
            {
                return true;
            }
        }
        return false;
    }

    std::variant<Success<T>, Failure> parse(Stream<char>& inputStream) override 
    { 
        std::variant<Success<T>, Failure> parseResult;
        for (Parser<T>* parser : m_parsers)
        {
            std::variant<Success<T>, Failure> result = parser->parse(inputStream);
            if (auto pval = std::get_if<0>(&result))
            {
                parseResult = *pval;
                return parseResult;
            }

        }
        parseResult = Failure(Error("AAAAAAAAAAAAA"));
        return parseResult;
        throw std::out_of_range("Variant did not contain matched value");
    }
private:
    std::vector<Parser<T>*> m_parsers;
};