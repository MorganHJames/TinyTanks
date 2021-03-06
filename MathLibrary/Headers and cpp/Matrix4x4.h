//\===========================================================================================
//\ File: Matrix4x4.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Matrix4x4 class declarations.
//\===========================================================================================

#ifndef _MATRIX4X4_H_
#define _MATRIX4X4_H_

#include "Matrix3x3.h"
#include "Vector4.h"
#include "Vector3.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Matrix4x4
//\ Brief: Overloaded operator functions for add, subtract, and multiply by both a scalar 
//\ value, Vector3 and by a Matrix4x4.
//\ Convert 3x3 Matrix to 4x4 via constructor.
//\ Functions to rotate around euler axis, inversion, scale, transpose a point, set to 
//\ identity, set to zero, override access operators to retrieve matrix value at row / column.
//\===========================================================================================

class Matrix4x4
{
private:
	//\===========================================================================================
	//\ Member Variables held in an unnamed union for accessibility
	//\===========================================================================================

	union//Everything in the union is at the same memory address.
	{
		float m_fmMatrix[4][4];//A matrix of floats in a 4x4 grid created by two arrays of four.

		struct//A structure three rows of three floats to make a matrix.
		{
			float m_fm_00, m_fm_01, m_fm_02, m_fm_03;//Floats representing the first row of the matrix.
				
			float m_fm_10, m_fm_11, m_fm_12, m_fm_13;//Floats representing the second row of the matrix.
							
			float m_fm_20, m_fm_21, m_fm_22, m_fm_23;//Floats representing the third row of the matrix.
								
			float m_fm_30, m_fm_31, m_fm_32, m_fm_33;//Floats representing the fourth row of the matrix.
		};

		struct//A structure containing nine floats representing a matrix.
		{
			float m_fiMatrix[16];//An array of sixteen floats.
		};

		struct//A structure that contains four Vector4's to make up a matrix.
		{
			Vector4 m_v4XAxis;//A Vector4 to contain the x axis of the matrix.
		
			Vector4 m_v4YAxis;//A Vector4 to contain the y axis of the matrix.
			
			Vector4 m_v4ZAxis;//A Vector4 to contain the z axis of the matrix.
			
			union//Everything in the union is at the same memory address.
			{
				Vector4 m_v4WAxis;//A Vector4 to contain the w axis of the matrix.
			
				Vector4 m_v4Translation;//A Vector4 to contain the translation of the matrix.
			};
		};
	};
	
public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Matrix4x4();//The Default constructor for a Matrix4x4 that initialises everything to 0.

	Matrix4x4(const Matrix4x4 &a_c_fm4Matrix4x4);//Copy constructor.

	Matrix4x4(const float a_c_fmMatrix[4][4]);//Constructor for a Matrix4x4 that is made from two arrays of four.

	Matrix4x4(const//Constructor that takes sixteen floats to make a Matrix4x4.
		float a_c_fm_00,
		float a_c_fm_01,
		float a_c_fm_02,
		float a_c_fm_03,
		float a_c_fm_10,
		float a_c_fm_11, 
		float a_c_fm_12,
		float a_c_fm_13, 
		float a_c_fm_20,
		float a_c_fm_21, 
		float a_c_fm_22, 
		float a_c_fm_23,
		float a_c_fm_30,
		float a_c_fm_31,
		float a_c_fm_32,
		float a_c_fm_33);

	Matrix4x4(const float a_c_fiMatrix[16]);//Constructor that takes an array of sixteen floats to make a Matrix4x4.

	Matrix4x4(const//Constructor for a Matrix4x4 made from four Vector4's.
		Vector4  a_c_v4XAxis,
		Vector4  a_c_v4YAxis,
		Vector4  a_c_v4ZAxis,
		Vector4  a_c_v4WAxis);

	Matrix4x4(const Matrix3x3 a_c_fm3Matrix3x3);//Constructor to make a Matrix4x4 from a Matrix3x3.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

	const float* getMatrix()const;//Returns a pointer to the first element in the array.

	float getmMatrix(const int &a_c_iRow, int &a_c_iCol)const;//A getter to return a float at the point specified with the two arguments.

	float getiMatrix(const int &a_c_iPosition)const;//A getter to Returns a float from the matrix at the position of the argument passed in.

	Vector4 getXAxis()const;//A getter to return the vXAxis of Matrix4x4 in the form of a Vector4.

	Vector4 getYAxis()const;//A getter to return the vYAxis of Matrix4x4 in the form of a Vector4.

	Vector4 getZAxis()const;//A getter to return the vZAxis of Matrix4x4 in the form of a Vector4.

	Vector4 getWAxis()const;//A getter to return the vWAxis of Matrix4x4 in the form of a Vector4.

	Vector4 getTranslation()const;//A getter to return the vTranslation of Matrix4x4 in the form of a Vector4.

	Vector4 getColumn(const int &a_c_iCol)const;//A getter to return the column specified by the argument a_c_iCol.

	Vector4 getRow(const int &a_c_iRow)const;//A getter to return the row specified by the argument a_c_iRow.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================

	void setmMatrix(const int &a_c_iRow, int &a_c_iCol, float &a_c_fNewNumber);//A setter to change the float in the matrix at the point specified with the two arguments.

	void setiMatrix(const int &a_c_iPosition, float &a_c_fNewNumber);//A setter to change the float in the matrix at the position of the argument passed in.

	void setXAxis(const Vector4 &a_c_v4Vector4);//A setter to change the vXAxis of Matrix4x4 to the Vector4 argument.

	void setYAxis(const Vector4 &a_c_v4Vector4);//A setter to change the vYAxis of Matrix4x4 to the Vector4 argument.

	void setZAxis(const Vector4 &a_c_v4Vector4);//A setter to change the vZAxis of Matrix4x4 to the Vector4 argument.
	
	void setWAxis(const Vector4 &a_c_v4Vector4);//A setter to change the vWAxis of Matrix4x4 to the Vector4 argument.

	void setTranslation(const Vector4 &a_c_v4Vector4);//A setter to change the vTranslation of Matrix4x4 to the vTranslation argument.

	void setColumn(const int &a_c_iCol, Vector4 &a_c_v4Vector4);//A setter for the column specified by the argument a_c_iCol.

	void setRow(const int &a_c_iRow, Vector4 &a_c_v4Vector4);//A setter for the row specified by the argument a_c_iRow.

	//\===========================================================================================
	//\ Arithmetic Operation Overloads
	//\===========================================================================================

	Matrix4x4 operator+(const float &a_c_fScalar)const;//Overloaded addition operation for Matrix4x4.

	Matrix4x4 operator+(const Vector3 &a_c_v3Vector3)const;//Overloaded addition operation for Matrix4x4.

	Matrix4x4 operator+(const Matrix4x4 &a_c_fm4Matrix4x4)const;//Overloaded addition operation for Matrix4x4.

	Matrix4x4 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Matrix4x4.

	Matrix4x4 operator-(const Vector3 &a_c_v3Vector3)const;//Overloaded subtraction operation for Matrix4x4.

	Matrix4x4 operator-(const Matrix4x4 &a_c_fm4Matrix4x4)const;//Overloaded subtraction operation for Matrix4x4.

	Matrix4x4 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Matrix4x4.

	Vector4 operator*(const Vector3 &a_c_v3Vector3)const;//Overloaded multiplication operation for Matrix4x4.

	Matrix4x4 operator*(const Matrix4x4 &a_c_fm4Matrix4x4)const;//Overloaded multiplication operation for Matrix4x4.

	Matrix4x4 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Matrix4x4.

	Vector4 operator/(const Vector3 &a_c_v3Vector3)const;//Overloaded division operation for Matrix4x4.

	Matrix4x4 operator/(const Matrix4x4 &a_c_fm4Matrix4x4)const;//Overloaded division operation for Matrix4x4.

	//\===========================================================================================
	//\ Assignment Operation Overloads
	//\===========================================================================================
	
	Matrix4x4 operator+=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator+=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator+=(const Matrix4x4 &a_c_fm4Matrix4x4);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator-=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator-=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator-=(const Matrix4x4 &a_c_fm4Matrix4x4);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator=(const float &a_c_fScalar);//Overloaded equals operation for Matrix4x4.

	Matrix4x4 operator=(const Vector3 &a_c_v3Vector3);//Overloaded equals operation for Matrix4x4.

	Matrix4x4 operator=(const Vector4 &a_c_v4Vector4);//Overloaded equals operation for Matrix4x4.

	Matrix4x4 operator=(const Matrix4x4 &a_c_fm4Matrix4x4);//Overloaded equals operation for Matrix4x4.

	Matrix4x4 operator*=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator*=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator*=(const Matrix4x4 &a_c_fm4Matrix4x4);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator/=(const float &a_c_fScalar);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator/=(const Vector3 &a_c_v3Vector3);//Overloaded times equals operation for Matrix4x4.

	Matrix4x4 operator/=(const Matrix4x4 &a_c_fm4Matrix4x4);//Overloaded times equals operation for Matrix4x4.

	//\===========================================================================================
	//\ Relational Operation Overloads
	//\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Matrix4x4.

	bool operator!=(const Vector3 &a_c_v3Vector3)const;//Overloaded not equals operation for Matrix4x4.

	bool operator!=(const Matrix4x4 &a_c_fm4Matrix4x4)const;//Overloaded not equals operation for Matrix4x4.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Matrix4x4.

	bool operator==(const Vector3 &a_c_v3Vector3)const;//Overloaded is equals operation for Matrix4x4.

	bool operator==(const Matrix4x4 &a_c_fm4Matrix4x4)const;//Overloaded is equals operation for Matrix4x4.

	//\===========================================================================================
	//\ Rotate Around Euler Axis
	//\===========================================================================================
	
	void rotateX(float &a_fAngle);//Rotates the Matrix4x4 by the angle in degrees. 

	void rotateY(float &a_fAngle);//Rotates the Matrix4x4 by the angle in degrees. 

	void rotateZ(float &a_fAngle);//Rotates the Matrix4x4 by the angle in degrees. 

	Matrix4x4 getXRotationMatrix(float &a_fAngle)const;//Returns the X Rotation Matrix4x4 by the angle in degrees. 

	Matrix4x4 getYRotationMatrix(float &a_fAngle)const;//Returns the Y Rotation Matrix4x4 by the angle in degrees.

	Matrix4x4 getZRotationMatrix(float &a_fAngle)const;//Returns the Z Rotation Matrix4x4 by the angle in degrees.

	//\===========================================================================================
	//\ Determinant
	//\===========================================================================================

	float determinant()const;//A function to get the determinant of a Matrix4x4.

	//\===========================================================================================
	//\ Inversion
	//\===========================================================================================

	bool inverse();//A function that returns the inverse of a Matrix4x4.

	//\===========================================================================================
	//\ Scale
	//\===========================================================================================

	void scale(const float &a_c_fXScale, float &a_c_fYScale, float &a_c_fZScale);//Rotates the Matrix4x4 by the angle in degrees. 

	Matrix4x4 getScaleMatrix(const float &a_c_fXScale, float &a_c_fYScale, float &a_c_fZScale)const;//Returns the scale Matrix4x4.

	//\===========================================================================================
	//\ Transpose A Point
	//\===========================================================================================

	void transpose();//Transposes the Matrix4x4. 

	//\===========================================================================================
	//\ Set To Identity
	//\===========================================================================================

	void setIdentity();//Makes the Matrix4x4 an identity matrix. 

	//\===========================================================================================
	//\ Identity
	//\===========================================================================================

	Matrix4x4 identity()const;//Returns a Matrix4x4 identity matrix.

	//\===========================================================================================
	//\ Set To Zero
	//\===========================================================================================

	void setZero();//Makes each Matrix4x4 element equal to 0. 

	//\===========================================================================================
	//\ Zero
	//\===========================================================================================

	Matrix4x4 zero()const;//Returns a Matrix4x4 zero matrix.

	//\===========================================================================================
	//\ Special Points
	//\===========================================================================================

	static const Matrix4x4 ZERO;//A Matrix4x4 where every element is equal to zero.

	static const Matrix4x4 IDENTITY;//A Matrix4x4 where the elements are equal to the identity matrix.

};

#endif
