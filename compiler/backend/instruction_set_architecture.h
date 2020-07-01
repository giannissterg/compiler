#pragma once

#include <array>
#include "instruction.h"
#include "register.h"

template<class Size> 
class InstructionSetArchitecture
{
private:
	std::vector<Instruction<Size>> m_instructionSet;
	std::array<Register, Size> m_generalPurposeRegisters;
	Register m_programCounter;
};