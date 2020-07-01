#pragma once 

#include <variant>
#include "parser.h"
#include "scope_parser.h"
#include "one_of_parser.h"
#include "term_parser.h"
#include "arithmetic_operator_parser.h"
#include "symbol_parser.h"

template<class T>
class TreeParser : public Parser<T>
{
public:
	TreeParser(Parser<T>* leafParser) : m_leafParser(leafParser) {}
	bool match(char element) { return m_leafParser->match(element); }
	std::variant<Success<T>, Failure> parse(Stream<char>& inputStream)
	{
		T finalResult;

		auto combinedParser = OneOfParser<T>({ m_leafParser,  new ParenthesisParser<T>(this)});
		auto termParser = TermParser(&combinedParser, new ArithmeticOperatorParser());

		auto result = termParser.parse(inputStream);
		if (auto success = std::get_if<0>(&result))
		{
			std::vector<std::tuple<char, T>> elements = success->getData();
		}
		else
		{
			return Failure(Error("Could not parse expression"));
		}
		return Success(finalResult);
	}
private:
	Parser<T>* m_leafParser;
};