#pragma once
#include "Matrix44.h"

#define USING_OPENGL 0

namespace Spectra {
	namespace Math {
		inline Matrix44 Perspective(const float& fovY, const float& aspect, const float& nearZ, const float& farZ)
		{
			Matrix44 result;
			float zoom = tanf(fovY * 0.5f);

#if USING_OPENGL == 0
			// DirectX perspective projection matrix (left-handed)
			result[0][0] = 1.0f / (zoom * aspect);
			result[1][1] = 1.0f / zoom;
			result[2][2] = farZ / (farZ - nearZ);
			result[2][3] = 1.0f;
			result[3][2] = -nearZ * farZ / (farZ - nearZ);
#else
			// OpenGL perspective projection matrix (right-handed)
			result[0][0] = 1.0f / (zoom * aspect);
			result[1][1] = 1.0f / zoom;
			result[2][2] = -(farZ + nearZ) / (farZ - nearZ);
			result[2][3] = -1.0f;
			result[3][2] = (-2.0f * farZ * nearZ) / (farZ - nearZ);
#endif

			return result;
		}

		inline Matrix44 Orthographic(const float& left, const float& right, const float& bottom, const float& top, const float& nearZ, const float& farZ)
		{
			Matrix44 result(1.0f);

#if USING_OPENGL == 0
			// DirectX orthographic projection matrix (left-handed)
			result[0][0] = 2.0f / (right - left);
			result[1][1] = 2.0f / (top - bottom);
			result[2][2] = 1.0f / (farZ - nearZ);
			result[3][2] = nearZ / (nearZ - farZ);
#else
			// OpenGL orthographic projection matrix (right-handed)
			result[0][0] = 2.0f / (right - left);
			result[1][1] = 2.0f / (top - bottom);
			result[2][2] = -2.0f / (farZ - nearZ);
			result[0][3] = -(right + left) / (right - left);
			result[1][3] = -(top + bottom) / (top - bottom);
			result[2][3] = -(farZ + nearZ) / (farZ - nearZ);
#endif

			return result;
		}
	} // end namespace Math
} // end namespace Spectra