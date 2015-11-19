#include "vect2.h"

namespace celia { namespace maths 
{
	Vect2::Vect2( void )
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vect2::Vect2(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	Vect2 operator+(Vect2 left, const Vect2& right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}

	Vect2 operator-(Vect2 left, const Vect2& right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}


	Vect2 operator*(Vect2 left, const Vect2& right)
	{
		left.x *= right.x;
		left.y *= right.y;

		return left;
	}

	Vect2 operator/(Vect2 left, const Vect2& right)
	{
		left.x /= right.x;
		left.y /= right.y;

		return left;
	}

	Vect2& Vect2::operator+=(const Vect2& right)
	{
		*this = *this + right;
		return *this;
	}

	Vect2& Vect2::operator-=(const Vect2& right)
	{
		*this = *this - right;
		return *this;
	}

	Vect2& Vect2::operator*=(const Vect2& right)
	{
		*this = *this * right;
		return *this;
	}

	Vect2& Vect2::operator/=(const Vect2& right)
	{
		*this = *this / right;
		return *this;
	}

	bool Vect2::operator==(const Vect2& other) 
	{
		return x == other.x && y == other.y;
	}

	bool Vect2::operator!=(const Vect2& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<< (std::ostream & stream, const Vect2 & vector)
	{
		stream << "Vect2: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}
}}