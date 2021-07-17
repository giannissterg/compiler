#pragma once

#include "mapper.h"

class DigitMapper : public Mapper<char, int>
{
public:
	int toDomain(char dataModel) { return static_cast<int>(dataModel) - '0'; }
	char fromDomain(int domainModel) { return domainModel + '0'; }
};