#pragma once

#include <variant>
#include "stream.h"
#include "result.h"

template<class T>
class Parser
{
public:
	virtual ~Parser() = 0;
	virtual bool match(char element) = 0; 
    virtual std::variant<Success<T>, Failure> parse(Stream<char>& inputStream) = 0;
};

template<class T>
inline Parser<T>::~Parser() = default;