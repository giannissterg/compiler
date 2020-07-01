#pragma once

#include <variant>
#include <tuple>
#include "base_parser.h"
#include "result.h"
#include "stream.h"

template <class... T>
class OrParser : public Parser<std::variant<T...>>
{
public:
    OrParser(Parser<T>*... parsers) : m_parsers(std::make_tuple(parsers...)) {}
    bool match(char element) override { return match_helper(element); }
    std::variant<Success<std::variant<T...>>, Failure> parse(Stream<char>& inputStream) override { return parse_helper(inputStream); }
private:
    template<size_t I = 0>
    bool match_helper(char element) { return std::get<I>(m_parsers)->match(element); }
    
    template<size_t I = 0>
    std::variant<Success<std::variant<T...>>, Failure> parse_helper(Stream<char>& inputStream)
    {
        if (match_helper<I>(inputStream.top()))
        {
            std::variant<Success<typename std::tuple_element<I, std::tuple<T...>>::type>, Failure> r = std::get<I>(m_parsers)->parse(inputStream);
            auto a = std::get<0>(r);
            std::variant<T...> b = a.getData();
            return Success(b);
        }

        if constexpr (I + 1 != sizeof...(T))
        {
            return parse_helper<I + 1>(inputStream);
        }
        else
        {
            return Failure(Error("Nothing matched"));
        }
    }

    std::tuple<Parser<T>*...> m_parsers;
};