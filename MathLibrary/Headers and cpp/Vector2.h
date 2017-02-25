//\===========================================================================================
//\ File: Vector2.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector2 class declarations.
//\===========================================================================================

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

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
	//\ Variables
	//\===========================================================================================

	float fX, fY;//Two float variables created.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector2();//A default constructor that initialises X and Y to 0.

	Vector2(float a_fX = 0, float a_fY = 0);//Constructor.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	float getfX();//A getter to get the x part of vector2.

	float getfY();//A getter to get the y part of vector2.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================

	void setfX(const float &a_fX);//A setter to set the x part of vector2 to the passed in argument.

	void setfY(const float &a_fY);//A setter to set the y part of vector2 to the passed in argument.

	//\===========================================================================================
	//\ Operation Overloads
	//\===========================================================================================

	Vector2 operator+(const float &a_fScalar);//Overloaded addition operation for Vector2.

	Vector2 operator+(const Vector2 &a_vVector2);//Overloaded addition operation for Vector2.

	Vector2 operator-(const float &a_fScalar);//Overloaded subtraction operation for Vector2.
	
	Vector2 operator-(const Vector2 &a_vVector2);//Overloaded subtraction operation for Vector2.

	Vector2 operator*(const float &a_fScalar);//Overloaded multiplication operation for Vector2.

	Vector2 operator*(const Vector2 &a_vVector2);//Overloaded multiplication operation for Vector2.
	
	Vector2 operator/(const float &a_fScalar);//Overloaded division operation for Vector2.

	Vector2 operator/(const Vector2 &a_vVector2);//Overloaded division operation for Vector2.

	Vector2 operator!=(const float &a_fScalar);//Overloaded not equals operation for Vector2.

	Vector2 operator!=(const Vector2 &a_vVector2);//Overloaded not equals operation for Vector2.

	Vector2 operator==(const float &a_fScalar);//Overloaded is equals operation for Vector2.

	Vector2 operator==(const Vector2 &a_vVector2);//Overloaded is equals operation for Vector2.
	
	//\===========================================================================================
	//\ Length
	//\===========================================================================================
	
	float length();//A function that returns the length of the vector as a float.

	//\===========================================================================================
	//\ Squared Length
	//\===========================================================================================

	float squaredLength();//A function that returns the length squared of the vector as a float.

	//\===========================================================================================
	//\ Distance Between this vector2 and another vector2
	//\===========================================================================================

	float distance(const Vector2 &a_vVector2);//Returns the distance from this vector2 and the passed in argument.

	//\===========================================================================================
	//\ Squared Distance Between this vector2 and another vector2
	//\===========================================================================================

	float distance(const Vector2 &a_vVector2);//Returns the squared distance from this vector2 and the passed in argument.

	//\===========================================================================================
	//\ Dot Product
	//\===========================================================================================
	
	float dotProduct(const Vector2 &a_vVector2);//A dot product function that takes in a Vector2.
												
	//\===========================================================================================
	//\ Cross Product
	//\===========================================================================================

	float crossProduct(const Vector2 &a_vVector2);//A dot product function that takes in a Vector2.

	//\===========================================================================================
	//\ Perpendicular
	//\===========================================================================================
	
	Vector2 perpendicularClockwise();//A perpendicularClockwise function for this Vector2.

	Vector2 perpendicularCounterClockwise();//A perpendicularCounterClockwise function for this Vector2.

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

	void normalise();//A normalisation function that sets the fX and fY of Vector2 to a normalised version.
		
	//\===========================================================================================
	//\ Return A Unit Vector
	//\===========================================================================================

	Vector2 unit();//A function that returns a unit vector created from this vector.

};

#endif
