////////////////////////////////////////////////////////////
// File: Spice  Invader
// Author: Morgan James
// Date Created: 26th November 2016
// Brief: A retro 2D arcade game based on Space Invaders
////////////////////////////////////////////////////////////

#ifndef _MATRIX4X4_H_
#define _MATRIX4X4_H_


namespace Matrix4x4
{
	class Matrix4x4
	{
	public:
		// Returns a + b
		static double Add(double a, double b);

		// Returns a - b
		static double Subtract(double a, double b);

		// Returns a * b
		static double Multiply(double a, double b);

		// Returns a / b
		static double Divide(double a, double b);
	};
}
#endif
