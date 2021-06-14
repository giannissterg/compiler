#pragma once

#include <vector>

class VariableMap {};

class Scope {
public:
	virtual ~Scope() = 0;
private:
	VariableMap m_variableMap;
};

class NodeScope : Scope {
private:
	std::vector<Scope*> m_scopes;
};

class LeafScope : Scope {

};