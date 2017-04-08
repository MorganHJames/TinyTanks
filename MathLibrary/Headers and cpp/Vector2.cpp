//\===========================================================================================
//\ File: Vector2.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector2.h.
//\===========================================================================================

#include "Vector2.h"
#include <cstring>
#include <cmath>
#include "MathUtil.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Vector2::Vector2() {}//A default constructor that initialises X and Y to 0.

Vector2::Vector2(const Vector2 &a_c_v2Vector2)//Copy constructor.
{
	m_fX = a_c_v2Vector2.getfX();//Sets the x value of the Vector2 equal to the Vector2's x component that is passed in.

	m_fY = a_c_v2Vector2.getfY();//Sets the y value of the Vector2 equal to the Vector2's y component that is passed in.
}

Vector2::Vector2(const float a_c_fX, float a_c_fY) ://Constructor.
	m_fX(a_c_fX),//Sets the x value of the Vector2 to the first argument passed in on Creation.
	m_fY(a_c_fY)//Sets the y value of the Vector2 to the second argument passed in on Creation.
{
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

const float* Vector2::getVector()const//Returns a pointer to the first element in the array.
{
	return (m_aVector2);//Returns a pointer to the first element in the array.
}

float Vector2::getfX()const//A getter to get the x part of Vector2.
{
	return float(m_fX);//Returns the m_fX of this Vector2.
}

float Vector2::getfY()const//A getter to get the y part of Vector2.
{
	return float(m_fY);//Returns them_fYof this Vector2.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector2::setfX(const float &a_c_fX)//A setter to set the x part of Vector2 to the passed in argument.
{
	m_fX = a_c_fX;//Makes this Vector2's m_fX value equal to the passed in argument.
}

void Vector2::setfY(const float &a_c_fY)//A setter to set the y part of Vector2 to the passed in argument.
{
	m_fY = a_c_fY;//Makes this Vector2'sm_fYvalue equal to the passed in argument.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Vector2 Vector2::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Vector2.
{
	return Vector2(//Returns x + number, y + number.
		m_fX + a_c_fScalar,
		m_fY + a_c_fScalar);
}

Vector2 Vector2::operator+(const Vector2 &a_c_v2Vector2)const//Overloaded addition operation for Vector2.
{
	return Vector2(//Returns Ax + Bx, Ay + By.
		m_fX + a_c_v2Vector2.m_fX,
		m_fY + a_c_v2Vector2.m_fY);
}

Vector2 Vector2::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Vector2.
{
	return Vector2(//Returns x - number, y - number.
		m_fX - a_c_fScalar,
		m_fY - a_c_fScalar);
}

Vector2 Vector2::operator-(const Vector2 &a_c_v2Vector2)const//Overloaded subtraction operation for Vector2.
{
	return Vector2(//Returns Ax - Bx, Ay - By.
		m_fX - a_c_v2Vector2.m_fX,
	    m_fY - a_c_v2Vector2.m_fY);
}

Vector2 Vector2::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Vector2.
{
	return Vector2(//Returns x * number, y * number.
		m_fX * a_c_fScalar,
		m_fY * a_c_fScalar);
}

Vector2 Vector2::operator*(const Vector2 &a_c_v2Vector2)const//Overloaded multiplication operation for Vector2.
{
	return Vector2(//Returns Ax * Bx, Ay * By.
		m_fX * a_c_v2Vector2.m_fX,
		m_fY * a_c_v2Vector2.m_fY);
}

Vector2 Vector2::operator/(const float &a_c_fScalar)const//Overloaded division operation for Vector2.
{
	return Vector2(//Returns x * 1 / number, y * 1 / number.
		*this * reciprocal(a_c_fScalar));
}

Vector2 Vector2::operator/(const Vector2 &a_c_v2Vector2)const//Overloaded division operation for Vector2.
{
	return Vector2(//Returns Ax / Bx, Ay / By.
		m_fX / a_c_v2Vector2.m_fX,
		m_fY / a_c_v2Vector2.m_fY);
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================	

Vector2 Vector2::operator+=(const float &a_c_fScalar)//Overloaded plus equals operation for Vector2.
{
	return Vector2(//Returns x += number, y += number.
		*this = *this + a_c_fScalar);
}

Vector2 Vector2::operator+=(const Vector2 &a_c_v2Vector2)//Overloaded plus equals operation for Vector2.
{
	return Vector2(//Returns Ax += Bx, Ay += By.
		*this = *this + a_c_v2Vector2);
}

Vector2 Vector2::operator-=(const float &a_c_fScalar)//Overloaded decrease equals operation for Vector2.
{
	return Vector2(//Returns x -= number, y -= number.
		*this = *this - a_c_fScalar);
}

Vector2 Vector2::operator-=(const Vector2 &a_c_v2Vector2)//Overloaded decrease equals operation for Vector2.
{
	return Vector2(//Returns Ax -= Bx, Ay -= By.
		*this = *this - a_c_v2Vector2);
}

Vector2 Vector2::operator=(const float &a_c_fScalar)//Overloaded equals operation for Vector2.
{
	return Vector2(//Returns x = number, y = number.
		m_fX = a_c_fScalar,
		m_fY = a_c_fScalar);
}

Vector2 Vector2::operator=(const Vector2 &a_c_v2Vector2)//Overloaded equals operation for Vector2.
{
	return Vector2(//Returns Ax = Bx, Ay = By.
		m_fX = a_c_v2Vector2.m_fX,
		m_fY = a_c_v2Vector2.m_fY);
}

Vector2 Vector2::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Vector2.
{
	return Vector2(//Returns x *= number, y *= number.
		*this = *this * a_c_fScalar);
}

Vector2 Vector2::operator*=(const Vector2 &a_c_v2Vector2)//Overloaded times equals operation for Vector2.
{
	return Vector2(//Returns Ax *= Bx, Ay *= By.
		*this = *this * a_c_v2Vector2);
}

Vector2 Vector2::operator/=(const float &a_c_fScalar)//Overloaded divide equals operation for Vector2.
{
	return Vector2(//Returns Ax /= Bx, Ay /= By.
		*this = *this / a_c_fScalar);
}

Vector2 Vector2::operator/=(const Vector2 &a_c_v2Vector2)//Overloaded divide equals operation for Vector2.
{
	return Vector2(//Returns Ax /= Bx, Ay /= By.
		*this = *this / a_c_v2Vector2);
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Vector2::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Vector2.
{
	return bool(//Returns x != number && y != number.
		m_fX != a_c_fScalar ||
		m_fY != a_c_fScalar);
}

bool Vector2::operator!=(const Vector2 &a_c_v2Vector2)const//Overloaded not equals operation for Vector2.
{
	return bool(//Returns Ax != Bx && Ay != By.
		m_fX != a_c_v2Vector2.m_fX ||
		m_fY != a_c_v2Vector2.m_fY);
}

bool Vector2::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Vector2.
{
	return bool(//Returns x == number && y == number.
		m_fX == a_c_fScalar &&
		m_fY == a_c_fScalar);
}

bool Vector2::operator==(const Vector2 &a_c_v2Vector2)const//Overloaded is equals operation for Vector2.
{
	return bool(//Returns Ax == Bx && Ay == By.
		m_fX == a_c_v2Vector2.m_fX &&
		m_fY == a_c_v2Vector2.m_fY);
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector2::magnitude()const//A magnitude function that returns a float.
{
	return float(sqrtf(m_fX * m_fX +m_fY* m_fY));//Returns the square root of x^2 + y^2.
}

//\===========================================================================================
//\ Squared Length
//\===========================================================================================

float Vector2::squaredMagnitude()const//A function that returns the length squared of the vector as a float.
{
	return float(m_fX * m_fX +m_fY* m_fY);//Returns ( x^2 + y^2 ).
}

//\===========================================================================================
//\ Distance Between this Vector2 and another Vector2
//\===========================================================================================

float Vector2::distance(const Vector2 &a_c_v2Vector2)const//Returns the distance from this Vector2 and the passed in argument.
{
	return float((*this - a_c_v2Vector2).magnitude());//Returns the square root of ( Ax - Bx )^2 + ( Ay - By )^2.
}

//\===========================================================================================
//\ Squared Distance Between this Vector2 and another Vector2
//\===========================================================================================

float Vector2::squaredDistance(const Vector2 &a_c_v2Vector2)const//Returns the squared distance from this Vector2 and the passed in argument.
{
	return float((*this - a_c_v2Vector2).squaredMagnitude());//Returns ( Ax - Bx )^2 + ( Ay - By )^2.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector2::dotProduct(const Vector2 &a_c_v2Vector2)const//A dot product function that takes in a Vector2.
{
	return float((m_fX * a_c_v2Vector2.m_fX) + (m_fY * a_c_v2Vector2.m_fY));//Returns ( Ax * Bx ) + ( Ay * By ).
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

float Vector2::crossProduct(const Vector2 &a_c_v2Vector2)const//A dot product function that takes in a Vector.
{
	return float((m_fX * a_c_v2Vector2.m_fY) - (a_c_v2Vector2.m_fX * m_fY));//Returns ( Ax * By ) - ( BX * Ay ).
}

//\===========================================================================================
//\ Perpendicular
//\===========================================================================================

Vector2 Vector2::perpendicularClockwise()const//A perpendicularClockwise function for this Vector2.
{
	return Vector2(//Returns -y, x.
		-m_fY,
		m_fX);
}

Vector2 Vector2::perpendicularCounterClockwise()const//A perpendicularCounterClockwise function for this Vector2.
{
	return Vector2(//Returns y, -x.
		m_fY,
		-m_fX);
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector2::rotate(float a_fAngle)//A Rotate function that takes in an angle in float format.
{
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
    
	float fXTemp = m_fX;//A temporary value for x as it will change after assignment.
	
	m_fX = (m_fX * cosf(a_fAngle)) - (m_fY * sinf(a_fAngle));//Assigns the x value to x * cos(number) - y * sin(number).
	
	m_fY = (fXTemp * sinf(a_fAngle)) + (m_fY * cosf(a_fAngle));//Assigns the y value to x * sin(number) + y * cos(number).
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

Vector2 Vector2::normalise()//A normalisation function that sets the m_fX andm_fYof Vector2 to a normalised version.
{
	float fMulti = 1 / magnitude();//Allows for multiplication rather than division.
	return Vector2(//Returns a normalised version of this vector.
		m_fX *= fMulti,//Sets the m_fX of Vector2 to the m_fX of Vector2 divided by Vector2's magnitude.
		m_fY *= fMulti);//Sets them_fYof Vector2 to them_fYof Vector2 divided by Vector2's magnitude.
}

//\===========================================================================================
//\ Return A Unit Vector
//\===========================================================================================

Vector2 Vector2::unit()const//A function that returns a unit vector created from this vector.
{
	Vector2 vTemp = *this;//Creates a temporary vector equal to the current Vector 2.
	
	vTemp.normalise();//Normalises the temporary vector.
	
	return Vector2(vTemp);//Returns a copy of a normalised version of this Vector2.
}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Vector2::setZero()//Makes each Vector2 element equal to 0. 
{
	*this = ZERO;//Set each element in the Vector2 to zero.
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Vector2 Vector2::zero()const//Returns a Vector2 zero matrix.
{
	return Vector2(ZERO);//Returns the Vector2 equal to 0.
}

//\===========================================================================================
//\ Special Points
//\===========================================================================================

const Vector2 Vector2::ZERO{ 0,0 };//A Vector2 equal to {0,0}

const Vector2 Vector2::UNIT_X{ 1,0 };//A Vector2 equal to {1,0}

const Vector2 Vector2::UNIT_Y{ 0,1 };//A Vector2 equal to {0,1}

const Vector2 Vector2::NEGATIVE_UNIT_X{ -1,0 };//A Vector2 equal to {-1,0}

const Vector2 Vector2::NEGATIVE_UNIT_Y{ 0,-1 };//A Vector2 equal to {0,-1}

const Vector2 Vector2::UNIT_SCALE{ 1,1 };//A Vector2 equal to {1,1}