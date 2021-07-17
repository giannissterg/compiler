#pragma once

#include <array>
#include "instruction.h"
#include "register.h"

template<class Size, size_t N> 
class InstructionSetArchitecture
{
private:
	std::vector<Instruction<Size>> m_instructionSet;
	std::array<Register<32>, N> m_generalPurposeRegisters;
	Register<32> m_programCounter;
	std::array<FlagRegister, 8> m_flagRegisters;
};