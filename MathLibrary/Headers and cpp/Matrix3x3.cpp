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
	for (int i = 0; i < 9; ++i)//Iterates through the nine times.
	{
		fiMatrix[i] = a_c_fiMatrix[i];//Makes each element of the matrix equal to each element of the matrix passed in.
	}
}

Matrix3x3::Matrix3x3(const Vector3 &a_c_vXAxis, Vector3 &a_c_vYAxis, Vector3 &a_c_vZAxis)://Constructor for a Matrix3x3 made from three Vector3's.
	vXAxis(a_c_vXAxis),//Sets the vXAxis of the Matrix3x3 equal to the first Vector passed in.
	vYAxis(a_c_vYAxis),//Sets the vYAxis of the Matrix3x3 equal to the second Vector passed in.
	vZAxis(a_c_vZAxis)//Sets the vZAxis of the Matrix3x3 equal to the third Vector passed in.
{
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Matrix3x3::getmMatrix(const int a_c_iRow, int a_c_iCol)const//A getter to return a float at the point specified with the two arguments.
{
	return float(fmMatrix[a_c_iRow][a_c_iCol]);//Returns a float at the row of the first argument passed in and the column of the second argument passed in.
}

float Matrix3x3::getiMatrix(const int a_c_iPosition)const//A getter to Returns a float from the matrix at the position of the argument passed in.
{
	return float(fiMatrix[a_c_iPosition]);//Returns a float from the matrix at the position of the argument passed in.
}

Vector3 Matrix3x3::getXAxis()const//A getter to return the vXAxis of matrix3x3 in the form of a Vector3.
{
	return Vector3(vXAxis);//Returns the vXAxis of the Matrix3x3 in the form of a Vector3.
}

Vector3 Matrix3x3::getYAxis()const//A getter to return the vYAxis of matrix3x3 in the form of a Vector3.
{
	return Vector3(vYAxis);//Returns the vYAxis of the Matrix3x3 in the form of a Vector3.
}

Vector3 Matrix3x3::getZAxis()const//A getter to return the vZAxis of matrix3x3 in the form of a Vector3.
{
	return Vector3(vZAxis);//Returns the vZAxis of the Matrix3x3 in the form of a Vector3.
}

Vector3 Matrix3x3::getTranslation()const//A getter to return the vTranslation of matrix3x3 in the form of a Vector3.
{
	return Vector3(vTranslation);//Returns the vTranslation of the Matrix3x3 in the form of a Vector3.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Matrix3x3::setmMatrix(const int a_c_iRow, int a_c_iCol, float a_c_fNewNumber)//A setter to change the float in the matrix at the point specified with the two arguments.
{
	fmMatrix[a_c_iRow][a_c_iCol] = a_c_fNewNumber;//Sets the float specified by the first and second argument to the third argument.
}

void Matrix3x3::setiMatrix(const int a_c_iPosition, float a_c_fNewNumber)//A setter to change the float in the matrix at the position of the argument passed in.
{
	fiMatrix[a_c_iPosition] = a_c_fNewNumber;//Sets the float at the position of the first argument to the float of the second argument.
}

void Matrix3x3::setXAxis(const Vector3 a_c_vVector3)//A setter to change the vXAxis of matrix3x3 to the Vector3 argument.
{
	vXAxis = a_c_vVector3;//Sets the vXAxis Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setYAxis(const Vector3 a_c_vVector3)//A setter to change the vYAxis of matrix3x3 to the Vector3 argument.
{
	vYAxis = a_c_vVector3;//Sets the vYAxis Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setZAxis(const Vector3 a_c_vVector3)//A setter to change the vZAxis of matrix3x3 to the Vector3 argument.
{
	vZAxis = a_c_vVector3;//Sets the vZAxis Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setTranslation(const Vector3 a_c_vVector3)//A setter to change the vTranslation of matrix3x3 to the vTranslation argument.
{
	vTranslation = a_c_vVector3;//Sets the vTranslation Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

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
