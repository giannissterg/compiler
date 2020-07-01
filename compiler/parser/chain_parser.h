#pragma once

#include <iostream>
#include <tuple>
#include <utility>
#include "parser.h"
#include "result.h"

template <class... T>
class ChainParser : public Parser<std::tuple<T...>>
{
public:
    ChainParser(Parser<T>*... parsers) 
    {
        m_parsers = std::make_tuple(parsers...);
    }
    bool match(char element) override { return match_helper(element); }
    std::variant<Success<std::tuple<T...>>, Failure> parse(Stream<char>& inputStream) override { return parse_helper(inputStream); }
private:
    template<size_t I = 0>
    bool match_helper(char element) { return std::get<I>(m_parsers)->match(element); }
    
    template<size_t I = 0>
    std::variant<Success<std::tuple<T...>>, Failure> parse_helper(Stream<char>& inputStream)
    {
        std::variant<Success<std::tuple<T...>>, Failure> parseResult;

        std::tuple<T...> parsedElements;
        std::variant<Success<typename std::tuple_element<I, std::tuple<T...>>::type>, Failure> result = std::get<I>(m_parsers)->parse(inputStream);
        if (auto pval = std::get_if<0>(&result))
        {
            std::get<I>(parsedElements) = pval->getData();
        }
        else
        {
            return Failure(Error("All wrong!"));
        }

        if constexpr (I + 1 != sizeof...(T)) { parseResult = parse_helper< I + 1>(inputStream); }
        if (auto nextPval = std::get_if<0>(&parseResult))
        {
            std::tuple<T...> local = nextPval->getData();
            std::get<I>(local) = std::get<I>(parsedElements);
            parseResult = Success(local);
        }
        else
        {
            parseResult = Failure(Error("All wrong2!"));
        }
        
        return parseResult;
    }
    std::tuple<Parser<T>*...> m_parsers;
};