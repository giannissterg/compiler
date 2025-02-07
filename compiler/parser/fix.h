#pragma once

template<template<typename> class F>
class Fix : public F<Fix<F>>
{
public:
    explicit Fix(F<Fix<F>> f) : F<Fix<F>>(f) {}
};

template<template<typename> class F>
Fix<F> Fx(F<Fix<F>> f)
{
    return Fix<F>{f};
}

template<template<typename> class F>
F<Fix<F>> unFix(Fix<F> f)
{
    return f;
}