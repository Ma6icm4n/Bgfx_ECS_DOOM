#pragma once
#include "Maths.h"

class Vec4 {
public:
	float x, y, z, w;

	Vec4(): x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

	Vec4(float x, float y, float z) : x(x), y(y), z(z), w(0.0f) {}

	Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	Vec4(const float* ax, float ang) {
		float scalar = Maths::sin(ang / 2.0f);
		x = ax[0] * scalar;
		y = ax[1] * scalar;
		z = ax[2] * scalar;
		w = Maths::cos(ang / 2.0f);
	}

	Vec4 operator+(Vec4 const& v) const
	{
		return Vec4(
			x + v.x,
			y + v.y,
			z + v.z,
			w + v.w);
	}

	Vec4 operator+=(Vec4 const& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}

	Vec4 operator-(Vec4 const& v) const
	{
		return Vec4(
			x - v.x,
			y - v.y,
			z - v.z,
			w - v.w);
	}

	Vec4 operator-=(Vec4 const& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}





};