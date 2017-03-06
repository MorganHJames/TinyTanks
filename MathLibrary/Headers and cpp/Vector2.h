//\===========================================================================================
//\ File: Vector2.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector2 class declarations.
//\===========================================================================================

#ifndef _Vector2_H_
#define _Vector2_H_

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Vector2
//\ Brief:Overloaded operator functions for add, subtract, and multiply by both a scalar 
//\ value and by a Vector2.
//\ Functions to allow for dot product, perpendicular, rotation, magnitude, normalisation.
//\===========================================================================================

class Vector2
{
private:
	//\===========================================================================================
	//\ Member Variables
	//\===========================================================================================

	float fX, fY;//Two float variables created.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector2();//A default constructor that initialises X and Y to 0.

	Vector2(const float a_c_fX = 0, float a_c_fY = 0);//Constructor.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	float getfX()const;//A getter to get the x part of Vector2.

	float getfY()const;//A getter to get the y part of Vector2.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================

	void setfX(const float &a_c_fX);//A setter to set the x part of Vector2 to the passed in argument.

	void setfY(const float &a_c_fY);//A setter to set the y part of Vector2 to the passed in argument.

	//\===========================================================================================
	//\ Arithmetic Operation Overloads
	//\===========================================================================================

	Vector2 operator+(const float &a_c_fScalar)const;//Overloaded addition operation for Vector2.

	Vector2 operator+(const Vector2 &a_c_vVector2)const;//Overloaded addition operation for Vector2.

	Vector2 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Vector2.

	Vector2 operator-(const Vector2 &a_c_vVector2)const;//Overloaded subtraction operation for Vector2.

	Vector2 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Vector2.

	Vector2 operator*(const Vector2 &a_c_vVector2)const;//Overloaded multiplication operation for Vector2.

	Vector2 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Vector2.

	Vector2 operator/(const Vector2 &a_c_vVector2)const;//Overloaded division operation for Vector2.

	//\===========================================================================================
	//\ Assignment Operation Overloads
	//\===========================================================================================

	Vector2 operator=(const float &a_c_fScalar);//Overloaded equals operation for Vector2.

	Vector2 operator=(const Vector2 &a_c_vVector2);//Overloaded equals operation for Vector2.

	//\===========================================================================================
	//\ Relational Operation Overloads
	//\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Vector2.

	bool operator!=(const Vector2 &a_c_vVector2)const;//Overloaded not equals operation for Vector2.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Vector2.

	bool operator==(const Vector2 &a_c_vVector2)const;//Overloaded is equals operation for Vector2.

	//\===========================================================================================
	//\ Magnitude
	//\===========================================================================================

	float magnitude()const;//A magnitude function that returns a float.

	//\===========================================================================================
	//\ Squared Magnitude
	//\===========================================================================================

	float squaredMagnitude()const;//A function that returns the Magnitude squared of the vector as a float.

	//\===========================================================================================
	//\ Distance Between this Vector2 and another Vector2
	//\===========================================================================================

	float distance(const Vector2 &a_c_vVector2)const;//Returns the distance from this Vector2 and the passed in argument.

	//\===========================================================================================
	//\ Squared Distance Between this Vector2 and another Vector2
	//\===========================================================================================

	float squaredDistance(const Vector2 &a_c_vVector2)const;//Returns the squared distance from this Vector2 and the passed in argument.

	//\===========================================================================================
	//\ Dot Product
	//\===========================================================================================

	float dotProduct(const Vector2 &a_c_vVector2)const;//A dot product function that takes in a Vector2.

	//\===========================================================================================
	//\ Cross Product
	//\===========================================================================================

	float crossProduct(const Vector2 &a_c_vVector2)const;//A dot product function that takes in a Vector2.

	//\===========================================================================================
	//\ Perpendicular
	//\===========================================================================================

	Vector2 perpendicularClockwise()const;//A perpendicularClockwise function for this Vector2.

	Vector2 perpendicularCounterClockwise()const;//A perpendicularCounterClockwise function for this Vector2.

	//\===========================================================================================
	//\ Rotation
	//\===========================================================================================

	void rotate(float a_fAngle);//A Rotate function that takes in an angle in float format.

	//\===========================================================================================
	//\ Normalisation
	//\===========================================================================================

	Vector2 normalise();//A normalisation function that sets the fX and fY of Vector2 to a normalised version.

	//\===========================================================================================
	//\ Return A Unit Vector
	//\===========================================================================================

	Vector2 unit()const;//A function that returns a unit vector created from this vector.

};

#endif
