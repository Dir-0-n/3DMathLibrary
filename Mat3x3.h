#pragma once

#include "Mappings.h"

namespace Spectra::Math
{
	template <typename T>
	class Mat3x3 {
	public:
		T m[3][3];

		Mat3x3()
		{
			memset(m, 0, sizeof(m[0][0]) * 3 * 3);
		}

		Mat3x3(const T diagonal)
		{
			memset(m, 0, sizeof(m[0][0]) * 3 * 3);
			m[0][0] = m[1][1] = m[2][2] = diagonal;
		}

		Mat3x3(const T& num1, const T& num2, const T& num3, const T& num4, const T& num5, const T& num6, const T& num7, const T& num8, const T& num9)
		{
			m[0][0] = num1;
			m[0][1] = num2;
			m[0][2] = num3;
			m[1][0] = num4;
			m[1][1] = num5;
			m[1][2] = num6;
			m[2][0] = num7;
			m[2][1] = num8;
			m[2][2] = num9;
		}

		Mat3x3(const Vector3<T>& vx, const Vector3<T>& vy, const Vector3<T>& vz)
		{
			m[0][0] = vx.x;
			m[0][1] = vx.y;
			m[0][2] = vx.z;
			m[1][0] = vy.x;
			m[1][1] = vy.y;
			m[1][2] = vy.z;
			m[2][0] = vz.x;
			m[2][1] = vz.y;
			m[2][2] = vz.z;
		}

		Mat3x3& Zero()
		{
			memset(m, 0, sizeof(m[0][0]) * 3 * 3);
			return *this;
		}

		Mat3x3& Identity()
		{
			m[0][0] = m[1][1] = m[2][2] = 1.0f;
			return *this;
		}

		Vector3<T> GetRow(int i) const
		{
			return Vector3<T>(m[i][0], m[i][1], m[i][2]);
		}

		Mat3x3& SetRow(int i, const Vector3<T>& column)
		{
			m[i][0] = column.x;
			m[i][1] = column.y;
			m[i][2] = column.z;

			return *this;
		}

		Mat3x3& operator*=(const Mat3x3& m2)
		{
			//Row 1
			Vector3<T> row1(m[0][0], m[0][1], m[0][2]);
			m[0][0] = row1.x * m2[0][0] + row1.y * m2[1][0] + row1.z * m2[2][0];
			m[0][1] = row1.x * m2[0][1] + row1.y * m2[1][1] + row1.z * m2[2][1];
			m[0][2] = row1.x * m2[0][2] + row1.y * m2[1][2] + row1.z * m2[2][2];

			//Row 2
			Vector3<T> row2(m[1][0], m[1][1], m[1][2]);
			m[1][0] = row2.x * m2[0][0] + row2.y * m2[1][0] + row2.z * m2[2][0];
			m[1][1] = row2.x * m2[0][1] + row2.y * m2[1][1] + row2.z * m2[2][1];
			m[1][2] = row2.x * m2[0][2] + row2.y * m2[1][2] + row2.z * m2[2][2];

			//Row 3
			Vector3<T> row3(m[2][0], m[2][1], m[2][2]);
			m[2][0] = row3.x * m2[0][0] + row3.y * m2[1][0] + row3.z * m2[2][0];
			m[2][1] = row3.x * m2[0][1] + row3.y * m2[1][1] + row3.z * m2[2][1];
			m[2][2] = row3.x * m2[0][2] + row3.y * m2[1][2] + row3.z * m2[2][2];

			return *this;
		}

		Mat3x3 operator*(const float& scalar) const
		{
			return Mat3x3(
				scalar * m[0][0], scalar * m[0][1], scalar * m[0][2],
				scalar * m[1][0], scalar * m[1][1], scalar * m[1][2],
				scalar * m[2][0], scalar * m[2][1], scalar * m[2][2]);
		}

		Mat3x3 operator*(const Mat3x3& m2) const
		{
			return Mat3x3(
				m[0][0] * m2[0][0] + m[0][1] * m2[1][0] + m[0][2] * m2[2][0],
				m[0][0] * m2[0][1] + m[0][1] * m2[1][1] + m[0][2] * m2[2][1],
				m[0][0] * m2[0][2] + m[0][1] * m2[1][2] + m[0][2] * m2[2][2],
				m[1][0] * m2[0][0] + m[1][1] * m2[1][0] + m[1][2] * m2[2][0],
				m[1][0] * m2[0][1] + m[1][1] * m2[1][1] + m[1][2] * m2[2][1],
				m[1][0] * m2[0][2] + m[1][1] * m2[1][2] + m[1][2] * m2[2][2],
				m[2][0] * m2[0][0] + m[2][1] * m2[1][0] + m[2][2] * m2[2][0],
				m[2][0] * m2[0][1] + m[2][1] * m2[1][1] + m[2][2] * m2[2][1],
				m[2][0] * m2[0][2] + m[2][1] * m2[1][2] + m[2][2] * m2[2][2]);
		}

		Vector3<T> operator*(const Vector3<T>& v) const
		{
			return Vector3<T>(
				v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
				v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
				v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2]);
		}

		bool operator==(const Mat3x3& m2) const
		{
			return m[0][0] == m2[0][0] && m[0][1] == m2[0][1] && m[0][2] == m2[0][2] && m[1][0] == m2[1][0] && m[1][1] == m2[1][1] && m[1][2] == m2[1][2] && m[2][0] == m2[2][0] && m[2][1] == m2[2][1] && m[2][2] == m2[2][2];
		}

		bool operator!=(const Mat3x3& m2) const
		{
			return m[0][0] != m2[0][0] || m[0][1] != m2[0][1] || m[0][2] != m2[0][2] || m[1][0] != m2[1][0] || m[1][1] != m2[1][1] || m[1][2] != m2[1][2] || m[2][0] != m2[2][0] || m[2][1] != m2[2][1] || m[2][2] != m2[2][2];
		}

		const T* operator[](uint8_t i) const
		{
			return m[i];
		}

		T* operator[](uint8_t i)
		{
			return m[i];
		}

		Mat3x3 Transpose() const
		{
			return Mat3x3(
				Vector3<T>(m[0][0], m[1][0], m[2][0]),
				Vector3<T>(m[0][1], m[1][1], m[2][1]),
				Vector3<T>(m[0][2], m[1][2], m[2][2]));
		}

		float Determinant() const
		{
			return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) + m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
		}

		Mat3x3 Inverse() const
		{
			float determinant = Determinant();

			if (determinant == 0.0f) {
				return Identity(); // Return an identity matrix if the current matrix is singular.
			}

			float inversedDet = 1.0f / determinant;

			// Transposed inverse matrix
			return Mat3x3(
				(m[1][1] * m[2][2] - m[1][2] * m[2][1]) * inversedDet,
				-(m[0][1] * m[2][2] - m[0][2] * m[2][1]) * inversedDet,
				(m[0][1] * m[1][2] - m[0][2] * m[1][1]) * inversedDet,
				-(m[1][0] * m[2][2] - m[1][2] * m[2][0]) * inversedDet,
				(m[0][0] * m[2][2] - m[0][2] * m[2][0]) * inversedDet,
				-(m[0][0] * m[1][2] - m[0][2] * m[1][0]) * inversedDet,
				(m[1][0] * m[2][1] - m[1][1] * m[2][0]) * inversedDet,
				-(m[0][0] * m[2][1] - m[0][1] * m[2][0]) * inversedDet,
				(m[0][0] * m[1][1] - m[0][1] * m[1][0]) * inversedDet);
		}
	};
}
