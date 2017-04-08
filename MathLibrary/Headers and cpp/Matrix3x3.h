//\===========================================================================================
//\ File: Matrix3x3.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Matrix3x3 class declarations.
//\===========================================================================================

#ifndef _MATRIX3X3_H_
#define _MATRIX3X3_H_

#include "Vector3.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Matrix3x3
//\ Brief: Overloaded operator functions for add, subtract, and multiply by both a scalar 
//\ value, Vector3 and by a Matrix3x3.
//\ Functions to rotate around euler axis, inversion, scale, transpose a point, set to 
//\ identity, set to zero, override access operators to retrieve matrix value at row / column.
//\===========================================================================================

class Matrix3x3
{
private:
	//\===========================================================================================
	//\ Member Variables held in an unnamed union for accessibility
	//\===========================================================================================

	union//Everything in the union is at the same memory address.
	{
		float m_fmMatrix[3][3];//A matrix of floats in a 3 x 3 grid created by two arrays of three.

		struct//A structure three rows of three floats to make a matrix.
		{
			float m_fm_00, m_fm_01, m_fm_02;//Floats representing the top row of the matrix.
						  
			float m_fm_10, m_fm_11, m_fm_12;//Floats representing the middle row of the matrix.
						 
			float m_fm_20, m_fm_21, m_fm_22;//Floats representing the bottom row of the matrix.
		};

		struct//A structure containing nine floats representing a matrix.
		{
			float m_fiMatrix[9];//An array of nine floats.
		};

		struct//A structure that contains three Vector3's to make up a matrix.
		{
			Vector3 m_v3XAxis;//A Vector3 to contain the x axis of the matrix.
		
			Vector3 m_v3YAxis;//A Vector3 to contain the y axis of the matrix.
		
			union//Everything in the union is at the same memory address.
			{
				Vector3 m_v3ZAxis;//A Vector3 to contain the z axis of the matrix.
			
				Vector3 m_v3Translation;//A Vector3 to contain the translation of the matrix.
			};
		};
	};
public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Matrix3x3();//The Default constructor for a Matrix3x3 that initialises everything to 0.

	Matrix3x3(const Matrix3x3 &a_c_fm3Matrix3x3);//Copy constructor.

	Matrix3x3(const float a_c_fmMatrix[3][3]);//Constructor for a Matrix3x3 that is made from two arrays of three.

	Matrix3x3(const 
		float a_c_fm_00,
		float a_c_fm_01, 
		float a_c_fm_02,
		float a_c_fm_10, 
		float a_c_fm_11,
		float a_c_fm_12, 
		float a_c_fm_20, 
		float a_c_fm_21, 
		float a_c_fm_22);//Constructor that takes nine floats to make a Matrix3x3.

	Matrix3x3(const float a_c_fiMatrix[9]);//Constructor that takes an array of nine floats to make a Matrix3x3.

	Matrix3x3(const
		Vector3 a_c_v3XAxis, 
		Vector3 a_c_v3YAxis, 
		Vector3 a_c_v3ZAxis);//Constructor for a Matrix3x3 made from three Vector3's.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	const float* getMatrix()const;//Returns a pointer to the first element in the array.

	float getmMatrix(const int &a_c_iRow, int &a_c_iCol)const;//A getter to return a float at the point specified with the two arguments.

	float getiMatrix(const int &a_c_iPosition)const;//A getter to Returns a float from the matrix at the position of the argument passed in.

	Vector3 getXAxis()const;//A getter to return the vXAxis of matrix3x3 in the form of a Vector3.

	Vector3 getYAxis()const;//A getter to return the vYAxis of matrix3x3 in the form of a Vector3.

	Vector3 getZAxis()const;//A getter to return the vZAxis of matrix3x3 in the form of a Vector3.

	Vector3 getTranslation()const;//A getter to return the vTranslation of matrix3x3 in the form of a Vector3.

	Vector3 getColumn(const int &a_c_iCol)const;//A getter to return the column specified by the argument a_c_iCol.

	Vector3 getRow(const int &a_c_iRow)const;//A getter to return the row specified by the argument a_c_iRow.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================

	void setmMatrix(const int &a_c_iRow, int &a_c_iCol, float &a_c_fNewNumber);//A setter to change the float in the matrix at the point specified with the two arguments.

	void setiMatrix(const int &a_c_iPosition, float &a_c_fNewNumber);//A setter to change the float in the matrix at the position of the argument passed in.

	void setXAxis(const Vector3 &a_c_v3Vector3);//A setter to change the vXAxis of matrix3x3 to the Vector3 argument.

	void setYAxis(const Vector3 &a_c_v3Vector3);//A setter to change the vYAxis of matrix3x3 to the Vector3 argument.

	void setZAxis(const Vector3 &a_c_v3Vector3);//A setter to change the vZAxis of matrix3x3 to the Vector3 argument.

	void setTranslation(const Vector3 &a_c_v3Vector3);//A setter to change the vTranslation of matrix3x3 to the vTranslation argument.

	void setColumn(const int &a_c_iCol, Vector3 &a_c_v3Vector3);//A setter for the column specified by the argument a_c_iCol.

	void setRow(const int &a_c_iRow, Vector3 &a_c_v3Vector3);//A setter for the row specified by the argument a_c_iRow.

	//\===========================================================================================
	//\ Arithmetic Operation Overloads
	//\===========================================================================================

	Matrix3x3 operator+(const float &a_c_fScalar)const;//Overloaded addition operation for Matrix3x3.

	Matrix3x3 operator+(const Vector3 &a_c_v3Vector3)const;//Overloaded addition operation for Matrix3x3.

	Matrix3x3 operator+(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Overloaded addition operation for Matrix3x3.

	Matrix3x3 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Matrix3x3.

	Matrix3x3 operator-(const Vector3 &a_c_v3Vector3)const;//Overloaded subtraction operation for Matrix3x3.

	Matrix3x3 operator-(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Overloaded subtraction operation for Matrix3x3.

	Matrix3x3 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Matrix3x3.

	Vector3 operator*(const Vector3 &a_c_v3Vector3)const;//Overloaded multiplication operation for Matrix3x3.

	Matrix3x3 operator*(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Overloaded multiplication operation for Matrix3x3.

	Matrix3x3 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Matrix3x3.

	Vector3 operator/(const Vector3 &a_c_v3Vector3)const;//Overloaded division operation for Matrix3x3.

	Matrix3x3 operator/(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Overloaded division operation for Matrix3x3.

	//\===========================================================================================
	//\ Assignment Operation Overloads
	//\===========================================================================================

	Matrix3x3 operator+=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator+=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator+=(const Matrix3x3 &a_c_fm3Matrix3x3);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator-=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator-=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator-=(const Matrix3x3 &a_c_fm3Matrix3x3);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator=(const float &a_c_fScalar);//Overloaded equals operation for Matrix3x3.

	Matrix3x3 operator=(const Vector3 &a_c_v3Vector3);//Overloaded equals operation for Matrix3x3.

	Matrix3x3 operator=(const Matrix3x3 &a_c_fm3Matrix3x3);//Overloaded equals operation for Matrix3x3.

	Matrix3x3 operator*=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator*=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix3x3.
	
	Matrix3x3 operator*=(const Matrix3x3 &a_c_fm3Matrix3x3);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator/=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator/=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix3x3.

	Matrix3x3 operator/=(const Matrix3x3 &a_c_fm3Matrix3x3);//Overloaded times equals operation for Matrix3x3.

	//\===========================================================================================
	//\ Relational Operation Overloads
	//\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Matrix3x3.

	bool operator!=(const Vector3 &a_c_v3Vector3)const;//Overloaded not equals operation for Matrix3x3.

	bool operator!=(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Overloaded not equals operation for Matrix3x3.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Matrix3x3.

	bool operator==(const Vector3 &a_c_v3Vector3)const;//Overloaded is equals operation for Matrix3x3.

	bool operator==(const Matrix3x3 &a_c_fm3Matrix3x3)const;//Overloaded is equals operation for Matrix3x3.

	//\===========================================================================================
	//\ Rotate Around Euler Axis
	//\===========================================================================================

	void rotate(float &a_fAngle);//Rotates the Matrix3x3 by the angle in degrees around the z axis. 

	Matrix3x3 getRotationMatrix(float &a_fAngle)const;//Returns the Rotation Matrix3x3 by the angle in degrees. 

	//\===========================================================================================
	//\ Determinant
	//\===========================================================================================

	float determinant()const;//A function to get the determinant of a Matrix3x3.

	//\===========================================================================================
	//\ Inversion
	//\===========================================================================================

	bool inverse();//A function that returns the inverse of a Matrix3x3.

	//\===========================================================================================
	//\ Scale
	//\===========================================================================================
	
	void scale(const float &a_c_fXScale, float &a_c_fYScale);//Rotates the Matrix3x3 by the angle in degrees. 
	
	Matrix3x3 getScaleMatrix(const float &a_c_fXScale, float &a_c_fYScale)const;//Returns the scale Matrix3x3.    

	//\===========================================================================================
	//\ Transpose A Point
	//\===========================================================================================

	void transpose();//Transposes the Matrix3x3. 

	//\===========================================================================================
	//\ Set To Identity
	//\===========================================================================================

	void setIdentity();//Makes the Matrix3x3 an identity matrix. 

	//\===========================================================================================
	//\ Identity
	//\===========================================================================================
 
	Matrix3x3 identity()const;//Returns a Matrix3x3 identity matrix.

	//\===========================================================================================
	//\ Set To Zero
	//\===========================================================================================

	void setZero();//Makes each Matrix3x3 element equal to 0. 

	//\===========================================================================================
	//\ Zero
	//\===========================================================================================

	Matrix3x3 zero()const;//Returns a Matrix3x3 zero matrix.

	//\===========================================================================================
	//\ Special Points
	//\===========================================================================================

	static const Matrix3x3 ZERO;//A Matrix3x3 where every element is equal to zero.

	static const Matrix3x3 IDENTITY;//A Matrix3x3 where the elements are equal to the identity matrix.

};

#endif
