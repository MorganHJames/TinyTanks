//\===========================================================================================
//\ File: Vector2.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector2 class declarations.
//\===========================================================================================

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <math.h>
//\===========================================================================================
//\ Author: Morgan James
//\ Class: Vector2
//\ Brief:Overloaded operator functions for add, subtract, and multiply by both a scalar 
//\ value and by a Vector2.
//\ Functions to allow for dot product, perpendicular, rotation, magnitude, normalisation.
//\===========================================================================================

class Vector2
{
public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector2(float a_fX = 0, float a_fY = 0);//Constructor.

	//\===========================================================================================
	//\ Destructor
	//\===========================================================================================

	~Vector2();

	//\===========================================================================================
	//\ Operation Overloads
	//\===========================================================================================

	Vector2 operator+(const float &a_fScalar);//Overloaded addition operation for Vector2.

	Vector2 operator+(const Vector2 &a_vVector2);//Overloaded addition operation for Vector2.

	Vector2 operator-(const float &a_fScalar);//Overloaded subtraction operation for Vector2.
	
	Vector2 operator-(const Vector2 &a_vVector2);//Overloaded subtraction operation for Vector2.

	Vector2 operator*(const float &a_fScalar);//Overloaded multiplication operation for Vector2.

	Vector2 operator*(const Vector2 &a_vVector2);//Overloaded multiplication operation for Vector2.

	//\===========================================================================================
	//\ Dot Product
	//\===========================================================================================
	
	float dotProduct(const Vector2 &a_vVector2);//A dot product function that takes in a Vector2.

	//\===========================================================================================
	//\ Perpendicular
	//\===========================================================================================
	
	Vector2 perpendicularClockwise(const Vector2 &a_vVector2);//A perpendicularClockwise function that takes in a Vector 2.

	Vector2 perpendicularCounterClockwise(const Vector2 &a_vVector2);//A perpendicularCounterClockwise function that takes in a Vector 2.

	//\===========================================================================================
	//\ Rotation
	//\===========================================================================================

	void rotate(const float fAngle);//A Rotate function that takes in an angle in float format.

	//\===========================================================================================
	//\ Magnitude
	//\===========================================================================================

	float magnitude();//A magnitude function that returns a float.

	//\===========================================================================================
	//\ Normalisation
	//\===========================================================================================

	void normalise();//A normalisation function that sets the fX and fY of Vector2 to a normalised version.

private:
	float fX, fY;//Coordinate storage.
};

#endif
