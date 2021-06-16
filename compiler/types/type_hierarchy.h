#pragma once

#include <array>


class object {};

template<size_t Base>
class digit
{
	digit() {}

};

template<size_t N>
class number
{
private:
	std::array<digit<10>, N> m_representation;
};

