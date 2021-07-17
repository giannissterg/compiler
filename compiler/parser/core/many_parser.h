#pragma once

#include <vector>
#include "parser.h"
#include "parser/result.h"

template<class T>
class ManyParser : Parser<std::vector<T>>
{
public:
	ManyParser(Parser<T>* parser) : m_parser(parser) {}
	ParseResult<std::vector<T>> parse(Stream<char>* inputStream)
	{
		ParseResult<T> firstResult = m_parser->parse(inputStream);
		if(auto success = std::get_if<0>(firstResult.result))
		{
			std::vector<T> finalResult = {success->getData() };

			ParseResult<std::vector<T>> restResult = this->parse(firstResult.restInputStream());
			if (auto restSuccess = std::get_if<0>(restResult.result))
			{
				finalResult.emplace(std::end(finalResult), std::begin(restSuccess->getData()), std::end(restSuccess->getData()))
			}
			return ParseResult(Success(finalResult));
		}
		else
		{
			return ParseResult(Failure(Error("Failll")), firstResult.restInputStream());
		}
		
	}
private:
	Parser<T>* m_parser;
};