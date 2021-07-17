#pragma once

#include "mapper.h"

class CharacterMapper : public Mapper<char, char>
{
public:
	char toDomain(char dataModel) { return dataModel; }
	char fromDomain(char domainEntity) { return domainEntity; }
};