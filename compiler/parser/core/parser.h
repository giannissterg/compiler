#pragma once

#include <variant>
#include "stream.h"
#include "../result.h"

template<class T>
class Parser
{
public:
	virtual ~Parser() = 0;
    virtual ParseResult<T> parse(Stream<char>* inputStream) = 0;
};

template<class T>
inline Parser<T>::~Parser() = default;