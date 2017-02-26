//\===========================================================================================
//\ File: Vector3.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector3.h.
//\===========================================================================================

#include "Vector3.h"
#include "Vector2.h"
#include <cmath>

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector3::Vector3() {};//Constructor default that sets all variables to 0.

Vector3::Vector3(float a_fX = 0, float a_fY = 0, float a_fZ = 0)//Constructor with three scalar values.
{
	fX = a_fX;//Sets the x value of the vector3 to the first argument passed in on Creation.
	fY = a_fY;//Sets the y value of the vector3 to the second argument passed in on Creation.
	fZ = a_fZ;//Sets the z value of the vector3 to the third argument passed in on Creation.
};

Vector3::Vector3(Vector2 &a_vVector2, float a_fZ = 0)//Constructor with a Vector2 and a scalar value.
{
	fX = a_vVector2.getfX();//Sets the x value of the vector3 to the first part of the Vector2 passed in.
	fY = a_vVector2.getfY();//Sets the y value of the vector3 to the second part of the Vector2 passed in.
	fZ = a_fZ;//Sets the z value of the vector3 to the third argument passed in on Creation.
};

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Vector3::getfX()//A getter to get the x part of Vector3.
{
	return fX;//Returns the fX of this Vector3.
}

float Vector3::getfY()//A getter to get the y part of Vector3.
{
	return fY;//Returns the fY of this Vector3.
}

float Vector3::getfZ()//A getter to get the z part of vector3.
{
	return fZ;//Returns the fZ of this Vector3.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector3::setfX(float a_fX)//A setter to set the x part of Vector3 to the passed in argument.
{
	fX = a_fX;//Makes this Vector3's fX value equal to the passed in argument.
}

void Vector3::setfY(float a_fY)//A setter to set the y part of Vector3 to the passed in argument.
{
	fY = a_fY;//Makes this Vector3's fY value equal to the passed in argument.
}
void Vector3::setfZ(float a_fZ)//A setter to set the z part of vector3 to the passed in argument.
{
	fY = a_fZ;//Makes this Vector3's fZ value equal to the passed in argument.
}

//\===========================================================================================
//\ Operation Overloads
//\===========================================================================================

Vector3 Vector3::operator+(const float &a_fScalar)//Overloaded addition operation for Vector3.
{
	return Vector3(
		fX + a_fScalar,
		fY + a_fScalar,
		fZ + a_fScalar);//Returns x + number, y + number, z + number.
}

Vector3 Vector3::operator+(const Vector3 &a_vVector3)//Overloaded addition operation for Vector3.
{
	return Vector3(
		fX + a_vVector3.fX,
		fY + a_vVector3.fY,
		fZ + a_vVector3.fZ);//Returns Ax + Bx, Ay + By, Az + Bz.
}

Vector3 Vector3::operator-(const float &a_fScalar)//Overloaded subtraction operation for Vector3.
{
	return Vector3(
		fX - a_fScalar,
		fY - a_fScalar,
		fZ - a_fScalar);//Returns x - number, y - number, z - number.
}

Vector3 Vector3::operator-(const Vector3 &a_vVector3)//Overloaded subtraction operation for Vector3.
{
	return Vector3(
		fX - a_vVector3.fX,
		fY - a_vVector3.fY,
		fZ - a_vVector3.fZ);//Returns Ax - Bx, Ay - By, Az - Bz.
}

Vector3 Vector3::operator*(const float &a_fScalar)//Overloaded multiplication operation for Vector3.
{
	return Vector3(
		fX * a_fScalar,
		fY * a_fScalar,
		fZ * a_fScalar);//Returns x * number, y * number, z * number.
}

Vector3 Vector3::operator*(const Vector3 &a_vVector3)//Overloaded multiplication operation for Vector3.
{
	return Vector3(
		fX * a_vVector3.fX,
		fY * a_vVector3.fY,
		fZ * a_vVector3.fZ);//Returns Ax * Bx, Ay * By, Az * Bz.
}

Vector3 Vector3::operator/(const float &a_fScalar)//Overloaded division operation for Vector3.
{
	float fMulti = 1 / a_fScalar;//Allows for multiplication rather than division.
	return Vector3(
		fX * fMulti,
		fY * fMulti,
		fZ * fMulti);//Returns x / number, y / number, z / number.
}

Vector3 Vector3::operator/(const Vector3 &a_vVector3)//Overloaded division operation for Vector3.
{
	return Vector3(
		fX / a_vVector3.fX,
		fY / a_vVector3.fY,
		fZ / a_vVector3.fZ);//Returns Ax / Bx, Ay / By, Az / Bz.
}

bool Vector3::operator!=(const float &a_fScalar)//Overloaded not equals operation for Vector3.
{
	return bool(fX != a_fScalar || fY != a_fScalar || fZ != a_fScalar);//Returns x != number || y != number || z != number.
}

bool Vector3::operator!=(const Vector3 &a_vVector3)//Overloaded not equals operation for Vector3.
{
	return bool(fX != a_vVector3.fX || fY != a_vVector3.fY || fZ != a_vVector3.fZ);//Returns Ax != Bx || Ay != By || Az != Bz.
}

bool Vector3::operator==(const float &a_fScalar)//Overloaded is equals operation for Vector3.
{
	return bool(fX == a_fScalar&& fY == a_fScalar && fZ == a_fScalar);//Returns x == number && y == number && z == number.
}

bool Vector3::operator==(const Vector3 &a_vVector3)//Overloaded is equals operation for Vector3.
{
	return bool(fX == a_vVector3.fX && fY == a_vVector3.fY && fZ == a_vVector3.fZ);//Returns Ax == Bx && Ay == By && Az == Bz.
}

Vector3 Vector3::operator=(const float &a_fScalar)//Overloaded equals operation for Vector3.
{
	return Vector3(
		fX = a_fScalar,
		fY = a_fScalar,
		fZ = a_fScalar);//Returns x = number, y = number, z = number.
}

Vector3 Vector3::operator=(const Vector3 &a_vVector3)//Overloaded equals operation for Vector3.
{
	return Vector3(
		fX = a_vVector3.fX,
		fY = a_vVector3.fY,
		fZ = a_vVector3.fZ);//Returns Ax = Bx, Ay = By, Az = Bz.
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector3::magnitude()//A magnitude function that returns a float.
{
	return sqrtf(fX * fX + fY * fY + fZ * fZ);//Returns the square root of x^2 + y^2 + z^2
}

//\===========================================================================================
//\ Squared Magnitude
//\===========================================================================================

float Vector3::squaredMagnitude()//A function that returns the Magnitude squared of the vector as a float.
{
	return (fX * fX + fY * fY + fZ * fZ);//Returns ( x^2 + y^2 + z^2 ).
}

//\===========================================================================================
//\ Distance Between this Vector3 and another Vector3
//\===========================================================================================

float Vector3::distance(const Vector3 &a_vVector3)//Returns the distance from this Vector3 and the passed in argument.
{
	return (*this - a_vVector3).magnitude();//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector3 and another Vector3
//\===========================================================================================

float Vector3::squaredDistance(const Vector3 &a_vVector3)//Returns the squared distance from this Vector3 and the passed in argument.
{
	return (*this - a_vVector3).squaredMagnitude();//Returns ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector3::dotProduct(const Vector3 &a_vVector3) //A dot product function that takes in a Vector3.
{
	return (fX * a_vVector3.fX) + (fY * a_vVector3.fY) + (fZ * a_vVector3.fZ);//Returns the value of the dot product.
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

Vector3 Vector3::crossProduct(const Vector3 &a_vVector3)//A cross product function that takes in a Vector3 .
{
	return (
		fY * a_vVector3.fZ - fZ * a_vVector3.fY,
		fZ * a_vVector3.fX - fX * a_vVector3.fZ,
		fX * a_vVector3.fY - fY * a_vVector3.fX);//Returns cross product using formula = ( a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1 )
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector3::rotateZ(const float fAngle)//A Rotate function that takes in an angle in float format.
{
	float fXTemp = fX;//A temporary value for x as it will change after assignment.
	fX = (fX * cosf(fAngle)) - (fY * sinf(fAngle));//Assigns the x value to x * cos(number) - y * sin(number).
	fY = (fXTemp * sinf(fAngle)) + (fY * cosf(fAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

void Vector3::rotateX(const float fAngle)//A Rotate function that takes in an angle in float format.
{
	float fYTemp = fY;//A temporary value for y as it will change after assignment.
	fY = (fY * cosf(fAngle)) - (fZ * sinf(fAngle));//Assigns the y value to y * cos(number) - z * sin(number).
	fZ = (fYTemp * sinf(fAngle)) + (fZ * cosf(fAngle));//Assigns the z value to y * sin(number) + z * cos(number).
}

void Vector3::rotateY(const float fAngle)//A Rotate function that takes in an angle in float format.
{
	float fZTemp = fZ;//A temporary value for z as it will change after assignment.
	fZ = (fZ * cosf(fAngle)) - (fX * sinf(fAngle));//Assigns the z value to z * cos(number) - x * sin(number).
	fX = (fZTemp * sinf(fAngle)) + (fX * cosf(fAngle));//Assigns the x value to z * sin(number) + x * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector3 Vector3::normalise()//A normalisation function that sets the fX and fY of Vector3 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	fX *= fMulti;//Sets the fX of Vector3 to the fX of Vector3 divided by Vector3's magnitude.
	fY *= fMulti;//Sets the fY of Vector3 to the fY of Vector3 divided by Vector3's magnitude.
	fY *= fMulti;//Sets the fZ of Vector3 to the fZ of Vector3 divided by Vector3's magnitude.
	return Vector3(*this);//Returns a normalised version of this vector.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector3 Vector3::unit()//A function that returns a unit vector created from this vector.
{
	Vector3 vTemp = *this;//Creates a temporary vector equal to the current Vector3.
	vTemp.normalise();//Normalises the temporary vector.
	return (vTemp);//Returns a copy of a normalised version of this Vector3.
}