#pragma once

#include <vector>
#include <string>
#include "stream.h"
#include <variant>
#include <tuple>
#include <optional>

class Rule
{
public:
	Rule() = default;
	virtual ~Rule() = 0;
	virtual bool match(Stream<char>* inputStream) = 0;
};

class CharacterRule : public Rule
{
public:
	CharacterRule(char character) : m_character(character) {}
	bool match(Stream<char>* inputStream)
	{
		char nextChar = inputStream->top();
		return (nextChar == m_character);
	}
private:
	char m_character;
};

class OrRule : public Rule
{
public:
	OrRule(std::vector<Rule*> rules) : m_rules(rules) {}
	bool match(Stream<char>* inputStream)
	{
		for (auto rule : m_rules)
		{
			if (rule->match(inputStream))
			{
				return true;
			}
		}
		return false;
	}
private:
	std::vector<Rule*> m_rules;
};

class OptionalRule : public Rule
{
public:
	OptionalRule(Rule* rule) : m_rule(rule) {}
	bool match(Stream<char>* inputStream) { return true; }
private:
	Rule* m_rule;
};

class ChainRule : public Rule
{
public:
	ChainRule(std::vector<Rule*> rules) : m_rules(rules) {}
	bool match(Stream<char>* inputStream)
	{
		for (auto rule : m_rules)
		{
			if (!rule->match(inputStream)) {
				return false;
			}
			inputStream->next();
		}
		return true;
	}
	std::vector<Rule*> getRules() const { return m_rules; }
private:
	std::vector<Rule*> m_rules;
};

class DigitRule : public OrRule
{
public:
	DigitRule() : OrRule({ new CharacterRule('0'), new CharacterRule('1'), new CharacterRule('2')}) {}
};

class RepeatingRule : public Rule
{
public:
	RepeatingRule(Rule* rule) : m_rule(rule) {}
private:
	Rule* m_rule;
};

class WordRule : public Rule
{
public:
	WordRule(std::string word) : m_word(word) {}
	bool match(Stream<char>* inputStream)
	{
		Stream<char>* input = inputStream;
		for (unsigned int i = 0; i < m_word.size(); ++i)
		{
			if (m_word[i] == input->top())
			{
				input->next();
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	std::string getWord() const { return m_word; }
private:
	std::string m_word;
};

class ScopeRule : public ChainRule
{
public:
	ScopeRule(char openScopeCharacter, Rule* innerRule, char closeScopeCharacter) : 
		ChainRule({
			new CharacterRule(openScopeCharacter),
			innerRule,
			new CharacterRule(closeScopeCharacter)
		}) {}
};
