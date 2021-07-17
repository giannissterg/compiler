#pragma once

template <class T>
class Rule
{
	virtual bool match(Stream<char>* inputStream) = 0;
};