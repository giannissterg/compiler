#pragma once

#include <iostream>
#include <tuple>
#include <utility>
#include "parser.h"
#include "../result.h"

template <class... T>
class ChainParser : public Parser<std::tuple<T...>>
{
public:
    ChainParser(Parser<T>*... parsers) 
    {
        m_parsers = std::make_tuple(parsers...);
    }
    ~ChainParser()
    {
        std::apply([](auto&&... args) {((delete args), ...); }, m_parsers);
    }
    ParseResult<std::tuple<T...>> parse(Stream<char>* inputStream) override { return parse_helper<0>(inputStream); }
    std::tuple<Parser<T>*...> getParsers() const { return m_parsers; }
private:    
    template<size_t I = 0>
    ParseResult<std::tuple<T...>> parse_helper(Stream<char>* inputStream)
    {
        ParseResult<std::tuple<T...>> parseResult;

        std::tuple<T...> parsedElements;
        ParseResult<typename std::tuple_element<I, std::tuple<T...>>::type> result = std::get<I>(m_parsers)->parse(inputStream);
        if (auto success = std::get_if<0>(&(result.result)))
        {
            std::get<I>(parsedElements) = success->getData();
        }
        else
        {
            return ParseResult<std::tuple<T...>>(Failure(Error("All wrong!")), inputStream);
        }

        if constexpr (I + 1 != sizeof...(T)) { parseResult = parse_helper< I + 1>(inputStream); }
        if (auto nextPval = std::get_if<0>(&(parseResult.result)))
        {
            std::tuple<T...> local = nextPval->getData();
            std::get<I>(local) = std::get<I>(parsedElements);
            return ParseResult<std::tuple<T...>>(Success(local), inputStream);
        }
        else
        {
            return ParseResult<std::tuple<T...>>(Failure(Error("All wrong2!")), inputStream);
        }        
    }

    std::tuple<Parser<T>*...> m_parsers;
};