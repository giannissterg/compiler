#pragma once

template <class Data, class Domain>
class Mapper
{
	virtual Domain toDomain(Data data) = 0;
	virtual Data fromDomain(Domain domain) = 0;
};