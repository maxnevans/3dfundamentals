#pragma once
#include "Vec3.h"
#include "Graphics.h"

template<typename T>
class Mat
{
public:
	Mat operator*(const Mat& rhs) const
	{
		Mat temp = {0};
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					temp.elements[i][j] += elements[i][k] * rhs.elements[k][j];
				}
			}
		}
		return temp;
	}
	Mat& operator*=(const Mat& rhs)
	{
		*this = *this*rhs;
		return *this;
	}
	Mat operator*(const T alpha) const
	{
		Mat temp(elements);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				temp *= alpha;
			}
		}
		return temp;
	}
	Mat& operator*=(const T alpha)
	{
		*this = *this * alpha;
		return *this;
	}
	
	static Mat Identity()
	{
		return {
			(T) 1.0, (T) 0.0, (T) 0.0,
			(T) 0.0, (T) 1.0, (T) 0.0,
			(T) 0.0, (T) 0.0, (T) 1.0
		};
	}
	static Mat Scale(const T factor)
	{
		return Identity * factor;
	}
	static Mat RotateZ(const T theta)
	{
		const double cosT = cos(theta);
		const double sinT = sin(theta);
		return {
			(T) cosT, (T) -sinT, (T) 0.0,
			(T) sinT, (T) cosT,  (T) 0.0,
			(T)  0.0, (T)  0.0,  (T) 1.0
		};
	}
	static Mat RotateY(const T theta)
	{
		const double cosT = cos(theta);
		const double sinT = sin(theta);
		return {
			(T)  cosT, (T) 0.0, (T) sinT,
			(T)   0.0, (T) 1.0, (T)  0.0,
			(T) -sinT, (T) 0.0, (T)  cosT
		};
	}
	static Mat RotateX(const T theta)
	{
		const double cosT = cos(theta);
		const double sinT = sin(theta);
		return {
			(T) 1.0, (T)  0.0,  (T) 0.0,
			(T) 0.0, (T) cosT, (T) -sinT,
			(T) 0.0, (T) sinT, (T) cosT
			
		};
	}
public:
	T elements[3][3];
};

template<typename T>
_vec3<T> operator*(const _vec3<T>& lhs, const Mat<T>& rhs)
{
	return {
		lhs.x * rhs.elements[0][0] + lhs.y*rhs.elements[1][0] + lhs.z*rhs.elements[2][0],
		lhs.x * rhs.elements[0][1] + lhs.y*rhs.elements[1][1] + lhs.z*rhs.elements[2][1],
		lhs.x * rhs.elements[0][2] + lhs.y*rhs.elements[1][2] + lhs.z*rhs.elements[2][2]
	};
}

template<typename T>
_vec3<T>& operator*=(_vec3<T>& lhs, const Mat<T>& rhs)
{
	return lhs = lhs * rhs;
}