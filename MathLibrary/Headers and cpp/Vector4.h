//\===========================================================================================
//\ File: Vector4.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Vector4 class declarations.
//\===========================================================================================

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include "Vector3.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Vector4
//\ Brief: Overloaded operator functions for add, subtract, and multiply by both a scalar 
//\ value and by a Vector4.
//\ Constructor to create vector4 from vector 2 & 3.
//\ Functions to allow for dot product, Cross product, rotation, magnitude, normalisation.
//\===========================================================================================

class Vector4
{
private:
	//\===========================================================================================
	//\ Member Variables
	//\===========================================================================================

	float fX, fY, fZ, fW;//Four float variables created.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Vector4();//Constructor default that sets all variables to 0.

	Vector4(const float a_c_fX = 0, float a_c_fY = 0, float a_c_fZ = 0, float a_c_fW = 0);//Constructor with four scalar values.

	Vector4(const Vector2 &a_c_vVector2, float a_c_fZ = 0, float a_c_fW = 0);//Constructor with a Vector2 and two scalar value.

	Vector4(const Vector3 &a_c_vVector3, float a_c_fW = 0);//Constructor with a Vector3 and a scalar value.

														   //\===========================================================================================
														   //\ Getters
														   //\===========================================================================================

	float getfX()const;//A getter to get the x part of Vector4.

	float getfY()const;//A getter to get the y part of Vector4.

	float getfZ()const;//A getter to get the z part of Vector4.

	float getfW()const;//A getter to get the w part of Vector4.

					   //\===========================================================================================
					   //\ Setters
					   //\===========================================================================================

	void setfX(const float a_c_fX);//A setter to set the x part of Vector4 to the passed in argument.

	void setfY(const float a_c_fY);//A setter to set the y part of Vector4 to the passed in argument.

	void setfZ(const float a_c_fZ);//A setter to set the z part of Vector4 to the passed in argument.

	void setfW(const float a_c_fW);//A setter to set the w part of Vector4 to the passed in argument.

								   //\===========================================================================================
								   //\ Arithmetic Operation Overloads
								   //\===========================================================================================

	Vector4 operator+(const float &a_c_fScalar)const;//Overloaded addition operation for Vector4.

	Vector4 operator+(const Vector4 &a_c_vVector4)const;//Overloaded addition operation for Vector4.

	Vector4 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Vector4.

	Vector4 operator-(const Vector4 &a_c_vVector4)const;//Overloaded subtraction operation for Vector4.

	Vector4 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Vector4.

	Vector4 operator*(const Vector4 &a_c_vVector4)const;//Overloaded multiplication operation for Vector4.

	Vector4 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Vector4.

	Vector4 operator/(const Vector4 &a_c_vVector4)const;//Overloaded division operation for Vector4.

														//\===========================================================================================
														//\ Assignment Operation Overloads
														//\===========================================================================================

	Vector4 operator=(const float &a_c_fScalar);//Overloaded equals operation for Vector4.

	Vector4 operator=(const Vector4 &a_c_vVector4);//Overloaded equals operation for Vector4.

												   //\===========================================================================================
												   //\ Relational Operation Overloads
												   //\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Vector4.

	bool operator!=(const Vector4 &a_c_vVector4)const;//Overloaded not equals operation for Vector4.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Vector4.

	bool operator==(const Vector4 &a_c_vVector4)const;//Overloaded is equals operation for Vector4.

													  //\===========================================================================================
													  //\ Magnitude
													  //\===========================================================================================

	float magnitude()const;//A magnitude function that returns a float.

						   //\===========================================================================================
						   //\ Squared Magnitude
						   //\===========================================================================================

	float squaredMagnitude()const;//A function that returns the Magnitude squared of the vector as a float.

								  //\===========================================================================================
								  //\ Distance Between this Vector4 and another Vector4
								  //\===========================================================================================

	float distance(const Vector4 &a_c_vVector4)const;//Returns the distance from this Vector4 and the passed in argument.

													 //\===========================================================================================
													 //\ Squared Distance Between this Vector4 and another Vector4
													 //\===========================================================================================

	float squaredDistance(const Vector4 &a_c_vVector4)const;//Returns the squared distance from this Vector4 and the passed in argument.

															//\===========================================================================================
															//\ Dot Product
															//\===========================================================================================

	float dotProduct(const Vector4 &a_c_vVector4)const;//A dot product function that takes in a Vector4.

													   //\===========================================================================================
													   //\ Cross Product
													   //\===========================================================================================

	Vector4 crossProduct(const Vector4 &a_c_vVector4)const;//A cross product function that takes in a Vector4 .

														   //\===========================================================================================
														   //\ Rotation
														   //\===========================================================================================

	void rotateZ(float a_fDegAngle);//A Rotate function that takes in an angle in float format.

	void rotateX(float a_fDegAngle);//A Rotate function that takes in an angle in float format.

	void rotateY(float a_fDegAngle);//A Rotate function that takes in an angle in float format.

									//\===========================================================================================
									//\ Normalisation
									//\===========================================================================================

	Vector4 normalise();//A normalisation function that sets the fX, fY, fZ and fW of Vector4 to a normalised version.

						//\===========================================================================================
						//\ Return A Unit Vector
						//\===========================================================================================

	Vector4 unit()const;//A function that returns a unit vector created from this vector.

};

#endif
