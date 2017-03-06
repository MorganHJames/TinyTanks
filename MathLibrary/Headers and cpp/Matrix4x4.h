//\===========================================================================================
//\ File: Matrix4x4.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the Matrix4x4 class declarations.
//\===========================================================================================

#ifndef _MATRIX4X4_H_
#define _MATRIX4X4_H_

#include "Matrix3x3.h"

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
		float fmMatrix[4][4];//A matrix of floats in a 4x4 grid created by two arrays of four.

		struct//A structure three rows of three floats to make a matrix.
		{
			float fm_00, fm_01, fm_02, fm_03;//Floats representing the first row of the matrix.
			float fm_10, fm_11, fm_12, fm_13;//Floats representing the second row of the matrix.
			float fm_20, fm_21, fm_22, fm_23;//Floats representing the third row of the matrix.
			float fm_30, fm_31, fm_32, fm_33;//Floats representing the fourth row of the matrix.
		};

		struct//A structure containing nine floats representing a matrix.
		{
			float fiMatrix[16];//An array of sixteen floats.
		};

		struct//A structure that contains four Vector4's to make up a matrix.
		{
			Vector4 vXAxis;//A Vector4 to contain the x axis of the matrix.
			Vector4 vYAxis;//A Vector4 to contain the y axis of the matrix.
			Vector4 vZAxis;//A Vector4 to contain the z axis of the matrix.
			union//Everything in the union is at the same memory address.
			{
				Vector4 vWAxis;//A Vector4 to contain the w axis of the matrix.
				Vector4 vTranslation;//A Vector4 to contain the translation of the matrix.
			};
		};
	};
public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Matrix4x4();//The Default constructor for a Matrix4x4 that initialises everything to 0.

	Matrix4x4(const float a_c_fmMatrix[4][4]);//Constructor for a Matrix4x4 that is made from two arrays of four.

	Matrix4x4(const//Constructor that takes sixteen floats to make a Matrix4x4.
		float &a_c_fm_00,
		float &a_c_fm_01,
		float &a_c_fm_02,
		float &a_c_fm_03,
		float &a_c_fm_10,
		float &a_c_fm_11, 
		float &a_c_fm_12,
		float &a_c_fm_13, 
		float &a_c_fm_20,
		float &a_c_fm_21, 
		float &a_c_fm_22, 
		float &a_c_fm_23,
		float &a_c_fm_30,
		float &a_c_fm_31,
		float &a_c_fm_32,
		float &a_c_fm_33);

	Matrix4x4(const float a_c_fiMatrix[16]);//Constructor that takes an array of sixteen floats to make a Matrix4x4.

	Matrix4x4(const//Constructor for a Matrix4x4 made from four Vector4's.
		Vector4 &a_c_vXAxis,
		Vector4 &a_c_vYAxis,
		Vector4 &a_c_vZAxis,
		Vector4 &a_c_vWAxis);

	Matrix4x4(const Matrix3x3 &a_c_mMatrix3x3);//Constructor to make a Matrix4x4 from a Matrix3x3.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================

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

	void setXAxis(const Vector4 &a_c_vVector4);//A setter to change the vXAxis of Matrix4x4 to the Vector4 argument.

	void setYAxis(const Vector4 &a_c_vVector4);//A setter to change the vYAxis of Matrix4x4 to the Vector4 argument.

	void setZAxis(const Vector4 &a_c_vVector4);//A setter to change the vZAxis of Matrix4x4 to the Vector4 argument.
	
	void setWAxis(const Vector4 &a_c_vVector4);//A setter to change the vWAxis of Matrix4x4 to the Vector4 argument.

	void setTranslation(const Vector4 &a_c_vVector4);//A setter to change the vTranslation of Matrix4x4 to the vTranslation argument.

	void setColumn(const int &a_c_iCol, Vector4 &a_c_vVector4);//A setter for the column specified by the argument a_c_iCol.

	void setRow(const int &a_c_iRow, Vector4 &a_c_vVector4);//A setter for the row specified by the argument a_c_iRow.

	//\===========================================================================================
	//\ Arithmetic Operation Overloads
	//\===========================================================================================

	Matrix4x4 operator+(const float &a_c_fScalar)const;//Overloaded addition operation for Matrix4x4.

	Matrix4x4 operator+(const Vector3 &a_c_vVector3)const;//Overloaded addition operation for Matrix4x4.

	Matrix4x4 operator+(const Matrix4x4 &a_c_mMatrix4x4)const;//Overloaded addition operation for Matrix4x4.

	Matrix4x4 operator-(const float &a_c_fScalar)const;//Overloaded subtraction operation for Matrix4x4.

	Matrix4x4 operator-(const Vector3 &a_c_vVector3)const;//Overloaded subtraction operation for Matrix4x4.

	Matrix4x4 operator-(const Matrix4x4 &a_c_mMatrix4x4)const;//Overloaded subtraction operation for Matrix4x4.

	Matrix4x4 operator*(const float &a_c_fScalar)const;//Overloaded multiplication operation for Matrix4x4.

	Vector3 operator*(const Vector3 &a_c_vVector3)const;//Overloaded multiplication operation for Matrix4x4.

	Matrix4x4 operator*(const Matrix4x4 &a_c_mMatrix4x4)const;//Overloaded multiplication operation for Matrix4x4.

	Matrix4x4 operator/(const float &a_c_fScalar)const;//Overloaded division operation for Matrix4x4.

	Vector3 operator/(const Vector3 &a_c_vVector3)const;//Overloaded division operation for Matrix4x4.

	Matrix4x4 operator/(const Matrix4x4 &a_c_mMatrix4x4)const;//Overloaded division operation for Matrix4x4.

	//\===========================================================================================
	//\ Assignment Operation Overloads
	//\===========================================================================================

	Matrix4x4 operator=(const float &a_c_fScalar);//Overloaded equals operation for Matrix4x4.

	Matrix4x4 operator=(const Vector3 &a_c_vVector3);//Overloaded equals operation for Matrix4x4.

	Matrix4x4 operator=(const Matrix4x4 &a_c_mMatrix4x4);//Overloaded equals operation for Matrix4x4.

	//\===========================================================================================
	//\ Relational Operation Overloads
	//\===========================================================================================

	bool operator!=(const float &a_c_fScalar)const;//Overloaded not equals operation for Matrix4x4.

	bool operator!=(const Vector3 &a_c_vVector3)const;//Overloaded not equals operation for Matrix4x4.

	bool operator!=(const Matrix4x4 &a_c_mMatrix4x4)const;//Overloaded not equals operation for Matrix4x4.

	bool operator==(const float &a_c_fScalar)const;//Overloaded is equals operation for Matrix4x4.

	bool operator==(const Vector3 &a_c_vVector3)const;//Overloaded is equals operation for Matrix4x4.

	bool operator==(const Matrix4x4 &a_c_mMatrix4x4)const;//Overloaded is equals operation for Matrix4x4.

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

	void identity();//Makes the Matrix4x4 an identity matrix. 

	//\===========================================================================================
	//\ Set To Zero
	//\===========================================================================================

	void zero();//Makes each Matrix4x4 element equal to 0. 

};

#endif
