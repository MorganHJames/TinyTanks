//\===========================================================================================
//\ File: Vector3.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector3 class declarations.
//\===========================================================================================

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include "Vector2.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Vector3
//\ Brief: Overloaded operator functions for add, subtract, and multiply by both a scalar 
//\ value and by a Vector3.
//\ Constructor to create vector 3 from vector 2.
//\ Functions to allow for dot product, cross product, rotation, magnitude, normalisation.
//\===========================================================================================

class Vector3
{
private:
	//\===========================================================================================
	//\ Variables
	//\===========================================================================================

	float fX, fY, fZ;//Three float variables created.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector3();//Constructor default that sets all variables to 0.

	Vector3(float a_fX = 0, float a_fY = 0, float a_fZ = 0);//Constructor with three scalar values.

	Vector3(Vector2 &a_vVector2, float a_fZ = 0);//Constructor with a Vector2 and a scalar value.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	float getfX();//A getter to get the x part of vector3.

	float getfY();//A getter to get the y part of vector3.

	float getfZ();//A getter to get the z part of vector3.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================

	void setfX(float a_fX);//A setter to set the x part of vector3 to the passed in argument.

	void setfY(float a_fY);//A setter to set the y part of vector3 to the passed in argument.

	void setfZ(float a_fZ);//A setter to set the z part of vector3 to the passed in argument.

	//\===========================================================================================
	//\ Operation Overloads
	//\===========================================================================================

	Vector3 operator+(const float &a_fScalar);//Overloaded addition operation for Vector3.

	Vector3 operator+(const Vector3 &a_vVector3);//Overloaded addition operation for Vector3.

	Vector3 operator-(const float &a_fScalar);//Overloaded subtraction operation for Vector3.

	Vector3 operator-(const Vector3 &a_vVector3);//Overloaded subtraction operation for Vector3.

	Vector3 operator*(const float &a_fScalar);//Overloaded multiplication operation for Vector3.

	Vector3 operator*(const Vector3 &a_vVector3);//Overloaded multiplication operation for Vector3.

	Vector3 operator/(const float &a_fScalar);//Overloaded division operation for Vector3.

	Vector3 operator/(const Vector3 &a_vVector3);//Overloaded division operation for Vector3.

	bool operator!=(const float &a_fScalar);//Overloaded not equals operation for Vector3.

	bool operator!=(const Vector3 &a_vVector3);//Overloaded not equals operation for Vector3.
	
	bool operator==(const float &a_fScalar);//Overloaded is equals operation for Vector3.

	bool operator==(const Vector3 &a_vVector3);//Overloaded is equals operation for Vector3.

	Vector3 operator=(const float &a_fScalar);//Overloaded equals operation for Vector3.

	Vector3 operator=(const Vector3 &a_vVector3);//Overloaded equals operation for Vector3.

    //\===========================================================================================
	//\ Magnitude
	//\===========================================================================================

	float magnitude();//A magnitude function that returns a float.

    //\===========================================================================================
	//\ Squared Magnitude
	//\===========================================================================================

	float squaredMagnitude();//A function that returns the Magnitude squared of the vector as a float.

    //\===========================================================================================
	//\ Distance Between this Vector3 and another Vector3
	//\===========================================================================================

	float distance(const Vector3 &a_vVector3);//Returns the distance from this Vector3 and the passed in argument.

	//\===========================================================================================
	//\ Squared Distance Between this Vector3 and another Vector3
	//\===========================================================================================

	float squaredDistance(const Vector3 &a_vVector3);//Returns the squared distance from this Vector3 and the passed in argument.

	//\===========================================================================================
    //\ Dot Product
	//\===========================================================================================

	float dotProduct(const Vector3 &a_vVector3);//A dot product function that takes in a Vector3.

	//\===========================================================================================
	//\ Cross Product
	//\===========================================================================================

	Vector3 crossProduct(const Vector3 &a_vVector3);//A cross product function that takes in a Vector3 .

	//\===========================================================================================
	//\ Rotation
	//\===========================================================================================

	void rotateZ(const float fAngle);//A Rotate function that takes in an angle in float format.

	void rotateX(const float fAngle);//A Rotate function that takes in an angle in float format.

	void rotateY(const float fAngle);//A Rotate function that takes in an angle in float format.

	//\===========================================================================================
	//\ Normalisation
	//\===========================================================================================

	Vector3 normalise();//A normalisation function that sets the fX and fY of Vector3 to a normalised version.

    //\===========================================================================================
	//\ Return A Unit Vector
	//\===========================================================================================

	Vector3 unit();//A function that returns a unit vector created from this vector.
};

#endif
