#pragma once

#include "function.h"

template <class A>
class Functor
{
public:
	virtual ~Functor() = 0;
	template <class B>
	virtual Functor<B> map(Function<A, B> function) = 0;
};

template <class A>
class List : Functor<A>
{
public:
	List(std::vector<A> list) : m_list(list) {}
	template <class B>
	List<B> map(Function function)
	{
		List<B> b;
		for (A& object : m_list)
		{
		}
		return b;
	}
private:
	std::vector<A> m_list;
};