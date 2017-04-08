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

Matrix4x4::Matrix4x4(const Matrix4x4 &a_c_fm4Matrix4x4)//Copy constructor.
{
	m_fm_00 = a_c_fm4Matrix4x4.getiMatrix(0);//Sets the fm_00 value of the Matrix4x4 equal to the Matrix4x4's fm_00 component that is passed in.
 
	m_fm_01 = a_c_fm4Matrix4x4.getiMatrix(1);//Sets the fm_01 value of the Matrix4x4 equal to the Matrix4x4's fm_01 component that is passed in.
	 
	m_fm_02 = a_c_fm4Matrix4x4.getiMatrix(2);//Sets the fm_02 value of the Matrix4x4 equal to the Matrix4x4's fm_02 component that is passed in.
 
	m_fm_03 = a_c_fm4Matrix4x4.getiMatrix(3);//Sets the fm_03 value of the Matrix4x4 equal to the Matrix4x4's fm_03 component that is passed in.
	 
	m_fm_10 = a_c_fm4Matrix4x4.getiMatrix(4);//Sets the fm_10 value of the Matrix4x4 equal to the Matrix4x4's fm_10 component that is passed in.
	 
	m_fm_11 = a_c_fm4Matrix4x4.getiMatrix(5);//Sets the fm_11 value of the Matrix4x4 equal to the Matrix4x4's fm_11 component that is passed in.
 
	m_fm_12 = a_c_fm4Matrix4x4.getiMatrix(6);//Sets the fm_12 value of the Matrix4x4 equal to the Matrix4x4's fm_12 component that is passed in.
 
	m_fm_13 = a_c_fm4Matrix4x4.getiMatrix(7);//Sets the fm_13 value of the Matrix4x4 equal to the Matrix4x4's fm_13 component that is passed in.
	 
	m_fm_20 = a_c_fm4Matrix4x4.getiMatrix(8);//Sets the fm_20 value of the Matrix4x4 equal to the Matrix4x4's fm_20 component that is passed in.
 
	m_fm_21 = a_c_fm4Matrix4x4.getiMatrix(9);//Sets the fm_21 value of the Matrix4x4 equal to the Matrix4x4's fm_21 component that is passed in.
	 
	m_fm_22 = a_c_fm4Matrix4x4.getiMatrix(10);//Sets the fm_22 value of the Matrix4x4 equal to the Matrix4x4's fm_22 component that is passed in.
	 
	m_fm_23 = a_c_fm4Matrix4x4.getiMatrix(11);//Sets the fm_23 value of the Matrix4x4 equal to the Matrix4x4's fm_23 component that is passed in.
	 
	m_fm_30 = a_c_fm4Matrix4x4.getiMatrix(12);//Sets the fm_30 value of the Matrix4x4 equal to the Matrix4x4's fm_30 component that is passed in.
	 
	m_fm_31 = a_c_fm4Matrix4x4.getiMatrix(13);//Sets the fm_31 value of the Matrix4x4 equal to the Matrix4x4's fm_31 component that is passed in.
	 
	m_fm_32 = a_c_fm4Matrix4x4.getiMatrix(14);//Sets the fm_32 value of the Matrix4x4 equal to the Matrix4x4's fm_32 component that is passed in.
	 
	m_fm_33 = a_c_fm4Matrix4x4.getiMatrix(15);//Sets the fm_33 value of the Matrix4x4 equal to the Matrix4x4's fm_33 component that is passed in.
}

Matrix4x4::Matrix4x4(const float a_c_fmMatrix[4][4])//Constructor for a Matrix4x4 that is made from two arrays of four.
{
	m_fmMatrix[0][0] = a_c_fmMatrix[0][0];//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[0][1] = a_c_fmMatrix[0][1];//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[0][2] = a_c_fmMatrix[0][2];//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[0][3] = a_c_fmMatrix[0][3];//Sets the matrix's fourth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[1][0] = a_c_fmMatrix[1][0];//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[1][1] = a_c_fmMatrix[1][1];//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[1][2] = a_c_fmMatrix[1][2];//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[1][3] = a_c_fmMatrix[1][3];//Sets the matrix's eighth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[2][0] = a_c_fmMatrix[2][0];//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[2][1] = a_c_fmMatrix[2][1];//Sets the matrix's tenth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[2][2] = a_c_fmMatrix[2][2];//Sets the matrix's eleventh element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[2][3] = a_c_fmMatrix[2][3];//Sets the matrix's twelve element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[3][0] = a_c_fmMatrix[3][0];//Sets the matrix's thirteenth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[3][1] = a_c_fmMatrix[3][1];//Sets the matrix's fourteenth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[3][2] = a_c_fmMatrix[3][2];//Sets the matrix's fifteenth element of the matrix to the same as the matrix passed in.
	
	m_fmMatrix[3][3] = a_c_fmMatrix[3][3];//Sets the matrix's sixteenth element of the matrix to the same as the matrix passed in.
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
	m_fm_00 = a_c_fm_00;//Sets the matrix's first element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_01 = a_c_fm_01;//Sets the matrix's second element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_02 = a_c_fm_02;//Sets the matrix's third element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_03 = a_c_fm_03;//Sets the matrix's fourth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_10 = a_c_fm_10;//Sets the matrix's fifth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_11 = a_c_fm_11;//Sets the matrix's sixth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_12 = a_c_fm_12;//Sets the matrix's seventh element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_13 = a_c_fm_13;//Sets the matrix's eighth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_20 = a_c_fm_20;//Sets the matrix's ninth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_21 = a_c_fm_21;//Sets the matrix's tenth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_22 = a_c_fm_22;//Sets the matrix's eleventh element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_23 = a_c_fm_23;//Sets the matrix's twelve element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_30 = a_c_fm_30;//Sets the matrix's thirteenth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_31 = a_c_fm_31;//Sets the matrix's fourteenth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_32 = a_c_fm_32;//Sets the matrix's fifteenth element of the matrix to the same as the equivalent argument  passed in.
	 
	m_fm_33 = a_c_fm_33;//Sets the matrix's sixteenth element of the matrix to the same as the equivalent argument  passed in.
}

Matrix4x4::Matrix4x4(const float a_c_fiMatrix[16])//Constructor that takes an array of sixteen floats to make a Matrix4x4.
{
	m_fiMatrix[0] = a_c_fiMatrix[0];//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[1] = a_c_fiMatrix[1];//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[2] = a_c_fiMatrix[2];//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[3] = a_c_fiMatrix[3];//Sets the matrix's fourth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[4] = a_c_fiMatrix[4];//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[5] = a_c_fiMatrix[5];//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[6] = a_c_fiMatrix[6];//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[7] = a_c_fiMatrix[7];//Sets the matrix's eighth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[8] = a_c_fiMatrix[8];//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[9] = a_c_fiMatrix[9];//Sets the matrix's tenth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[10] = a_c_fiMatrix[10];//Sets the matrix's eleventh element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[11] = a_c_fiMatrix[11];//Sets the matrix's twelve element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[12] = a_c_fiMatrix[12];//Sets the matrix's thirteenth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[13] = a_c_fiMatrix[13];//Sets the matrix's fourteenth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[14] = a_c_fiMatrix[14];//Sets the matrix's fifteenth element of the matrix to the same as the matrix passed in.
	 
	m_fiMatrix[15] = a_c_fiMatrix[15];//Sets the matrix's sixteenth element of the matrix to the same as the matrix passed in.
}

Matrix4x4::Matrix4x4(const//Constructor for a Matrix4x4 made from four Vector4's.
	Vector4 a_c_v4XAxis,
	Vector4 a_c_v4YAxis,
	Vector4 a_c_v4ZAxis,
	Vector4 a_c_v4WAxis):
	m_v4XAxis(a_c_v4XAxis),//Sets the vXAxis of the Matrix3x3 equal to the first Vector passed in.
	m_v4YAxis(a_c_v4YAxis),//Sets the vYAxis of the Matrix3x3 equal to the second Vector passed in.
	m_v4ZAxis(a_c_v4ZAxis),//Sets the vZAxis of the Matrix3x3 equal to the third Vector passed in.
	m_v4WAxis(a_c_v4WAxis)//Sets the vWAxis of the Matrix3x3 equal to the fourth Vector passed in.
{}

Matrix4x4::Matrix4x4(const Matrix3x3 a_c_fm3Matrix3x3)//Constructor to make a Matrix4x4 from a Matrix3x3.
{
	m_fm_00 = a_c_fm3Matrix3x3.getiMatrix(0);//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	 
	m_fm_01 = a_c_fm3Matrix3x3.getiMatrix(1);//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	 
	m_fm_02 = a_c_fm3Matrix3x3.getiMatrix(2);//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	 
	m_fm_03 = 0;//Sets the element to what is would be in the identity matrix.
	 
	m_fm_10 = a_c_fm3Matrix3x3.getiMatrix(5);//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	 
	m_fm_11 = a_c_fm3Matrix3x3.getiMatrix(6);//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	 
	m_fm_12 = a_c_fm3Matrix3x3.getiMatrix(7);//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	 
	m_fm_13 = 0;//Sets the element to what is would be in the identity matrix.
	 
	m_fm_20 = a_c_fm3Matrix3x3.getiMatrix(9);//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
	 
	m_fm_21 = a_c_fm3Matrix3x3.getiMatrix(10);//Sets the matrix's tenth element of the matrix to the same as the matrix passed in.
	 
	m_fm_22 = a_c_fm3Matrix3x3.getiMatrix(11);//Sets the matrix's eleventh element of the matrix to the same as the matrix passed in.
	 
	m_fm_23 = 0;//Sets the element to what is would be in the identity matrix.
	 
	m_fm_30 = 0;//Sets the element to what is would be in the identity matrix.
	 
	m_fm_31 = 0;//Sets the element to what is would be in the identity matrix.
	 
	m_fm_32 = 0;//Sets the element to what is would be in the identity matrix.
	 
	m_fm_33 = 1;//Sets the element to what is would be in the identity matrix.
}

//\===========================================================================================
//\ Getters
//\===========================================================================================

const float* Matrix4x4::getMatrix()const//Returns a pointer to the first element in the array.
{
	return m_fiMatrix;//Returns a pointer to the first element in the matrix.
}

float Matrix4x4::getmMatrix(const int &a_c_iRow, int &a_c_iCol)const//A getter to return a float at the point specified with the two arguments.
{
	return float(m_fmMatrix[a_c_iRow][a_c_iCol]);//Returns a float at the row of the first argument passed in and the column of the second argument passed in.
}

float Matrix4x4::getiMatrix(const int &a_c_iPosition)const//A getter to Returns a float from the matrix at the position of the argument passed in.
{
	return float(m_fiMatrix[a_c_iPosition]);//Returns a float from the matrix at the position of the argument passed in.
}

Vector4 Matrix4x4::getXAxis()const//A getter to return the vXAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(m_v4XAxis);//Returns the vXAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getYAxis()const//A getter to return the vYAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(m_v4YAxis);//Returns the vYAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getZAxis()const//A getter to return the vZAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(m_v4ZAxis);//Returns the vZAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getWAxis()const//A getter to return the vWAxis of Matrix4x4 in the form of a Vector4.
{
	return Vector4(m_v4WAxis);//Returns the vWAxis of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getTranslation()const//A getter to return the vTranslation of Matrix4x4 in the form of a Vector4.
{
	return Vector4(m_v4Translation);//Returns the vTranslation of the Matrix4x4 in the form of a Vector4.
}

Vector4 Matrix4x4::getColumn(const int &a_c_iCol)const//A getter to return the column specified by the argument a_c_iCol.
{
	return Vector4(m_fmMatrix[0][a_c_iCol], m_fmMatrix[1][a_c_iCol], m_fmMatrix[2][a_c_iCol], m_fmMatrix[3][a_c_iCol]);//Returns the column as a Vector4.
}

Vector4 Matrix4x4::getRow(const int &a_c_iRow)const//A getter to return the row specified by the argument a_c_iRow.
{
	return Vector4(m_fmMatrix[a_c_iRow][0], m_fmMatrix[a_c_iRow][1], m_fmMatrix[a_c_iRow][2], m_fmMatrix[a_c_iRow][3]);//Returns the row as a Vector4.
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Matrix4x4::setmMatrix(const int &a_c_iRow, int &a_c_iCol, float &a_c_fNewNumber)//A setter to change the float in the matrix at the point specified with the two arguments.
{
	m_fmMatrix[a_c_iRow][a_c_iCol] = a_c_fNewNumber;//Sets the float specified by the first and second argument to the third argument.
}

void Matrix4x4::setiMatrix(const int &a_c_iPosition, float &a_c_fNewNumber)//A setter to change the float in the matrix at the position of the argument passed in.
{
	m_fiMatrix[a_c_iPosition] = a_c_fNewNumber;//Sets the float at the position of the first argument to the float of the second argument.
}

void Matrix4x4::setXAxis(const Vector4 &a_c_v4Vector4)//A setter to change the vXAxis of Matrix4x4 to the Vector4 argument.
{
	m_v4XAxis = a_c_v4Vector4;//Sets the vXAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setYAxis(const Vector4 &a_c_v4Vector4)//A setter to change the vYAxis of Matrix4x4 to the Vector4 argument.
{
	m_v4YAxis = a_c_v4Vector4;//Sets the vYAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setZAxis(const Vector4 &a_c_v4Vector4)//A setter to change the vZAxis of Matrix4x4 to the Vector4 argument.
{
	m_v4ZAxis = a_c_v4Vector4;//Sets the vZAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setWAxis(const Vector4 &a_c_v4Vector4)//A setter to change the vWAxis of Matrix4x4 to the Vector4 argument.
{
	m_v4WAxis = a_c_v4Vector4;//Sets the vWAxis Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setTranslation(const Vector4 &a_c_v4Vector4)//A setter to change the vTranslation of Matrix4x4 to the vTranslation argument.
{
	m_v4Translation = a_c_v4Vector4;//Sets the vTranslation Vector4 of the Matrix4x4 equal to the Vector4 passed in.
}

void Matrix4x4::setColumn(const int &a_c_iCol, Vector4 &a_c_v4Vector4)//A setter for the column specified by the argument a_c_iCol.
{//Sets the column specified by the a_c_iCol equal to the argument Vector4.
	m_fmMatrix[0][a_c_iCol] = a_c_v4Vector4.getfX();//Sets the first row of the specified column to be equal to the x component of the Vector4 passed in.

	m_fmMatrix[1][a_c_iCol] = a_c_v4Vector4.getfY();//Sets the second row of the specified column to be equal to the y component of the Vector4 passed in.

	m_fmMatrix[2][a_c_iCol] = a_c_v4Vector4.getfZ();//Sets the third row of the specified column to be equal to the z component of the Vector4 passed in.

	m_fmMatrix[3][a_c_iCol] = a_c_v4Vector4.getfW();//Sets the fourth row of the specified column to be equal to the w component of the Vector4 passed in.
}

void Matrix4x4::setRow(const int &a_c_iRow, Vector4 &a_c_v4Vector4)//A setter for the row specified by the argument a_c_iRow.
{//Sets the row specified by the a_c_iRow equal to the argument Vector4.
	m_fmMatrix[a_c_iRow][0] = a_c_v4Vector4.getfX();//Sets the first column of the specified row to be equal to the x component of the Vector4 passed in.

	m_fmMatrix[a_c_iRow][1] = a_c_v4Vector4.getfY();//Sets the second column of the specified row to be equal to the y component of the Vector4 passed in.

	m_fmMatrix[a_c_iRow][2] = a_c_v4Vector4.getfZ();//Sets the third column of the specified row to be equal to the z component of the Vector4 passed in.

	m_fmMatrix[a_c_iRow][3] = a_c_v4Vector4.getfW();//Sets the fourth column of the specified row to be equal to the w component of the Vector4 passed in.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Matrix4x4 Matrix4x4::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Matrix4x4.
{
	Matrix4x4 tempAdditionMatrix;//Creates a temporary matrix that will hold the added matrix.

	tempAdditionMatrix.m_fm_00 = m_fm_00 + a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix increased by the float passed in.
		 
	tempAdditionMatrix.m_fm_01 = m_fm_01 + a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix increased by the float passed in.
					 
	tempAdditionMatrix.m_fm_02 = m_fm_02 + a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix increased by the float passed in.
					   
	tempAdditionMatrix.m_fm_03 = m_fm_03 + a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix increased by the float passed in.
				 
	tempAdditionMatrix.m_fm_10 = m_fm_10 + a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix increased by the float passed in.
					 
	tempAdditionMatrix.m_fm_11 = m_fm_11 + a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix increased by the float passed in.
					 
	tempAdditionMatrix.m_fm_12 = m_fm_12 + a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix increased by the float passed in.
					  
	tempAdditionMatrix.m_fm_13 = m_fm_13 + a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix increased by the float passed in.
					 
	tempAdditionMatrix.m_fm_20 = m_fm_20 + a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix increased by the float passed in.
					   
	tempAdditionMatrix.m_fm_21 = m_fm_21 + a_c_fScalar;//Makes temporary matrix equal to the tenth element of the matrix increased by the float passed in.
					 
	tempAdditionMatrix.m_fm_22 = m_fm_22 + a_c_fScalar;//Makes temporary matrix equal to the eleventh element of the matrix increased by the float passed in.
					  
	tempAdditionMatrix.m_fm_23 = m_fm_23 + a_c_fScalar;//Makes temporary matrix equal to the twelve element of the matrix increased by the float passed in.
					 
	tempAdditionMatrix.m_fm_30 = m_fm_30 + a_c_fScalar;//Makes temporary matrix equal to the thirteenth element of the matrix increased by the float passed in.
					   		 
	tempAdditionMatrix.m_fm_31 = m_fm_31 + a_c_fScalar;//Makes temporary matrix equal to the fourteenth element of the matrix increased by the float passed in.
					   		 
	tempAdditionMatrix.m_fm_32 = m_fm_32 + a_c_fScalar;//Makes temporary matrix equal to the fifteenth element of the matrix increased by the float passed in.
					   		 
	tempAdditionMatrix.m_fm_33 = m_fm_33 + a_c_fScalar;//Makes temporary matrix equal to the sixteenth element of the matrix increased by the float passed in.

	return Matrix4x4(tempAdditionMatrix);//Returns the increased matrix.
}

Matrix4x4 Matrix4x4::operator+(const Vector3 &a_c_v3Vector3)const//Overloaded addition operation for Matrix4x4.
{
	Vector4 temp(a_c_v3Vector3);//Creates a temporary Vector4 equal to the passed in Vector3.

	m_v4XAxis + temp;//Increases the vXAxis by the argument Vector3.
	 
	m_v4YAxis + temp;//Increases the vYAxis by the argument Vector3.
	 
	m_v4ZAxis + temp;//Increases the vZAxis by the argument Vector3.
	 
	m_v4WAxis + temp;//Increases the vWAxis by the argument Vector3.

	return Matrix4x4(*this);//Returns the increased matrix.
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &a_c_fm4Matrix4x4)const//Overloaded addition operation for Matrix4x4.
{
	Matrix4x4 tempAdditionMatrix;//Creates a temporary matrix that will hold the added matrix.

	tempAdditionMatrix.m_fm_00 = m_fm_00 + a_c_fm4Matrix4x4.m_fm_00;//Makes temporary matrix equal to the first element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_01 = m_fm_01 + a_c_fm4Matrix4x4.m_fm_01;//Makes temporary matrix equal to the second element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_02 = m_fm_02 + a_c_fm4Matrix4x4.m_fm_02;//Makes temporary matrix equal to the third element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_03 = m_fm_03 + a_c_fm4Matrix4x4.m_fm_03;//Makes temporary matrix equal to the fourth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_10 = m_fm_10 + a_c_fm4Matrix4x4.m_fm_10;//Makes temporary matrix equal to the fifth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_11 = m_fm_11 + a_c_fm4Matrix4x4.m_fm_11;//Makes temporary matrix equal to the sixth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_12 = m_fm_12 + a_c_fm4Matrix4x4.m_fm_12;//Makes temporary matrix equal to the seventh element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_13 = m_fm_13 + a_c_fm4Matrix4x4.m_fm_13;//Makes temporary matrix equal to the eighth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_20 = m_fm_20 + a_c_fm4Matrix4x4.m_fm_20;//Makes temporary matrix equal to the ninth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_21 = m_fm_21 + a_c_fm4Matrix4x4.m_fm_21;//Makes temporary matrix equal to the tenth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_22 = m_fm_22 + a_c_fm4Matrix4x4.m_fm_22;//Makes temporary matrix equal to the eleventh element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_23 = m_fm_23 + a_c_fm4Matrix4x4.m_fm_23;//Makes temporary matrix equal to the twelve element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_30 = m_fm_30 + a_c_fm4Matrix4x4.m_fm_30;//Makes temporary matrix equal to the thirteenth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_31 = m_fm_31 + a_c_fm4Matrix4x4.m_fm_31;//Makes temporary matrix equal to the fourteenth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_32 = m_fm_32 + a_c_fm4Matrix4x4.m_fm_32;//Makes temporary matrix equal to the fifteenth element of the matrix increase by the equivalent part of the matrix passed in.
					   		 							 
	tempAdditionMatrix.m_fm_33 = m_fm_33 + a_c_fm4Matrix4x4.m_fm_33;//Makes temporary matrix equal to the sixteenth element of the matrix increase by the equivalent part of the matrix passed in.

	return Matrix4x4(tempAdditionMatrix);//Returns the increased matrix.
}

Matrix4x4 Matrix4x4::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Matrix4x4.
{
	Matrix4x4 tempSubtractionMatrix;//Creates a temporary matrix that will hold the subtracted matrix.

	tempSubtractionMatrix.m_fm_00 = m_fm_00 - a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_01 = m_fm_01 - a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_02 = m_fm_02 - a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_03 = m_fm_03 - a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_10 = m_fm_10 - a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_11 = m_fm_11 - a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_12 = m_fm_12 - a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_13 = m_fm_13 - a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_20 = m_fm_20 - a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_21 = m_fm_21 - a_c_fScalar;//Makes temporary matrix equal to the tenth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_22 = m_fm_22 - a_c_fScalar;//Makes temporary matrix equal to the eleventh element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_23 = m_fm_23 - a_c_fScalar;//Makes temporary matrix equal to the twelve element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_30 = m_fm_30 - a_c_fScalar;//Makes temporary matrix equal to the thirteenth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_31 = m_fm_31 - a_c_fScalar;//Makes temporary matrix equal to the fourteenth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_32 = m_fm_32 - a_c_fScalar;//Makes temporary matrix equal to the fifteenth element of the matrix decreased by the float passed in.
						  		 
	tempSubtractionMatrix.m_fm_33 = m_fm_33 - a_c_fScalar;//Makes temporary matrix equal to the sixteenth element of the matrix decreased by the float passed in.

	return Matrix4x4(tempSubtractionMatrix);//Returns the decreased matrix.
}

Matrix4x4 Matrix4x4::operator-(const Vector3 &a_c_v3Vector3)const//Overloaded subtraction operation for Matrix4x4.
{
	Vector4 temp(a_c_v3Vector3);//Creates a temporary Vector4 equal to the passed in Vector3.

	m_v4XAxis - temp;//Decreases the vXAxis by the argument Vector3.
	 
	m_v4YAxis - temp;//Decreases the vYAxis by the argument Vector3.
	 
	m_v4ZAxis - temp;//Decreases the vZAxis by the argument Vector3.
	 
	m_v4WAxis - temp;//Decreases the vWAxis by the argument Vector3.

	return Matrix4x4(*this);//Returns the decreased matrix.
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &a_c_fm4Matrix4x4)const//Overloaded subtraction operation for Matrix4x4.
{
	Matrix4x4 tempSubtractionMatrix;//Creates a temporary matrix that will hold the subtracted matrix.

	tempSubtractionMatrix.m_fm_00 = m_fm_00 - a_c_fm4Matrix4x4.m_fm_00;//Makes temporary matrix equal to the first element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_01 = m_fm_01 - a_c_fm4Matrix4x4.m_fm_01;//Makes temporary matrix equal to the second element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_02 = m_fm_02 - a_c_fm4Matrix4x4.m_fm_02;//Makes temporary matrix equal to the third element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_03 = m_fm_03 - a_c_fm4Matrix4x4.m_fm_03;//Makes temporary matrix equal to the fourth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_10 = m_fm_10 - a_c_fm4Matrix4x4.m_fm_10;//Makes temporary matrix equal to the fifth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_11 = m_fm_11 - a_c_fm4Matrix4x4.m_fm_11;//Makes temporary matrix equal to the sixth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_12 = m_fm_12 - a_c_fm4Matrix4x4.m_fm_12;//Makes temporary matrix equal to the seventh element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_13 = m_fm_13 - a_c_fm4Matrix4x4.m_fm_13;//Makes temporary matrix equal to the eighth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_20 = m_fm_20 - a_c_fm4Matrix4x4.m_fm_20;//Makes temporary matrix equal to the ninth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_21 = m_fm_21 - a_c_fm4Matrix4x4.m_fm_21;//Makes temporary matrix equal to the tenth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_22 = m_fm_22 - a_c_fm4Matrix4x4.m_fm_22;//Makes temporary matrix equal to the eleventh element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_23 = m_fm_23 - a_c_fm4Matrix4x4.m_fm_23;//Makes temporary matrix equal to the twelve element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_30 = m_fm_30 - a_c_fm4Matrix4x4.m_fm_30;//Makes temporary matrix equal to the thirteenth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_31 = m_fm_31 - a_c_fm4Matrix4x4.m_fm_31;//Makes temporary matrix equal to the fourteenth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_32 = m_fm_32 - a_c_fm4Matrix4x4.m_fm_32;//Makes temporary matrix equal to the fifteenth element of the matrix decreased by the equivalent part of the matrix passed in.
						  		 						   
	tempSubtractionMatrix.m_fm_33 = m_fm_33 - a_c_fm4Matrix4x4.m_fm_33;//Makes temporary matrix equal to the sixteenth element of the matrix decreased by the equivalent part of the matrix passed in.

	return Matrix4x4(tempSubtractionMatrix);//Returns the decreased matrix.
}

Matrix4x4 Matrix4x4::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Matrix4x4.
{
	Matrix4x4 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied matrix.

	tempMultiplicationMatrix.m_fm_00 = m_fm_00 * a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_01 = m_fm_01 * a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_02 = m_fm_02 * a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_03 = m_fm_03 * a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_10 = m_fm_10 * a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_11 = m_fm_11 * a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_12 = m_fm_12 * a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_13 = m_fm_13 * a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_20 = m_fm_20 * a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_21 = m_fm_21 * a_c_fScalar;//Makes temporary matrix equal to the tenth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_22 = m_fm_22 * a_c_fScalar;//Makes temporary matrix equal to the eleventh element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_23 = m_fm_23 * a_c_fScalar;//Makes temporary matrix equal to the twelve element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_30 = m_fm_30 * a_c_fScalar;//Makes temporary matrix equal to the thirteenth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_31 = m_fm_31 * a_c_fScalar;//Makes temporary matrix equal to the fourteenth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_32 = m_fm_32 * a_c_fScalar;//Makes temporary matrix equal to the fifteenth element of the matrix multiplied by the float passed in.
							 		   
	tempMultiplicationMatrix.m_fm_33 = m_fm_33 * a_c_fScalar;//Makes temporary matrix equal to the sixteenth element of the matrix multiplied by the float passed in.

	return Matrix4x4(tempMultiplicationMatrix);//Returns the multiplied matrix.
}

Vector4 Matrix4x4::operator*(const Vector3 &a_c_v3Vector3)const//Overloaded multiplication operation for Matrix4x4.
{
	Vector4 temp(a_c_v3Vector3);//Creates a temporary Vector4 equal to the passed in Vector3.

	return Vector4(//Returns the multiplied matrix.
		m_fm_00 * temp.getfX() + m_fm_01 * temp.getfY() + m_fm_02 * temp.getfZ() + m_fm_03 * temp.getfW(),//Dot product for the first row of the first matrix and the only column of the Vector3.
		m_fm_10 * temp.getfX() + m_fm_11 * temp.getfY() + m_fm_12 * temp.getfZ() + m_fm_13 * temp.getfW(),//Dot product for the second row of the first matrix and the only column of the Vector3.
		m_fm_20 * temp.getfX() + m_fm_21 * temp.getfY() + m_fm_22 * temp.getfZ() + m_fm_23 * temp.getfW(),//Dot product for the third row of the first matrix and the only column of the Vector3.
		m_fm_30 * temp.getfX() + m_fm_31 * temp.getfY() + m_fm_32 * temp.getfZ() + m_fm_33 * temp.getfW());//Dot product for the fourth row of the first matrix and the only column of the Vector3.
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &a_c_fm4Matrix4x4)const//Overloaded multiplication operation for Matrix4x4.
{
	Matrix4x4 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied vector.

	tempMultiplicationMatrix.m_fm_00 = m_fm_00 * a_c_fm4Matrix4x4.m_fm_00 + m_fm_01 * a_c_fm4Matrix4x4.m_fm_10 + m_fm_02 * a_c_fm4Matrix4x4.m_fm_20 + m_fm_03 * a_c_fm4Matrix4x4.m_fm_30;//Dot product for the first row of the first matrix and the first column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_01 = m_fm_00 * a_c_fm4Matrix4x4.m_fm_01 + m_fm_01 * a_c_fm4Matrix4x4.m_fm_11 + m_fm_02 * a_c_fm4Matrix4x4.m_fm_21 + m_fm_03 * a_c_fm4Matrix4x4.m_fm_31;//Dot product for the first row of the first matrix and the second column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_02 = m_fm_00 * a_c_fm4Matrix4x4.m_fm_02 + m_fm_01 * a_c_fm4Matrix4x4.m_fm_12 + m_fm_02 * a_c_fm4Matrix4x4.m_fm_22 + m_fm_03 * a_c_fm4Matrix4x4.m_fm_32;//Dot product for the first row of the first matrix and the third column of the second matrix.																																		  
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_03 = m_fm_00 * a_c_fm4Matrix4x4.m_fm_03 + m_fm_01 * a_c_fm4Matrix4x4.m_fm_13 + m_fm_02 * a_c_fm4Matrix4x4.m_fm_23 + m_fm_03 * a_c_fm4Matrix4x4.m_fm_33;//Dot product for the first row of the first matrix and the fourth column of the second matrix.	
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_10 = m_fm_10 * a_c_fm4Matrix4x4.m_fm_00 + m_fm_11 * a_c_fm4Matrix4x4.m_fm_10 + m_fm_12 * a_c_fm4Matrix4x4.m_fm_20 + m_fm_13 * a_c_fm4Matrix4x4.m_fm_30;//Dot product for the second row of the first matrix and the first column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_11 = m_fm_10 * a_c_fm4Matrix4x4.m_fm_01 + m_fm_11 * a_c_fm4Matrix4x4.m_fm_11 + m_fm_12 * a_c_fm4Matrix4x4.m_fm_21 + m_fm_13 * a_c_fm4Matrix4x4.m_fm_31;//Dot product for the second row of the first matrix and the second column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_12 = m_fm_10 * a_c_fm4Matrix4x4.m_fm_02 + m_fm_11 * a_c_fm4Matrix4x4.m_fm_12 + m_fm_12 * a_c_fm4Matrix4x4.m_fm_22 + m_fm_13 * a_c_fm4Matrix4x4.m_fm_32;//Dot product for the second row of the first matrix and the third column of the second matrix.	
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_13 = m_fm_10 * a_c_fm4Matrix4x4.m_fm_03 + m_fm_11 * a_c_fm4Matrix4x4.m_fm_13 + m_fm_12 * a_c_fm4Matrix4x4.m_fm_23 + m_fm_13 * a_c_fm4Matrix4x4.m_fm_33;//Dot product for the second row of the first matrix and the fourth column of the second matrix.	
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_20 = m_fm_20 * a_c_fm4Matrix4x4.m_fm_00 + m_fm_21 * a_c_fm4Matrix4x4.m_fm_10 + m_fm_22 * a_c_fm4Matrix4x4.m_fm_20 + m_fm_23 * a_c_fm4Matrix4x4.m_fm_30;//Dot product for the third row of the first matrix and the first column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_21 = m_fm_20 * a_c_fm4Matrix4x4.m_fm_01 + m_fm_21 * a_c_fm4Matrix4x4.m_fm_11 + m_fm_22 * a_c_fm4Matrix4x4.m_fm_21 + m_fm_23 * a_c_fm4Matrix4x4.m_fm_31;//Dot product for the third row of the first matrix and the second column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_22 = m_fm_20 * a_c_fm4Matrix4x4.m_fm_02 + m_fm_21 * a_c_fm4Matrix4x4.m_fm_12 + m_fm_22 * a_c_fm4Matrix4x4.m_fm_22 + m_fm_23 * a_c_fm4Matrix4x4.m_fm_32;//Dot product for the third row of the first matrix and the third column of the second matrix.
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_23 = m_fm_20 * a_c_fm4Matrix4x4.m_fm_03 + m_fm_21 * a_c_fm4Matrix4x4.m_fm_13 + m_fm_22 * a_c_fm4Matrix4x4.m_fm_23 + m_fm_23 * a_c_fm4Matrix4x4.m_fm_33;	//Dot product for the third row of the first matrix and the fourth column of the second matrix.			  
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_30 = m_fm_30 * a_c_fm4Matrix4x4.m_fm_00 + m_fm_31 * a_c_fm4Matrix4x4.m_fm_10 + m_fm_32 * a_c_fm4Matrix4x4.m_fm_20 + m_fm_33 * a_c_fm4Matrix4x4.m_fm_30;//Dot product for the third row of the first matrix and the first column of the second matrix.		
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_31 = m_fm_30 * a_c_fm4Matrix4x4.m_fm_01 + m_fm_31 * a_c_fm4Matrix4x4.m_fm_11 + m_fm_32 * a_c_fm4Matrix4x4.m_fm_21 + m_fm_33 * a_c_fm4Matrix4x4.m_fm_31;//Dot product for the third row of the first matrix and the second column of the second matrix.		
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_32 = m_fm_30 * a_c_fm4Matrix4x4.m_fm_02 + m_fm_31 * a_c_fm4Matrix4x4.m_fm_12 + m_fm_32 * a_c_fm4Matrix4x4.m_fm_22 + m_fm_33 * a_c_fm4Matrix4x4.m_fm_32;//Dot product for the third row of the first matrix and the third column of the second matrix.	
							 		   						  		 						   		 							 		  						 
	tempMultiplicationMatrix.m_fm_33 = m_fm_30 * a_c_fm4Matrix4x4.m_fm_03 + m_fm_31 * a_c_fm4Matrix4x4.m_fm_13 + m_fm_32 * a_c_fm4Matrix4x4.m_fm_23 + m_fm_33 * a_c_fm4Matrix4x4.m_fm_33;//Dot product for the third row of the first matrix and the fourth column of the second matrix.
																			 
	return Matrix4x4(tempMultiplicationMatrix);//Returns the multiplied matrix.
}

Matrix4x4 Matrix4x4::operator/(const float &a_c_fScalar)const//Overloaded division operation for Matrix4x4.
{
	return Matrix4x4(*this * reciprocal(a_c_fScalar));//Returns the Matrix4x4 / the argument.
}

Vector4 Matrix4x4::operator/(const Vector3 &a_c_v3Vector3)const//Overloaded division operation for Matrix4x4.
{
	return Vector4(*this * a_c_v3Vector3.inverse());//Returns the Matrix4x4 / the argument.
}

Matrix4x4 Matrix4x4::operator/(const Matrix4x4 &a_c_fm4Matrix4x4)const//Overloaded division operation for Matrix4x4.
{//Returns the Matrix4x4 / the argument.
	Matrix4x4 tempMatrix = a_c_fm4Matrix4x4;//Creates a temporary matrix4x4 equal to the passed in matrix4x4.

	tempMatrix.inverse();//Inverses the temporary matrix so it can be used in multiplication rather than division.

	return Matrix4x4(*this * tempMatrix);//Returns the Matrix4x4 * tempMatrix.
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Matrix4x4 Matrix4x4::operator+=(const float &a_c_fScalar)//Overloaded added equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this + a_c_fScalar);//Returns the added equated matrix.
}

Matrix4x4 Matrix4x4::operator+=(const Vector3 &a_c_v3Vector3)//Overloaded added equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this + a_c_v3Vector3);//Returns the added equated matrix.
}

Matrix4x4 Matrix4x4::operator+=(const Matrix4x4 &a_c_fm4Matrix4x4)//Overloaded added equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this + a_c_fm4Matrix4x4);//Returns the added equated matrix.
}

Matrix4x4 Matrix4x4::operator-=(const float &a_c_fScalar)//Overloaded subtracted equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this - a_c_fScalar);//Returns the subtracted equated matrix.
}

Matrix4x4 Matrix4x4::operator-=(const Vector3 &a_c_v3Vector3)//Overloaded subtracted equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this - a_c_v3Vector3);//Returns the subtracted equated matrix.
}

Matrix4x4 Matrix4x4::operator-=(const Matrix4x4 &a_c_fm4Matrix4x4)//Overloaded subtracted equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this - a_c_fm4Matrix4x4);//Returns the subtracted equated matrix.
}

Matrix4x4 Matrix4x4::operator=(const float &a_c_fScalar)//Overloaded equals operation for Matrix4x4.
{
	m_fm_00 = a_c_fScalar;//Makes the first element of the matrix equal to the scalar passed in.
   	 
	m_fm_01 = a_c_fScalar;//Makes the second element of the matrix equal to the scalar passed in.
	 
	m_fm_02 = a_c_fScalar;//Makes the third element of the matrix equal to the scalar passed in.
	 
	m_fm_03 = a_c_fScalar;//Makes the fourth element of the matrix equal to the scalar passed in.
	 
	m_fm_10 = a_c_fScalar;//Makes the fifth element of the matrix equal to the scalar passed in.
	 
	m_fm_11 = a_c_fScalar;//Makes the sixth element of the matrix equal to the scalar passed in.
	 
	m_fm_12 = a_c_fScalar;//Makes the seventh element of the matrix equal to the scalar passed in.
	 
	m_fm_13 = a_c_fScalar;//Makes the eighth element of the matrix equal to the scalar passed in.
	 
	m_fm_20 = a_c_fScalar;//Makes the ninth element of the matrix equal to the scalar passed in.
	 
	m_fm_21 = a_c_fScalar;//Makes the tenth element of the matrix equal to the scalar passed in.
	 
	m_fm_22 = a_c_fScalar;//Makes the eleventh element of the matrix equal to the scalar passed in.
	 
	m_fm_23 = a_c_fScalar;//Makes the	twelve element of the matrix equal to the scalar passed in.
	 
	m_fm_30 = a_c_fScalar;//Makes the	thirteenth element of the matrix equal to the scalar passed in.
	 
	m_fm_31 = a_c_fScalar;//Makes the	fourteenth element of the matrix equal to the scalar passed in.
	 
	m_fm_32 = a_c_fScalar;//Makes the	fifteenth element of the matrix equal to the scalar passed in.
	 
	m_fm_33 = a_c_fScalar;//Makes the	sixteenth element of the matrix equal to the scalar passed in.
	
	return Matrix4x4(*this);//Returns the equated matrix.
}						

Matrix4x4 Matrix4x4::operator=(const Vector3 &a_c_v3Vector3)//Overloaded equals operation for Matrix4x4.
{
	Vector4 temp(a_c_v3Vector3);
	
	m_v4XAxis = temp;//Equates the vXAxis to the argument Vector3.
	
	m_v4YAxis = temp;//Equates the vYAxis to the argument Vector3.
	
	m_v4ZAxis = temp;//Equates the vZAxis to the argument Vector3.
	
	m_v4WAxis = temp;//Equates the vWAxis to the argument Vector3.
	
	return Matrix4x4(*this);//Returns the equated matrix.
}

Matrix4x4 Matrix4x4::operator=(const Vector4 &a_c_v4Vector4)//Overloaded equals operation for Matrix4x4.
{
	m_v4XAxis = a_c_v4Vector4;//Equates the vXAxis to the argument Vector4.
	
	m_v4YAxis = a_c_v4Vector4;//Equates the vYAxis to the argument Vector4.
	
	m_v4ZAxis = a_c_v4Vector4;//Equates the vZAxis to the argument Vector4.
	
	m_v4WAxis = a_c_v4Vector4;//Equates the vWAxis to the argument Vector4.
	
	return Matrix4x4(*this);//Returns the equated matrix.
}

Matrix4x4 Matrix4x4::operator=(const Matrix4x4 &a_c_fm4Matrix4x4)//Overloaded equals operation for Matrix4x4.
{
	m_fm_00 = a_c_fm4Matrix4x4.m_fm_00;//Makes the first element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_01 = a_c_fm4Matrix4x4.m_fm_01;//Makes the second element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_02 = a_c_fm4Matrix4x4.m_fm_02;//Makes the third element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_03 = a_c_fm4Matrix4x4.m_fm_03;//Makes the fourth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_10 = a_c_fm4Matrix4x4.m_fm_10;//Makes the fifth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_11 = a_c_fm4Matrix4x4.m_fm_11;//Makes the sixth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_12 = a_c_fm4Matrix4x4.m_fm_12;//Makes the seventh element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_13 = a_c_fm4Matrix4x4.m_fm_13;//Makes the eighth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_20 = a_c_fm4Matrix4x4.m_fm_20;//Makes the ninth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_21 = a_c_fm4Matrix4x4.m_fm_21;//Makes the tenth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_22 = a_c_fm4Matrix4x4.m_fm_22;//Makes the eleventh element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_23 = a_c_fm4Matrix4x4.m_fm_23;//Makes the twelve element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_30 = a_c_fm4Matrix4x4.m_fm_30;//Makes the thirteenth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_31 = a_c_fm4Matrix4x4.m_fm_31;//Makes the fourteenth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_32 = a_c_fm4Matrix4x4.m_fm_32;//Makes the fifteenth element of the matrix equal to the equivalent position of the matrix passed in.
	 						   
	m_fm_33 = a_c_fm4Matrix4x4.m_fm_33;//Makes the sixteenth element of the matrix equal to the equivalent position of the matrix passed in.
	
	return Matrix4x4(*this);//Returns the equated matrix.
}

Matrix4x4 Matrix4x4::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Matrix4x4.
{  
	return Matrix4x4(*this = *this * a_c_fScalar);//Returns the multiplied equated matrix.
}

Matrix4x4 Matrix4x4::operator*=(const Vector3 &a_c_v3Vector3)//Overloaded times equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this * a_c_v3Vector3);//Returns the multiplied equated matrix.
}

Matrix4x4 Matrix4x4::operator*=(const Matrix4x4 &a_c_fm4Matrix4x4)//Overloaded times equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this * a_c_fm4Matrix4x4);//Returns the multiplied equated matrix.
}

Matrix4x4 Matrix4x4::operator/=(const float &a_c_fScalar)//Overloaded divided equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this / a_c_fScalar);//Returns the divided equated matrix.
}

Matrix4x4 Matrix4x4::operator/=(const Vector3 &a_c_v3Vector3)//Overloaded divided equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this / a_c_v3Vector3);//Returns the divided equated matrix.
}

Matrix4x4 Matrix4x4::operator/=(const Matrix4x4 &a_c_fm4Matrix4x4)//Overloaded divided equals operation for Matrix4x4.
{
	return Matrix4x4(*this = *this / a_c_fm4Matrix4x4);//Returns the divided equated matrix.
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Matrix4x4::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Matrix4x4.
{
	return bool(//Checks to see if each element in the Matrix4x4 is not equal to the scalar argument passed in and returns true if one is not.
		m_fm_00 != a_c_fScalar || m_fm_01 != a_c_fScalar || m_fm_02 != a_c_fScalar || m_fm_03 != a_c_fScalar ||
		m_fm_10 != a_c_fScalar || m_fm_11 != a_c_fScalar || m_fm_12 != a_c_fScalar || m_fm_13 != a_c_fScalar ||
		m_fm_20 != a_c_fScalar || m_fm_21 != a_c_fScalar || m_fm_22 != a_c_fScalar || m_fm_23 != a_c_fScalar ||
		m_fm_30 != a_c_fScalar || m_fm_31 != a_c_fScalar || m_fm_32 != a_c_fScalar || m_fm_33 != a_c_fScalar);
}

bool Matrix4x4::operator!=(const Vector3 &a_c_v3Vector3)const//Overloaded not equals operation for Matrix4x4.
{
	Vector4 temp(a_c_v3Vector3);
	return bool(//Checks to see if each axis in the Matrix4x4 is not equal to the Vector3 argument passed in and returns true if one is not.
		m_v4XAxis != temp ||
		m_v4YAxis != temp ||
		m_v4ZAxis != temp ||
		m_v4WAxis != temp);
}

bool Matrix4x4::operator!=(const Matrix4x4 &a_c_fm4Matrix4x4)const//Overloaded not equals operation for Matrix4x4.
{
	return bool(//Checks each element in the Matrix4x4 against the passed in Matrix4x4 and if one element is not the same as the passed in matrix then return true.
		m_fm_00 != a_c_fm4Matrix4x4.m_fm_00 || m_fm_01 != a_c_fm4Matrix4x4.m_fm_01 || m_fm_02 != a_c_fm4Matrix4x4.m_fm_02 || m_fm_03 != a_c_fm4Matrix4x4.m_fm_03 ||
		m_fm_10 != a_c_fm4Matrix4x4.m_fm_10 || m_fm_11 != a_c_fm4Matrix4x4.m_fm_11 || m_fm_12 != a_c_fm4Matrix4x4.m_fm_12 || m_fm_13 != a_c_fm4Matrix4x4.m_fm_13 ||
		m_fm_20 != a_c_fm4Matrix4x4.m_fm_20 || m_fm_21 != a_c_fm4Matrix4x4.m_fm_21 || m_fm_22 != a_c_fm4Matrix4x4.m_fm_22 || m_fm_23 != a_c_fm4Matrix4x4.m_fm_23 ||
		m_fm_30 != a_c_fm4Matrix4x4.m_fm_30 || m_fm_31 != a_c_fm4Matrix4x4.m_fm_31 || m_fm_32 != a_c_fm4Matrix4x4.m_fm_32 || m_fm_33 != a_c_fm4Matrix4x4.m_fm_33);
}

bool Matrix4x4::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Matrix4x4.
{
	return bool(//Checks to see if each element in the Matrix4x4 is equal to the scalar argument passed in and returns true if every element is.
		m_fm_00 == a_c_fScalar && m_fm_01 == a_c_fScalar && m_fm_02 == a_c_fScalar && m_fm_03 == a_c_fScalar &&
		m_fm_10 == a_c_fScalar && m_fm_11 == a_c_fScalar && m_fm_12 == a_c_fScalar && m_fm_13 == a_c_fScalar &&
        m_fm_20 == a_c_fScalar && m_fm_21 == a_c_fScalar && m_fm_22 == a_c_fScalar && m_fm_23 == a_c_fScalar &&
		m_fm_30 == a_c_fScalar && m_fm_31 == a_c_fScalar && m_fm_32 == a_c_fScalar && m_fm_33 == a_c_fScalar);
}

bool Matrix4x4::operator==(const Vector3 &a_c_v3Vector3)const//Overloaded is equals operation for Matrix4x4.
{
	Vector4 temp(a_c_v3Vector3);
	return bool(//Checks to see if every axis in the Matrix4x4 is equal to the argument vector and returns true if they are all equal.
		m_v4XAxis == temp &&
		m_v4YAxis == temp &&
		m_v4ZAxis == temp &&
		m_v4WAxis == temp);
}

bool Matrix4x4::operator==(const Matrix4x4 &a_c_fm4Matrix4x4)const//Overloaded is equals operation for Matrix4x4.
{
	return bool(// Checks each element in the Matrix4x4 against the passed in Matrix4x4 and if all elements are the same return true.
		m_fm_00 == a_c_fm4Matrix4x4.m_fm_00 && m_fm_01 == a_c_fm4Matrix4x4.m_fm_01 && m_fm_02 == a_c_fm4Matrix4x4.m_fm_02 && m_fm_03 == a_c_fm4Matrix4x4.m_fm_03 &&
		m_fm_10 == a_c_fm4Matrix4x4.m_fm_10 && m_fm_11 == a_c_fm4Matrix4x4.m_fm_11 && m_fm_12 == a_c_fm4Matrix4x4.m_fm_12 && m_fm_13 == a_c_fm4Matrix4x4.m_fm_13 &&
		m_fm_20 == a_c_fm4Matrix4x4.m_fm_20 && m_fm_21 == a_c_fm4Matrix4x4.m_fm_21 && m_fm_22 == a_c_fm4Matrix4x4.m_fm_22 && m_fm_23 == a_c_fm4Matrix4x4.m_fm_23 &&
		m_fm_30 == a_c_fm4Matrix4x4.m_fm_30 && m_fm_31 == a_c_fm4Matrix4x4.m_fm_31 && m_fm_32 == a_c_fm4Matrix4x4.m_fm_32 && m_fm_33 == a_c_fm4Matrix4x4.m_fm_33);
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
	Matrix4x4 temp = *this;//Creates a temporary Matrix4x4 equal to the Matrix4x4.

	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	const float co = cosf(a_fAngle);//Creates a variable equal to the cos of the angle to save on recalculation.										   

	const float si = sinf(a_fAngle);//Creates a variable equal to the sin of the angle to save on recalculation.	   									   

	temp.m_fm_00 = 1; temp.m_fm_01 =   0; temp.m_fm_02 =  0; temp.m_fm_03 =  0;//\=  1,   0,   0,   0,
		 				   				   				  
	temp.m_fm_10 = 0; temp.m_fm_11 =  co; temp.m_fm_12 = si; temp.m_fm_13 = 0;//\=  0, cos, sin,   0,
		 				   				   				  
	temp.m_fm_20 = 0; temp.m_fm_21 = -si; temp.m_fm_22 = co; temp.m_fm_23 = 0;//\=  0,-sin, cos,   0,
		 				   				   				  
	temp.m_fm_30 = 0; temp.m_fm_31 =   0; temp.m_fm_32 =  0; temp.m_fm_33 = 1;	//\=  0,   0,   0,   1
						   
	return Matrix4x4(temp);//Returns the x rotation matrix.												  
}

Matrix4x4 Matrix4x4::getYRotationMatrix(float &a_fAngle)const//Returns the Y Rotation Matrix4x4 by the angle in degrees.
{
	Matrix4x4 temp = *this;//Creates a temporary Matrix4x4 equal to the Matrix4x4.

	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	const float co = cosf(a_fAngle);//Creates a variable equal to the cos of the angle to save on recalculation.										   										

	const float si = sinf(a_fAngle);//Creates a variable equal to the sin of the angle to save on recalculation.	   									   										

	temp.m_fm_00 = co; temp.m_fm_01 = 0; temp.m_fm_02 = -si; temp.m_fm_03 = 0;//\=  cos,   0,-sin,   0,
		 					 				  				  
	temp.m_fm_10 =  0; temp.m_fm_11 = 1; temp.m_fm_12 =   0; temp.m_fm_13 = 0;//\=    0,   1,   0,   0,
		 					 				  				  
	temp.m_fm_20 = si; temp.m_fm_21 = 0; temp.m_fm_22 =  co; temp.m_fm_23 = 0;//\=  sin,   0, cos,   0,
		 					 				  				  
	temp.m_fm_30 =  0; temp.m_fm_31 = 0; temp.m_fm_32 =   0; temp.m_fm_33 = 1;//\=    0,   0,   0,   1

	return Matrix4x4(temp);//Returns the y rotation matrix.										    
}

Matrix4x4 Matrix4x4::getZRotationMatrix(float &a_fAngle)const//Returns the Z Rotation Matrix4x4 by the angle in degrees.
{
	Matrix4x4 temp = *this;//Creates a temporary Matrix4x4 equal to the Matrix4x4.

	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.

	const float co = cosf(a_fAngle);//Creates a variable equal to the cos of the angle to save on recalculation.										   										  

	const float si = sinf(a_fAngle);//Creates a variable equal to the sin of the angle to save on recalculation.	   									   										  

	temp.m_fm_00 =  co; temp.m_fm_01 = si; temp.m_fm_02 = 0; temp.m_fm_03 = 0;//\=  cos, sin,   0,   0,
		 					 					 				  
	temp.m_fm_10 = -si; temp.m_fm_11 = co; temp.m_fm_12 = 0; temp.m_fm_13 = 0;//\= -sin, cos,   0,   0,
		 					 					 				  
	temp.m_fm_20 =   0; temp.m_fm_21 =  0; temp.m_fm_22 = 1; temp.m_fm_23 = 0;//\=    0,   0,   1,   0,
		 					 					 				  
	temp.m_fm_30 =   0; temp.m_fm_31 =  0; temp.m_fm_32 = 0; temp.m_fm_33 = 1;//\=    0,   0,   0,   1

	return Matrix4x4(temp);//Returns the z rotation matrix.														  
}

//\===========================================================================================
//\ Determinant
//\===========================================================================================

float Matrix4x4::determinant()const//A function to get the determinant of a Matrix4x4.
{
	return float(//Returns the determinant of the matrix3x3 using the equation 00*(11*22-12*21)+01*(12*20-10*22)+02*(10*21-11*20)
		m_fm_00 * (m_fm_11 * m_fm_22 - m_fm_12 * m_fm_21) +
		m_fm_01 * (m_fm_12 * m_fm_20 - m_fm_10 * m_fm_22) +
		m_fm_02 * (m_fm_10 * m_fm_21 - m_fm_11 * m_fm_20));
}

//\===========================================================================================
//\ Inversion
//\===========================================================================================

bool Matrix4x4::inverse()//A function that returns the inverse of a Matrix4x4.
{
	const float fDeterminant = determinant();//Creates a float equal to the Matrix4x4 determinant.

	if (fDeterminant != 0)//If the determinant isn't zero inverse the matrix.
	{
		const float fInverseDeterminant = reciprocal(fDeterminant);//Creates a constant float equal to the inverse of the determinant.

		Matrix4x4 temp = *this;//Creates a temporary matrix that is equal to the Matrix4x4 it will inverse.

		m_fm_00 = (temp.m_fm_11 * temp.m_fm_22 - temp.m_fm_12 * temp.m_fm_21) * fInverseDeterminant;//00 = (11 * 22 - 12 * 21) * inverse determinant. 
		 				 			   			  			 
		m_fm_01 = (temp.m_fm_02 * temp.m_fm_21 - temp.m_fm_01 * temp.m_fm_22) * fInverseDeterminant;//01 = (02 * 21 -	01 * 22) * inverse determinant.
		 				 			   			  			 
		m_fm_02 = (temp.m_fm_01 * temp.m_fm_12 - temp.m_fm_02 * temp.m_fm_11) * fInverseDeterminant;//02 = (01 * 12 -	02 * 11) * inverse determinant.
		 
		m_fm_03 = 0;//03 = 0.
		 
		m_fm_10 = (temp.m_fm_12 * temp.m_fm_20 - temp.m_fm_10 * temp.m_fm_22) * fInverseDeterminant;//10 = (12 * 20 -	10 * 22) * inverse determinant.
		 				 			   			  			 
		m_fm_11 = (temp.m_fm_00 * temp.m_fm_22 - temp.m_fm_02 * temp.m_fm_20) * fInverseDeterminant;//11 = (00 * 22 -	02 * 20) * inverse determinant.
		 				 			   			  			 
		m_fm_12 = (temp.m_fm_02 * temp.m_fm_10 - temp.m_fm_00 * temp.m_fm_12) * fInverseDeterminant;//12 = (02 * 10 -	00 * 12) * inverse determinant.
		 
		m_fm_13 = 0;//13 =0.
		 
		m_fm_20 = (temp.m_fm_10 * temp.m_fm_21 - temp.m_fm_11 * temp.m_fm_20) * fInverseDeterminant;//20 = (10 * 21 -	11 * 20) * inverse determinant.
		 				 			   			  			 
		m_fm_21 = (temp.m_fm_01 * temp.m_fm_20 - temp.m_fm_00 * temp.m_fm_21) * fInverseDeterminant;//21 = (01 * 20 -	00 * 21) * inverse determinant.
		 				 			   			  			 
		m_fm_22 = (temp.m_fm_00 * temp.m_fm_11 - temp.m_fm_01 * temp.m_fm_10) * fInverseDeterminant;//22 = (00 * 11 -	01 * 10) * inverse determinant.
		 
		m_fm_23 = 0;//23 = 0.
		 
		m_fm_30 = (temp.m_fm_10 * (temp.m_fm_22 * temp.m_fm_31 - temp.m_fm_21 * temp.m_fm_32) +
		 	     temp.m_fm_11 * (temp.m_fm_20 * temp.m_fm_32 - temp.m_fm_22 * temp.m_fm_30) + 
		 	     temp.m_fm_12 * (temp.m_fm_21 * temp.m_fm_30 - temp.m_fm_20 * temp.m_fm_31)) * fInverseDeterminant;//30 = (10 * (22 * 31 - 21 * 32) + 11 * (20 * 32 - 22 * 30) + 12 * (21 * 30 - 20 *31)) * inverse determinant.
		 
		m_fm_31 = (temp.m_fm_00 * (temp.m_fm_21 * temp.m_fm_32 - temp.m_fm_22 * temp.m_fm_31) +
		 	     temp.m_fm_01 * (temp.m_fm_22 * temp.m_fm_30 - temp.m_fm_20 * temp.m_fm_32) + 
		 	     temp.m_fm_02 * (temp.m_fm_20 * temp.m_fm_31 - temp.m_fm_21 * temp.m_fm_30)) * fInverseDeterminant;//31 = (00 * (22 * 33 - 22 * 31) + 01 * (22 * 30 - 20 * 32) + 02 * (20 * 31 - 21 *30)) * inverse determinant.
		 
		m_fm_32 = (temp.m_fm_00 * (temp.m_fm_12 * temp.m_fm_31 - temp.m_fm_11 * temp.m_fm_32) +
		 	     temp.m_fm_01 * (temp.m_fm_10 * temp.m_fm_32 - temp.m_fm_12 * temp.m_fm_30) + 
		 	     temp.m_fm_02 * (temp.m_fm_11 * temp.m_fm_30 - temp.m_fm_10 * temp.m_fm_31)) * fInverseDeterminant;//32 = (00 * (12 * 31 - 11 * 32) + 01 * (10 * 32 - 12 * 30) + 02 * (11 * 30 - 10 *31)) * inverse determinant.
		 
		m_fm_33 = 1;//33 = 1.
	
		return bool(true);//Returns true if inverted.
	}
	return bool(false);//Returns false if can't be inverted.
}

//\===========================================================================================
//\ Scale
//\===========================================================================================

void Matrix4x4::scale(const float &a_c_fXScale, float &a_c_fYScale, float &a_c_fZScale)//Scales Matrix4x4          
{
	*this = *this * getScaleMatrix(a_c_fXScale, a_c_fYScale, a_c_fZScale);//Multiplies the matrix by the scale matrix.
}

Matrix4x4 Matrix4x4::getScaleMatrix(const float &a_c_fXScale, float &a_c_fYScale, float &a_c_fZScale)const//Returns the scale Matrix4x4.                     
{
	Matrix4x4 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will scale matrix.  	   
	
	temp.m_fm_00 = a_c_fXScale; temp.m_fm_01 =           0; temp.m_fm_02 =           0; temp.m_fm_03 = 0;//\= xScale,       0,      0, 0,            
		 							 							 							 	 //
	temp.m_fm_10 =           0; temp.m_fm_11 = a_c_fYScale; temp.m_fm_12 =           0; temp.m_fm_13 = 0;//\=      0,  yScale,      0, 0,            
		 							 							 							 	 //
	temp.m_fm_20 =           0; temp.m_fm_21 =           0; temp.m_fm_22 = a_c_fZScale; temp.m_fm_23 = 0;//\=      0,       0, zScale, 0,            
		 							 							 							 	 //
	temp.m_fm_30 =           0; temp.m_fm_31 =           0; temp.m_fm_32 =           0; temp.m_fm_33 = 1;//\=      0,       0,      0, 1			 
	
	return Matrix4x4(temp);//Returns the scale matrix.                                                                                  
}

//\===========================================================================================
//\ Transpose A Point
//\===========================================================================================

void Matrix4x4::transpose()//Transposes the Matrix4x4. 													 
{																										
	Matrix4x4 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will transpose.

	m_fm_01 = temp.m_fm_10; m_fm_02 = temp.m_fm_20; m_fm_03 = temp.m_fm_30;//\= 00, 10, 20, 30,											
	 				 		 				 		 		   //  
	m_fm_10 = temp.m_fm_01; m_fm_12 = temp.m_fm_21; m_fm_13 = temp.m_fm_31;//\= 01, 11, 21, 31,											
	 				 		 				 		 		   //  
	m_fm_20 = temp.m_fm_02; m_fm_21 = temp.m_fm_12; m_fm_23 = temp.m_fm_32;//\= 02, 12, 22, 32											
	 				 		 				 		 		   //  
	m_fm_30 = temp.m_fm_03; m_fm_31 = temp.m_fm_13; m_fm_32 = temp.m_fm_23;//\= 03, 13, 23, 33											
}															   											
															   									   
//\===========================================================================================
//\ Set To Identity
//\===========================================================================================

void Matrix4x4::setIdentity()//Makes the Matrix4x4 an identity matrix.
{																      
	*this = IDENTITY;//Makes the Matrix4x equal to the 4x4 identity matrix.
}																      
																
//\===================================================================
//\ Identity
//\===========================================================================================

Matrix4x4 Matrix4x4::identity()const//Returns a Matrix4x4 identity matrix.
{
	return Matrix4x4(IDENTITY);//Returns the 4x4 identity matrix.
}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Matrix4x4::setZero()//Makes each Matrix4x4 element equal to 0. 
{
	*this = ZERO;//Set each element in the Matrix4x4 to zero.
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Matrix4x4 Matrix4x4::zero()const//Returns a Matrix4x4 zero matrix.
{
	return Matrix4x4(ZERO);//Returns a 4x4 matrix of zero's.
}

//\===========================================================================================
//\ Special Points
//\===========================================================================================

const Matrix4x4 Matrix4x4::ZERO{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//A Matrix4x4 where every element is equal to zero.

const Matrix4x4 Matrix4x4::IDENTITY{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };//A Matrix4x4 where the elements are equal to the identity matrix.
