#pragma once

#include "abstract_syntax_tree.h"

template<class T>
class Analyzer
{
public:
	Analyzer() {}
	void analyze(const T& ast) {}

};

class BlockAnalyzer : Analyzer<Block>
{
public:
	BlockAnalyzer() {}
	void analyze(const Block& ast) {}
};