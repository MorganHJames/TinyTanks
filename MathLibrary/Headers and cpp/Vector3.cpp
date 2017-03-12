//\===========================================================================================
//\ File: Vector3.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector3.h.
//\===========================================================================================

#include "Vector3.h"
#include <cstring>
#include <cmath>
#include "MathUtil.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector3::Vector3() {}//Constructor default that sets all variables to 0.

Vector3::Vector3(float a_c_fX, float a_c_fY, float a_c_fZ) ://Constructor with three scalar values.
	fX(a_c_fX),//Sets the x value of the Vector3 to the first argument passed in on Creation.
	fY(a_c_fY),//Sets the y value of the Vector3 to the second argument passed in on Creation.
	fZ(a_c_fZ)//Sets the z value of the Vector3 to the third argument passed in on Creation.
{
}

Vector3::Vector3(const Vector2 &a_c_vVector2, float a_c_fZ) ://Constructor with a Vector2 and a scalar value.
	fX(a_c_vVector2.getfX()),//Sets the x value of the Vector3 to the first part of the Vector2 passed in.
	fY(a_c_vVector2.getfY()),//Sets the y value of the Vector3 to the second part of the Vector2 passed in.
	fZ(a_c_fZ)//Sets the z value of the Vector3 to the third argument passed in on Creation.
{
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Vector3::getfX()const//A getter to get the x part of Vector3.
{
	return float(fX);//Returns the fX of this Vector3.
}

float Vector3::getfY()const//A getter to get the y part of Vector3.
{
	return float(fY);//Returns the fY of this Vector3.
}

float Vector3::getfZ()const//A getter to get the z part of Vector3.
{
	return float(fZ);//Returns the fZ of this Vector3.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector3::setfX(const float &a_c_fX)//A setter to set the x part of Vector3 to the passed in argument.
{
	fX = a_c_fX;//Makes this Vector3's fX value equal to the passed in argument.
}

void Vector3::setfY(const float &a_c_fY)//A setter to set the y part of Vector3 to the passed in argument.
{
	fY = a_c_fY;//Makes this Vector3's fY value equal to the passed in argument.
}
void Vector3::setfZ(const float &a_c_fZ)//A setter to set the z part of Vector3 to the passed in argument.
{
	fY = a_c_fZ;//Makes this Vector3's fZ value equal to the passed in argument.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Vector3 Vector3::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Vector3.
{
	return Vector3(//Returns x + number, y + number, z + number.
		fX + a_c_fScalar,
		fY + a_c_fScalar,
		fZ + a_c_fScalar);
}

Vector3 Vector3::operator+(const Vector3 &a_c_vVector3)const//Overloaded addition operation for Vector3.
{
	return Vector3(//Returns Ax + Bx, Ay + By, Az + Bz.
		fX + a_c_vVector3.fX,
		fY + a_c_vVector3.fY,
		fZ + a_c_vVector3.fZ);
}

Vector3 Vector3::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Vector3.
{
	return Vector3(//Returns x - number, y - number, z - number.
		fX - a_c_fScalar,
		fY - a_c_fScalar,
		fZ - a_c_fScalar);
}

Vector3 Vector3::operator-(const Vector3 &a_c_vVector3)const//Overloaded subtraction operation for Vector3.
{
	return Vector3(//Returns Ax - Bx, Ay - By, Az - Bz.
		fX - a_c_vVector3.fX,
		fY - a_c_vVector3.fY,
		fZ - a_c_vVector3.fZ);
}

Vector3 Vector3::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Vector3.
{
	return Vector3(//Returns x * number, y * number, z * number.
		fX * a_c_fScalar,
		fY * a_c_fScalar,
		fZ * a_c_fScalar);
}

Vector3 Vector3::operator*(const Vector3 &a_c_vVector3)const//Overloaded multiplication operation for Vector3.
{
	return Vector3(//Returns Ax * Bx, Ay * By, Az * Bz.
		fX * a_c_vVector3.fX,
		fY * a_c_vVector3.fY,
		fZ * a_c_vVector3.fZ);
}

Vector3 Vector3::operator/(const float &a_c_fScalar)const//Overloaded division operation for Vector3.
{
	return Vector3(//Returns x / number, y / number, z / number.
		*this * reciprocal(a_c_fScalar));
}

Vector3 Vector3::operator/(const Vector3 &a_c_vVector3)const//Overloaded division operation for Vector3.
{
	return Vector3(//Returns Ax / Bx, Ay / By, Az / Bz.
		fX / a_c_vVector3.fX,
		fY / a_c_vVector3.fY,
		fZ / a_c_vVector3.fZ);
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Vector3 Vector3::operator+=(const float &a_c_fScalar)//Overloaded plus equals operation for Vector3.
{
	return Vector3(//Returns x += number, y += number, z += number.
		*this = *this + a_c_fScalar);
}

Vector3 Vector3::operator+=(const Vector3 &a_c_vVector3)//Overloaded plus equals operation for Vector3.
{
	return Vector3(//Returns Ax += Bx, Ay += By, Az += Bz.
		*this = *this + a_c_vVector3);
}

Vector3 Vector3::operator-=(const float &a_c_fScalar)//Overloaded decrease equals operation for Vector3.
{
	return Vector3(//Returns x -= number, y -= number, z -= number.
		*this = *this - a_c_fScalar);
}

Vector3 Vector3::operator-=(const Vector3 &a_c_vVector3)//Overloaded decrease equals operation for Vector3.
{
	return Vector3(//Returns Ax -= Bx, Ay -= By, Az -= Bz.
		*this = *this - a_c_vVector3);
}

Vector3 Vector3::operator=(const float &a_c_fScalar)//Overloaded equals operation for Vector3.
{
	return Vector3(//Returns x = number, y = number, z = number.
		fX = a_c_fScalar,
		fY = a_c_fScalar,
		fZ = a_c_fScalar);
}

Vector3 Vector3::operator=(const Vector3 &a_c_vVector3)//Overloaded equals operation for Vector3.
{
	return Vector3(//Returns Ax = Bx, Ay = By, Az = Bz.
		fX = a_c_vVector3.fX,
		fY = a_c_vVector3.fY,
		fZ = a_c_vVector3.fZ);
}

Vector3 Vector3::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Vector3.
{
	return Vector3(//Returns x *= number, y *= number, z *= number.
		*this = *this * a_c_fScalar);
}

Vector3 Vector3::operator*=(const Vector3 &a_c_vVector3)//Overloaded times equals operation for Vector3.
{
	return Vector3(//Returns Ax *= Bx, Ay *= By, Az *= Bz.
		*this = *this * a_c_vVector3);
}

Vector3 Vector3::operator/=(const float &a_c_fScalar)//Overloaded divide equals operation for Vector3.
{
	return Vector3(//Returns x /= number, y /= number, z /= number.
		*this = *this / a_c_fScalar);
}

Vector3 Vector3::operator/=(const Vector3 &a_c_vVector3)//Overloaded divide equals operation for Vector3.
{
	return Vector3(//Returns Ax /= Bx, Ay /= By, Az /= Bz.
		*this = *this / a_c_vVector3);
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Vector3::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Vector3.
{
	return bool(//Returns x != number || y != number || z != number.
		fX != a_c_fScalar ||
		fY != a_c_fScalar ||
		fZ != a_c_fScalar);
}

bool Vector3::operator!=(const Vector3 &a_c_vVector3)const//Overloaded not equals operation for Vector3.
{
	return bool(//Returns Ax != Bx || Ay != By || Az != Bz.
		fX != a_c_vVector3.fX ||
		fY != a_c_vVector3.fY ||
		fZ != a_c_vVector3.fZ);
}

bool Vector3::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Vector3.
{
	return bool(//Returns x == number && y == number && z == number.
		fX == a_c_fScalar &&
		fY == a_c_fScalar &&
		fZ == a_c_fScalar);
}

bool Vector3::operator==(const Vector3 &a_c_vVector3)const//Overloaded is equals operation for Vector3.
{
	return bool(//Returns Ax == Bx && Ay == By && Az == Bz.
		fX == a_c_vVector3.fX &&
		fY == a_c_vVector3.fY &&
		fZ == a_c_vVector3.fZ);
}

//\===========================================================================================
//\ Inverse
//\===========================================================================================

Vector3 Vector3::inverse()const//Returns the inverse of this vector3.
{
	return(*this * -1);
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector3::magnitude()const//A magnitude function that returns a float.
{
	return float(sqrtf(fX * fX + fY * fY + fZ * fZ));//Returns the square root of x^2 + y^2 + z^2
}

//\===========================================================================================
//\ Squared Magnitude
//\===========================================================================================

float Vector3::squaredMagnitude()const//A function that returns the Magnitude squared of the vector as a float.
{
	return float(fX * fX + fY * fY + fZ * fZ);//Returns ( x^2 + y^2 + z^2 ).
}

//\===========================================================================================
//\ Distance Between this Vector3 and another Vector3
//\===========================================================================================

float Vector3::distance(const Vector3 &a_c_vVector3)const//Returns the distance from this Vector3 and the passed in argument.
{
	return float((*this - a_c_vVector3).magnitude());//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector3 and another Vector3
//\===========================================================================================

float Vector3::squaredDistance(const Vector3 &a_c_vVector3)const//Returns the squared distance from this Vector3 and the passed in argument.
{
	return float((*this - a_c_vVector3).squaredMagnitude());//Returns ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector3::dotProduct(const Vector3 &a_c_vVector3)const//A dot product function that takes in a Vector3.
{
	return float((fX * a_c_vVector3.fX) + (fY * a_c_vVector3.fY) + (fZ * a_c_vVector3.fZ));//Returns ( Ax * Bx ) + ( Ay * By ) + ( Az * Bz ).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

Vector3 Vector3::crossProduct(const Vector3 &a_c_vVector3)const//A cross product function that takes in a Vector3 .
{
	return Vector3(//Returns cross product using formula = ( a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1 ).
		fY * a_c_vVector3.fZ - fZ * a_c_vVector3.fY,
		fZ * a_c_vVector3.fX - fX * a_c_vVector3.fZ,
		fX * a_c_vVector3.fY - fY * a_c_vVector3.fX);
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector3::rotateZ(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
	float fXTemp = fX;//A temporary value for x as it will change after assignment.
	fX = (fX * cosf(a_fAngle)) - (fY * sinf(a_fAngle));//Assigns the x value to x * cos(number) - y * sin(number).
	fY = (fXTemp * sinf(a_fAngle)) + (fY * cosf(a_fAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

void Vector3::rotateX(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
	float fYTemp = fY;//A temporary value for y as it will change after assignment.
	fY = (fY * cosf(a_fAngle)) - (fZ * sinf(a_fAngle));//Assigns the y value to y * cos(number) - z * sin(number).
	fZ = (fYTemp * sinf(a_fAngle)) + (fZ * cosf(a_fAngle));//Assigns the z value to y * sin(number) + z * cos(number).
}

void Vector3::rotateY(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
	float fZTemp = fZ;//A temporary value for z as it will change after assignment.
	fZ = (fZ * cosf(a_fAngle)) - (fX * sinf(a_fAngle));//Assigns the z value to z * cos(number) - x * sin(number).
	fX = (fZTemp * sinf(a_fAngle)) + (fX * cosf(a_fAngle));//Assigns the x value to z * sin(number) + x * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector3 Vector3::normalise()//A normalisation function that sets the fX, fY and fZ of Vector3 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	return Vector3(//Returns a normalised version of this vector.
		fX *= fMulti,//Sets the fX of Vector3 to the fX of Vector3 divided by Vector3's magnitude.
		fY *= fMulti,//Sets the fY of Vector3 to the fY of Vector3 divided by Vector3's magnitude.
		fZ *= fMulti);//Sets the fZ of Vector3 to the fZ of Vector3 divided by Vector3's magnitude.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector3 Vector3::unit()const//A function that returns a unit vector created from this vector.
{
	Vector3 vTemp = *this;//Creates a temporary vector equal to the current Vector3.
	vTemp.normalise();//Normalises the temporary vector.
	return (vTemp);//Returns a copy of a normalised version of this Vector3.
}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Vector3::setZero()//Makes each Vector3 element equal to 0. 
{//Set each element in the Vector3 to zero.
	fX = 0;
	fY = 0;
	fZ = 0;
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Vector3 Vector3::zero()const//Returns a Vector3 zero matrix.
{
	Vector3 temp;
	temp.setZero();
	return Vector3(temp);
}