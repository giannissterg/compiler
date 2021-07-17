#pragma once

#include <tuple>
#include <string>
#include "mapper.h"
#include "ast/variable.h"

class VariableMapper : public Mapper<std::tuple<std::string, std::string>, Variable>
{
public:
	Variable toDomain(std::tuple<std::string, std::string> dataModel)
	{
		std::string type = std::get<0>(dataModel);
		std::string name = std::get<1>(dataModel);
		return Variable(name, type);
	}
	std::tuple<std::string, std::string> fromDomain(Variable variable)
	{
		return { variable.getType().value(), variable.getName() };
	}
};