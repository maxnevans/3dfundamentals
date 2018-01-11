#pragma once
#include <cmath>

template<typename T>
class _vec
{
public:
	_vec() = default;
	_vec(T x, T y)
		:
		x(x),
		y(y)
	{
	}
	T length()
	{
		return x * x + y * y;
	}
	T length_sqrt()
	{
		return (T) std::sqrt(length());
	}
	_vec operator-(const _vec& v) const
	{
		return _vec(x - v.x, y - v.y);
	}
public:
	T x;
	T y;
};

typedef _vec<int> Vei2;