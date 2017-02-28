//\===========================================================================================
//\ File: Matrix3x3.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Matrix3x3.h.
//\===========================================================================================

#include "Matrix3x3.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Matrix3x3::Matrix3x3() {}//The Default constructor for a Matrix3x3 that initialises everything to 0.

Matrix3x3::Matrix3x3(const float a_c_fmMatrix[3][3])//Constructor for a Matrix3x3 that is made from two arrays of three.
{
	for (int iRow = 0; iRow < 3; ++iRow)//Iterates through the rows.
	{
		for (int iCol = 0; iCol < 3; ++iCol)//Iterates through the columns.
		{
			fmMatrix[iRow][iCol] = a_c_fmMatrix[iRow][iCol];//Sets each element of the matrix to the same as the matrix passed in.
		}
	}
}

Matrix3x3::Matrix3x3(const float &a_c_fm_00, float &a_c_fm_01, float &a_c_fm_02, float &a_c_fm_10, float &a_c_fm_11, float &a_c_fm_12, float &a_c_fm_20, float &a_c_fm_21, float &a_c_fm_22)//Constructor that takes nine floats to make a Matrix3x3.
{
	fmMatrix[0][0] = a_c_fm_00;//Sets the matrix's first element equal to the first argument passed in.
	fmMatrix[0][1] = a_c_fm_01;//Sets the matrix's second element equal to the second argument passed in.
	fmMatrix[0][2] = a_c_fm_02;//Sets the matrix's third element equal to the third argument passed in.
	fmMatrix[1][0] = a_c_fm_10;//Sets the matrix's fourth element equal to the fourth argument passed in.
	fmMatrix[1][1] = a_c_fm_11;//Sets the matrix's fifth element equal to the fifth argument passed in.
	fmMatrix[1][2] = a_c_fm_12;//Sets the matrix's sixth element equal to the sixth argument passed in.
	fmMatrix[2][0] = a_c_fm_20;//Sets the matrix's seventh element equal to the seventh argument passed in.
	fmMatrix[2][1] = a_c_fm_21;//Sets the matrix's eighth element equal to the eighth argument passed in.
	fmMatrix[2][2] = a_c_fm_22;//Sets the matrix's ninth element equal to the ninth argument passed in.
}

Matrix3x3::Matrix3x3(const float a_c_fiMatrix[9])//Constructor that takes an array of nine floats to make a Matrix3x3.
{
	for (int i = 0; i < 9; ++i)
	{
		fiMatrix[i] = a_c_fiMatrix[i];
	}
}

Matrix3x3::Matrix3x3(const Vector3 &a_c_vXAxis, Vector3 &a_c_vYAxis, Vector3 &a_c_vZAxis)://Constructor for a Matrix3x3 made from three Vector3's.
	vXAxis(a_c_vXAxis),
	vYAxis(a_c_vYAxis),
	vZAxis(a_c_vZAxis)
{
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Matrix3x3::getfmMatrix(const int a_c_iRow, int a_c_iCol)const//A the specified number in the matrix.
{
	return float(fmMatrix[a_c_iRow][a_c_iCol]);
}

float Matrix3x3::getfiMatrix(const int a_c_iPosition)const//A the specified number in the matrix.
{
	return float(fiMatrix[a_c_iPosition]);
}

Vector3 Matrix3x3::vXAxis()const//A the specified number in the matrix.
{
	return vXAxis;
}

Vector3 Matrix3x3::vYAxis()const//A the specified number in the matrix.
{
	return (vYAxis);
}

Vector3 Matrix3x3::vZAxis()const//A the specified number in the matrix.
{
	return Vector3(vZAxis);
}

Vector3 Matrix3x3::vTranslation()const//A the specified number in the matrix.
{
	return Vector3(vTranslation);
}

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
