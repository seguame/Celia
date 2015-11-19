#pragma once

#include <iostream>

namespace celia { namespace maths {

	struct Vect2
	{
		float x;
		float y;

		Vect2( void );
		Vect2(const float x, const float y);

		friend Vect2 operator+(Vect2 left, const Vect2& right);
		friend Vect2 operator-(Vect2 left, const Vect2& right);
		friend Vect2 operator/(Vect2 left, const Vect2& right);
		friend Vect2 operator*(Vect2 left, const Vect2& right);

		bool operator==(const Vect2& other);
		bool operator!=(const Vect2& other);
		Vect2& operator+=(const Vect2& right);
		Vect2& operator-=(const Vect2& right);
		Vect2& operator*=(const Vect2& right);
		Vect2& operator/=(const Vect2& right);

		friend std::ostream& operator<<(std::ostream& stream, const Vect2& vector);
	};
} }