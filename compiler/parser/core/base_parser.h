#pragma once

#include <vector>
#include <string>
#include <utility>
#include <variant>
#include "stream.h"
#include "parser.h"
#include "../result.h"

template <class T>
class BaseParser : public Parser<T>
{
public:
    BaseParser() = default;
    ~BaseParser() = default;
    virtual bool match(char element) = 0;
    ParseResult<T> parse(Stream<char>* inputStream) override
    { 
        if (match(inputStream->top()))
        {
            T parsedElement = transform(inputStream->top());
            inputStream->next();
            return ParseResult<T>(Success(parsedElement), inputStream);
        }
        else
        {
            return ParseResult<T>(Failure(Error("Not parsed")), inputStream);
        }
    }
    virtual T transform(char element) = 0;
};