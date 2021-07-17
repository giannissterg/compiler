#pragma once

template <class T>
class Allocator
{
public:
	virtual T* allocate(size_t n) = 0;
	virtual bool deallocate(T* p, size_t n) = 0;
};