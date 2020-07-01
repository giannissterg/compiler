#pragma once 

#include <variant>
#include "parser.h"
#include "scope_parser.h"
#include "one_of_parser.h"
#include "arithmetic_operator_parser.h"

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
		auto parser = ChainParser(
			&combinedParser,
			new RepeatingParser(
				new ChainParser(
					new ArithmeticOperatorParser(),
					&combinedParser
				))
		);

		auto result = parser.parse(inputStream);
		if (auto success = std::get_if<0>(&result))
		{
			auto elements = success->getData();

			T firstOperand = std::get<0>(elements);
			finalResult = firstOperand;
			std::vector<std::tuple<char, T>> restElements = std::get<1>(elements);
			for (unsigned int i = 0; i < restElements.size(); i++)
			{
				std::tuple<char, T> nextElement = restElements[i];
				char operatorSymbol = std::get<0>(nextElement);
				int elementValue = std::get<1>(nextElement);
				switch (operatorSymbol)
				{
				case '+': { finalResult += elementValue; break; }
				case '-': { finalResult -= elementValue; break; }
				case '*': { finalResult *= elementValue; break; }
				default:
					break;
				}
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