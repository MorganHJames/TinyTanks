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

Vector2::Vector2() {}//A default constructor that initialises X and Y to 0.

Vector2::Vector2(const float a_c_fX, float a_c_fY)://Constructor.
	fX(a_c_fX),//Sets the x value of the Vector2 to the first argument passed in on Creation.
	fY(a_c_fY)//Sets the y value of the Vector2 to the second argument passed in on Creation.
{}

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Vector2::getfX()const//A getter to get the x part of Vector2.
{
	return fX;//Returns the fX of this Vector2.
}

float Vector2::getfY()const//A getter to get the y part of Vector2.
{
	return fY;//Returns the fY of this Vector2.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector2::setfX(const float &a_c_fX)//A setter to set the x part of Vector2 to the passed in argument.
{
	fX = a_c_fX;//Makes this Vector2's fX value equal to the passed in argument.
}

void Vector2::setfY(const float &a_c_fY)//A setter to set the y part of Vector2 to the passed in argument.
{
	fY = a_c_fY;//Makes this Vector2's fY value equal to the passed in argument.
}

//\===========================================================================================
//\ Operation Overloads
//\===========================================================================================

Vector2 Vector2::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Vector2.
{
	return Vector2(
		fX + a_c_fScalar,
		fY + a_c_fScalar);//Returns x + number, y + number.
}

Vector2 Vector2::operator+(const Vector2 &a_c_vVector2)const//Overloaded addition operation for Vector2.
{
	return Vector2(
		fX + a_c_vVector2.fX,
		fY + a_c_vVector2.fY);//Returns Ax + Bx, Ay + By.
}

Vector2 Vector2::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Vector2.
{
	return Vector2(
		fX - a_c_fScalar,
		fY - a_c_fScalar);//Returns x - number, y - number.
}

Vector2 Vector2::operator-(const Vector2 &a_c_vVector2)const//Overloaded subtraction operation for Vector2.
{
	return Vector2(
		fX - a_c_vVector2.fX,
		fY - a_c_vVector2.fY);//Returns Ax - Bx, Ay - By.
}

Vector2 Vector2::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Vector2.
{
	return Vector2(
		fX * a_c_fScalar,
		fY * a_c_fScalar);//Returns x * number, y * number.
}

Vector2 Vector2::operator*(const Vector2 &a_c_vVector2)const//Overloaded multiplication operation for Vector2.
{
	return Vector2(
		fX * a_c_vVector2.fX,
		fY * a_c_vVector2.fY);//Returns Ax * Bx, Ay * By.
}

Vector2 Vector2::operator/(const float &a_c_fScalar)const//Overloaded division operation for Vector2.
{
	float fMulti = 1 / a_c_fScalar;//Allows for multiplication rather than division.
	return Vector2(
		fX * fMulti,
		fY * fMulti);//Returns x * 1 / number, y * 1 / number.
}

Vector2 Vector2::operator/(const Vector2 &a_c_vVector2)const//Overloaded division operation for Vector2.
{
	return Vector2(
		fX / a_c_vVector2.fX,
		fY / a_c_vVector2.fY);//Returns Ax / Bx, Ay / By.
}

bool Vector2::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Vector2.
{
	return bool(
		fX != a_c_fScalar ||
		fY != a_c_fScalar);//Returns x != number && y != number.
}

bool Vector2::operator!=(const Vector2 &a_c_vVector2)const//Overloaded not equals operation for Vector2.
{
	return bool(
		fX != a_c_vVector2.fX ||
		fY != a_c_vVector2.fY);//Returns Ax != Bx && Ay != By.
}

bool Vector2::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Vector2.
{
	return bool(
		fX == a_c_fScalar &&
		fY == a_c_fScalar);//Returns x == number && y == number.
}

bool Vector2::operator==(const Vector2 &a_c_vVector2)const//Overloaded is equals operation for Vector2.
{
	return bool(
		fX == a_c_vVector2.fX &&
		fY == a_c_vVector2.fY);//Returns Ax == Bx && Ay == By.
}

Vector2 Vector2::operator=(const float &a_c_fScalar)//Overloaded equals operation for Vector2.
{
	return Vector2(
		fX = a_c_fScalar
		, fY = a_c_fScalar);//Returns x = number, y = number.
}

Vector2 Vector2::operator=(const Vector2 &a_c_vVector2)//Overloaded equals operation for Vector2.
{
	return Vector2(
		fX = a_c_vVector2.fX,
		fY = a_c_vVector2.fY);//Returns Ax = Bx, Ay = By.
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector2::magnitude()const//A magnitude function that returns a float.
{
	return sqrtf(fX * fX + fY * fY);//Returns the square root of x^2 + y^2.
}

//\===========================================================================================
//\ Squared Length
//\===========================================================================================

float Vector2::squaredMagnitude()const//A function that returns the length squared of the vector as a float.
{
	return (fX * fX + fY * fY);//Returns ( x^2 + y^2 ).
}

//\===========================================================================================
//\ Distance Between this Vector2 and another Vector2
//\===========================================================================================

float Vector2::distance(const Vector2 &a_c_vVector2)const//Returns the distance from this Vector2 and the passed in argument.
{
	return (*this - a_c_vVector2).magnitude();//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector2 and another Vector2
//\===========================================================================================

float Vector2::squaredDistance(const Vector2 &a_c_vVector2)const//Returns the squared distance from this Vector2 and the passed in argument.
{
	return (*this - a_c_vVector2).squaredMagnitude();//Returns ( Ax - Bx )^2 + ( Ay - By )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector2::dotProduct(const Vector2 &a_c_vVector2)const//A dot product function that takes in a Vector2.
{
	return (fX * a_c_vVector2.fX) + (fY * a_c_vVector2.fY);//Returns ( Ax * Bx ) + ( Ay * By ).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

float Vector2::crossProduct(const Vector2 &a_c_vVector2)const//A dot product function that takes in a Vector.
{
	return ((fX * a_c_vVector2.fY) - (a_c_vVector2.fX * fY));//Returns ( Ax * By ) - ( BX * Ay ).
}

//\===========================================================================================
//\ Perpendicular
//\===========================================================================================

Vector2 Vector2::perpendicularClockwise()const//A perpendicularClockwise function for this Vector2.
{
	return Vector2(
		-fY,
		fX);//Returns -y, x.
}

Vector2 Vector2::perpendicularCounterClockwise()const//A perpendicularCounterClockwise function for this Vector2.
{
	return Vector2(
		fY,
		-fX);//Returns y, -x.
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector2::rotate(const float a_c_fDegAngle)//A Rotate function that takes in an angle in float format.
{
	float fRadAngle = a_c_fDegAngle * (PI / 180);//Creates a float equal to the conversion of the degree angle to radians.
	float fXTemp = fX;//A temporary value for x as it will change after assignment.
	fX = (fX * cosf(fRadAngle)) - (fY * sinf(fRadAngle));//Assigns the x value to x * cos(number) - y * sin(number).
	fY = (fXTemp * sinf(fRadAngle)) + (fY * cosf(fRadAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector2 Vector2::normalise()//A normalisation function that sets the fX and fY of Vector2 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	fX *= fMulti;//Sets the fX of Vector2 to the fX of Vector2 divided by Vector2's magnitude.
	fY *= fMulti;//Sets the fY of Vector2 to the fY of Vector2 divided by Vector2's magnitude.
	return Vector2(*this);//Returns a normalised version of this vector.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector2 Vector2::unit()const//A function that returns a unit vector created from this vector.
{
	Vector2 vTemp = *this;//Creates a temporary vector equal to the current Vector 2.
	vTemp.normalise();//Normalises the temporary vector.
	return (vTemp);//Returns a copy of a normalised version of this Vector2.
}