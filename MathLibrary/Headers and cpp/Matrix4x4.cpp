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

Matrix4x4::Matrix4x4(const Matrix4x4 &a_c_mMatrix4x4)//Copy constructor.
{
	fm_00 = a_c_mMatrix4x4.getiMatrix(0);
	fm_01 = a_c_mMatrix4x4.getiMatrix(1);
	fm_02 = a_c_mMatrix4x4.getiMatrix(2);
	fm_03 = a_c_mMatrix4x4.getiMatrix(3);
	fm_10 = a_c_mMatrix4x4.getiMatrix(4);
	fm_11 = a_c_mMatrix4x4.getiMatrix(5);
	fm_12 = a_c_mMatrix4x4.getiMatrix(6);
	fm_13 = a_c_mMatrix4x4.getiMatrix(7);
	fm_20 = a_c_mMatrix4x4.getiMatrix(8);
	fm_21 = a_c_mMatrix4x4.getiMatrix(9);
	fm_22 = a_c_mMatrix4x4.getiMatrix(10);
	fm_23 = a_c_mMatrix4x4.getiMatrix(11);
	fm_30 = a_c_mMatrix4x4.getiMatrix(12);
	fm_31 = a_c_mMatrix4x4.getiMatrix(13);
	fm_32 = a_c_mMatrix4x4.getiMatrix(14);
	fm_33 = a_c_mMatrix4x4.getiMatrix(15);
}

Matrix4x4::Matrix4x4(const float a_c_fmMatrix[4][4])//Constructor for a Matrix4x4 that is made from two arrays of four.
{
	fmMatrix[0][0] = a_c_fmMatrix[0][0];//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	fmMatrix[0][1] = a_c_fmMatrix[0][1];//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	fmMatrix[0][2] = a_c_fmMatrix[0][2];//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	fmMatrix[0][3] = a_c_fmMatrix[0][3];//Sets the matrix's fourth element of the matrix to the same as the matrix passed in.
	fmMatrix[1][0] = a_c_fmMatrix[1][0];//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	fmMatrix[1][1] = a_c_fmMatrix[1][1];//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	fmMatrix[1][2] = a_c_fmMatrix[1][2];//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	fmMatrix[1][3] = a_c_fmMatrix[1][3];//Sets the matrix's eighth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][0] = a_c_fmMatrix[2][0];//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][1] = a_c_fmMatrix[2][1];//Sets the matrix's tenth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][2] = a_c_fmMatrix[2][2];//Sets the matrix's eleventh element of the matrix to the same as the matrix passed in.
	fmMatrix[2][3] = a_c_fmMatrix[2][3];//Sets the matrix's twelve element of the matrix to the same as the matrix passed in.
	fmMatrix[3][0] = a_c_fmMatrix[3][0];//Sets the matrix's thirteenth element of the matrix to the same as the matrix passed in.
	fmMatrix[3][1] = a_c_fmMatrix[3][1];//Sets the matrix's fourteenth element of the matrix to the same as the matrix passed in.
	fmMatrix[3][2] = a_c_fmMatrix[3][2];//Sets the matrix's fifteenth element of the matrix to the same as the matrix passed in.
	fmMatrix[3][3] = a_c_fmMatrix[3][3];//Sets the matrix's sixteenth element of the matrix to the same as the matrix passed in.
}

Matrix4x4::Matrix4x4(const//Constructor that takes sixteen floats to make a Matrix4x4.
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
	float a_c_fm_33)
{
	fm_00 = a_c_fm_00;//Sets the matrix's first element of the matrix to the same as the equivalent argument  passed in.
	fm_01 = a_c_fm_01;//Sets the matrix's second element of the matrix to the same as the equivalent argument  passed in.
	fm_02 = a_c_fm_02;//Sets the matrix's third element of the matrix to the same as the equivalent argument  passed in.
	fm_03 = a_c_fm_03;//Sets the matrix's fourth element of the matrix to the same as the equivalent argument  passed in.
	fm_10 = a_c_fm_10;//Sets the matrix's fifth element of the matrix to the same as the equivalent argument  passed in.
	fm_11 = a_c_fm_11;//Sets the matrix's sixth element of the matrix to the same as the equivalent argument  passed in.
	fm_12 = a_c_fm_12;//Sets the matrix's seventh element of the matrix to the same as the equivalent argument  passed in.
	fm_13 = a_c_fm_13;//Sets the matrix's eighth element of the matrix to the same as the equivalent argument  passed in.
	fm_20 = a_c_fm_20;//Sets the matrix's ninth element of the matrix to the same as the equivalent argument  passed in.
	fm_21 = a_c_fm_21;//Sets the matrix's tenth element of the matrix to the same as the equivalent argument  passed in.
	fm_22 = a_c_fm_22;//Sets the matrix's eleventh element of the matrix to the same as the equivalent argument  passed in.
	fm_23 = a_c_fm_23;//Sets the matrix's twelve element of the matrix to the same as the equivalent argument  passed in.
	fm_30 = a_c_fm_30;//Sets the matrix's thirteenth element of the matrix to the same as the equivalent argument  passed in.
	fm_31 = a_c_fm_31;//Sets the matrix's fourteenth element of the matrix to the same as the equivalent argument  passed in.
	fm_32 = a_c_fm_32;//Sets the matrix's fifteenth element of the matrix to the same as the equivalent argument  passed in.
	fm_33 = a_c_fm_33;//Sets the matrix's sixteenth element of the matrix to the same as the equivalent argument  passed in.
}

Matrix4x4::Matrix4x4(const float a_c_fiMatrix[16])//Constructor that takes an array of sixteen floats to make a Matrix4x4.
{
	fiMatrix[0] = a_c_fiMatrix[0];//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	fiMatrix[1] = a_c_fiMatrix[1];//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	fiMatrix[2] = a_c_fiMatrix[2];//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	fiMatrix[3] = a_c_fiMatrix[3];//Sets the matrix's fourth element of the matrix to the same as the matrix passed in.
	fiMatrix[4] = a_c_fiMatrix[4];//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	fiMatrix[5] = a_c_fiMatrix[5];//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	fiMatrix[6] = a_c_fiMatrix[6];//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	fiMatrix[7] = a_c_fiMatrix[7];//Sets the matrix's eighth element of the matrix to the same as the matrix passed in.
	fiMatrix[8] = a_c_fiMatrix[8];//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
	fiMatrix[9] = a_c_fiMatrix[9];//Sets the matrix's tenth element of the matrix to the same as the matrix passed in.
	fiMatrix[10] = a_c_fiMatrix[10];//Sets the matrix's eleventh element of the matrix to the same as the matrix passed in.
	fiMatrix[11] = a_c_fiMatrix[11];//Sets the matrix's twelve element of the matrix to the same as the matrix passed in.
	fiMatrix[12] = a_c_fiMatrix[12];//Sets the matrix's thirteenth element of the matrix to the same as the matrix passed in.
	fiMatrix[13] = a_c_fiMatrix[13];//Sets the matrix's fourteenth element of the matrix to the same as the matrix passed in.
	fiMatrix[14] = a_c_fiMatrix[14];//Sets the matrix's fifteenth element of the matrix to the same as the matrix passed in.
	fiMatrix[15] = a_c_fiMatrix[15];//Sets the matrix's sixteenth element of the matrix to the same as the matrix passed in.
}

Matrix4x4::Matrix4x4(const//Constructor for a Matrix4x4 made from four Vector4's.
	Vector4 a_c_vXAxis,
	Vector4 a_c_vYAxis,
	Vector4 a_c_vZAxis,
	Vector4 a_c_vWAxis):
	vXAxis(a_c_vXAxis),//Sets the vXAxis of the Matrix3x3 equal to the first Vector passed in.
	vYAxis(a_c_vYAxis),//Sets the vYAxis of the Matrix3x3 equal to the second Vector passed in.
	vZAxis(a_c_vZAxis),//Sets the vZAxis of the Matrix3x3 equal to the third Vector passed in.
	vWAxis(a_c_vWAxis)//Sets the vWAxis of the Matrix3x3 equal to the fourth Vector passed in.
{}

Matrix4x4::Matrix4x4(const Matrix3x3 a_c_mMatrix3x3)//Constructor to make a Matrix4x4 from a Matrix3x3.
{
	fm_00 = a_c_mMatrix3x3.getiMatrix(0);//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	fm_01 = a_c_mMatrix3x3.getiMatrix(1);//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	fm_02 = a_c_mMatrix3x3.getiMatrix(2);//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	fm_03 = 0;//Sets the element to what is would be in the identity matrix.
	fm_10 = a_c_mMatrix3x3.getiMatrix(5);//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	fm_11 = a_c_mMatrix3x3.getiMatrix(6);//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	fm_12 = a_c_mMatrix3x3.getiMatrix(7);//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	fm_13 = 0;//Sets the element to what is would be in the identity matrix.
	fm_20 = a_c_mMatrix3x3.getiMatrix(9);//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
	fm_21 = a_c_mMatrix3x3.getiMatrix(10);//Sets the matrix's tenth element of the matrix to the same as the matrix passed in.
	fm_22 = a_c_mMatrix3x3.getiMatrix(11);//Sets the matrix's eleventh element of the matrix to the same as the matrix passed in.
	fm_23 = 0;//Sets the element to what is would be in the identity matrix.
	fm_30 = 0;//Sets the element to what is would be in the identity matrix.
	fm_31 = 0;//Sets the element to what is would be in the identity matrix.
	fm_32 = 0;//Sets the element to what is would be in the identity matrix.
	fm_33 = 1;//Sets the element to what is would be in the identity matrix.
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

const float* Matrix4x4::getMatrix()const//Returns a pointer to the first element in the array.
{
	return fiMatrix;
}

float Matrix4x4::getmMatrix(const int &a_c_iRow, int &a_c_iCol)const//A getter to return a float at the point specified with the two arguments.
{
	return float(fmMatrix[a_c_iRow][a_c_iCol]);//Returns a float at the row of the first argument passed in and the column of the second argument passed in.
}

float Matrix4x4::getiMatrix(const int &a_c_iPosition)const//A getter to Returns a float from the matrix at the position of the argument passed in.
{
	return float(fiMatrix[a_c_iPosition]);//Returns a float from the matrix at the position of the argument passed in.
}

Vector4 Matrix4x4::getXAxis()const//A getter to return the vXAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(vXAxis);//Returns the vXAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getYAxis()const//A getter to return the vYAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(vYAxis);//Returns the vYAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getZAxis()const//A getter to return the vZAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(vZAxis);//Returns the vZAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getWAxis()const//A getter to return the vWAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(vWAxis);//Returns the vWAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getTranslation()const//A getter to return the vTranslation of Matrix4x4 in the form of a Vector4.
{
	return Vector4(vTranslation);//Returns the vTranslation of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getColumn(const int &a_c_iCol)const//A getter to return the column specified by the argument a_c_iCol.
{
	return Vector4(fmMatrix[0][a_c_iCol], fmMatrix[1][a_c_iCol], fmMatrix[2][a_c_iCol], fmMatrix[3][a_c_iCol]);//Returns the column as a Vector4.
}

Vector4 Matrix4x4::getRow(const int &a_c_iRow)const//A getter to return the row specified by the argument a_c_iRow.
{
	return Vector4(fmMatrix[a_c_iRow][0], fmMatrix[a_c_iRow][1], fmMatrix[a_c_iRow][2], fmMatrix[a_c_iRow][3]);//Returns the row as a Vector4.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Matrix4x4::setmMatrix(const int &a_c_iRow, int &a_c_iCol, float &a_c_fNewNumber)//A setter to change the float in the matrix at the point specified with the two arguments.
{
	fmMatrix[a_c_iRow][a_c_iCol] = a_c_fNewNumber;//Sets the float specified by the first and second argument to the third argument.
}

void Matrix4x4::setiMatrix(const int &a_c_iPosition, float &a_c_fNewNumber)//A setter to change the float in the matrix at the position of the argument passed in.
{
	fiMatrix[a_c_iPosition] = a_c_fNewNumber;//Sets the float at the position of the first argument to the float of the second argument.
}

void Matrix4x4::setXAxis(const Vector4 &a_c_vVector4)//A setter to change the vXAxis of Matrix4x4 to the Vector4 argument.
{
	vXAxis = a_c_vVector4;//Sets the vXAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setYAxis(const Vector4 &a_c_vVector4)//A setter to change the vYAxis of Matrix4x4 to the Vector4 argument.
{
	vYAxis = a_c_vVector4;//Sets the vYAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setZAxis(const Vector4 &a_c_vVector4)//A setter to change the vZAxis of Matrix4x4 to the Vector4 argument.
{
	vZAxis = a_c_vVector4;//Sets the vZAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setWAxis(const Vector4 &a_c_vVector4)//A setter to change the vWAxis of Matrix4x4 to the Vector4 argument.
{
	vWAxis = a_c_vVector4;//Sets the vWAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setTranslation(const Vector4 &a_c_vVector4)//A setter to change the vTranslation of Matrix4x4 to the vTranslation argument.
{
	vTranslation = a_c_vVector4;//Sets the vTranslation Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setColumn(const int &a_c_iCol, Vector4 &a_c_vVector4)//A setter for the column specified by the argument a_c_iCol.
{
	fmMatrix[0][a_c_iCol] = a_c_vVector4.getfX();
	fmMatrix[1][a_c_iCol] = a_c_vVector4.getfY();
	fmMatrix[2][a_c_iCol] = a_c_vVector4.getfZ();
	fmMatrix[3][a_c_iCol] = a_c_vVector4.getfW();//Sets the column specified by the a_c_iCol equal to the argument Vector4.
}

void Matrix4x4::setRow(const int &a_c_iRow, Vector4 &a_c_vVector4)//A setter for the row specified by the argument a_c_iRow.
{
	fmMatrix[a_c_iRow][0] = a_c_vVector4.getfX();
	fmMatrix[a_c_iRow][1] = a_c_vVector4.getfY();
	fmMatrix[a_c_iRow][2] = a_c_vVector4.getfZ();
	fmMatrix[a_c_iRow][3] = a_c_vVector4.getfW();//Sets the row specified by the a_c_iRow equal to the argument Vector4.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Matrix4x4 Matrix4x4::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Matrix4x4.
{
	Matrix4x4 tempAdditionMatrix;//Creates a temporary matrix that will hold the added matrix.
	tempAdditionMatrix.fm_00 = fm_00 + a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_01 = fm_01 + a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_02 = fm_02 + a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_03 = fm_03 + a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_10 = fm_10 + a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_11 = fm_11 + a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_12 = fm_12 + a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_13 = fm_13 + a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_20 = fm_20 + a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_21 = fm_21 + a_c_fScalar;//Makes temporary matrix equal to the tenth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_22 = fm_22 + a_c_fScalar;//Makes temporary matrix equal to the eleventh element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_23 = fm_23 + a_c_fScalar;//Makes temporary matrix equal to the twelve element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_30 = fm_30 + a_c_fScalar;//Makes temporary matrix equal to the thirteenth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_31 = fm_31 + a_c_fScalar;//Makes temporary matrix equal to the fourteenth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_32 = fm_32 + a_c_fScalar;//Makes temporary matrix equal to the fifteenth element of the matrix increased by the float passed in.
	tempAdditionMatrix.fm_33 = fm_33 + a_c_fScalar;//Makes temporary matrix equal to the sixteenth element of the matrix increased by the float passed in.
	return Matrix4x4(tempAdditionMatrix);//Returns the increased matrix.
}

Matrix4x4 Matrix4x4::operator+(const Vector3 &a_c_vVector3)const//Overloaded addition operation for Matrix4x4.
{
	Vector4 temp(a_c_vVector3);
	vXAxis + temp;//Increases the vXAxis by the argument Vector3.
	vYAxis + temp;//Increases the vYAxis by the argument Vector3.
	vZAxis + temp;//Increases the vZAxis by the argument Vector3.
	vWAxis + temp;//Increases the vWAxis by the argument Vector3.
	return Matrix4x4(*this);//Returns the increased matrix.
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded addition operation for Matrix4x4.
{
	Matrix4x4 tempAdditionMatrix;//Creates a temporary matrix that will hold the added matrix.
	tempAdditionMatrix.fm_00 = fm_00 + a_c_mMatrix4x4.fm_00;//Makes temporary matrix equal to the first element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_01 = fm_01 + a_c_mMatrix4x4.fm_01;//Makes temporary matrix equal to the second element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_02 = fm_02 + a_c_mMatrix4x4.fm_02;//Makes temporary matrix equal to the third element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_03 = fm_03 + a_c_mMatrix4x4.fm_03;//Makes temporary matrix equal to the fourth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_10 = fm_10 + a_c_mMatrix4x4.fm_10;//Makes temporary matrix equal to the fifth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_11 = fm_11 + a_c_mMatrix4x4.fm_11;//Makes temporary matrix equal to the sixth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_12 = fm_12 + a_c_mMatrix4x4.fm_12;//Makes temporary matrix equal to the seventh element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_13 = fm_13 + a_c_mMatrix4x4.fm_13;//Makes temporary matrix equal to the eighth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_20 = fm_20 + a_c_mMatrix4x4.fm_20;//Makes temporary matrix equal to the ninth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_21 = fm_21 + a_c_mMatrix4x4.fm_21;//Makes temporary matrix equal to the tenth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_22 = fm_22 + a_c_mMatrix4x4.fm_22;//Makes temporary matrix equal to the eleventh element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_23 = fm_23 + a_c_mMatrix4x4.fm_23;//Makes temporary matrix equal to the twelve element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_30 = fm_30 + a_c_mMatrix4x4.fm_30;//Makes temporary matrix equal to the thirteenth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_31 = fm_31 + a_c_mMatrix4x4.fm_31;//Makes temporary matrix equal to the fourteenth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_32 = fm_32 + a_c_mMatrix4x4.fm_32;//Makes temporary matrix equal to the fifteenth element of the matrix increase by the equivalent part of the matrix passed in.
	tempAdditionMatrix.fm_33 = fm_33 + a_c_mMatrix4x4.fm_33;//Makes temporary matrix equal to the sixteenth element of the matrix increase by the equivalent part of the matrix passed in.
	return Matrix4x4(tempAdditionMatrix);//Returns the increased matrix.
}

Matrix4x4 Matrix4x4::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Matrix4x4.
{
	Matrix4x4 tempSubtractionMatrix;//Creates a temporary matrix that will hold the subtracted matrix.
	tempSubtractionMatrix.fm_00 = fm_00 - a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_01 = fm_01 - a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_02 = fm_02 - a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_03 = fm_03 - a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_10 = fm_10 - a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_11 = fm_11 - a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_12 = fm_12 - a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_13 = fm_13 - a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_20 = fm_20 - a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_21 = fm_21 - a_c_fScalar;//Makes temporary matrix equal to the tenth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_22 = fm_22 - a_c_fScalar;//Makes temporary matrix equal to the eleventh element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_23 = fm_23 - a_c_fScalar;//Makes temporary matrix equal to the twelve element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_30 = fm_30 - a_c_fScalar;//Makes temporary matrix equal to the thirteenth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_31 = fm_31 - a_c_fScalar;//Makes temporary matrix equal to the fourteenth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_32 = fm_32 - a_c_fScalar;//Makes temporary matrix equal to the fifteenth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_33 = fm_33 - a_c_fScalar;//Makes temporary matrix equal to the sixteenth element of the matrix decreased by the float passed in.
	return Matrix4x4(tempSubtractionMatrix);//Returns the decreased matrix.
}

Matrix4x4 Matrix4x4::operator-(const Vector3 &a_c_vVector3)const//Overloaded subtraction operation for Matrix4x4.
{
	Vector4 temp(a_c_vVector3);
	vXAxis - temp;//Decreases the vXAxis by the argument Vector3.
	vYAxis - temp;//Decreases the vYAxis by the argument Vector3.
	vZAxis - temp;//Decreases the vZAxis by the argument Vector3.
	vWAxis - temp;//Decreases the vWAxis by the argument Vector3.
	return Matrix4x4(*this);//Returns the decreased matrix.
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded subtraction operation for Matrix4x4.
{
	Matrix4x4 tempSubtractionMatrix;//Creates a temporary matrix that will hold the subtracted matrix.
	tempSubtractionMatrix.fm_00 = fm_00 - a_c_mMatrix4x4.fm_00;//Makes temporary matrix equal to the first element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_01 = fm_01 - a_c_mMatrix4x4.fm_01;//Makes temporary matrix equal to the second element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_02 = fm_02 - a_c_mMatrix4x4.fm_02;//Makes temporary matrix equal to the third element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_03 = fm_03 - a_c_mMatrix4x4.fm_03;//Makes temporary matrix equal to the fourth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_10 = fm_10 - a_c_mMatrix4x4.fm_10;//Makes temporary matrix equal to the fifth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_11 = fm_11 - a_c_mMatrix4x4.fm_11;//Makes temporary matrix equal to the sixth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_12 = fm_12 - a_c_mMatrix4x4.fm_12;//Makes temporary matrix equal to the seventh element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_13 = fm_13 - a_c_mMatrix4x4.fm_13;//Makes temporary matrix equal to the eighth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_20 = fm_20 - a_c_mMatrix4x4.fm_20;//Makes temporary matrix equal to the ninth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_21 = fm_21 - a_c_mMatrix4x4.fm_21;//Makes temporary matrix equal to the tenth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_22 = fm_22 - a_c_mMatrix4x4.fm_22;//Makes temporary matrix equal to the eleventh element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_23 = fm_23 - a_c_mMatrix4x4.fm_23;//Makes temporary matrix equal to the twelve element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_30 = fm_30 - a_c_mMatrix4x4.fm_30;//Makes temporary matrix equal to the thirteenth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_31 = fm_31 - a_c_mMatrix4x4.fm_31;//Makes temporary matrix equal to the fourteenth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_32 = fm_32 - a_c_mMatrix4x4.fm_32;//Makes temporary matrix equal to the fifteenth element of the matrix decreased by the equivalent part of the matrix passed in.
	tempSubtractionMatrix.fm_33 = fm_33 - a_c_mMatrix4x4.fm_33;//Makes temporary matrix equal to the sixteenth element of the matrix decreased by the equivalent part of the matrix passed in.
	return Matrix4x4(tempSubtractionMatrix);//Returns the decreased matrix.
}

Matrix4x4 Matrix4x4::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Matrix4x4.
{
	Matrix4x4 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied matrix.
	tempMultiplicationMatrix.fm_00 = fm_00 * a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_01 = fm_01 * a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_02 = fm_02 * a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_03 = fm_03 * a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_10 = fm_10 * a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_11 = fm_11 * a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_12 = fm_12 * a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_13 = fm_13 * a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_20 = fm_20 * a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_21 = fm_21 * a_c_fScalar;//Makes temporary matrix equal to the tenth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_22 = fm_22 * a_c_fScalar;//Makes temporary matrix equal to the eleventh element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_23 = fm_23 * a_c_fScalar;//Makes temporary matrix equal to the twelve element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_30 = fm_30 * a_c_fScalar;//Makes temporary matrix equal to the thirteenth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_31 = fm_31 * a_c_fScalar;//Makes temporary matrix equal to the fourteenth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_32 = fm_32 * a_c_fScalar;//Makes temporary matrix equal to the fifteenth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_33 = fm_33 * a_c_fScalar;//Makes temporary matrix equal to the sixteenth element of the matrix multiplied by the float passed in.
	return Matrix4x4(tempMultiplicationMatrix);//Returns the multiplied matrix.
}

Vector4 Matrix4x4::operator*(const Vector3 &a_c_vVector3)const//Overloaded multiplication operation for Matrix4x4.
{
	Vector4 temp(a_c_vVector3);
	return Vector4(//Returns the multiplied matrix.
		fm_00 * temp.getfX() + fm_01 * temp.getfY() + fm_02 * temp.getfZ() + fm_03 * temp.getfW(),//Dot product for the first row of the first matrix and the only column of the Vector3.
		fm_10 * temp.getfX() + fm_11 * temp.getfY() + fm_12 * temp.getfZ() + fm_13 * temp.getfW(),//Dot product for the second row of the first matrix and the only column of the Vector3.
		fm_20 * temp.getfX() + fm_21 * temp.getfY() + fm_22 * temp.getfZ() + fm_23 * temp.getfW(),//Dot product for the third row of the first matrix and the only column of the Vector3.
		fm_30 * temp.getfX() + fm_31 * temp.getfY() + fm_32 * temp.getfZ() + fm_33 * temp.getfW());//Dot product for the fourth row of the first matrix and the only column of the Vector3.
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded multiplication operation for Matrix4x4.
{
	Matrix4x4 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied vector.
	tempMultiplicationMatrix.fm_00 = fm_00 * a_c_mMatrix4x4.fm_00 + fm_01 * a_c_mMatrix4x4.fm_10 + fm_02 * a_c_mMatrix4x4.fm_20 + fm_03 * a_c_mMatrix4x4.fm_30;//Dot product for the first row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_01 = fm_00 * a_c_mMatrix4x4.fm_01 + fm_01 * a_c_mMatrix4x4.fm_11 + fm_02 * a_c_mMatrix4x4.fm_21 + fm_03 * a_c_mMatrix4x4.fm_31;//Dot product for the first row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_02 = fm_00 * a_c_mMatrix4x4.fm_02 + fm_01 * a_c_mMatrix4x4.fm_12 + fm_02 * a_c_mMatrix4x4.fm_22 + fm_03 * a_c_mMatrix4x4.fm_32;//Dot product for the first row of the first matrix and the third column of the second matrix.																																		  
	tempMultiplicationMatrix.fm_03 = fm_00 * a_c_mMatrix4x4.fm_03 + fm_01 * a_c_mMatrix4x4.fm_13 + fm_02 * a_c_mMatrix4x4.fm_23 + fm_03 * a_c_mMatrix4x4.fm_33;//Dot product for the first row of the first matrix and the fourth column of the second matrix.	
	tempMultiplicationMatrix.fm_10 = fm_10 * a_c_mMatrix4x4.fm_00 + fm_11 * a_c_mMatrix4x4.fm_10 + fm_12 * a_c_mMatrix4x4.fm_20 + fm_13 * a_c_mMatrix4x4.fm_30;//Dot product for the second row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_11 = fm_10 * a_c_mMatrix4x4.fm_01 + fm_11 * a_c_mMatrix4x4.fm_11 + fm_12 * a_c_mMatrix4x4.fm_21 + fm_13 * a_c_mMatrix4x4.fm_31;//Dot product for the second row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_12 = fm_10 * a_c_mMatrix4x4.fm_02 + fm_11 * a_c_mMatrix4x4.fm_12 + fm_12 * a_c_mMatrix4x4.fm_22 + fm_13 * a_c_mMatrix4x4.fm_32;//Dot product for the second row of the first matrix and the third column of the second matrix.	
	tempMultiplicationMatrix.fm_13 = fm_10 * a_c_mMatrix4x4.fm_03 + fm_11 * a_c_mMatrix4x4.fm_13 + fm_12 * a_c_mMatrix4x4.fm_23 + fm_13 * a_c_mMatrix4x4.fm_33;//Dot product for the second row of the first matrix and the fourth column of the second matrix.	
	tempMultiplicationMatrix.fm_20 = fm_20 * a_c_mMatrix4x4.fm_00 + fm_21 * a_c_mMatrix4x4.fm_10 + fm_22 * a_c_mMatrix4x4.fm_20 + fm_23 * a_c_mMatrix4x4.fm_30;//Dot product for the third row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_21 = fm_20 * a_c_mMatrix4x4.fm_01 + fm_21 * a_c_mMatrix4x4.fm_11 + fm_22 * a_c_mMatrix4x4.fm_21 + fm_23 * a_c_mMatrix4x4.fm_31;//Dot product for the third row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_22 = fm_20 * a_c_mMatrix4x4.fm_02 + fm_21 * a_c_mMatrix4x4.fm_12 + fm_22 * a_c_mMatrix4x4.fm_22 + fm_23 * a_c_mMatrix4x4.fm_32;//Dot product for the third row of the first matrix and the third column of the second matrix.
	tempMultiplicationMatrix.fm_23 = fm_20 * a_c_mMatrix4x4.fm_03 + fm_21 * a_c_mMatrix4x4.fm_13 + fm_22 * a_c_mMatrix4x4.fm_23 + fm_23 * a_c_mMatrix4x4.fm_33;	//Dot product for the third row of the first matrix and the fourth column of the second matrix.			  
	tempMultiplicationMatrix.fm_30 = fm_30 * a_c_mMatrix4x4.fm_00 + fm_31 * a_c_mMatrix4x4.fm_10 + fm_32 * a_c_mMatrix4x4.fm_20 + fm_33 * a_c_mMatrix4x4.fm_30;//Dot product for the third row of the first matrix and the first column of the second matrix.		
	tempMultiplicationMatrix.fm_31 = fm_30 * a_c_mMatrix4x4.fm_01 + fm_31 * a_c_mMatrix4x4.fm_11 + fm_32 * a_c_mMatrix4x4.fm_21 + fm_33 * a_c_mMatrix4x4.fm_31;//Dot product for the third row of the first matrix and the second column of the second matrix.		
	tempMultiplicationMatrix.fm_32 = fm_30 * a_c_mMatrix4x4.fm_02 + fm_31 * a_c_mMatrix4x4.fm_12 + fm_32 * a_c_mMatrix4x4.fm_22 + fm_33 * a_c_mMatrix4x4.fm_32;//Dot product for the third row of the first matrix and the third column of the second matrix.	
	tempMultiplicationMatrix.fm_33 = fm_30 * a_c_mMatrix4x4.fm_03 + fm_31 * a_c_mMatrix4x4.fm_13 + fm_32 * a_c_mMatrix4x4.fm_23 + fm_33 * a_c_mMatrix4x4.fm_33;//Dot product for the third row of the first matrix and the fourth column of the second matrix.
	return Matrix4x4(tempMultiplicationMatrix);//Returns the multiplied matrix.
}

Matrix4x4 Matrix4x4::operator/(const float &a_c_fScalar)const//Overloaded division operation for Matrix4x4.
{
	return Matrix4x4(*this * reciprocal(a_c_fScalar));//Returns the Matrix4x4 / the argument.
}

Vector4 Matrix4x4::operator/(const Vector3 &a_c_vVector3)const//Overloaded division operation for Matrix4x4.
{
	return Vector4(*this * a_c_vVector3.inverse());//Returns the Matrix4x4 / the argument.
}

Matrix4x4 Matrix4x4::operator/(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded division operation for Matrix4x4.
{
	Matrix4x4 tempMatrix = a_c_mMatrix4x4;
	tempMatrix.inverse();
	return Matrix4x4(*this * tempMatrix);//Returns the Matrix4x4 / the argument.
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Matrix4x4 Matrix4x4::operator+=(const float &a_c_fScalar)//Overloaded added equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this + a_c_fScalar);//Returns the added equated matrix.
}

Matrix4x4 Matrix4x4::operator+=(const Vector3 &a_c_vVector3)//Overloaded added equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this + a_c_vVector3);//Returns the added equated matrix.
}

Matrix4x4 Matrix4x4::operator+=(const Matrix4x4 &a_c_mMatrix4x4)//Overloaded added equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this + a_c_mMatrix4x4);//Returns the added equated matrix.
}

Matrix4x4 Matrix4x4::operator-=(const float &a_c_fScalar)//Overloaded subtracted equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this - a_c_fScalar);//Returns the subtracted equated matrix.
}

Matrix4x4 Matrix4x4::operator-=(const Vector3 &a_c_vVector3)//Overloaded subtracted equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this - a_c_vVector3);//Returns the subtracted equated matrix.
}

Matrix4x4 Matrix4x4::operator-=(const Matrix4x4 &a_c_mMatrix4x4)//Overloaded subtracted equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this - a_c_mMatrix4x4);//Returns the subtracted equated matrix.
}

Matrix4x4 Matrix4x4::operator=(const float &a_c_fScalar)//Overloaded equals operation for Matrix4x4.
{
	fm_00 = a_c_fScalar;//Makes the first element of the matrix equal to the scalar passed in.
	fm_01 = a_c_fScalar;//Makes the second element of the matrix equal to the scalar passed in.
	fm_02 = a_c_fScalar;//Makes the third element of the matrix equal to the scalar passed in.
	fm_03 = a_c_fScalar;//Makes the fourth element of the matrix equal to the scalar passed in.
	fm_10 = a_c_fScalar;//Makes the fifth element of the matrix equal to the scalar passed in.
	fm_11 = a_c_fScalar;//Makes the sixth element of the matrix equal to the scalar passed in.
	fm_12 = a_c_fScalar;//Makes the seventh element of the matrix equal to the scalar passed in.
	fm_13 = a_c_fScalar;//Makes the eighth element of the matrix equal to the scalar passed in.
	fm_20 = a_c_fScalar;//Makes the ninth element of the matrix equal to the scalar passed in.
	fm_21 = a_c_fScalar;//Makes the tenth element of the matrix equal to the scalar passed in.
	fm_22 = a_c_fScalar;//Makes the eleventh element of the matrix equal to the scalar passed in.
	fm_23 = a_c_fScalar;//Makes the	twelve element of the matrix equal to the scalar passed in.
	fm_30 = a_c_fScalar;//Makes the	thirteenth element of the matrix equal to the scalar passed in.
	fm_31 = a_c_fScalar;//Makes the	fourteenth element of the matrix equal to the scalar passed in.
	fm_32 = a_c_fScalar;//Makes the	fifteenth element of the matrix equal to the scalar passed in.
	fm_33 = a_c_fScalar;//Makes the	sixteenth element of the matrix equal to the scalar passed in.
	return Matrix4x4(*this);//Returns the equated matrix.
}						

Matrix4x4 Matrix4x4::operator=(const Vector3 &a_c_vVector3)//Overloaded equals operation for Matrix4x4.
{
	Vector4 temp(a_c_vVector3);
	vXAxis = temp;//Equates the vXAxis to the argument Vector3.
	vYAxis = temp;//Equates the vYAxis to the argument Vector3.
	vZAxis = temp;//Equates the vZAxis to the argument Vector3.
	vWAxis = temp;//Equates the vWAxis to the argument Vector3.
	return Matrix4x4(*this);//Returns the equated matrix.
}

Matrix4x4 Matrix4x4::operator=(const Vector4 &a_c_vVector4)//Overloaded equals operation for Matrix4x4.
{
	vXAxis = a_c_vVector4;//Equates the vXAxis to the argument Vector4.
	vYAxis = a_c_vVector4;//Equates the vYAxis to the argument Vector4.
	vZAxis = a_c_vVector4;//Equates the vZAxis to the argument Vector4.
	vWAxis = a_c_vVector4;//Equates the vWAxis to the argument Vector4.
	return Matrix4x4(*this);//Returns the equated matrix.
}

Matrix4x4 Matrix4x4::operator=(const Matrix4x4 &a_c_mMatrix4x4)//Overloaded equals operation for Matrix4x4.
{
	fm_00 = a_c_mMatrix4x4.fm_00;//Makes the first element of the matrix equal to the equivalent position of the matrix passed in.
	fm_01 = a_c_mMatrix4x4.fm_01;//Makes the second element of the matrix equal to the equivalent position of the matrix passed in.
	fm_02 = a_c_mMatrix4x4.fm_02;//Makes the third element of the matrix equal to the equivalent position of the matrix passed in.
	fm_03 = a_c_mMatrix4x4.fm_03;//Makes the fourth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_10 = a_c_mMatrix4x4.fm_10;//Makes the fifth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_11 = a_c_mMatrix4x4.fm_11;//Makes the sixth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_12 = a_c_mMatrix4x4.fm_12;//Makes the seventh element of the matrix equal to the equivalent position of the matrix passed in.
	fm_13 = a_c_mMatrix4x4.fm_13;//Makes the eighth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_20 = a_c_mMatrix4x4.fm_20;//Makes the ninth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_21 = a_c_mMatrix4x4.fm_21;//Makes the tenth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_22 = a_c_mMatrix4x4.fm_22;//Makes the eleventh element of the matrix equal to the equivalent position of the matrix passed in.
	fm_23 = a_c_mMatrix4x4.fm_23;//Makes the twelve element of the matrix equal to the equivalent position of the matrix passed in.
	fm_30 = a_c_mMatrix4x4.fm_30;//Makes the thirteenth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_31 = a_c_mMatrix4x4.fm_31;//Makes the fourteenth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_32 = a_c_mMatrix4x4.fm_32;//Makes the fifteenth element of the matrix equal to the equivalent position of the matrix passed in.
	fm_33 = a_c_mMatrix4x4.fm_33;//Makes the sixteenth element of the matrix equal to the equivalent position of the matrix passed in.
	return Matrix4x4(*this);//Returns the equated matrix.
}

Matrix4x4 Matrix4x4::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Matrix4x4.
{  
	return Matrix4x4(*this = *this * a_c_fScalar);//Returns the multiplied equated matrix.
}

Matrix4x4 Matrix4x4::operator*=(const Vector3 &a_c_vVector3)//Overloaded times equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this * a_c_vVector3);//Returns the multiplied equated matrix.
}

Matrix4x4 Matrix4x4::operator*=(const Matrix4x4 &a_c_mMatrix4x4)//Overloaded times equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this * a_c_mMatrix4x4);//Returns the multiplied equated matrix.
}

Matrix4x4 Matrix4x4::operator/=(const float &a_c_fScalar)//Overloaded divided equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this / a_c_fScalar);//Returns the divided equated matrix.
}

Matrix4x4 Matrix4x4::operator/=(const Vector3 &a_c_vVector3)//Overloaded divided equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this / a_c_vVector3);//Returns the divided equated matrix.
}

Matrix4x4 Matrix4x4::operator/=(const Matrix4x4 &a_c_mMatrix4x4)//Overloaded divided equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this / a_c_mMatrix4x4);//Returns the divided equated matrix.
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Matrix4x4::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Matrix4x4.
{
	return bool(//Checks to see if each element in the Matrix4x4 is not equal to the scalar argument passed in and returns true if one is not.
		fm_00 != a_c_fScalar || fm_01 != a_c_fScalar || fm_02 != a_c_fScalar || fm_03 != a_c_fScalar ||
		fm_10 != a_c_fScalar || fm_11 != a_c_fScalar || fm_12 != a_c_fScalar || fm_13 != a_c_fScalar ||
		fm_20 != a_c_fScalar || fm_21 != a_c_fScalar || fm_22 != a_c_fScalar || fm_23 != a_c_fScalar ||
		fm_30 != a_c_fScalar || fm_31 != a_c_fScalar || fm_32 != a_c_fScalar || fm_33 != a_c_fScalar);
}

bool Matrix4x4::operator!=(const Vector3 &a_c_vVector3)const//Overloaded not equals operation for Matrix4x4.
{
	Vector4 temp(a_c_vVector3);
	return bool(//Checks to see if each axis in the Matrix4x4 is not equal to the Vector3 argument passed in and returns true if one is not.
		vXAxis != temp ||
		vYAxis != temp ||
		vZAxis != temp ||
		vWAxis != temp);
}

bool Matrix4x4::operator!=(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded not equals operation for Matrix4x4.
{
	return bool(//Checks each element in the Matrix4x4 against the passed in Matrix4x4 and if one element is not the same as the passed in matrix then return true.
		fm_00 != a_c_mMatrix4x4.fm_00 || fm_01 != a_c_mMatrix4x4.fm_01 || fm_02 != a_c_mMatrix4x4.fm_02 || fm_03 != a_c_mMatrix4x4.fm_03 ||
		fm_10 != a_c_mMatrix4x4.fm_10 || fm_11 != a_c_mMatrix4x4.fm_11 || fm_12 != a_c_mMatrix4x4.fm_12 || fm_13 != a_c_mMatrix4x4.fm_13 ||
		fm_20 != a_c_mMatrix4x4.fm_20 || fm_21 != a_c_mMatrix4x4.fm_21 || fm_22 != a_c_mMatrix4x4.fm_22 || fm_23 != a_c_mMatrix4x4.fm_23 ||
		fm_30 != a_c_mMatrix4x4.fm_30 || fm_31 != a_c_mMatrix4x4.fm_31 || fm_32 != a_c_mMatrix4x4.fm_32 || fm_33 != a_c_mMatrix4x4.fm_33);
}

bool Matrix4x4::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Matrix4x4.
{
	return bool(//Checks to see if each element in the Matrix4x4 is equal to the scalar argument passed in and returns true if every element is.
		fm_00 == a_c_fScalar && fm_01 == a_c_fScalar && fm_02 == a_c_fScalar && fm_03 == a_c_fScalar &&
		fm_10 == a_c_fScalar && fm_11 == a_c_fScalar && fm_12 == a_c_fScalar && fm_13 == a_c_fScalar &&
        fm_20 == a_c_fScalar && fm_21 == a_c_fScalar && fm_22 == a_c_fScalar && fm_23 == a_c_fScalar &&
		fm_30 == a_c_fScalar && fm_31 == a_c_fScalar && fm_32 == a_c_fScalar && fm_33 == a_c_fScalar);
}

bool Matrix4x4::operator==(const Vector3 &a_c_vVector3)const//Overloaded is equals operation for Matrix4x4.
{
	Vector4 temp(a_c_vVector3);
	return bool(//Checks to see if every axis in the Matrix4x4 is equal to the argument vector and returns true if they are all equal.
		vXAxis == temp &&
		vYAxis == temp &&
		vZAxis == temp &&
		vWAxis == temp);
}

bool Matrix4x4::operator==(const Matrix4x4 &a_c_mMatrix4x4)const//Overloaded is equals operation for Matrix4x4.
{
	return bool(// Checks each element in the Matrix4x4 against the passed in Matrix4x4 and if all elements are the same return true.
		fm_00 == a_c_mMatrix4x4.fm_00 && fm_01 == a_c_mMatrix4x4.fm_01 && fm_02 == a_c_mMatrix4x4.fm_02 && fm_03 == a_c_mMatrix4x4.fm_03 &&
		fm_10 == a_c_mMatrix4x4.fm_10 && fm_11 == a_c_mMatrix4x4.fm_11 && fm_12 == a_c_mMatrix4x4.fm_12 && fm_13 == a_c_mMatrix4x4.fm_13 &&
		fm_20 == a_c_mMatrix4x4.fm_20 && fm_21 == a_c_mMatrix4x4.fm_21 && fm_22 == a_c_mMatrix4x4.fm_22 && fm_23 == a_c_mMatrix4x4.fm_23 &&
		fm_30 == a_c_mMatrix4x4.fm_30 && fm_31 == a_c_mMatrix4x4.fm_31 && fm_32 == a_c_mMatrix4x4.fm_32 && fm_33 == a_c_mMatrix4x4.fm_33);
}

//\===========================================================================================
//\ Rotate Around Euler Axis
//\===========================================================================================

void Matrix4x4::rotateX(float &a_fAngle)//Rotates the Matrix4x4 by the angle in degrees around the x axis. 
{
	*this = *this * getXRotationMatrix(a_fAngle);//Multiplies the matrix by the rotations matrix.
}

void Matrix4x4::rotateY(float &a_fAngle)//Rotates the Matrix4x4 by the angle in degrees around the y axis. 
{
	*this = *this * getYRotationMatrix(a_fAngle);//Multiplies the matrix by the rotations matrix.
}

void Matrix4x4::rotateZ(float &a_fAngle)//Rotates the Matrix4x4 by the angle in degrees around the z axis. 
{
	*this = *this * getZRotationMatrix(a_fAngle);//Multiplies the matrix by the rotations matrix.
}

Matrix4x4 Matrix4x4::getXRotationMatrix(float &a_fAngle)const//Returns the X Rotation Matrix4x4 by the angle in degrees. 
{
	Matrix4x4 temp = *this;
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
	const float co = cosf(a_fAngle);									   //\===================================
	const float si = sinf(a_fAngle);									   //\= Makes a Matrix4x4 equal to the XRotation matrix which is:
	temp.fm_00 = 1; temp.fm_01 =   0; temp.fm_02 =  0; temp.fm_03 =  0;	   //\=  1,   0,   0,   0,
	temp.fm_10 = 0; temp.fm_11 =  co; temp.fm_12 =  si; temp.fm_13 = 0;	   //\=  0, cos, sin,   0,
	temp.fm_20 = 0; temp.fm_21 = -si; temp.fm_22 =  co; temp.fm_23 = 0;	   //\=  0,-sin, cos,   0,
	temp.fm_30 = 0; temp.fm_31 =  0; temp.fm_32 =    0; temp.fm_33 = 1;	       //\=  0,   0,   0,   1
	return Matrix4x4(temp);												   //\===================================
}

Matrix4x4 Matrix4x4::getYRotationMatrix(float &a_fAngle)const//Returns the Y Rotation Matrix4x4 by the angle in degrees.
{
	Matrix4x4 temp = *this;
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
	const float co = cosf(a_fAngle);										//\===================================
	const float si = sinf(a_fAngle);										//\= Makes a Matrix4x4 equal to the YRotation matrix which is:
	temp.fm_00 = co; temp.fm_01 = 0; temp.fm_02 = -si; temp.fm_03 = 0;		//\=  cos,   0,-sin,   0,
	temp.fm_10 =  0; temp.fm_11 = 1; temp.fm_12 =   0; temp.fm_13 = 0;		//\=    0,   1,   0,   0,
	temp.fm_20 = si; temp.fm_21 = 0; temp.fm_22 =  co; temp.fm_23 = 0;		//\=  sin,   0, cos,   0,
	temp.fm_30 =  0; temp.fm_31 = 0; temp.fm_32 =   0; temp.fm_33 = 1;		//\=    0,   0,   0,   1
	return Matrix4x4(temp);												    //\===================================
}

Matrix4x4 Matrix4x4::getZRotationMatrix(float &a_fAngle)const//Returns the Z Rotation Matrix4x4 by the angle in degrees.
{
	Matrix4x4 temp = *this;
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.
	const float co = cosf(a_fAngle);										  //\===================================
	const float si = sinf(a_fAngle);										  //\= Makes a Matrix4x4 equal to the ZRotation matrix which is:
	temp.fm_00 =  co; temp.fm_01 = si; temp.fm_02 = 0; temp.fm_03 = 0;		  //\=  cos, sin,   0,   0,
	temp.fm_10 = -si; temp.fm_11 = co; temp.fm_12 = 0; temp.fm_13 = 0;		  //\= -sin, cos,   0,   0,
	temp.fm_20 =   0; temp.fm_21 =  0; temp.fm_22 = 1; temp.fm_23 = 0;		  //\=    0,   0,   1,   0,
	temp.fm_30 =   0; temp.fm_31 =  0; temp.fm_32 = 0; temp.fm_33 = 1;		  //\=    0,   0,   0,   1
	return Matrix4x4(temp);													  //\===================================
}

//\===========================================================================================
//\ Determinant
//\===========================================================================================

float Matrix4x4::determinant()const//A function to get the determinant of a Matrix4x4.
{
	return float(//Returns the determinant of the matrix3x3 using the equation 00*(11*22-12*21)+01*(12*20-10*22)+02*(10*21-11*20)
		fm_00 * (fm_11 * fm_22 - fm_12 * fm_21) +
		fm_01 * (fm_12 * fm_20 - fm_10 * fm_22) +
		fm_02 * (fm_10 * fm_21 - fm_11 * fm_20));
}

//\===========================================================================================
//\ Inversion
//\===========================================================================================

bool Matrix4x4::inverse()//A function that returns the inverse of a Matrix4x4.
{
	const float fDeterminant = determinant();
	if (fDeterminant != 0)
	{
		const float fInverseDeterminant = reciprocal(fDeterminant);
		Matrix4x4 temp = *this;
		fm_00 = (temp.fm_11 * temp.fm_22 - temp.fm_12 * temp.fm_21) * fInverseDeterminant; 
		fm_01 = (temp.fm_02 * temp.fm_21 - temp.fm_01 * temp.fm_22) * fInverseDeterminant;
		fm_02 = (temp.fm_01 * temp.fm_12 - temp.fm_02 * temp.fm_11) * fInverseDeterminant;
		fm_03 = 0;
		fm_10 = (temp.fm_12 * temp.fm_20 - temp.fm_10 * temp.fm_22) * fInverseDeterminant;
		fm_11 = (temp.fm_00 * temp.fm_22 - temp.fm_02 * temp.fm_20) * fInverseDeterminant;
		fm_12 = (temp.fm_02 * temp.fm_10 - temp.fm_00 * temp.fm_12) * fInverseDeterminant;
		fm_13 = 0;
		fm_20 = (temp.fm_10 * temp.fm_21 - temp.fm_11 * temp.fm_20) * fInverseDeterminant;
		fm_21 = (temp.fm_01 * temp.fm_20 - temp.fm_00 * temp.fm_21) * fInverseDeterminant;
		fm_22 = (temp.fm_00 * temp.fm_11 - temp.fm_01 * temp.fm_10) * fInverseDeterminant;
		fm_23 = 0;
		fm_30 = (temp.fm_10 * (temp.fm_22 * temp.fm_31 - temp.fm_21 * temp.fm_32) + 
			     temp.fm_11 * (temp.fm_20 * temp.fm_32 - temp.fm_22 * temp.fm_30) + 
			     temp.fm_12 * (temp.fm_21 * temp.fm_30 - temp.fm_20 * temp.fm_31)) * fInverseDeterminant;
		fm_31 = (temp.fm_00 * (temp.fm_21 * temp.fm_32 - temp.fm_22 * temp.fm_31) + 
			     temp.fm_01 * (temp.fm_22 * temp.fm_30 - temp.fm_20 * temp.fm_32) + 
			     temp.fm_02 * (temp.fm_20 * temp.fm_31 - temp.fm_21 * temp.fm_30)) * fInverseDeterminant;
		fm_32 = (temp.fm_00 * (temp.fm_12 * temp.fm_31 - temp.fm_11 * temp.fm_32) + 
			     temp.fm_01 * (temp.fm_10 * temp.fm_32 - temp.fm_12 * temp.fm_30) + 
			     temp.fm_02 * (temp.fm_11 * temp.fm_30 - temp.fm_10 * temp.fm_31)) * fInverseDeterminant;
		fm_33 = 1;
		return bool(true);
	}
	return bool(false);
}

//\===========================================================================================
//\ Scale
//\===========================================================================================

void Matrix4x4::scale(const float &a_c_fXScale, float &a_c_fYScale, float &a_c_fZScale)//Scales Matrix4x4          
{
	*this = *this * getScaleMatrix(a_c_fXScale, a_c_fYScale, a_c_fZScale);//Multiplies the matrix by the scale matrix.
}

Matrix4x4 Matrix4x4::getScaleMatrix(const float &a_c_fXScale, float &a_c_fYScale, float &a_c_fZScale)const//Returns the scale Matrix4x4                     
{
	Matrix4x4 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will scale matrix.  //\===================================		   
	temp.fm_00 = a_c_fXScale; temp.fm_01 =           0; temp.fm_02 =           0; temp.fm_03 = 0;            //\= xScale,       0,      0, 0,
	temp.fm_10 =           0; temp.fm_11 = a_c_fYScale; temp.fm_12 =           0; temp.fm_13 = 0;            //\=      0,  yScale,      0, 0,
	temp.fm_20 =           0; temp.fm_21 =           0; temp.fm_22 = a_c_fZScale; temp.fm_23 = 0;            //\=      0,       0, zScale, 0,
	temp.fm_30 =           0; temp.fm_31 =           0; temp.fm_32 =           0; temp.fm_33 = 1;			 //\=      0,       0,      0, 1
	return Matrix4x4(temp);                                                                                  //\===================================
}

//\===========================================================================================
//\ Transpose A Point
//\===========================================================================================

void Matrix4x4::transpose()//Transposes the Matrix4x4. 													 
{																										//\===================================
	Matrix4x4 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will transpose.//\= Makes the Matrix4x4 equal to the transpose matrix which is:
	fm_01 = temp.fm_10; fm_02 = temp.fm_20; fm_03 = temp.fm_30;											//\= 00, 10, 20, 30,
	fm_10 = temp.fm_01; fm_12 = temp.fm_21; fm_13 = temp.fm_31;											//\= 01, 11, 21, 31,
	fm_20 = temp.fm_02; fm_21 = temp.fm_12; fm_23 = temp.fm_32;											//\= 02, 12, 22, 32
	fm_30 = temp.fm_03; fm_31 = temp.fm_13; fm_32 = temp.fm_23;											//\= 03, 13, 23, 33
}															   											//\===================================
															   									   
//\===========================================================================================
//\ Set To Identity
//\===========================================================================================

void Matrix4x4::setIdentity()//Makes the Matrix4x4 an identity matrix.
{																      
	*this = IDENTITY;
}																      
																
//\===================================================================
//\ Identity
//\===========================================================================================

Matrix4x4 Matrix4x4::identity()const//Returns a Matrix4x4 identity matrix.
{
	return Matrix4x4(IDENTITY);
}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Matrix4x4::setZero()//Makes each Matrix4x4 element equal to 0. 
{//Set each element in the Matrix4x4 to zero.
	*this = ZERO;
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Matrix4x4 Matrix4x4::zero()const//Returns a Matrix4x4 zero matrix.
{
	return Matrix4x4(ZERO);
}

//\===========================================================================================
//\ Special Points
//\===========================================================================================

static const Matrix4x4 ZERO{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
static const Matrix4x4 IDENTITY{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };