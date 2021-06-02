#pragma once

#include "parser/core/parser.h"

template<class T, class U>
class MapParser : public Parser<U>
{
public:
	MapParser(Parser<T>* parser) : m_parser(parser) {}
	~MapParser() { delete m_parser; }
	ParseResult<U> parse(Stream<char>* elements) override
	{
		std::variant<Success<U>, Failure> parseResult;
		std::variant<Success<T>, Failure> result = m_parser->parse(elements);
		if (auto pval = std::get_if<0>(&result))
		{
			U mappedResult = map(pval->getData());
			parseResult = Success<U>(mappedResult);
		}
		else
		{
			parseResult = std::get<1>(result);
		}
		return parseResult;
	}
protected:
	virtual U map(T elements) = 0;
private:
	Parser<T>* m_parser;
};