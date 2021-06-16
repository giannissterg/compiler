#pragma once

#include "product_type.h"

template <class A, class B>
class TypeEquivalence
{
public:
	virtual B equivalent(A a) = 0;
};

template <class A, class B, class C>
class ProductAssociativity : public TypeEquivalence<ProductType<A, ProductType<B, C>>, ProductType<ProductType<A, B>, C>>
{
public:
	ProductType<ProductType<A, B>, Ck equivalent(ProductType<A, ProductType<B, C>> object) {}
};

template <class A, class B, class C>
class SumAssociativity : public TypeEquivalence<SumType<A, SumType<B, C>>, SumType<SumType<A, B>, C>>
{
	SumType<SumType<A, B>, C> equivalent(SumType<A, SumType<B, C>> object) {}

};