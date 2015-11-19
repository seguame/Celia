#include "Vect4.h"

namespace celia { namespace maths 
{
	Vect4::Vect4( void )
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	Vect4::Vect4(const float x, const float y, const float z, const float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vect4 operator+(Vect4 left, const Vect4& right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		left.w += right.w;

		return left;
	}

	Vect4 operator-(Vect4 left, const Vect4& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		left.w -= right.w;

		return left;
	}


	Vect4 operator*(Vect4 left, const Vect4& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		left.z *= right.z;
		left.w *= right.w;

		return left;
	}

	Vect4 operator/(Vect4 left, const Vect4& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		left.z /= right.z;
		left.w /= right.w;

		return left;
	}

	Vect4& Vect4::operator+=(const Vect4& right)
	{
		*this = *this + right;
		return *this;
	}

	Vect4& Vect4::operator-=(const Vect4& right)
	{
		*this = *this - right;
		return *this;
	}

	Vect4& Vect4::operator*=(const Vect4& right)
	{
		*this = *this * right;
		return *this;
	}

	Vect4& Vect4::operator/=(const Vect4& right)
	{
		*this = *this / right;
		return *this;
	}

	bool Vect4::operator==(const Vect4& other) 
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool Vect4::operator!=(const Vect4& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<< (std::ostream & stream, const Vect4 & vector)
	{
		stream << "Vect4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}
}}