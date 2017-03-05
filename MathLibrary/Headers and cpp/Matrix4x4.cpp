//\===========================================================================================
//\ File: Matrix4x4.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Matrix4x4.h.
//\===========================================================================================

#include "Matrix4x4.h"
#include <cstring>
#include <cmath>
#include "MathUtil.h"


//\===========================================================================================
//\ Constructor
//\===========================================================================================

Matrix4x4::Matrix4x4() {}//The Default constructor for a Matrix4x4 that initialises everything to 0.

Matrix4x4::Matrix4x4(const float a_c_fmMatrix[4][4])//Constructor for a Matrix4x4 that is made from two arrays of four.
{

}

Matrix4x4::Matrix4x4(const//Constructor that takes sixteen floats to make a Matrix4x4.
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
	float &a_c_fm_33)
{

}

Matrix4x4::Matrix4x4(const float a_c_fiMatrix[16])//Constructor that takes an array of sixteen floats to make a Matrix4x4.
{

}

Matrix4x4::Matrix4x4(const//Constructor for a Matrix4x4 made from four Vector4's.
	Vector4 &a_c_vXAxis,
	Vector4 &a_c_vYAxis,
	Vector4 &a_c_vZAxis,
	Vector4 &a_c_vWAxis)
{

}

Matrix4x4::Matrix4x4(const Matrix3x3 a_c_mMatrix3x3)//Constructor to make a Matrix4x4 from a Matrix3x3.
{

}

//\===========================================================================================
//\ Getters
//\===========================================================================================

float Matrix4x4::getmMatrix(const int &a_c_iRow, int &a_c_iCol)const//A getter to return a float at the point specified with the two arguments.
{

}

float Matrix4x4::getiMatrix(const int &a_c_iPosition)const//A getter to Returns a float from the matrix at the position of the argument passed in.
{

}

Vector4 Matrix4x4::getXAxis()const//A getter to return the vXAxis of Matrix4x4 in the form of a Vector4.
{

}

Vector4 Matrix4x4::getYAxis()const//A getter to return the vYAxis of Matrix4x4 in the form of a Vector4.
{

}

Vector4 Matrix4x4::getZAxis()const//A getter to return the vZAxis of Matrix4x4 in the form of a Vector4.
{

}

Vector4 Matrix4x4::getWAxis()const//A getter to return the vWAxis of Matrix4x4 in the form of a Vector4.
{

}

Vector4 Matrix4x4::getTranslation()const//A getter to return the vTranslation of Matrix4x4 in the form of a Vector4.
{

}

Vector4 Matrix4x4::getColumn(const int a_c_iCol)const//A getter to return the column specified by the argument a_c_iCol.
{

}

Vector4 Matrix4x4::getRow(const int a_c_iRow)const//A getter to return the row specified by the argument a_c_iRow.
{

}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Matrix4x4::setmMatrix(const int &a_c_iRow, int &a_c_iCol, float &a_c_fNewNumber)//A setter to change the float in the matrix at the point specified with the two arguments.
{

}

void Matrix4x4::setiMatrix(const int &a_c_iPosition, float &a_c_fNewNumber)//A setter to change the float in the matrix at the position of the argument passed in.
{

}

void Matrix4x4::setXAxis(const Vector4 &a_c_vVector4)//A setter to change the vXAxis of Matrix4x4 to the Vector4 argument.
{

}

void Matrix4x4::setYAxis(const Vector4 &a_c_vVector4)//A setter to change the vYAxis of Matrix4x4 to the Vector4 argument.
{

}

void Matrix4x4::setZAxis(const Vector4 &a_c_vVector4)//A setter to change the vZAxis of Matrix4x4 to the Vector4 argument.
{

}

void Matrix4x4::setWAxis(const Vector4 &a_c_vVector4)//A setter to change the vWAxis of Matrix4x4 to the Vector4 argument.
{

}

void Matrix4x4::setTranslation(const Vector4 &a_c_vVector4)//A setter to change the vTranslation of Matrix4x4 to the vTranslation argument.
{

}

void Matrix4x4::setColumn(const int &a_c_iCol, Vector4 &a_c_vVector4)//A setter for the column specified by the argument a_c_iCol.
{

}

void Matrix4x4::setRow(const int &a_c_iRow, Vector4 &a_c_vVector4)//A setter for the row specified by the argument a_c_iRow.
{

}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Matrix4x4 Matrix4x4::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator+(const Vector3 &a_c_vVector3)const//Overloaded addition operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded addition operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator-(const Vector3 &a_c_vVector3)const//Overloaded subtraction operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded subtraction operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Matrix4x4.
{

}

Vector3 Matrix4x4::operator*(const Vector3 &a_c_vVector3)const//Overloaded multiplication operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded multiplication operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator/(const float &a_c_fScalar)const//Overloaded division operation for Matrix4x4.
{

}

Vector3 Matrix4x4::operator/(const Vector3 &a_c_vVector3)const//Overloaded division operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator/(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded division operation for Matrix4x4.
{

}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Matrix4x4 Matrix4x4::operator=(const float &a_c_fScalar)//Overloaded equals operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator=(const Vector3 &a_c_vVector3)//Overloaded equals operation for Matrix4x4.
{

}

Matrix4x4 Matrix4x4::operator=(const Matrix4x4 &a_c_mMatrix4x4)//Overloaded equals operation for Matrix4x4.
{

}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Matrix4x4::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Matrix4x4.
{

}

bool Matrix4x4::operator!=(const Vector3 &a_c_vVector3)const//Overloaded not equals operation for Matrix4x4.
{

}

bool Matrix4x4::operator!=(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded not equals operation for Matrix4x4.
{

}

bool Matrix4x4::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Matrix4x4.
{

}

bool Matrix4x4::operator==(const Vector3 &a_c_vVector3)const//Overloaded is equals operation for Matrix4x4.
{

}

bool Matrix4x4::operator==(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded is equals operation for Matrix4x4.
{

}

//\===========================================================================================
//\ Rotate Around Euler Axis
//\===========================================================================================

void Matrix4x4::rotateX(float &a_fAngle)//Rotates the Matrix4x4 by the angle in degrees. 
{

}

void Matrix4x4::rotateY(float &a_fAngle)//Rotates the Matrix4x4 by the angle in degrees. 
{

}

void Matrix4x4::rotateZ(float &a_fAngle)//Rotates the Matrix4x4 by the angle in degrees. 
{

}

//\===========================================================================================
//\ Determinant
//\===========================================================================================

float Matrix4x4::determinant()const//A function to get the determinant of a Matrix4x4.
{

}

//\===========================================================================================
//\ Inversion
//\===========================================================================================

bool Matrix4x4::inverse()//A function that returns the inverse of a Matrix4x4.
{

}

//\===========================================================================================
//\ Scale
//\===========================================================================================

void Matrix4x4::scale(const float a_c_fXScale, float a_c_fYScale, float a_c_fZScale, float a_c_fWScale)//Rotates the Matrix4x4 by the angle in degrees. 
{

}

//\===========================================================================================
//\ Transpose A Point
//\===========================================================================================

void Matrix4x4::transpose()//Transposes the Matrix4x4. 
{

}

//\===========================================================================================
//\ Set To Identity
//\===========================================================================================

void Matrix4x4::identity()//Makes the Matrix4x4 an identity matrix. 
{

}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Matrix4x4::zero()//Makes each Matrix4x4 element equal to 0. 
{

}