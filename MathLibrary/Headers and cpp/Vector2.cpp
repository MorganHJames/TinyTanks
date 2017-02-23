//\===========================================================================================
//\ File: Vector2.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector2.h.
//\===========================================================================================


#include "Vector2.h"
//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector2::Vector2(float a_fX = 0, float a_fY = 0)//Constructor.
{
	fX = a_fX;//Sets the x value of the vector2 to the first argument passed in on Creation.
	fY = a_fY;//Sets the y value of the vector2 to the second argument passed in on Creation.
};

//\===========================================================================================
//\ Destructor
//\===========================================================================================

Vector2::~Vector2() {};

//\===========================================================================================
//\ Operation Overloads
//\===========================================================================================

Vector2 Vector2::operator+(const float &a_fScalar)//Overloaded addition operation for Vector2.
{
	return Vector2(fX + a_fScalar, fY + a_fScalar);//Returns the value of the addition.
}

Vector2 Vector2::operator+(const Vector2 &a_vVector2)//Overloaded addition operation for Vector2.
{
	return Vector2(fX + a_vVector2.fX, fY + a_vVector2.fY);//Returns the value of the addition.
}

Vector2 Vector2::operator-(const float &a_fScalar)//Overloaded subtraction operation for Vector2.
{
	return Vector2(fX - a_fScalar, fY - a_fScalar);//Returns the value of the subtraction.
}

Vector2 Vector2::operator-(const Vector2 &a_vVector2)//Overloaded subtraction operation for Vector2.
{
	return Vector2(fX - a_vVector2.fX, fY - a_vVector2.fY);//Returns the value of the subtraction.
}

Vector2 Vector2::operator*(const float &a_fScalar)//Overloaded multiplication operation for Vector2.
{
	return Vector2(fX * a_fScalar, fY * a_fScalar);//Returns the value of the multiplication.
}

Vector2 Vector2::operator*(const Vector2 &a_vVector2) //Overloaded multiplication operation for Vector2.
{
	return Vector2(fX * a_vVector2.fX, fY * a_vVector2.fY);//Returns the value of the multiplication.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector2::dotProduct(const Vector2 &a_vVector2) //A dot product function that takes in a Vector2.
{
	return (fX*a_vVector2.fX) + (fY*a_vVector2.fY);//Returns the value of the dot product.
}

//\===========================================================================================
//\ Perpendicular
//\===========================================================================================

Vector2 Vector2::perpendicularClockwise(const Vector2 &a_vVector2)//A perpendicularClockwise function that takes in a Vector 2.
{
	return Vector2(-a_vVector2.fY, a_vVector2.fX);//Returns a Vector2 containing the perpendicularClockwise of the passed in Vector2.
}

Vector2 Vector2::perpendicularCounterClockwise(const Vector2 &a_vVector2)//A perpendicularCounterClockwise function that takes in a Vector 2.
{
	return Vector2(a_vVector2.fY, -a_vVector2.fX);//Returns a Vector2 containing the perpendicularCounterClockwise of the passed in Vector2.
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector2::rotate(const float fAngle)//A Rotate function that takes in an angle in float format.
{
	float fXTemp = (fX * cosf(fAngle)) - (fY * sinf(fAngle));//Creates a temporary float equal to the rotated version of that number.
	float fYTemp = (fY * cosf(fAngle)) + (fX * sinf(fAngle));//Creates a temporary float equal to the rotated version of that number.
	fX = fXTemp;//Assigns Vector2's X to the temporary X.
	fY = fYTemp;//Assigns Vector2's Y to the temporary Y.
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector2::magnitude()//A magnitude function that returns a float.
{
	return sqrtf(fX * fX + fY * fY)//Returns the square root of x^2 + y^2
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

void Vector2::normalise()//A normalisation function that sets the fX and fY of Vector2 to a normalised version.
{
	this->fX = fX / magnitude();//Sets the fX of Vector2 to the fX of Vector2 divided by Vector2's magnitude.
	this->fY = fY / magnitude();//Sets the fY of Vector2 to the fY of Vector2 divided by Vector2's magnitude.
}