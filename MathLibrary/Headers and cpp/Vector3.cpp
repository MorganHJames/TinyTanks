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
#include "Matrix3x3.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector3::Vector3() {}//Constructor default that sets all variables to 0.

Vector3::Vector3(const Vector3 &a_c_v3Vector3)//Copy constructor.
{
	m_fX = a_c_v3Vector3.getfX();//Sets the x value of the Vector3 equal to the Vector3's x component that is passed in.
	
	m_fY = a_c_v3Vector3.getfY();//Sets the y value of the Vector3 equal to the VeVector3ctor4's y component that is passed in.
	
	m_fZ = a_c_v3Vector3.getfZ();//Sets the z value of the Vector3 equal to the Vector3's z component that is passed in.
}

Vector3::Vector3(float a_c_fX, float a_c_fY, float a_c_fZ) ://Constructor with three scalar values.
	m_fX(a_c_fX),//Sets the x value of the Vector3 to the first argument passed in on Creation.
	m_fY(a_c_fY),//Sets the y value of the Vector3 to the second argument passed in on Creation.
	m_fZ(a_c_fZ)//Sets the z value of the Vector3 to the third argument passed in on Creation.
{
}

Vector3::Vector3(const Vector2 &a_c_v2Vector2, float a_c_fZ) ://Constructor with a Vector2 and a scalar value.
	m_fX(a_c_v2Vector2.getfX()),//Sets the x value of the Vector3 to the first part of the Vector2 passed in.
	m_fY(a_c_v2Vector2.getfY()),//Sets the y value of the Vector3 to the second part of the Vector2 passed in.
	m_fZ(a_c_fZ)//Sets the z value of the Vector3 to the third argument passed in on Creation.
{
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

const float* Vector3::getVector()const//Returns a pointer to the first element in the array.
{
	return (m_aVector3);//Returns a pointer to the first element in the array.
}

float Vector3::getfX()const//A getter to get the x part of Vector3.
{
	return float(m_fX);//Returns the m_fX of this Vector3.
}

float Vector3::getfY()const//A getter to get the y part of Vector3.
{
	return float(m_fY);//Returns the fY of this Vector3.
}

float Vector3::getfZ()const//A getter to get the z part of Vector3.
{
	return float(m_fZ);//Returns the fZ of this Vector3.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector3::setfX(const float &a_c_fX)//A setter to set the x part of Vector3 to the passed in argument.
{
	m_fX = a_c_fX;//Makes this Vector3's m_fX value equal to the passed in argument.
}

void Vector3::setfY(const float &a_c_fY)//A setter to set the y part of Vector3 to the passed in argument.
{
	m_fY = a_c_fY;//Makes this Vector3's fY value equal to the passed in argument.
}
void Vector3::setfZ(const float &a_c_fZ)//A setter to set the z part of Vector3 to the passed in argument.
{
	m_fY = a_c_fZ;//Makes this Vector3's fZ value equal to the passed in argument.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Vector3 Vector3::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Vector3.
{
	return Vector3(//Returns x + number, y + number, z + number.
		m_fX + a_c_fScalar,
		m_fY + a_c_fScalar,
		m_fZ + a_c_fScalar);
}

Vector3 Vector3::operator+(const Vector3 &a_c_v3Vector3)const//Overloaded addition operation for Vector3.
{
	return Vector3(//Returns Ax + Bx, Ay + By, Az + Bz.
		m_fX + a_c_v3Vector3.m_fX,
		m_fY + a_c_v3Vector3.m_fY,
		m_fZ + a_c_v3Vector3.m_fZ);
}

Vector3 Vector3::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Vector3.
{
	return Vector3(//Returns x - number, y - number, z - number.
		m_fX - a_c_fScalar,
		m_fY - a_c_fScalar,
		m_fZ - a_c_fScalar);
}

Vector3 Vector3::operator-(const Vector3 &a_c_v3Vector3)const//Overloaded subtraction operation for Vector3.
{
	return Vector3(//Returns Ax - Bx, Ay - By, Az - Bz.
		m_fX - a_c_v3Vector3.m_fX,
		m_fY - a_c_v3Vector3.m_fY,
		m_fZ - a_c_v3Vector3.m_fZ);
}

Vector3 Vector3::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Vector3.
{
	return Vector3(//Returns x * number, y * number, z * number.
		m_fX * a_c_fScalar,
		m_fY * a_c_fScalar,
		m_fZ * a_c_fScalar);
}

Vector3 Vector3::operator*(const Vector3 &a_c_v3Vector3)const//Overloaded multiplication operation for Vector3.
{
	return Vector3(//Returns Ax * Bx, Ay * By, Az * Bz.
		m_fX * a_c_v3Vector3.m_fX,  
		m_fY * a_c_v3Vector3.m_fY,  
		m_fZ * a_c_v3Vector3.m_fZ); 
}

Vector3 Vector3::operator*(const Matrix3x3 &a_c_fm3Matrix3x3)const//Multiplication for a vector times a matrix as introducing this as an overload would cause circular dependency.
{
	return Vector3(//Returns the multiplied Vector3.
		m_fX * a_c_fm3Matrix3x3.getiMatrix(1) + m_fY * a_c_fm3Matrix3x3.getiMatrix(4) + m_fZ * a_c_fm3Matrix3x3.getiMatrix(7),//Dot product for the only row of the Vector3 and the first row of the Matrix3x3.
		m_fX * a_c_fm3Matrix3x3.getiMatrix(2) + m_fY * a_c_fm3Matrix3x3.getiMatrix(5) + m_fZ * a_c_fm3Matrix3x3.getiMatrix(8),//Dot product for the only row of the Vector3 and the second row of the Matrix3x3.
		m_fX * a_c_fm3Matrix3x3.getiMatrix(3) + m_fY * a_c_fm3Matrix3x3.getiMatrix(6) + m_fZ * a_c_fm3Matrix3x3.getiMatrix(9));//Dot product for the only row of the Vector3 and the third row of the Matrix3x3.
}


Vector3 Vector3::operator/(const float &a_c_fScalar)const//Overloaded division operation for Vector3.
{
	return Vector3(//Returns x / number, y / number, z / number.
		*this * reciprocal(a_c_fScalar));
}

Vector3 Vector3::operator/(const Vector3 &a_c_v3Vector3)const//Overloaded division operation for Vector3.
{
	return Vector3(//Returns Ax / Bx, Ay / By, Az / Bz.
		m_fX / a_c_v3Vector3.m_fX,
		m_fY / a_c_v3Vector3.m_fY,
		m_fZ / a_c_v3Vector3.m_fZ);
}		

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Vector3 Vector3::operator+=(const float &a_c_fScalar)//Overloaded plus equals operation for Vector3.
{
	return Vector3(//Returns x += number, y += number, z += number.
		*this = *this + a_c_fScalar);
}

Vector3 Vector3::operator+=(const Vector3 &a_c_v3Vector3)//Overloaded plus equals operation for Vector3.
{
	return Vector3(//Returns Ax += Bx, Ay += By, Az += Bz.
		*this = *this + a_c_v3Vector3);
}

Vector3 Vector3::operator-=(const float &a_c_fScalar)//Overloaded decrease equals operation for Vector3.
{
	return Vector3(//Returns x -= number, y -= number, z -= number.
		*this = *this - a_c_fScalar);
}

Vector3 Vector3::operator-=(const Vector3 &a_c_v3Vector3)//Overloaded decrease equals operation for Vector3.
{
	return Vector3(//Returns Ax -= Bx, Ay -= By, Az -= Bz.
		*this = *this - a_c_v3Vector3);
}

Vector3 Vector3::operator=(const float &a_c_fScalar)//Overloaded equals operation for Vector3.
{
	return Vector3(//Returns x = number, y = number, z = number.
	    m_fX = a_c_fScalar,
		m_fY = a_c_fScalar,
		m_fZ = a_c_fScalar);
}

Vector3 Vector3::operator=(const Vector3 &a_c_v3Vector3)//Overloaded equals operation for Vector3.
{
	return Vector3(//Returns Ax = Bx, Ay = By, Az = Bz.
		m_fX = a_c_v3Vector3.m_fX,
		m_fY = a_c_v3Vector3.m_fY,
		m_fZ = a_c_v3Vector3.m_fZ);
}

Vector3 Vector3::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Vector3.
{
	return Vector3(//Returns x *= number, y *= number, z *= number.
		*this = *this * a_c_fScalar);
}

Vector3 Vector3::operator*=(const Vector3 &a_c_v3Vector3)//Overloaded times equals operation for Vector3.
{
	return Vector3(//Returns Ax *= Bx, Ay *= By, Az *= Bz.
		*this = *this * a_c_v3Vector3);
}

Vector3 Vector3::operator/=(const float &a_c_fScalar)//Overloaded divide equals operation for Vector3.
{
	return Vector3(//Returns x /= number, y /= number, z /= number.
		*this = *this / a_c_fScalar);
}

Vector3 Vector3::operator/=(const Vector3 &a_c_v3Vector3)//Overloaded divide equals operation for Vector3.
{
	return Vector3(//Returns Ax /= Bx, Ay /= By, Az /= Bz.
		*this = *this / a_c_v3Vector3);
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Vector3::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Vector3.
{
	return bool(//Returns x != number || y != number || z != number.
		m_fX != a_c_fScalar ||
		m_fY != a_c_fScalar ||
		m_fZ != a_c_fScalar);
}

bool Vector3::operator!=(const Vector3 &a_c_v3Vector3)const//Overloaded not equals operation for Vector3.
{
	return bool(//Returns Ax != Bx || Ay != By || Az != Bz.
		m_fX != a_c_v3Vector3.m_fX ||
		m_fY != a_c_v3Vector3.m_fY ||
		m_fZ != a_c_v3Vector3.m_fZ);
}

bool Vector3::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Vector3.
{
	return bool(//Returns x == number && y == number && z == number.
		m_fX == a_c_fScalar &&
		m_fY == a_c_fScalar &&
		m_fZ == a_c_fScalar);
}

bool Vector3::operator==(const Vector3 &a_c_v3Vector3)const//Overloaded is equals operation for Vector3.
{
	return bool(//Returns Ax == Bx && Ay == By && Az == Bz.
		m_fX == a_c_v3Vector3.m_fX &&
		m_fY == a_c_v3Vector3.m_fY &&
		m_fZ == a_c_v3Vector3.m_fZ);
}

//\===========================================================================================
//\ Inverse
//\===========================================================================================

Vector3 Vector3::inverse()const//Returns the inverse of this vector3.
{
	return(*this * -1);//Returns Vector3 * -1.
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector3::magnitude()const//A magnitude function that returns a float.
{
	return float(sqrtf(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ));//Returns the square root of x^2 + y^2 + z^2
}

//\===========================================================================================
//\ Squared Magnitude
//\===========================================================================================

float Vector3::squaredMagnitude()const//A function that returns the Magnitude squared of the vector as a float.
{
	return float(m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ);//Returns ( x^2 + y^2 + z^2 ).
}

//\===========================================================================================
//\ Distance Between this Vector3 and another Vector3
//\===========================================================================================

float Vector3::distance(const Vector3 &a_c_v3Vector3)const//Returns the distance from this Vector3 and the passed in argument.
{
	return float((*this - a_c_v3Vector3).magnitude());//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector3 and another Vector3
//\===========================================================================================

float Vector3::squaredDistance(const Vector3 &a_c_v3Vector3)const//Returns the squared distance from this Vector3 and the passed in argument.
{
	return float((*this - a_c_v3Vector3).squaredMagnitude());//Returns ( Ax - Bx )^2 + ( Ay - By )^2 + ( Az - Bz )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector3::dotProduct(const Vector3 &a_c_v3Vector3)const//A dot product function that takes in a Vector3.
{
	return float((m_fX * a_c_v3Vector3.m_fX) + (m_fY * a_c_v3Vector3.m_fY) + (m_fZ * a_c_v3Vector3.m_fZ));//Returns ( Ax * Bx ) + ( Ay * By ) + ( Az * Bz ).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

Vector3 Vector3::crossProduct(const Vector3 &a_c_v3Vector3)const//A cross product function that takes in a Vector3 .
{
	return Vector3(//Returns cross product using formula = ( a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1 ).
		m_fY * a_c_v3Vector3.m_fZ - m_fZ * a_c_v3Vector3.m_fY,
		m_fZ * a_c_v3Vector3.m_fX - m_fX * a_c_v3Vector3.m_fZ,
		m_fX * a_c_v3Vector3.m_fY - m_fY * a_c_v3Vector3.m_fX);
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector3::rotateZ(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	float fXTemp = m_fX;//A temporary value for x as it will change after assignment.

	m_fX = (m_fX * cosf(a_fAngle)) - (m_fY * sinf(a_fAngle));//Assigns the x value to x * cos(number) - y * sin(number).

	m_fY = (fXTemp * sinf(a_fAngle)) + (m_fY * cosf(a_fAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

void Vector3::rotateX(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	float fYTemp = m_fY;//A temporary value for y as it will change after assignment.

	m_fY = (m_fY * cosf(a_fAngle)) - (m_fZ * sinf(a_fAngle));//Assigns the y value to y * cos(number) - z * sin(number).

	m_fZ = (fYTemp * sinf(a_fAngle)) + (m_fZ * cosf(a_fAngle));//Assigns the z value to y * sin(number) + z * cos(number).
}

void Vector3::rotateY(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	float fZTemp = m_fZ;//A temporary value for z as it will change after assignment.

	m_fZ = (m_fZ * cosf(a_fAngle)) - (m_fX * sinf(a_fAngle));//Assigns the z value to z * cos(number) - x * sin(number).

	m_fX = (fZTemp * sinf(a_fAngle)) + (m_fX * cosf(a_fAngle));//Assigns the x value to z * sin(number) + x * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector3 Vector3::normalise()//A normalisation function that sets the fX, fY and fZ of Vector3 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	return Vector3(//Returns a normalised version of this vector.
		m_fX *= fMulti,//Sets the m_fX of Vector3 to the m_fX of Vector3 divided by Vector3's magnitude.
		m_fY *= fMulti,//Sets the fY of Vector3 to the fY of Vector3 divided by Vector3's magnitude.
		m_fZ *= fMulti);//Sets the fZ of Vector3 to the fZ of Vector3 divided by Vector3's magnitude.
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
{
	*this = ZERO;//Set each element in the Vector3 to zero.
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Vector3 Vector3::zero()const//Returns a Vector3 zero matrix.
{
	return Vector3(ZERO);//Returns the Vector3 equal to 0.
}

//\===========================================================================================
//\ Special Points
//\===========================================================================================

const Vector3 Vector3::ZERO{ 0,0,0 };//A Vector3 equal to {0,0,0}.

const Vector3 Vector3::UNIT_X{ 1,0,0 };//A Vector3 equal to {1,0,0}.

const Vector3 Vector3::UNIT_Y{ 0,1,0 };//A Vector3 equal to {0,1,0}.

const Vector3 Vector3::UNIT_Z{ 0,0,1 };//A Vector3 equal to {0,0,1}.

const Vector3 Vector3::NEGATIVE_UNIT_X{ -1,0,0 };//A Vector3 equal to {-1,0,0}.

const Vector3 Vector3::NEGATIVE_UNIT_Y{ 0,-1,0 };//A Vector3 equal to {0,-1,0}.

const Vector3 Vector3::NEGATIVE_UNIT_Z{ 0,0,-1 };//A Vector3 equal to {0,0,-1}.

const Vector3 Vector3::UNIT_SCALE{ 1,1,1 };//A Vector3 equal to {1,1,1}.