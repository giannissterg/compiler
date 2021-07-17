#pragma once

#include "base_parser.h"

class FailingParser : public BaseParser<std::monostate>
{
public:
	FailingParser() = default;
	bool match(char element) { return false; }
	std::monostate transform(char elements) { return std::monostate{}; }
private:
};