////////////////////////////////////////////////////////////
// File: Spice  Invader
// Author: Morgan James
// Date Created: 26th November 2016
// Brief: A retro 2D arcade game based on Space Invaders
////////////////////////////////////////////////////////////

#ifndef _MATRIX3X3_H_
#define _MATRIX3X3_H_


namespace Matrix3x3
{
	class Matrix3x3
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
