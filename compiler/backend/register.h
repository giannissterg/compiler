#pragma once

#include <string>
#include <bitset>

template <size_t Bits>
class Register
{
public:
	Register(std::string identifier) : m_identifier(identifier) {}
protected:
	std::string m_identifier;
	std::bitset<Bits> bits;
};

class FlagRegister : Register<1>
{
};

class SignRegister : FlagRegister {};
class ZeroRegister : FlagRegister {};
class CarryRegister : FlagRegister {};
class OverflowRegister : FlagRegister {};

class ByteRegister : Register<8>
{

};

class WordRegister : Register<16>
{

};

class EAX : Register<32>
{
public:
};

class AX : Register<16>
{
public:
};

class AH : Register<8>
{

};

class AL : Register<8>
{

};
