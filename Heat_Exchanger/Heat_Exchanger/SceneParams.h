#pragma once
#include "BuildParams.h"

struct SceneParams {

	bool edges = false;
	int lightType = 1;
	bool section = false;
	int plain = 2;
	std::vector<std::uint32_t> hideIndexes = std::vector<std::uint32_t>{ CASE_ITEMNAME };
};