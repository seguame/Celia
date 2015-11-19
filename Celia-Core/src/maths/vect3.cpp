#include "Vect3.h"

namespace celia { namespace maths 
{
	Vect3::Vect3( void )
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vect3::Vect3(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vect3 operator+(Vect3 left, const Vect3& right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;

		return left;
	}

	Vect3 operator-(Vect3 left, const Vect3& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;

		return left;
	}


	Vect3 operator*(Vect3 left, const Vect3& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		left.z *= right.z;

		return left;
	}

	Vect3 operator/(Vect3 left, const Vect3& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		left.z /= right.z;

		return left;
	}

	Vect3& Vect3::operator+=(const Vect3& right)
	{
		*this = *this + right;
		return *this;
	}

	Vect3& Vect3::operator-=(const Vect3& right)
	{
		*this = *this - right;
		return *this;
	}

	Vect3& Vect3::operator*=(const Vect3& right)
	{
		*this = *this * right;
		return *this;
	}

	Vect3& Vect3::operator/=(const Vect3& right)
	{
		*this = *this / right;
		return *this;
	}

	bool Vect3::operator==(const Vect3& other) 
	{
		return x == other.x && y == other.y  && z == other.z;
	}

	bool Vect3::operator!=(const Vect3& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<< (std::ostream & stream, const Vect3 & vector)
	{
		stream << "Vect3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}}