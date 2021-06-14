#pragma once

#include "parser.h"
#include "fix.h"
#include "result.h"
#include "expression_parser.h"

class RecursiveParser : public Parser<Fix<ExpressionParser>>
{
	RecursiveParser(Parser<Fix<ExpressionParser>>* parser) : m_parser(parser) {}
	ParseResult<Fix<ExpressionParser>> parse(Stream<char>* inputStream)
	{
		auto res = m_parser->parse(inputStream);
		if (auto success = std::get_if<0>(&(res.result)))
		{
			Fix<ExpressionParser> data = success->getData();
			auto newParser = unFix(data);
			auto res2 = newParser.parse(inputStream);
			if (auto success2 = std::get_if<0>((&res2.result))) 
			{
				auto data2 = success2->getData();
			}
			else 
			{

			}
		}
		else
		{

		}
	}
private:
	Parser<Fix<ExpressionParser>>* m_parser;
};