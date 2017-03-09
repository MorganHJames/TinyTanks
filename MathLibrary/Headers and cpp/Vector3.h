//\===========================================================================================
//\ File: Vector3.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector3 class declarations.
//\===========================================================================================

#ifndef _Vector3_H_
#define _Vector3_H_

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
	//\ Member Variables
	//\===========================================================================================

	float fX, fY, fZ;//Three float variables created.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector3();//Constructor default that sets all variables to 0.

	Vector3(const float a_c_fX = 0, float a_c_fY = 0, float a_c_fZ = 0);//Constructor with three scalar values.

	Vector3(const Vector2 &a_c_vVector2, float a_c_fZ = 0);//Constructor with a Vector2 and a scalar value.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	float getfX()const;//A getter to get the x part of Vector3.

	float getfY()const;//A getter to get the y part of Vector3.

	float getfZ()const;//A getter to get the z part of Vector3.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================

	void setfX(const float &a_c_fX);//A setter to set the x part of Vector3 to the passed in argument.

	void setfY(const float &a_c_fY);//A setter to set the y part of Vector3 to the passed in argument.

	void setfZ(const float &a_c_fZ);//A setter to set the z part of Vector3 to the passed in argument.

	//\===========================================================================================
	//\ Arithmetic Operation Overloads
	//\===========================================================================================

	Vector3 operator+(const float &a_c_fScalar)const;//Overloaded addition operation for Vector3.

	Vector3 operator+(const Vector3 &a_c_vVector3)const;//Overloaded addition operation for Vector3.

	Vector3 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Vector3.

	Vector3 operator-(const Vector3 &a_c_vVector3)const;//Overloaded subtraction operation for Vector3.

	Vector3 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Vector3.

	Vector3 operator*(const Vector3 &a_c_vVector3)const;//Overloaded multiplication operation for Vector3.

	Vector3 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Vector3.

	Vector3 operator/(const Vector3 &a_c_vVector3)const;//Overloaded division operation for Vector3.

	//\===========================================================================================
	//\ Assignment Operation Overloads
	//\===========================================================================================

	Vector3 operator=(const float &a_c_fScalar);//Overloaded equals operation for Vector3.

	Vector3 operator=(const Vector3 &a_c_vVector3);//Overloaded equals operation for Vector3.

	//\===========================================================================================
	//\ Relational Operation Overloads
	//\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Vector3.

	bool operator!=(const Vector3 &a_c_vVector3)const;//Overloaded not equals operation for Vector3.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Vector3.

	bool operator==(const Vector3 &a_c_vVector3)const;//Overloaded is equals operation for Vector3.
	
	//\===========================================================================================
	//\ Inverse
	//\===========================================================================================

	Vector3 inverse()const;//Returns the inverse of this vector3.

	//\===========================================================================================
	//\ Magnitude
	//\===========================================================================================

	float magnitude()const;//A magnitude function that returns a float.

	//\===========================================================================================
	//\ Squared Magnitude
	//\===========================================================================================

	float squaredMagnitude()const;//A function that returns the Magnitude squared of the vector as a float.

	//\===========================================================================================
	//\ Distance Between this Vector3 and another Vector3
	//\===========================================================================================

	float distance(const Vector3 &a_c_vVector3)const;//Returns the distance from this Vector3 and the passed in argument.

	//\===========================================================================================
	//\ Squared Distance Between this Vector3 and another Vector3
	//\===========================================================================================

	float squaredDistance(const Vector3 &a_c_vVector3)const;//Returns the squared distance from this Vector3 and the passed in argument.

	//\===========================================================================================
	//\ Dot Product
	//\===========================================================================================

	float dotProduct(const Vector3 &a_c_vVector3)const;//A dot product function that takes in a Vector3.

	//\===========================================================================================
	//\ Cross Product
	//\===========================================================================================

	Vector3 crossProduct(const Vector3 &a_c_vVector3)const;//A cross product function that takes in a Vector3 .

	//\===========================================================================================
	//\ Rotation
	//\===========================================================================================

	void rotateZ(float a_fDegAngle);//A Rotate function that takes in an angle in float format.

	void rotateX(float a_fDegAngle);//A Rotate function that takes in an angle in float format.

	void rotateY(float a_fDegAngle);//A Rotate function that takes in an angle in float format.

	//\===========================================================================================
	//\ Normalisation
	//\===========================================================================================

	Vector3 normalise();//A normalisation function that sets the fX, fY and fZ of Vector3 to a normalised version.

	//\===========================================================================================
	//\ Return A Unit Vector
	//\===========================================================================================

	Vector3 unit()const;//A function that returns a unit vector created from this vector.

};

#endif

