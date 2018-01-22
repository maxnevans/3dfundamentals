#pragma once
#include <vector>
#include "Vec3.h"
#include <assert.h>

class IndexedTriangleList
{
public:
	IndexedTriangleList(std::vector<_vec3<float>> verts_in, std::vector<size_t> ind_in)
		:
		vertices(std::move( verts_in )),
		indices(std::move( ind_in ))
	{
		assert(indices.size()>2);
		assert(indices.size() % 3 == 0);
		cullFlags.resize(indices.size()/3, false);
	}
	std::vector<_vec3<float>> vertices;
	std::vector<size_t> indices;
	std::vector<bool> cullFlags;
};