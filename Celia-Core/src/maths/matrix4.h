#pragma once

#include "mathematics.h"

namespace celia { namespace maths {
	
	struct Matrix4
	{
		float elements[4 * 4];

		Matrix4( void );
		Matrix4( float diagonal );

		static Matrix4 identity( void );
		static Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far);
		static Matrix4 perspective(float fov, float aspectRatio, float near, float far);
		static Matrix4 translation(const Vect3& translation);
		static Matrix4 rotation(float angle, const Vect3& axis);
		static Matrix4 scale(const Vect3& scale);

		friend Matrix4 operator*(const Matrix4& left, const Matrix4& right);
		Matrix4& operator*=(const Matrix4& right);
	};
} }