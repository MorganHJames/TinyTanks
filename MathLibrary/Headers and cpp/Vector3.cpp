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
	return fX;
}

float Vector3::getfY()//A getter to get the y part of Vector3.
{
	return fY;
}

float Vector3::getfZ()//A getter to get the z part of vector3.
{
	return fZ;
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Vector3::setfX(float a_fX)//A setter to set the x part of Vector3 to the passed in argument.
{
	fX = a_fX;
}

void Vector3::setfY(float a_fY)//A setter to set the y part of Vector3 to the passed in argument.
{
	fY = a_fY;
}
void Vector3::setfZ(float a_fZ)//A setter to set the z part of vector3 to the passed in argument.
{
	fY = a_fZ;
}

//\===========================================================================================
//\ Operation Overloads
//\===========================================================================================

Vector3 Vector3::operator+(const float &a_fScalar)//Overloaded addition operation for Vector3.
{
	return Vector3(fX + a_fScalar, fY + a_fScalar, fZ + a_fScalar);//Returns the value of the addition.
}

Vector3 Vector3::operator+(const Vector3 &a_vVector3)//Overloaded addition operation for Vector3.
{
	return Vector3(fX + a_vVector3.fX, fY + a_vVector3.fY, fZ + a_vVector3.fZ);//Returns the value of the addition.
}

Vector3 Vector3::operator-(const float &a_fScalar)//Overloaded subtraction operation for Vector3.
{
	return Vector3(fX - a_fScalar, fY - a_fScalar, fZ - a_fScalar);//Returns the value of the subtraction.
}

Vector3 Vector3::operator-(const Vector3 &a_vVector3)//Overloaded subtraction operation for Vector3.
{
	return Vector3(fX - a_vVector3.fX, fY - a_vVector3.fY, fZ - a_vVector3.fZ);//Returns the value of the subtraction.
}

Vector3 Vector3::operator*(const float &a_fScalar)//Overloaded multiplication operation for Vector3.
{
	return Vector3(fX * a_fScalar, fY * a_fScalar, fZ * a_fScalar);//Returns the value of the multiplication.
}

Vector3 Vector3::operator*(const Vector3 &a_vVector3) //Overloaded multiplication operation for Vector3.
{
	return Vector3(fX * a_vVector3.fX, fY * a_vVector3.fY, fZ * a_vVector3.fZ);//Returns the value of the multiplication.
}

//\===========================================================================================
//\ Dot Product
//\===========================================================================================

float Vector3::dotProduct(const Vector3 &a_vVector3) //A dot product function that takes in a Vector3.
{
	return (fX * a_vVector3.fX) + (fY * a_vVector3.fY) + (fZ * a_vVector3.fZ;//Returns the value of the dot product.
}

//\===========================================================================================
//\ Cross Product
//\===========================================================================================

Vector3 Vector3::crossProduct(const Vector3 &a_vVector3)//A cross product function that takes in a Vector3 .
{
	return (fY * a_vVector3.fZ - fZ * a_vVector3.fY, fZ * a_vVector3.fX - fX * a_vVector3.fZ, fX * a_vVector3.fY - fY * a_vVector3.fX);//Returns cross product using formula = (a2*b3-a3*b2, a3*b1-a1*b3, a1*b2-a2*b1)
}

//\===========================================================================================
//\ Rotation
//\===========================================================================================

void Vector3::rotate(const float fAngle)//A Rotate function that takes in an angle in float format.
{
	/*
	if(fAngle < + 1)
	{
		if(fAngle > ?1)
		{
			fY = sin(fAngle);
			fX = a t a n 2 (?r12, r 2 2);
			fZ = a t a n 2 (?r01, r 0 0);
		}
		e l s e // r 0 2 = ?1
		{
			// Not a u n i q u e s o l u t i o n : t h e t aZ ? t he t aX = a t a n 2 ( r10 , r 1 1 )
			t he t aY = ?PI / 2;
		t he t aX = ?a t a n 2 (r10 , r 1 1);
		t h e t aZ = 0;
		}
	}
	4
		e l s e // r 0 2 = +1
	{
		// Not a u n i q u e s o l u t i o n : t h e t aZ + t he t aX = a t a n 2 ( r10 , r 1 1 )
		t he t aY = +PI / 2;
	t he t aX = a t a n 2 (r10 , r 1 1);
	t h e t aZ = 0;
	}
	*/
}

//\===========================================================================================
//\ Magnitude
//\===========================================================================================

float Vector3::magnitude()//A magnitude function that returns a float.
{
	return sqrtf(fX * fX + fY * fY + fZ * fZ);//Returns the square root of x^2 + y^2 + z^2
}

//\===========================================================================================
//\ Normalisation
//\===========================================================================================

void Vector3::normalise()//A normalisation function that sets the fX and fY of Vector3 to a normalised version.
{
	fX = fX / magnitude();//Sets the fX of Vector3 to the fX of Vector3 divided by Vector3's magnitude.
	fY = fY / magnitude();//Sets the fY of Vector3 to the fY of Vector3 divided by Vector3's magnitude.
	fY = fY / magnitude();//Sets the fZ of Vector3 to the fZ of Vector3 divided by Vector3's magnitude.
}
