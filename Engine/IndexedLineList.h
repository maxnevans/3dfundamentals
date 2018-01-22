#pragma once
#include <vector>
#include "Vec3.h"

struct IndexedLineList
{
	std::vector<_vec3<float>> vertices;
	std::vector<size_t> indicies;
};