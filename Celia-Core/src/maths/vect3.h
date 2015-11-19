#pragma once

#include <iostream>

namespace celia { namespace maths {

	struct Vect3
	{
		float x;
		float y;
		float z;

		Vect3( void );
		Vect3(const float x, const float y, const float z);

		friend Vect3 operator+(Vect3 left, const Vect3& right);
		friend Vect3 operator-(Vect3 left, const Vect3& right);
		friend Vect3 operator/(Vect3 left, const Vect3& right);
		friend Vect3 operator*(Vect3 left, const Vect3& right);

		bool operator==(const Vect3& other);
		bool operator!=(const Vect3& other);
		Vect3& operator+=(const Vect3& right);
		Vect3& operator-=(const Vect3& right);
		Vect3& operator*=(const Vect3& right);
		Vect3& operator/=(const Vect3& right);

		friend std::ostream& operator<<(std::ostream& stream, const Vect3& vector);
	};
} }