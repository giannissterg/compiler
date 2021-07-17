#pragma once

#include "../instruction.h"
#include "../register.h"
#include "../label.h"

class MovInstruction : public Instruction<32>
{

};

class PushInstruction : public Instruction<32>
{
public:
	PushInstruction(Register<32> x86register) : m_register(x86register) {}
private:
	Register<32> m_register;
};

class PopInstruction : public Instruction<32>
{
public:
	PopInstruction(Register<32> x86register) : m_register(x86register) {}
private:
	Register<32> m_register;
};

class CallInstruction : public Instruction<32>
{
public:
	CallInstruction(Label label) : m_label(label) {}
private:
	Label m_label;
};

class RetInstruction : public Instruction<32>
{
public:
	RetInstruction() = default;
};