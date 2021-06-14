#pragma once

#include <variant>
#include <tuple>
#include "parser.h"
#include "../result.h"
#include "stream.h"

template <class... T>
class OrParser : public Parser<std::variant<T...>>
{
public:
    OrParser(Parser<T>*... parsers) : m_parsers(std::make_tuple(parsers...)) {}
    ParseResult<std::variant<T...>> parse(Stream<char>* inputStream) override { return parse_helper(inputStream); }
private:
    template<size_t I = 0>
    ParseResult<std::variant<T...>> parse_helper(Stream<char>* inputStream)
    {
            ParseResult<typename std::tuple_element<I, std::tuple<T...>>::type> result = std::get<I>(m_parsers)->parse(inputStream);
            if (auto success = std::get_if<0>(&(result.result)))
            {
                std::variant<T...> finalResult = success->getData();
                return ParseResult<std::variant<T...>>(Success(finalResult), inputStream);
            }
            else
            {
                if constexpr (I + 1 != sizeof...(T))
                {
                    return parse_helper<I + 1>(inputStream);
                }
                else
                {
                    return ParseResult<std::variant<T...>>(Failure(Error("Nothing matched")), inputStream);
                }
            }
    }

    std::tuple<Parser<T>*...> m_parsers;
};