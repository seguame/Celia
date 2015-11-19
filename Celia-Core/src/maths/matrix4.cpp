#include "matrix4.h"


namespace celia { namespace maths {

		Matrix4::Matrix4(void)
		{
			memset(elements, 0, (sizeof(float) * 4 * 4));
		}

		Matrix4::Matrix4(float diagonal) : Matrix4()
		{
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		Matrix4 Matrix4::identity(void)
		{
			return Matrix4(1.0f);
		}

		Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			Matrix4 result; //(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);
			result.elements[3 + 3 * 4] = 1.0f;

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		Matrix4 Matrix4::perspective(float fov, float aspectRatio, float near, float far) 
		{
			Matrix4 result;

			float q = 1.0f / tan(to_radians(0.5f * fov));
			float a = q / aspectRatio;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = -1.0f;
			result.elements[2 + 3 * 4] = c;

			return result;
		}

		Matrix4 Matrix4::translation(const Vect3& translation)
		{
			Matrix4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			return result;
		}


		Matrix4 Matrix4::rotation(float angle, const Vect3& axis)
		{
			Matrix4 result(1.0f);

			float r = to_radians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;
			
			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc  + c;

			return result;

		}
		
		Matrix4 Matrix4::scale(const Vect3& scale)
		{
			Matrix4 result;

			result.elements[0 + 3 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;
			result.elements[3 + 3 * 4] = 1.0f;

			return result;
		}

		Matrix4 operator*(const Matrix4& left, const Matrix4& right)
		{
			Matrix4 result;

			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += left.elements[x + e * 4] * right.elements[e + y * 4];
					}

					result.elements[x + y * 4] = sum;
				}
			}

			return result;
		}

		Matrix4& Matrix4::operator*=(const Matrix4& right) 
		{
			*this = *this * right;
			return *this;
		}
} }