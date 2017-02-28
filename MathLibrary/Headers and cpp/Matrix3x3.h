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
public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================
	
	Matrix3x3();//The Default constructor for a Matrix3x3 that initialises everything to 0.

	Matrix3x3(const float a_c_fmMatrix[3][3]);//Constructor for a Matrix3x3 that is made from two arrays of three.

	Matrix3x3(const float &a_c_fm_00, float &a_c_fm_01, float &a_c_fm_02, float &a_c_fm_10, float &a_c_fm_11, float &a_c_fm_12, float &a_c_fm_20, float &a_c_fm_21, float &a_c_fm_22);//Constructor that takes nine floats to make a Matrix3x3.

	Matrix3x3(const float a_c_fiMatrix[9]);//Constructor that takes an array of nine floats to make a Matrix3x3.

	Matrix3x3(const Vector3 &a_c_vXAxis, Vector3 &a_c_vYAxis, Vector3 &a_c_vZAxis);//Constructor for a Matrix3x3 made from three Vector3's.

	//\===========================================================================================
	//\ Getters
	//\===========================================================================================
	
	float getfmMatrix(const int a_c_iRow, int a_c_iCol)const;//A the specified number in the matrix.
	
	float getfiMatrix(const int a_c_iPosition)const;//A the specified number in the matrix.
	
	Vector3 vXAxis()const;//A the specified number in the matrix.

	Vector3 vYAxis()const;//A the specified number in the matrix.

	Vector3 vZAxis()const;//A the specified number in the matrix.

	Vector3 vTranslation()const;//A the specified number in the matrix.

	//\===========================================================================================
	//\ Setters
	//\===========================================================================================
	
	//\===========================================================================================
	//\ Operation Overloads
	//\===========================================================================================

	//\===========================================================================================
	//\ Rotate Around Euler Axis
	//\===========================================================================================
	
	//\===========================================================================================
	//\ Inversion
	//\===========================================================================================

	//\===========================================================================================
	//\ Scale
	//\===========================================================================================

	//\===========================================================================================
	//\ Transpose A Point
	//\===========================================================================================

	//\===========================================================================================
	//\ Set To Identity
	//\===========================================================================================

	//\===========================================================================================
	//\ Set To Zero
	//\===========================================================================================

	//\===========================================================================================
	//\ Override Access Operators To Retrieve Matrix Value At Row / Column
	//\===========================================================================================

private:
	//\===========================================================================================
	//\ Member Variables held in an unnamed union for accessibility
	//\===========================================================================================

	union//Everything in the union is at the same memory address.
	{
		float fmMatrix[3][3];//A matrix of floats in a 3 x 3 grid created by two arrays of three.

		struct//A structure three rows of three floats to make a matrix.
		{
			float fm_00, fm_01, fm_02;//Floats representing the top row of the matrix.
			float fm_10, fm_11, fm_12;//Floats representing the middle row of the matrix.
			float fm_20, fm_21, fm_22;//Floats representing the bottom row of the matrix.
		};

		struct//A structure containing nine floats representing a matrix.
		{
			float fiMatrix[9];//An array of nine floats.
		};

		struct//A structure that contains three Vector3's to make up a matrix.
		{
			Vector3 vXAxis;//A Vector3 to contain the x axis of the matrix.
			Vector3 vYAxis;//A Vector3 to contain the y axis of the matrix.
			union//Everything in the union is at the same memory address.
			{
				Vector3 vZAxis;//A Vector3 to contain the z axis of the matrix.
				Vector3 vTranslation;//A Vector3 to contain the translation of the matrix.
			};
		};
	};
};

#endif
