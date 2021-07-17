#pragma once

#include <bitset>

template<size_t Size>
class Instruction
{
public:
	Instruction() = default;
	Instruction(std::bitset<Size> code) : m_content(content)
private:
	std::bitset<Size> m_content;
};


class X86Instruction : Instruction<32> {};

class AdditionInstruction : public Instruction<32>
{
public:
	AdditionInstruction() : Instruction() {}
};