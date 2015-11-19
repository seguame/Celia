#pragma once

#include <iostream>

namespace celia { namespace maths {

	struct Vect4
	{
		float x;
		float y;
		float z;
		float w;

		Vect4( void );
		Vect4(const float x, const float y, const float z, const float w);

		friend Vect4 operator+(Vect4 left, const Vect4& right);
		friend Vect4 operator-(Vect4 left, const Vect4& right);
		friend Vect4 operator/(Vect4 left, const Vect4& right);
		friend Vect4 operator*(Vect4 left, const Vect4& right);

		bool operator==(const Vect4& other);
		bool operator!=(const Vect4& other);
		Vect4& operator+=(const Vect4& right);
		Vect4& operator-=(const Vect4& right);
		Vect4& operator*=(const Vect4& right);
		Vect4& operator/=(const Vect4& right);

		friend std::ostream& operator<<(std::ostream& stream, const Vect4& vector);
	};
} }