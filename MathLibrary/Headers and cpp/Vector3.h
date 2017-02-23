//\===========================================================================================
//\ File: Vector3.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector3 class declarations.
//\===========================================================================================

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

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
public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector3(float a_fX = 0, float a_fY = 0);//Constructor.

	//\===========================================================================================
	//\ Destructor
    //\===========================================================================================

	~Vector3();

	//\===========================================================================================
	//\ Operation Overloads
	//\===========================================================================================

	Vector3 operator+(const float &a_fScalar);//Overloaded addition operation for Vector3.

	Vector3 operator+(const Vector3 &a_vVector3);//Overloaded addition operation for Vector3.

	Vector3 operator-(const float &a_fScalar);//Overloaded subtraction operation for Vector3.

	Vector3 operator-(const Vector3 &a_vVector3);//Overloaded subtraction operation for Vector3.

	Vector3 operator*(const float &a_fScalar);//Overloaded multiplication operation for Vector3.

	Vector3 operator*(const Vector3 &a_vVector3);//Overloaded multiplication operation for Vector3.

	//\===========================================================================================
    //\ Dot Product
	//\===========================================================================================

	float dotProduct(const Vector3 &a_vVector3);//A dot product function that takes in a Vector3.

	//\===========================================================================================
	//\ Perpendicular
	//\===========================================================================================

	Vector3 perpendicularClockwise(const Vector3 &a_vVector3);//A perpendicularClockwise function that takes in a Vector3 .

	Vector3 perpendicularCounterClockwise(const Vector3 &a_vVector3);//A perpendicularCounterClockwise function that takes in a Vector3 .

	//\===========================================================================================
	//\ Rotation
	//\===========================================================================================

	void rotate(const float fAngle);//A Rotate function that takes in an angle in float format.

	//\===========================================================================================
    //\ Magnitude
    //\===========================================================================================

	float magnitude();//A magnitude function that returns a float.

	//\===========================================================================================
	//\ Normalisation
	//\===========================================================================================

	void normalise();//A normalisation function that sets the fX and fY of Vector3 to a normalised version.

private:
	float fX, fY, fZ;//Coordinate storage.
private:
};

#endif
