////////////////////////////////////////////////////////////
// File: Spice  Invader
// Author: Morgan James
// Date Created: 26th November 2016
// Brief: A retro 2D arcade game based on Space Invaders
////////////////////////////////////////////////////////////

#ifndef _VECTOR2_H_
#define _VECTOR2_H_


namespace Vector2
{
	class Vector2
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
