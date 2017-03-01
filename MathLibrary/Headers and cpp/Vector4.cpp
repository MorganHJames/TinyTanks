//\===========================================================================================
//\ File: Vector4.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector4.h.
//\===========================================================================================

#include "Vector4.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector4::Vector4() {}//Constructor default that sets all variables to 0.

Vector4::Vector4(const float a_c_fX, float a_c_fY, float a_c_fZ, float a_c_fW)://Constructor with four scalar values.
	fX(a_c_fX),//Sets the x value of the Vector4 to the first argument passed in on Creation.
	fY(a_c_fY),//Sets the y value of the Vector4 to the second argument passed in on Creation.
	fZ(a_c_fZ),//Sets the z value of the Vector4 to the third argument passed in on Creation.
	fW(a_c_fW)//Sets the w value of the Vector4 to the fourth argument passed in on Creation.
{}

Vector4::Vector4(const Vector2 &a_c_vVector2, float a_c_fZ, float a_c_fW)://Constructor with a Vector2 and two scalar value.
	fX(a_c_vVector2.getfX()),//Sets the x value of the Vector4 to the first part of the Vector2 passed in.
	fY(a_c_vVector2.getfY()),//Sets the y value of the Vector4 to the second part of the Vector2 passed in.
	fZ(a_c_fZ),//Sets the z value of the Vector4 to the second argument passed in on Creation.
	fW(a_c_fW)//Sets the w value of the Vector4 to the third argument passed in on Creation.
{}

Vector4::Vector4(const Vector3 &a_c_vVector3, float a_c_fW)://Constructor with a Vector3 and a scalar value.
	fX(a_c_vVector3.getfX()),//Sets the x value of the Vector4 to the first part of the Vector3 passed in.
	fY(a_c_vVector3.getfY()),//Sets the y value of the Vector4 to the second part of the Vector3 passed in.
	fZ(a_c_vVector3.getfZ()),//Sets the z value of the Vector4 to the third part of the Vector3 passed in.
	fW(a_c_fW)//Sets the w value of the Vector4 to the second argument passed in on Creation.
{}

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Vector4::getfX()const//A getter to get the x part of Vector4.
{
	return fX;//Returns the fX of this Vector4.
}

float Vector4::getfY()const//A getter to get the y part of Vector4.
{
	return fY;//Returns the fY of this Vector4.
}

float Vector4::getfZ()const//A getter to get the z part of Vector4.
{
	return fZ;//Returns the fZ of this Vector4.
}

float Vector4::getfW()const//A getter to get the w part of Vector4.
{
	return fW;//Returns the fW of this Vector4.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector4::setfX(const float a_c_fX)//A setter to set the x part of Vector4 to the passed in argument.
{
	fX = a_c_fX;//Makes this Vector4's fX value equal to the passed in argument.
}

void Vector4::setfY(const float a_c_fY)//A setter to set the y part of Vector4 to the passed in argument.
{
	fY = a_c_fY;//Makes this Vector4's fY value equal to the passed in argument.
}

void Vector4::setfZ(const float a_c_fZ)//A setter to set the z part of Vector4 to the passed in argument.
{
	fY = a_c_fZ;//Makes this Vector4's fZ value equal to the passed in argument.
}

void Vector4::setfW(const float a_c_fW)//A setter to set the w part of Vector4 to the passed in argument.
{
	fW = a_c_fW;//Makes this Vector4's fW value equal to the passed in argument.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Vector4 Vector4::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Vector4.
{
	return Vector4(
		fX + a_c_fScalar,
		fY + a_c_fScalar,
		fZ + a_c_fScalar,
		fW + a_c_fScalar);//Returns x + number, y + number, z + number, w + number.
}

Vector4 Vector4::operator+(const Vector4 &a_c_vVector4)const//Overloaded addition operation for Vector4.
{
	return Vector4(
		fX + a_c_vVector4.fX,
		fY + a_c_vVector4.fY,
		fZ + a_c_vVector4.fZ,
		fW + a_c_vVector4.fW);//Returns Ax + Bx, Ay + By, Az + Bz, Aw + Bw.
}

Vector4 Vector4::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Vector4.
{
	return Vector4(
		fX - a_c_fScalar,
		fY - a_c_fScalar,
		fZ - a_c_fScalar,
		fW - a_c_fScalar);//Returns x - number, y - number, z - number, w - number.
}

Vector4 Vector4::operator-(const Vector4 &a_c_vVector4)const//Overloaded subtraction operation for Vector4.
{
	return Vector4(
		fX - a_c_vVector4.fX,
		fY - a_c_vVector4.fY,
		fZ - a_c_vVector4.fZ,
		fW - a_c_vVector4.fW);//Returns Ax - Bx, Ay - By, Az - Bz, Aw - Bw.
}

Vector4 Vector4::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Vector4.
{
	return Vector4(
		fX * a_c_fScalar,
		fY * a_c_fScalar,
		fZ * a_c_fScalar,
		fW * a_c_fScalar);//Returns x * number, y * number, z * number, w * number.
}

Vector4 Vector4::operator*(const Vector4 &a_c_vVector4)const//Overloaded multiplication operation for Vector4.
{
	return Vector4(
		fX * a_c_vVector4.fX,
		fY * a_c_vVector4.fY,
		fZ * a_c_vVector4.fZ,
		fW * a_c_vVector4.fW);//Returns Ax * Bx, Ay * By, Az * Bz, Aw * Bw.
}

Vector4 Vector4::operator/(const float &a_c_fScalar)const//Overloaded division operation for Vector4.
{
	float fMulti = 1 / a_c_fScalar;//Allows for multiplication rather than division.
	return Vector4(
		fX * fMulti,
		fY * fMulti,
		fZ * fMulti,
		fW * fMulti);//Returns x / number, y / number, z / number, w / number.
}

Vector4 Vector4::operator/(const Vector4 &a_c_vVector4)const//Overloaded division operation for Vector4.
{
	return Vector4(
		fX / a_c_vVector4.fX,
		fY / a_c_vVector4.fY,
		fZ / a_c_vVector4.fZ,
		fW / a_c_vVector4.fW);//Returns Ax / Bx, Ay / By, Az / Bz, Aw / Bw.
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Vector4 Vector4::operator=(const float &a_c_fScalar)//Overloaded equals operation for Vector4.
{
	return Vector4(
		fX = a_c_fScalar,
		fY = a_c_fScalar,
		fZ = a_c_fScalar,
		fW = a_c_fScalar);//Returns Ax = number, Ay = number, Az = number, Aw = number.
}

Vector4 Vector4::operator=(const Vector4 &a_c_vVector4)//Overloaded equals operation for Vector4.
{
	return Vector4(
		fX = a_c_vVector4.fX,
		fY = a_c_vVector4.fY,
		fZ = a_c_vVector4.fZ,
		fW = a_c_vVector4.fW);//Returns Ax = Bx, Ay = By, Az = Bz, Aw = Bw.
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Vector4::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Vector4.
{
	return bool(
		fX != a_c_fScalar ||
		fY != a_c_fScalar ||
		fZ != a_c_fScalar ||
		fW != a_c_fScalar);//Returns x != number || y != number || z != number || w != number.
}

bool Vector4::operator!=(const Vector4 &a_c_vVector4)const//Overloaded not equals operation for Vector4.
{
	return bool(
		fX != a_c_vVector4.fX ||
		fY != a_c_vVector4.fY ||
		fZ != a_c_vVector4.fZ ||
		fW != a_c_vVector4.fW);//Returns Ax != Bx || Ay != By || Az != Bz || Aw != Bw.
}

bool Vector4::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Vector4.
{
	return bool(
		fX == a_c_fScalar &&
		fY == a_c_fScalar &&
		fZ == a_c_fScalar &&
		fW == a_c_fScalar);//Returns x == number && y == number && z == number && w == number.
}

bool Vector4::operator==(const Vector4 &a_c_vVector4)const//Overloaded is equals operation for Vector4.
{
	return bool(
		fX == a_c_vVector4.fX &&
		fY == a_c_vVector4.fY &&
		fZ == a_c_vVector4.fZ && 
		fW == a_c_vVector4.fW);//Returns Ax == Bx && Ay == By && Az == Bz && Aw == Bw.
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector4::magnitude()const//A magnitude function that returns a float.
{
	return sqrtf(fX * fX + fY * fY + fZ * fZ + fW * fW);//Returns the square root of x^2 + y^2 + z^2 + w^2.
}

//\===========================================================================================
//\ Squared Magnitude
//\===========================================================================================

float Vector4::squaredMagnitude()const//A function that returns the Magnitude squared of the vector as a float.
{
	return (fX * fX + fY * fY + fZ * fZ + fW * fW);//Returns x^2 + y^2 + z^2 + w^2.
}

//\===========================================================================================
//\ Distance Between this Vector4 and another Vector4
//\===========================================================================================

float Vector4::distance(const Vector4 &a_c_vVector4)const//Returns the distance from this Vector4 and the passed in argument.
{
	return (*this - a_c_vVector4).magnitude();//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2 + ( Aw - Bw )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector4 and another Vector4
//\===========================================================================================

float Vector4::squaredDistance(const Vector4 &a_c_vVector4)const//Returns the squared distance from this Vector4 and the passed in argument.
{
	return (*this - a_c_vVector4).squaredMagnitude();//Returns ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2 + ( Aw - Bw )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector4::dotProduct(const Vector4 &a_c_vVector4)const//A dot product function that takes in a Vector4.
{
	return (fX * a_c_vVector4.fX) + (fY * a_c_vVector4.fY) + (fZ * a_c_vVector4.fZ) + (fW * a_c_vVector4.fW);//Returns ( Ax * Bx ) + ( Ay * By ) + ( Az * Bz ) + ( Aw * Bw).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

Vector4 Vector4::crossProduct(const Vector4 &a_c_vVector4)const//A cross product function that takes in a Vector4.
{
	return (
		fY * a_c_vVector4.fZ - fZ * a_c_vVector4.fY,
		fZ * a_c_vVector4.fX - fX * a_c_vVector4.fZ,
		fX * a_c_vVector4.fY - fY * a_c_vVector4.fX,
		fW);//Returns cross product using formula = ( a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1, a4 )
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector4::rotateZ(const float a_c_fDegAngle)//A Rotate function that takes in an angle in float format.
{
	float fRadAngle = a_c_fDegAngle * (PI / 180);//Creates a float equal to the conversion of the degree angle to radians.
	float fXTemp = fX;//A temporary value for x as it will change after assignment.
	fX = (fX * cosf(fRadAngle)) - (fY * sinf(fRadAngle));//Assigns the x value to x * cos(number) - y * sin(number).
	fY = (fXTemp * sinf(fRadAngle)) + (fY * cosf(fRadAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

void Vector4::rotateX(const float a_c_fDegAngle)//A Rotate function that takes in an angle in float format.
{
	float fRadAngle = a_c_fDegAngle * (PI / 180);//Creates a float equal to the conversion of the degree angle to radians.
	float fYTemp = fY;//A temporary value for y as it will change after assignment.
	fY = (fY * cosf(fRadAngle)) - (fZ * sinf(fRadAngle));//Assigns the y value to y * cos(number) - z * sin(number).
	fZ = (fYTemp * sinf(fRadAngle)) + (fZ * cosf(fRadAngle));//Assigns the z value to y * sin(number) + z * cos(number).
}

void Vector4::rotateY(const float a_c_fDegAngle)//A Rotate function that takes in an angle in float format.
{
	float fRadAngle = a_c_fDegAngle * (PI / 180);//Creates a float equal to the conversion of the degree angle to radians.
	float fZTemp = fZ;//A temporary value for z as it will change after assignment.
	fZ = (fZ * cosf(fRadAngle)) - (fX * sinf(fRadAngle));//Assigns the z value to z * cos(number) - x * sin(number).
	fX = (fZTemp * sinf(fRadAngle)) + (fX * cosf(fRadAngle));//Assigns the x value to z * sin(number) + x * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector4 Vector4::normalise()//A normalisation function that sets the fX, fY, fZ and fW of Vector4 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	fX *= fMulti;//Sets the fX of Vector4 to the fX of Vector4 divided by Vector4's magnitude.
	fY *= fMulti;//Sets the fY of Vector4 to the fY of Vector4 divided by Vector4's magnitude.
	fY *= fMulti;//Sets the fZ of Vector4 to the fZ of Vector4 divided by Vector4's magnitude.
	fW *= fMulti;//Sets the fW of Vector4 to the fZ of Vector4 divided by Vector4's magnitude.
	return Vector4(*this);//Returns a normalised version of this vector.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector4 Vector4::unit()const//A function that returns a unit vector created from this vector.
{
	Vector4 vTemp = *this;//Creates a temporary vector equal to the current Vector4.
	vTemp.normalise();//Normalises the temporary vector.
	return (vTemp);//Returns a copy of a normalised version of this Vector4.
}
