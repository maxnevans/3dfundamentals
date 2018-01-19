#pragma once
#include "Vec2.h"

template<typename T>
class _vec3 : public _vec<T>
{
public:
	_vec3(const T x, const T y, const T z)
		:
		_vec<T>(x, y),
		z(z)
	{}
	template<typename S>
	_vec3(_vec3<S> vec)
		:
		x((T)vec.x),
		y((T)vec.y),
		z((T)vec.z)
	{}
	template<typename S>
	_vec3(S x, S y, S z)
		:
		x((T)x),
		y((T)y),
		z((T)z)
	{}
	T length()
	{
		return x * x + y * y + z*z;
	}
	T length_sqrt()
	{
		return (T)std::sqrt(length());
	}
	_vec3 operator-(const _vec3& v) const
	{
		return _vec(x - v.x, y - v.y, z - z*v.z);
	}
	_vec3 operator+(const _vec3& v) const
	{
		return _vec3(x + v.x, y + v.y, z + v.z);
	}
	_vec3& operator+=(const _vec3& v)
	{
		return *this = *this + v;
	}
	_vec3 operator*(const T alpha) const
	{
		return _vec3(x*alpha, y*alpha, z*alpha);
	}
	_vec3& operator*=(const T alpha)
	{
		x *= alpha;
		y *= alpha;
		z *= alpha;
		return this;
	}
public:
	T z;
};