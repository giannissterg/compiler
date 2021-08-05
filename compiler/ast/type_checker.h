#pragma once

#include <string>
#include "variable.h"
#include "types/product_type.h"
#include "abstract_syntax_tree.h"

template <class T>
class TypeChecker
{
public:
	virtual bool typeCheck(T type, std::string identifier) = 0;
};

template<class A, class B>
class ProductTypeChecker : public TypeChecker<ProductType<A,B>>
{
public:
	ProductTypeChecker(TypeChecker<A> t1, TypeChecker<B> t2) : t1(t1), t2(t2) {}
	bool typeCheck(ProductType<A, B> type, std::string identifier)
	{
		t1.typeCheck(first);
		t2.typeCheck(second);
		return true; 
	}
private:
	TypeChecker<A> t1;
	TypeChecker<B> t2;
};

template<class A, class B>
class SumTypeChecker : public TypeChecker<SumType<A, B>>
{
public:
	SumTypeChecker(TypeChecker<A> t1, TypeChecker<B> t2) : t1(t1), t2(t2) {}
	bool typeCheck(SumType<A, B> type, std::string identifier)
	{
		t1.typeCheck(type.first());
		t2.typeCheck(type.second());
		return true;
	}
private:
	TypeChecker<A> t1;
	TypeChecker<B> t2;
};