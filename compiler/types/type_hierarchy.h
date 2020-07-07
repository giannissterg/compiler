#pragma once

#include <array>

class Type {};

class object {};

class digit;

template<size_t N>
class number
{
private:
	std::array<digit, N> m_representation;
};

template<size_t Base>
class digit
{
	digit()
private:

};

class 