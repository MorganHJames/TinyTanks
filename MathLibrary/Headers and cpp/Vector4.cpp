//\===========================================================================================
//\ File: Vector4.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector4.h.
//\===========================================================================================

#include "Vector4.h"
#include <cstring>
#include <cmath>
#include "MathUtil.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector4::Vector4() {}//Constructor default that sets all variables to 0.

Vector4::Vector4(const Vector4 &a_c_v4Vector4)//Copy constructor.
{
	m_fX = a_c_v4Vector4.getfX();//Sets the x value of the Vector4 equal to the Vector4's x component that is passed in.
	
	m_fY = a_c_v4Vector4.getfY();//Sets the y value of the Vector4 equal to the Vector4's y component that is passed in.
	
	m_fZ = a_c_v4Vector4.getfZ();//Sets the z value of the Vector4 equal to the Vector4's z component that is passed in.
	
	m_fW = a_c_v4Vector4.getfW();//Sets the w value of the Vector4 equal to the Vector4's w component that is passed in.
}

Vector4::Vector4(const float a_c_fX, float a_c_fY, float a_c_fZ, float a_c_fW) ://Constructor with four scalar values.
	m_fX(a_c_fX),//Sets the x value of the Vector4 to the first argument passed in on Creation.
	m_fY(a_c_fY),//Sets the y value of the Vector4 to the second argument passed in on Creation.
	m_fZ(a_c_fZ),//Sets the z value of the Vector4 to the third argument passed in on Creation.
	m_fW(a_c_fW)//Sets the w value of the Vector4 to the fourth argument passed in on Creation.
{
}

Vector4::Vector4(const Vector2 &a_c_v2Vector2, float a_c_fZ, float a_c_fW) ://Constructor with a Vector2 and two scalar value.
	m_fX(a_c_v2Vector2.getfX()),//Sets the x value of the Vector4 to the first part of the Vector2 passed in.
	m_fY(a_c_v2Vector2.getfY()),//Sets the y value of the Vector4 to the second part of the Vector2 passed in.
	m_fZ(a_c_fZ),//Sets the z value of the Vector4 to the second argument passed in on Creation.
	m_fW(a_c_fW)//Sets the w value of the Vector4 to the third argument passed in on Creation.
{
}

Vector4::Vector4(const Vector3 &a_c_v3Vector3, float a_c_fW) ://Constructor with a Vector3 and a scalar value.
	m_fX(a_c_v3Vector3.getfX()),//Sets the x value of the Vector4 to the first part of the Vector3 passed in.
	m_fY(a_c_v3Vector3.getfY()),//Sets the y value of the Vector4 to the second part of the Vector3 passed in.
	m_fZ(a_c_v3Vector3.getfZ()),//Sets the z value of the Vector4 to the third part of the Vector3 passed in.
	m_fW(a_c_fW)//Sets the w value of the Vector4 to the second argument passed in on Creation.
{
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

const float* Vector4::getVector()const//Returns a pointer to the first element in the array.
{
	return (m_aVector4);//Returns a pointer to the first element in the array.
}

float Vector4::getfX()const//A getter to get the x part of Vector4.
{
	return float(m_fX);//Returns the fX of this Vector4.
}

float Vector4::getfY()const//A getter to get the y part of Vector4.
{
	return float(m_fY);//Returns the fY of this Vector4.
}

float Vector4::getfZ()const//A getter to get the z part of Vector4.
{
	return float(m_fZ);//Returns the fZ of this Vector4.
}

float Vector4::getfW()const//A getter to get the w part of Vector4.
{
	return float(m_fW);//Returns the fW of this Vector4.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector4::setfX(const float &a_c_fX)//A setter to set the x part of Vector4 to the passed in argument.
{
	m_fX = a_c_fX;//Makes this Vector4's fX value equal to the passed in argument.
}

void Vector4::setfY(const float &a_c_fY)//A setter to set the y part of Vector4 to the passed in argument.
{
	m_fY = a_c_fY;//Makes this Vector4's fY value equal to the passed in argument.
}

void Vector4::setfZ(const float &a_c_fZ)//A setter to set the z part of Vector4 to the passed in argument.
{
	m_fY = a_c_fZ;//Makes this Vector4's fZ value equal to the passed in argument.
}

void Vector4::setfW(const float &a_c_fW)//A setter to set the w part of Vector4 to the passed in argument.
{
	m_fW = a_c_fW;//Makes this Vector4's fW value equal to the passed in argument.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Vector4 Vector4::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Vector4.
{
	return Vector4(//Returns x + number, y + number, z + number, w + number.
		m_fX + a_c_fScalar,
		m_fY + a_c_fScalar,
		m_fZ + a_c_fScalar,
		m_fW + a_c_fScalar);
}

Vector4 Vector4::operator+(const Vector4 &a_c_v4Vector4)const//Overloaded addition operation for Vector4.
{
	return Vector4(//Returns Ax + Bx, Ay + By, Az + Bz, Aw + Bw.
		m_fX + a_c_v4Vector4.m_fX,
		m_fY + a_c_v4Vector4.m_fY,
		m_fZ + a_c_v4Vector4.m_fZ,
		m_fW + a_c_v4Vector4.m_fW);
}

Vector4 Vector4::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Vector4.
{
	return Vector4(//Returns x - number, y - number, z - number, w - number.
		m_fX - a_c_fScalar,
		m_fY - a_c_fScalar,
		m_fZ - a_c_fScalar,
		m_fW - a_c_fScalar);
}

Vector4 Vector4::operator-(const Vector4 &a_c_v4Vector4)const//Overloaded subtraction operation for Vector4.
{
	return Vector4(//Returns Ax - Bx, Ay - By, Az - Bz, Aw - Bw.
		m_fX - a_c_v4Vector4.m_fX,
		m_fY - a_c_v4Vector4.m_fY,
		m_fZ - a_c_v4Vector4.m_fZ,
		m_fW - a_c_v4Vector4.m_fW);
}

Vector4 Vector4::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Vector4.
{
	return Vector4(//Returns x * number, y * number, z * number, w * number.
		m_fX * a_c_fScalar,
		m_fY * a_c_fScalar,
		m_fZ * a_c_fScalar,
		m_fW * a_c_fScalar);
}

Vector4 Vector4::operator*(const Vector4 &a_c_v4Vector4)const//Overloaded multiplication operation for Vector4.
{
	return Vector4(//Returns Ax * Bx, Ay * By, Az * Bz, Aw * Bw.
		m_fX * a_c_v4Vector4.m_fX,
		m_fY * a_c_v4Vector4.m_fY,
		m_fZ * a_c_v4Vector4.m_fZ,
		m_fW * a_c_v4Vector4.m_fW);
}

Vector4 Vector4::operator/(const float &a_c_fScalar)const//Overloaded division operation for Vector4.
{
	return Vector4(//Returns x / number, y / number, z / number, w / number.
		*this * reciprocal(a_c_fScalar));
}

Vector4 Vector4::operator/(const Vector4 &a_c_v4Vector4)const//Overloaded division operation for Vector4.
{
	return Vector4(//Returns Ax / Bx, Ay / By, Az / Bz, Aw / Bw.
		m_fX / a_c_v4Vector4.m_fX,
		m_fY / a_c_v4Vector4.m_fY,
		m_fZ / a_c_v4Vector4.m_fZ,
		m_fW / a_c_v4Vector4.m_fW);
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Vector4 Vector4::operator+=(const float &a_c_fScalar)//Overloaded plus equals operation for Vector4.
{
	return Vector4(//Returns Ax += number, Ay += number, Az += number, Aw += number.
		*this = *this + a_c_fScalar);
}

Vector4 Vector4::operator+=(const Vector4 &a_c_v4Vector4)//Overloaded plus equals operation for Vector4.
{
	return Vector4(//Returns Ax += Bx, Ay += By, Az += Bz, Aw += Bw.
		*this = *this + a_c_v4Vector4);
}

Vector4 Vector4::operator-=(const float &a_c_fScalar)//Overloaded decrease equals operation for Vector4.
{
	return Vector4(//Returns Ax -= number, Ay -= number, Az -= number, Aw -= number.
		*this = *this - a_c_fScalar);
}

Vector4 Vector4::operator-=(const Vector4 &a_c_v4Vector4)//Overloaded decrease equals operation for Vector4.
{
	return Vector4(//Returns Ax -= Bx, Ay -= By, Az -= Bz, Aw -= Bw.
		*this = *this - a_c_v4Vector4);
}

Vector4 Vector4::operator=(const float &a_c_fScalar)//Overloaded equals operation for Vector4.
{
	return Vector4(//Returns Ax = number, Ay = number, Az = number, Aw = number.
		m_fX = a_c_fScalar,
		m_fY = a_c_fScalar,
		m_fZ = a_c_fScalar,
		m_fW = a_c_fScalar);
}

Vector4 Vector4::operator=(const Vector4 &a_c_v4Vector4)//Overloaded equals operation for Vector4.
{
	return Vector4(//Returns Ax = Bx, Ay = By, Az = Bz, Aw = Bw.
		m_fX = a_c_v4Vector4.m_fX,
		m_fY = a_c_v4Vector4.m_fY,
		m_fZ = a_c_v4Vector4.m_fZ,
		m_fW = a_c_v4Vector4.m_fW);
}

Vector4 Vector4::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Vector4.
{
	return Vector4(//Returns Ax *= number, Ay *= number, Az *= number, Aw *= number.
		*this = *this * a_c_fScalar);
}

Vector4 Vector4::operator*=(const Vector4 &a_c_v4Vector4)//Overloaded times equals operation for Vector4.
{
	return Vector4(//Returns Ax *= Bx, Ay *= By, Az *= Bz, Aw *= Bw.
		*this = *this * a_c_v4Vector4);
}

Vector4 Vector4::operator/=(const float &a_c_fScalar)//Overloaded divide equals operation for Vector4.
{
	return Vector4(//Returns Ax /= number, Ay /= number, Az /= number, Aw /= number.
		*this = *this / a_c_fScalar);
}

Vector4 Vector4::operator/=(const Vector4 &a_c_v4Vector4)//Overloaded divide equals operation for Vector4.
{
	return Vector4(//Returns Ax /= Bx, Ay /= By, Az /= Bz, Aw /= Bw.
		*this = *this / a_c_v4Vector4);
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Vector4::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Vector4.
{
	return bool(//Returns x != number || y != number || z != number || w != number.
		m_fX != a_c_fScalar ||
		m_fY != a_c_fScalar ||
		m_fZ != a_c_fScalar ||
		m_fW != a_c_fScalar);
}

bool Vector4::operator!=(const Vector4 &a_c_v4Vector4)const//Overloaded not equals operation for Vector4.
{
	return bool(//Returns Ax != Bx || Ay != By || Az != Bz || Aw != Bw.
		m_fX != a_c_v4Vector4.m_fX ||
		m_fY != a_c_v4Vector4.m_fY ||
		m_fZ != a_c_v4Vector4.m_fZ ||
		m_fW != a_c_v4Vector4.m_fW);
}

bool Vector4::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Vector4.
{
	return bool(//Returns x == number && y == number && z == number && w == number.
		m_fX == a_c_fScalar &&
		m_fY == a_c_fScalar &&
		m_fZ == a_c_fScalar &&
		m_fW == a_c_fScalar);
}

bool Vector4::operator==(const Vector4 &a_c_v4Vector4)const//Overloaded is equals operation for Vector4.
{
	return bool(//Returns Ax == Bx && Ay == By && Az == Bz && Aw == Bw.
		m_fX == a_c_v4Vector4.m_fX &&
		m_fY == a_c_v4Vector4.m_fY &&
		m_fZ == a_c_v4Vector4.m_fZ &&
		m_fW == a_c_v4Vector4.m_fW);
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector4::magnitude()const//A magnitude function that returns a float.
{
	return float(sqrtf(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ + m_fW * m_fW));//Returns the square root of x^2 + y^2 + z^2 + w^2.
}

//\===========================================================================================
//\ Squared Magnitude
//\===========================================================================================

float Vector4::squaredMagnitude()const//A function that returns the Magnitude squared of the vector as a float.
{
	return float(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ + m_fW * m_fW);//Returns x^2 + y^2 + z^2 + w^2.
}

//\===========================================================================================
//\ Distance Between this Vector4 and another Vector4
//\===========================================================================================

float Vector4::distance(const Vector4 &a_c_v4Vector4)const//Returns the distance from this Vector4 and the passed in argument.
{
	return float((*this - a_c_v4Vector4).magnitude());//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2 + ( Aw - Bw )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector4 and another Vector4
//\===========================================================================================

float Vector4::squaredDistance(const Vector4 &a_c_v4Vector4)const//Returns the squared distance from this Vector4 and the passed in argument.
{
	return float((*this - a_c_v4Vector4).squaredMagnitude());//Returns ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2 + ( Aw - Bw )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector4::dotProduct(const Vector4 &a_c_v4Vector4)const//A dot product function that takes in a Vector4.
{
	return float((m_fX * a_c_v4Vector4.m_fX) + (m_fY * a_c_v4Vector4.m_fY) + (m_fZ * a_c_v4Vector4.m_fZ) + (m_fW * a_c_v4Vector4.m_fW));//Returns ( Ax * Bx ) + ( Ay * By ) + ( Az * Bz ) + ( Aw * Bw).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

Vector4 Vector4::crossProduct(const Vector4 &a_c_v4Vector4)const//A cross product function that takes in a Vector4.
{
	return Vector4(//Returns cross product using formula = ( a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1, a4 )
		m_fY * a_c_v4Vector4.m_fZ - m_fZ * a_c_v4Vector4.m_fY,
		m_fZ * a_c_v4Vector4.m_fX - m_fX * a_c_v4Vector4.m_fZ,
		m_fX * a_c_v4Vector4.m_fY - m_fY * a_c_v4Vector4.m_fX,
		m_fW);
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector4::rotateZ(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	float fXTemp = m_fX;//A temporary value for x as it will change after assignment.

	m_fX = (m_fX * cosf(a_fAngle)) - (m_fY * sinf(a_fAngle));//Assigns the x value to x * cos(number) - y * sin(number).

	m_fY = (fXTemp * sinf(a_fAngle)) + (m_fY * cosf(a_fAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

void Vector4::rotateX(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	float fYTemp = m_fY;//A temporary value for y as it will change after assignment.

	m_fY = (m_fY * cosf(a_fAngle)) - (m_fZ * sinf(a_fAngle));//Assigns the y value to y * cos(number) - z * sin(number).

	m_fZ = (fYTemp * sinf(a_fAngle)) + (m_fZ * cosf(a_fAngle));//Assigns the z value to y * sin(number) + z * cos(number).
}

void Vector4::rotateY(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	float fZTemp = m_fZ;//A temporary value for z as it will change after assignment.

	m_fZ = (m_fZ * cosf(a_fAngle)) - (m_fX * sinf(a_fAngle));//Assigns the z value to z * cos(number) - x * sin(number).

	m_fX = (fZTemp * sinf(a_fAngle)) + (m_fX * cosf(a_fAngle));//Assigns the x value to z * sin(number) + x * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector4 Vector4::normalise()//A normalisation function that sets the fX, fY, fZ and fW of Vector4 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	return Vector4(//Returns the normalised version of the Vector4.
		m_fX *= fMulti,//Sets the fX of Vector4 to the fX of Vector4 divided by Vector4's magnitude.
		m_fY *= fMulti,//Sets the fY of Vector4 to the fY of Vector4 divided by Vector4's magnitude.
		m_fZ *= fMulti,//Sets the fZ of Vector4 to the fZ of Vector4 divided by Vector4's magnitude.
		m_fW *= fMulti);//Sets the fW of Vector4 to the fZ of Vector4 divided by Vector4's magnitude.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector4 Vector4::unit()const//A function that returns a unit vector created from this vector.
{
	Vector4 vTemp = *this;//Creates a temporary vector equal to the current Vector4.

	vTemp.normalise();//Normalises the temporary vector.

	return Vector4(vTemp);//Returns a copy of a normalised version of this Vector4.
}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Vector4::setZero()//Makes each Vector4 element equal to 0. 
{
	*this = ZERO;//Set each element in the Vector4 to zero.
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Vector4 Vector4::zero()const//Returns a Vector4 zero matrix.
{
	return Vector4(ZERO);//Returns the Vector4 equal to 0.
}

//\===========================================================================================
//\ Special Points
//\===========================================================================================

const Vector4 Vector4::ZERO{ 0,0,0,0 };//A Vector4 equal to {0,0,0,0}.