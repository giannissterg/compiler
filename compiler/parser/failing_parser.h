#pragma once

#include "base_parser.h"

class FailingParser : public BaseParser<void>
{
public:
	FailingParser() = default;
	bool match(char element) { return false; }
	void transform(char elements) {}
private:
};