#pragma once

#include <vector>
#include <string>

class LlamaLanguage
{
public:
	LlamaLanguage() 
		: m_llamaTypes({ "unit", "int", "char", "bool", "float"})
		, m_typeDeclarationKeyword("type")
		, m_variableDeclarationKeyword("let")
		, m_functionDeclarationKeyword("let")
		, m_modifiers({ "mutable" })
		, m_typeAssignmentKeyword(':') {}
private:
	std::vector<std::string> m_llamaTypes;
	std::string m_typeDeclarationKeyword;
	std::string m_variableDeclarationKeyword;
	std::string m_functionDeclarationKeyword;
	std::vector<std::string> m_modifiers;
	char m_typeAssignmentKeyword;
};