#pragma once

#include "parser/core/parser.h"

template<class T, class U>
class MapParser : public Parser<U>
{
public:
	MapParser(Parser<T>* parser) : m_parser(parser) {}
	~MapParser() { delete m_parser; }
	ParseResult<U> parse(Stream<char>* inputStream) override
	{
		ParseResult<T> result = m_parser->parse(inputStream);
		if (auto pval = std::get_if<0>(&(result.result)))
		{
			U mappedResult = map(pval->getData());
			return ParseResult<U>(Success<U>(mappedResult), inputStream);
		}
		else
		{
			return ParseResult<U>(std::get<1>(result.result), inputStream);
		}
	}
protected:
	virtual U map(T elements) = 0;
private:
	Parser<T>* m_parser;
};