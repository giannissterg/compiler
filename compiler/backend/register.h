#pragma once

#include <string>

template <size_t Bits>
class Register
{
private:
	std::bitset<Bits> m_bits;
};

