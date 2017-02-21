////////////////////////////////////////////////////////////
// File: Spice  Invader
// Author: Morgan James
// Date Created: 26th November 2016
// Brief: A retro 2D arcade game based on Space Invaders
////////////////////////////////////////////////////////////

#include "Matrix4x4.h"


namespace Matrix4x4
{
	double Matrix4x4::Add(double a, double b)
	{
		return a + b;
	}

	double Matrix4x4::Subtract(double a, double b)
	{
		return a - b;
	}

	double Matrix4x4::Multiply(double a, double b)
	{
		return a * b;
	}

	double Matrix4x4::Divide(double a, double b)
	{
		return a / b;
	}
}
