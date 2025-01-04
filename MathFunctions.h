#pragma once

#include <math.h>

//PI defines
#define PI 3.14159265359f 

namespace Spectra
{
	namespace Math
	{
		//Trigonometric Functions
		inline float Sin(const float value)
		{
			return sinf(value);
		}

		inline float Cos(const float value)
		{
			return cosf(value);
		}

		inline float Tan(const float value)
		{
			return tanf(value);
		}

		inline float ASin(const float value)
		{
			return asinf(value);
		}

		inline float ACos(const float value)
		{
			return acosf(value);
		}

		inline float ATan(const float value)
		{
			return atanf(value);
		}

		inline float Max(const float fValueA, const float fValueB)
		{
			return (fValueA > fValueB) ? fValueA : fValueB;
		}

		inline float Min(const float fValueA, const float fValueB)
		{
			return (fValueA < fValueB) ? fValueA : fValueB;
		}

		inline float DegToRad(const float value)
		{
			return static_cast<float>(value) * PI / 180.0f;
		}

		inline float RadToDeg(const float value)
		{
			return static_cast<float>(value) * 180.0f / PI;
		}
	}
}


