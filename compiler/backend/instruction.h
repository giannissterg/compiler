#pragma once

#include <bitset>

template<size_t Size>
class Instruction
{
	Instruction(std::bitset<Size> code) : m_code(code)
private:
	std::bitset<Size> m_code;
};


class AdditionInstruction : public Instruction<32>
{
public:
	AdditionInstruction() : Instruction() {}
};