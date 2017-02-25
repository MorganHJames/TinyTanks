//\===========================================================================================
//\ File: Vector2.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector2.h.
//\===========================================================================================

#include "Vector2.h"
#include <cmath>

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector2::Vector2() {};//A default constructor that initialises X and Y to 0.

Vector2::Vector2(float a_fX = 0, float a_fY = 0)//Constructor.
{
	fX = a_fX;//Sets the x value of the Vector2 to the first argument passed in on Creation.
	fY = a_fY;//Sets the y value of the Vector2 to the second argument passed in on Creation.
};

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Vector2::getfX()//A getter to get the x part of Vector2.
{
	return fX;//Returns the fX of this Vector2.
}

float Vector2::getfY()//A getter to get the y part of Vector2.
{
	return fY;//Returns the fY of this Vector2.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector2::setfX(const float &a_fX)//A setter to set the x part of Vector2 to the passed in argument.
{
	fX = a_fX;//Makes this Vector2's fX value equal to the passed in argument.
}

void Vector2::setfY(const float &a_fY)//A setter to set the y part of Vector2 to the passed in argument.
{
	fY = a_fY;//Makes this Vector2's fY value equal to the passed in argument.
}

//\===========================================================================================
//\ Operation Overloads
//\===========================================================================================

Vector2 Vector2::operator+(const float &a_fScalar)//Overloaded addition operation for Vector2.
{
	return Vector2(fX + a_fScalar, fY + a_fScalar);//Returns x + number, y + number.
}

Vector2 Vector2::operator+(const Vector2 &a_vVector2)//Overloaded addition operation for Vector2.
{
	return Vector2(fX + a_vVector2.fX, fY + a_vVector2.fY);//Returns Ax + Bx, Ay + By.
}

Vector2 Vector2::operator-(const float &a_fScalar)//Overloaded subtraction operation for Vector2.
{
	return Vector2(fX - a_fScalar, fY - a_fScalar);//Returns x - number, y - number.
}

Vector2 Vector2::operator-(const Vector2 &a_vVector2)//Overloaded subtraction operation for Vector2.
{
	return Vector2(fX - a_vVector2.fX, fY - a_vVector2.fY);//Returns Ax - Bx, Ay - By.
}

Vector2 Vector2::operator*(const float &a_fScalar)//Overloaded multiplication operation for Vector2.
{
	return Vector2(fX * a_fScalar, fY * a_fScalar);//Returns x * number, y * number.
}

Vector2 Vector2::operator*(const Vector2 &a_vVector2) //Overloaded multiplication operation for Vector2.
{
	return Vector2(fX * a_vVector2.fX, fY * a_vVector2.fY);//Returns Ax * Bx, Ay * By.
}

Vector2 Vector2::operator/(const float &a_fScalar)//Overloaded division operation for Vector2.
{
	return Vector2(fX / a_fScalar, fY / a_fScalar);//Returns x / number, y / number.
}

Vector2 Vector2::operator/(const Vector2 &a_vVector2) //Overloaded division operation for Vector2.
{
	return Vector2(fX / a_vVector2.fX, fY / a_vVector2.fY);//Returns Ax / Bx, Ay / By.
}

Vector2 Vector2::operator!=(const float &a_fScalar)//Overloaded not equals operation for Vector2.
{
	return Vector2(fX != a_fScalar, fY != a_fScalar);//Returns x != number, y != number.
}

Vector2 Vector2::operator!=(const Vector2 &a_vVector2) //Overloaded not equals operation for Vector2.
{
	return Vector2(fX != a_vVector2.fX, fY != a_vVector2.fY);//Returns Ax != Bx, Ay != By.
}

Vector2 Vector2::operator==(const float &a_fScalar)//Overloaded is equals operation for Vector2.
{
	return Vector2(fX == a_fScalar, fY == a_fScalar);//Returns x == number, y == number.
}

Vector2 Vector2::operator==(const Vector2 &a_vVector2) //Overloaded is equals operation for Vector2.
{
	return Vector2(fX == a_vVector2.fX, fY == a_vVector2.fY);//Returns Ax == Bx , Ay == By.
}

//\===========================================================================================
//\ Length
//\===========================================================================================

float Vector2::length()//A function that returns the length of the vector as a float.
{
	return sqrt(fX * fX + fY * fY);//Returns the square root of ( x^2 + y^2 ).
}

//\===========================================================================================
//\ Squared Length
//\===========================================================================================

float Vector2::squaredLength()//A function that returns the length squared of the vector as a float.
{
	return (fX * fX + fY * fY);//Returns ( x^2 + y^2 ).
}

//\===========================================================================================
//\ Distance Between this Vector2 and another Vector2
//\===========================================================================================

float Vector2::distance(const Vector2 &a_vVector2)//Returns the distance from this Vector2 and the passed in argument.
{
	return sqrt(((fX - a_vVector2.fX) * (fX - a_vVector2.fX)) + ((fY - a_vVector2.fY) * (fY - a_vVector2.fY)));//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector2 and another Vector2
//\===========================================================================================

float Vector2::distance(const Vector2 &a_vVector2)//Returns the squared distance from this Vector2 and the passed in argument.
{
	return ((fX - a_vVector2.fX) * (fX - a_vVector2.fX)) + ((fY - a_vVector2.fY) * (fY - a_vVector2.fY));//Returns ( Ax - Bx )^2 + ( Ay - By )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector2::dotProduct(const Vector2 &a_vVector2) //A dot product function that takes in a Vector2.
{
	return (fX * a_vVector2.fX) + (fY * a_vVector2.fY);//Returns ( Ax * Bx ) + ( Ay * By ).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

float Vector2::crossProduct(const Vector2 &a_vVector2)//A dot product function that takes in a Vector.
{
	return ((fX * a_vVector2.fY) - (a_vVector2.fX * fY));//Returns ( Ax * By ) - ( BX * Ay ).
}

//\===========================================================================================
//\ Perpendicular
//\===========================================================================================

Vector2 Vector2::perpendicularClockwise()//A perpendicularClockwise function for this Vector2.
{
	return Vector2(-fY, fX);//Returns -y, x.
}

Vector2 Vector2::perpendicularCounterClockwise()//A perpendicularCounterClockwise function for this Vector2.
{
	return Vector2(fY, -fX);//Returns y, -x.
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector2::rotate(const float fAngle)//A Rotate function that takes in an angle in float format.
{
	float fXTemp = (fX * cosf(fAngle)) - (fY * sinf(fAngle));//Creates a temporary float equal to the rotated version of that number.
	float fYTemp = (fX * sinf(fAngle)) + (fY * cosf(fAngle));//Creates a temporary float equal to the rotated version of that number.
	fX = fXTemp;//Assigns Vector2's X to the temporary X.
	fY = fYTemp;//Assigns Vector2's Y to the temporary Y.
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector2::magnitude()//A magnitude function that returns a float.
{
	return sqrtf(fX * fX + fY * fY)//Returns the square root of x^2 + y^2.
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

void Vector2::normalise()//A normalisation function that sets the fX and fY of Vector2 to a normalised version.
{
	fX = fX / magnitude();//Sets the fX of Vector2 to the fX of Vector2 divided by Vector2's magnitude.
	fY = fY / magnitude();//Sets the fY of Vector2 to the fY of Vector2 divided by Vector2's magnitude.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector2 Vector2::unit()//A function that returns a unit vector created from this vector.
{
	return (fX / magnitude() , fY / magnitude());//Returns a normalised version of this Vector2.
}