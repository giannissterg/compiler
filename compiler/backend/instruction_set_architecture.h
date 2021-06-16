#pragma once

#include <array>
#include "instruction.h"
#include "register.h"

template<class Size, size_t N> 
class InstructionSetArchitecture
{
private:
	std::vector<Instruction<Size>> m_instructionSet;
	std::array<Register, N> m_generalPurposeRegisters;
	Register m_programCounter;
};