#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Mat
{
public:

	template<typename T>
	static _vec<T> rotate(const _vec<T> vec, const int thetta)
	{
		const double pi = std::acos(-1);
		const float cosT = std::cos(pi / 180 * thetta);
		const float sinT = std::sin(pi / 180 * thetta);

		const float rtt[2][2] = {{cosT,-sinT},
								 {+sinT,cosT}};
		return _vec<T>(vec.x*rtt[0][0] + vec.y*rtt[0][1], vec.x*rtt[1][0] + vec.y*rtt[1][1]);
	}

	template<typename T>
	static _vec<T> conv(_vec<T> vec)
	{
		return _vec<T>( (vec.x + 1) * Graphics::ScreenWidth/2, (vec.y + 1) * Graphics::ScreenHeight / 2);
	}
};