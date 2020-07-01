#pragma once

#include <vector>
#include <string>
#include <utility>
#include <variant>
#include "stream.h"
#include "result.h"

template <class T>
class BaseParser : public Parser<T>
{
public:
    BaseParser() = default;
    ~BaseParser() = default;
    virtual bool match(char element) = 0;
    std::variant<Success<T>, Failure> parse(Stream<char>& inputStream) override
    { 
        std::variant<Success<T>, Failure> parseResult;
        if (match(inputStream.top()))
        {
            T parsedElement = transform(inputStream.top());
            inputStream.next();
            parseResult = Success(parsedElement);
        }
        else
        {
            parseResult = Failure(Error("Not parsed"));
        }
        return parseResult;
    }
    virtual T transform(char element) = 0;
};