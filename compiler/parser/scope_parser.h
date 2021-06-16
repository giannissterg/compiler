#pragma once

#include "core/chain_parser.h"
#include "core/character_parser.h"
#include "core/map_parser.h"
#include "core/optional_parser.h"

template <class T>
class ScopeParser : public ChainParser<char, T, char>
{
public:
    ScopeParser(char openScopeCharacter, char closeScopeCharacter, Parser<T>* parser) :
        m_weight(1),
        m_openScopeCharacter(openScopeCharacter),
        m_closeScopeCharacter(closeScopeCharacter),
        ChainParser<char, T, char>(new CharacterParser(openScopeCharacter), parser, new CharacterParser(closeScopeCharacter)) {}
      
    unsigned int getWeight() const { return m_weight; };
private:
    unsigned int m_weight;
    char m_openScopeCharacter;
    char m_closeScopeCharacter;
};

template <class T>
class ParenthesisParser : public MapParser<std::tuple<char, T, char>, T>
{
public:
    ParenthesisParser(Parser<T>* parser) : MapParser<std::tuple<char, T, char>, T>(new ScopeParser<T>('(', ')', parser)) {}
    T map(std::tuple<char, T, char> element)
    {
        return std::get<1>(element);
    }
};

template <class T>
class BlockParser : public MapParser<std::tuple<char, T, char>, T>
{
public:
    BlockParser(Parser<T>* parser) : MapParser<std::tuple<char, T, char>, T>(new ScopeParser<T>('{', '}', parser)) {}
    T map(std::tuple<char, T, char> element)
    {
        return std::get<1>(element);
    }
};


template <class T>
class OptionalScopeParser : public ChainParser<std::optional<char>, T, std::optional<char>>
{
public:
    OptionalScopeParser(char openScopeCharacter, char closeScopeCharacter, Parser<T>* parser) :
        m_weight(0),
        m_openScopeCharacter(openScopeCharacter),
        m_closeScopeCharacter(closeScopeCharacter),
        ChainParser<std::optional<char>, T, std::optional<char>>(
            new OptionalParser<char>(new CharacterParser(openScopeCharacter)),
            parser, 
            new OptionalParser<char>(new CharacterParser(closeScopeCharacter))
        ) {}
private:
    unsigned int m_weight;
    char m_openScopeCharacter;
    char m_closeScopeCharacter;
};