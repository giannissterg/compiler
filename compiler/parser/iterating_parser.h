#pragma once

#include <array>
#include "parser.h"

template<std::size_t N, class T>
class IteratingParser : public Parser<std::array<T, N>>
{
public:
	IteratingParser(Parser<T>* parser) : m_parser(parser) {}

    bool match(char element) override { return m_parser->match(element); }

    std::variant<Success<std::array<T, N>>, Failure> parse(Stream<char>& inputStream) override
    {
        std::array<T, N> parsedElements;
        for (unsigned int i = 0; i < N; i++)
        {
            std::variant<Success<T>, Failure> result = m_parser->parse(inputStream);
            if (auto pval = std::get_if<0>(&result))
            {
                parsedElements[i] = pval->getData();
            }
            else
            {
                return Failure(Error("Wrong!"));
            }
        }
        return Success(parsedElements);
    }
private:
    Parser<T>* m_parser;
};