#pragma once

#include <bitset>

class Assembler
{
	virtual std::bitset<32> assemble() = 0;
};