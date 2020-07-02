#pragma once

#include <array>

class Type {};

class Object {};

class Digit;

template<size_t N>
class Number
{
private:
	std::array<Digit, N> m_representation;
};

class Digit
{
private:

};

class 