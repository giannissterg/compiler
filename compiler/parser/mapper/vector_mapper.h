#pragma once

#include <vector>
#include "mapper.h"

template <class Data, class Domain>
class VectorMapper : Mapper<std::vector<Data>, std::vector<Domain>>
{
public:
	VectorMapper(Mapper<Data, Domain> mapper) : m_mapper(mapper) {}
	std::vector<Domain> toDomain(std::vector<Data> dataList)
	{
		std::vector<Domain> domainList;
		domainList.reserve(dataList.size);
		for (auto& dataModel : dataList)
		{
			domainList.emplace_back(m_mapper.toDomain(dataModel));
		}
		return domainList;
	}
	std::vector<Data> fromDomain(std::vector<Domain> domainList)
	{
		std::vector<Domain> dataList;
		dataList.reserve(domainList.size);
		for (auto& domainEntity : domainList)
		{
			dataList.emplace_back(m_mapper.fromDomain(domainEntity));
		}
		return dataList;
	}
private:
	Mapper<Data, Domain> m_mapper;
};