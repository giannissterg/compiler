#pragma once 

#include <variant>
#include <tuple>
#include "parser.h"
#include "scope_parser.h"
#include "or_parser.h"
#include "term_parser.h"
#include "arithmetic_operator_parser.h"
#include "symbol_parser.h"

template<class... T> // TermParser
class TermParser : public Parser<std::vector<std::tuple<char, std::variant<T...>>>>
{
public:
	TermParser(Parser<T>*... leafParsers) : m_leafParsers(new ParenthesisParser(this), leafParsers...), m_expressionParser(&m_leafParsers, new ArithmeticOperatorParser()) {}
	bool match(char element) { return m_leafParsers.match(element); }
	std::variant<Success<std::vector<std::tuple<char, std::variant<T...>>>>, Failure> parse(Stream<char>& inputStream)
	{
		std::vector<std::tuple<char, std::variant<T...>>> finalResult;

		auto result = m_expressionParser.parse(inputStream);
		if (auto success = std::get_if<0>(&result))
		{
			std::vector<std::tuple<char, std::variant<std::vector<std::tuple<char, std::variant<T...>>>, T...>>> elements = success->getData();
			for (unsigned int i = 0; i < elements.size(); i++)
			{
				auto firstOperator = std::get<0>(elements[i]);
				auto restElements = std::get<1>(elements[i]);
				if (auto pval = std::get_if<0>(&restElements))
				{
					std::vector<std::tuple<char, std::variant<T...>>> nestedElements = *pval;
					finalResult.push_back({ firstOperator, std::get<1>(nestedElements[0]) });
					for (unsigned int j = 1; j < nestedElements.size(); j++)
					{
						finalResult.push_back(nestedElements[j]);
					}
				}
				else
				{
					std::variant<T...> operand = convertVariant(restElements);
					finalResult.push_back({ firstOperator, operand });
				}
			}
		}
		else
		{
			return Failure(Error("Could not parse expression"));
		}
		return Success(finalResult);
	}
private:
	template<size_t I = 0>
	std::variant<T...> convertVariant(std::variant<std::vector<std::tuple<char, std::variant<T...>>>, T...> restElements)
	{
		if (auto pval = std::get_if<typename std::tuple_element<I, std::tuple<T...>>::type > (&restElements)) 
		{ 
			return *pval; 
		}

		if constexpr (I + 1 != sizeof...(T))
		{
			return convertVariant<I + 1>(restElements);
		}
		else
		{
			throw("Non exhaustive cases for variant");
		}
	}

	// IMPORTANT: initialization order depends on declaration order
	OrParser<std::vector<std::tuple<char, std::variant<T...>>>, T...> m_leafParsers;
	ExpressionParser2<std::variant<std::vector<std::tuple<char, std::variant<T...>>>, T...>> m_expressionParser;
};