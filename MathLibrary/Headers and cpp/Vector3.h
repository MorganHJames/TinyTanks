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
	friend class Matrix3x3;
private:
	//\===========================================================================================
	//\ Member Variables
	//\===========================================================================================
	union
	{
		struct//A structure three floats to make a vector3.
		{
			float m_fX, m_fY, m_fZ;//three float variables created.
		};

		struct//A structure containing 3 floats representing a Vector3.
		{
			float m_aVector3[3];//An array of 3 floats.
		};
	};

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector3();//Constructor default that sets all variables to 0.

	Vector3(const Vector3 &a_c_v3Vector3);//Copy constructor.

	Vector3(const float a_c_fX, float a_c_fY, float a_c_fZ);//Constructor with three scalar values.

	Vector3(const Vector2 &a_c_v2Vector2, float a_c_fZ = 0);//Constructor with a Vector2 and a scalar value.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	const float* Vector3::getVector()const;//Returns a pointer to the first element in the array.

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

	Vector3 operator+(const Vector3 &a_c_v3Vector3)const;//Overloaded addition operation for Vector3.

	Vector3 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Vector3.

	Vector3 operator-(const Vector3 &a_c_v3Vector3)const;//Overloaded subtraction operation for Vector3.

	Vector3 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Vector3.

	Vector3 operator*(const Vector3 &a_c_v3Vector3)const;//Overloaded multiplication operation for Vector3.

	Vector3 operator*(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Multiplication for a vector times a matrix as introducing this as an overload would cause circular dependency.

	Vector3 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Vector3.

	Vector3 operator/(const Vector3 &a_c_v3Vector3)const;//Overloaded division operation for Vector3.

	//\===========================================================================================
	//\ Assignment Operation Overloads
	//\==========================================================================================
	
	Vector3 operator+=(const float &a_c_fScalar);//Overloaded plus equals operation for Vector3.

	Vector3 operator+=(const Vector3 &a_c_v3Vector3);//Overloaded plus equals operation for Vector3.

	Vector3 operator-=(const float &a_c_fScalar);//Overloaded decrease equals operation for Vector3.

	Vector3 operator-=(const Vector3 &a_c_v3Vector3);//Overloaded decrease equals operation for Vector3.

	Vector3 operator=(const float &a_c_fScalar);//Overloaded equals operation for Vector3.

	Vector3 operator=(const Vector3 &a_c_v3Vector3);//Overloaded equals operation for Vector3.
	
	Vector3 operator*=(const float &a_c_fScalar);//Overloaded times equals operation for Vector3.
	
	Vector3 operator*=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Vector3.

	Vector3 operator/=(const float &a_c_fScalar);//Overloaded divide equals operation for Vector3.

	Vector3 operator/=(const Vector3 &a_c_v3Vector3);//Overloaded divide equals operation for Vector3.
	
	//\===========================================================================================
	//\ Relational Operation Overloads
	//\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Vector3.

	bool operator!=(const Vector3 &a_c_v3Vector3)const;//Overloaded not equals operation for Vector3.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Vector3.

	bool operator==(const Vector3 &a_c_v3Vector3)const;//Overloaded is equals operation for Vector3.
	
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

	float distance(const Vector3 &a_c_v3Vector3)const;//Returns the distance from this Vector3 and the passed in argument.

	//\===========================================================================================
	//\ Squared Distance Between this Vector3 and another Vector3
	//\===========================================================================================

	float squaredDistance(const Vector3 &a_c_v3Vector3)const;//Returns the squared distance from this Vector3 and the passed in argument.

	//\===========================================================================================
	//\ Dot Product
	//\===========================================================================================

	float dotProduct(const Vector3 &a_c_v3Vector3)const;//A dot product function that takes in a Vector3.

	//\===========================================================================================
	//\ Cross Product
	//\===========================================================================================

	Vector3 crossProduct(const Vector3 &a_c_v3Vector3)const;//A cross product function that takes in a Vector3 .

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
						
	//\===========================================================================================
	//\ Set To Zero
	//\===========================================================================================

	void setZero();//Makes each Matrix4x4 element equal to 0. 

	//\===========================================================================================
	//\ Zero
	//\===========================================================================================

	Vector3 zero()const;//Returns a Vector3 zero matrix.

	//\===========================================================================================
	//\ Special Points
	//\===========================================================================================

	static const Vector3 ZERO;//A Vector3 equal to {0,0,0}.
	
	static const Vector3 UNIT_X;//A Vector3 equal to {1,0,0}.

	static const Vector3 UNIT_Y;//A Vector3 equal to {0,1,0}.

	static const Vector3 UNIT_Z;//A Vector3 equal to {0,0,1}.

	static const Vector3 NEGATIVE_UNIT_X;//A Vector3 equal to {-1,0,0}.

	static const Vector3 NEGATIVE_UNIT_Y;//A Vector3 equal to {0,-1,0}.

	static const Vector3 NEGATIVE_UNIT_Z;//A Vector3 equal to {0,0,-1}.

	static const Vector3 UNIT_SCALE;//A Vector3 equal to {1,1,1}.

};

#endif

