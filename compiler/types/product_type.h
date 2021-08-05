#pragma once

class Type {};

class Unit : Type 
{
public:
	Unit() = default;
};

template <class A, class B>
class ProductType : public Type {};

template <class A, class B>
class ExponentialType : public Type {};

template <class A, class B>
class SumType : public Type 
{
public:
	SumType(A& a) : m_type(a) {}
	SumType(B& b) : m_type(b) {}
private:
	std::variant<A, B> m_type;
};

class NumberType : public Type {};

class CharacterType : public Type {};

class BooleanType : public ProductType<Unit, Unit> {};

template <class A>
class ListType : public SumType<Unit, ProductType<A, ListType<A>>> 
{
};

template <class A>
class TreeType : public SumType<Unit, ProductType<A, ProductType<TreeType<A>, TreeType<A>>>> {};