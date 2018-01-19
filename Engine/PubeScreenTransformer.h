#pragma once
#include "Vec3.h"
#include "Graphics.h"

class PubeScreenTransformer
{
public:
	PubeScreenTransformer()
		:
		xFactor(float(Graphics::ScreenWidth) / 2.0f),
		yFactor(float(Graphics::ScreenHeight) / 2.0f)
	{}
	_vec<float>& Transform(_vec3<float>& input) const
	{
		input.x = (input.x/input.z + 1)*xFactor;
		input.y = (-input.y/input.z + 1)*yFactor;

		return input;
	}
	_vec<float> GetTransformed(const _vec3<float>& input) const
	{
		return Transform(_vec3<float>(input));
	}
private:
	float xFactor;
	float yFactor;
};