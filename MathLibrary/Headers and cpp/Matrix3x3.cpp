//\===========================================================================================
//\ File: Matrix3x3.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Matrix3x3.h.
//\===========================================================================================

#include "Matrix3x3.h"
#include <cstring>
#include <cmath>
#include "MathUtil.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Matrix3x3::Matrix3x3() {}//The Default constructor for a Matrix3x3 that initialises everything to 0.

Matrix3x3::Matrix3x3(const Matrix3x3 &a_c_mMatrix3x3)//Copy constructor.
{
	fm_00 = a_c_mMatrix3x3.getiMatrix(0);
	fm_01 = a_c_mMatrix3x3.getiMatrix(1);
	fm_02 = a_c_mMatrix3x3.getiMatrix(2);
	fm_10 = a_c_mMatrix3x3.getiMatrix(3);
	fm_11 = a_c_mMatrix3x3.getiMatrix(4);
	fm_12 = a_c_mMatrix3x3.getiMatrix(5);
	fm_20 = a_c_mMatrix3x3.getiMatrix(6);
	fm_21 = a_c_mMatrix3x3.getiMatrix(7);
	fm_22 = a_c_mMatrix3x3.getiMatrix(8);
}
Matrix3x3::Matrix3x3(const float a_c_fmMatrix[3][3])//Constructor for a Matrix3x3 that is made from two arrays of three.
{
	fmMatrix[0][0] = a_c_fmMatrix[0][0];//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	fmMatrix[0][1] = a_c_fmMatrix[0][1];//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	fmMatrix[0][2] = a_c_fmMatrix[0][2];//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	fmMatrix[1][0] = a_c_fmMatrix[1][0];//Sets the matrix's fourth element of the matrix to the same as the matrix passed in.
	fmMatrix[1][1] = a_c_fmMatrix[1][1];//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	fmMatrix[1][2] = a_c_fmMatrix[1][2];//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][0] = a_c_fmMatrix[2][0];//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	fmMatrix[2][1] = a_c_fmMatrix[2][1];//Sets the matrix's eighth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][2] = a_c_fmMatrix[2][2];//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
}

Matrix3x3::Matrix3x3(const 
	float a_c_fm_00, 
	float a_c_fm_01, 
	float a_c_fm_02,
	float a_c_fm_10,
	float a_c_fm_11,
	float a_c_fm_12,
	float a_c_fm_20,
	float a_c_fm_21,
	float a_c_fm_22)//Constructor that takes nine floats to make a Matrix3x3.
{
	fm_00 = a_c_fm_00;//Sets the matrix's first element equal to the first argument passed in.
	fm_01 = a_c_fm_01;//Sets the matrix's second element equal to the second argument passed in.
	fm_02 = a_c_fm_02;//Sets the matrix's third element equal to the third argument passed in.
	fm_10 = a_c_fm_10;//Sets the matrix's fourth element equal to the fourth argument passed in.
	fm_11 = a_c_fm_11;//Sets the matrix's fifth element equal to the fifth argument passed in.
	fm_12 = a_c_fm_12;//Sets the matrix's sixth element equal to the sixth argument passed in.
	fm_20 = a_c_fm_20;//Sets the matrix's seventh element equal to the seventh argument passed in.
	fm_21 = a_c_fm_21;//Sets the matrix's eighth element equal to the eighth argument passed in.
	fm_22 = a_c_fm_22;//Sets the matrix's ninth element equal to the ninth argument passed in.
}

Matrix3x3::Matrix3x3(const float a_c_fiMatrix[9])//Constructor that takes an array of nine floats to make a Matrix3x3.
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
}

Matrix3x3::Matrix3x3(const 
	Vector3 a_c_vXAxis,
	Vector3 a_c_vYAxis, 
	Vector3 a_c_vZAxis) ://Constructor for a Matrix3x3 made from three Vector3's.
	vXAxis(a_c_vXAxis),//Sets the vXAxis of the Matrix3x3 equal to the first Vector passed in.
	vYAxis(a_c_vYAxis),//Sets the vYAxis of the Matrix3x3 equal to the second Vector passed in.
	vZAxis(a_c_vZAxis)//Sets the vZAxis of the Matrix3x3 equal to the third Vector passed in.
{}

//\===========================================================================================
//\ Getters
//\===========================================================================================

const float* Matrix3x3::getMatrix()const//Returns a pointer to the first element in the array.
{
	return fiMatrix;
}

float Matrix3x3::getmMatrix(const int &a_c_iRow, int &a_c_iCol)const//A getter to return a float at the point specified with the two arguments.
{
	return float(fmMatrix[a_c_iRow][a_c_iCol]);//Returns a float at the row of the first argument passed in and the column of the second argument passed in.
}

float Matrix3x3::getiMatrix(const int &a_c_iPosition)const//A getter to Returns a float from the matrix at the position of the argument passed in.
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

Vector3 Matrix3x3::getColumn(const int &a_c_iCol)const//A getter to return the column specified by the argument a_c_iCol.
{
	return Vector3(fmMatrix[0][a_c_iCol], fmMatrix[1][a_c_iCol], fmMatrix[2][a_c_iCol]);//Returns the column as a Vector3.
}

Vector3 Matrix3x3::getRow(const int &a_c_iRow)const//A getter to return the row specified by the argument a_c_iRow.
{
	return Vector3(fmMatrix[a_c_iRow][0], fmMatrix[a_c_iRow][1], fmMatrix[a_c_iRow][2]);//Returns the row as a Vecotor3
}

//\===========================================================================================
//\ Setters
//\===========================================================================================

void Matrix3x3::setmMatrix(const int &a_c_iRow, int &a_c_iCol, float &a_c_fNewNumber)//A setter to change the float in the matrix at the point specified with the two arguments.
{
	fmMatrix[a_c_iRow][a_c_iCol] = a_c_fNewNumber;//Sets the float specified by the first and second argument to the third argument.
}

void Matrix3x3::setiMatrix(const int &a_c_iPosition, float &a_c_fNewNumber)//A setter to change the float in the matrix at the position of the argument passed in.
{
	fiMatrix[a_c_iPosition] = a_c_fNewNumber;//Sets the float at the position of the first argument to the float of the second argument.
}

void Matrix3x3::setXAxis(const Vector3 &a_c_vVector3)//A setter to change the vXAxis of matrix3x3 to the Vector3 argument.
{
	vXAxis = a_c_vVector3;//Sets the vXAxis Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setYAxis(const Vector3 &a_c_vVector3)//A setter to change the vYAxis of matrix3x3 to the Vector3 argument.
{
	vYAxis = a_c_vVector3;//Sets the vYAxis Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setZAxis(const Vector3 &a_c_vVector3)//A setter to change the vZAxis of matrix3x3 to the Vector3 argument.
{
	vZAxis = a_c_vVector3;//Sets the vZAxis Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setTranslation(const Vector3 &a_c_vVector3)//A setter to change the vTranslation of matrix3x3 to the vTranslation argument.
{
	vTranslation = a_c_vVector3;//Sets the vTranslation Vector3 of the Matrix3x3 equal to the Vector3 passed in.
}

void Matrix3x3::setColumn(const int &a_c_iCol, Vector3 &a_c_vVector3)//A setter for the column specified by the argument a_c_iCol.
{
	fmMatrix[0][a_c_iCol] = a_c_vVector3.getfX();
	fmMatrix[1][a_c_iCol] = a_c_vVector3.getfY();
    fmMatrix[2][a_c_iCol] = a_c_vVector3.getfZ();//Sets the column specified by the a_c_iCol equal to the argument vector3.
}

void Matrix3x3::setRow(const int &a_c_iRow, Vector3 &a_c_vVector3)//A setter for the row specified by the argument a_c_iRow.
{
	fmMatrix[a_c_iRow][0] = a_c_vVector3.getfX();
	fmMatrix[a_c_iRow][1] = a_c_vVector3.getfY();
	fmMatrix[a_c_iRow][2] = a_c_vVector3.getfZ();//Sets the row specified by the a_c_iRow equal to the argument vector3.
}

//\===========================================================================================
//\ Arithmetic Operation Overloads
//\===========================================================================================

Matrix3x3 Matrix3x3::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Matrix3x3.
{
	Matrix3x3 tempAdditionMatrix;//Creates a temporary matrix that will hold the added matrix.
	tempAdditionMatrix.fm_00 = fm_00 + a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_01 = fm_01 + a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_02 = fm_02 + a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_10 = fm_10 + a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_11 = fm_11 + a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_12 = fm_12 + a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_20 = fm_20 + a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_21 = fm_21 + a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix increase by the float passed in.
	tempAdditionMatrix.fm_22 = fm_22 + a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix increase by the float passed in.
	return Matrix3x3(tempAdditionMatrix);//Returns the increased matrix.
}

Matrix3x3 Matrix3x3::operator+(const Vector3 &a_c_vVector3)const//Overloaded addition operation for Matrix3x3.
{
	vXAxis + a_c_vVector3;//Increases the vXAxis by the argument Vector3.
	vYAxis + a_c_vVector3;//Increases the vYAxis by the argument Vector3.
	vZAxis + a_c_vVector3;//Increases the vZAxis by the argument Vector3.
	return Matrix3x3(*this);//Returns the increased matrix.
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded addition operation for Matrix3x3.
{
	Matrix3x3 tempAdditionMatrix;//Creates a temporary matrix that will hold the added matrix.
	tempAdditionMatrix.fm_00 = fm_00 + a_c_mMatrix3x3.fm_00;//Makes temporary matrix equal to the first element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_01 = fm_01 + a_c_mMatrix3x3.fm_01;//Makes temporary matrix equal to the second element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_02 = fm_02 + a_c_mMatrix3x3.fm_02;//Makes temporary matrix equal to the third element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_10 = fm_10 + a_c_mMatrix3x3.fm_10;//Makes temporary matrix equal to the fourth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_11 = fm_11 + a_c_mMatrix3x3.fm_11;//Makes temporary matrix equal to the fifth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_12 = fm_12 + a_c_mMatrix3x3.fm_12;//Makes temporary matrix equal to the sixth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_20 = fm_20 + a_c_mMatrix3x3.fm_20;//Makes temporary matrix equal to the seventh element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_21 = fm_21 + a_c_mMatrix3x3.fm_21;//Makes temporary matrix equal to the eighth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	tempAdditionMatrix.fm_22 = fm_22 + a_c_mMatrix3x3.fm_22;//Makes temporary matrix equal to the ninth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	return Matrix3x3(tempAdditionMatrix);//Returns the increased matrix.
}

Matrix3x3 Matrix3x3::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Matrix3x3.
{
	Matrix3x3 tempSubtractionMatrix;//Creates a temporary matrix that will hold the subtracted matrix.
	tempSubtractionMatrix.fm_00 = fm_00 - a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_01 = fm_01 - a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_02 = fm_02 - a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_10 = fm_10 - a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_11 = fm_11 - a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_12 = fm_12 - a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_20 = fm_20 - a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_21 = fm_21 - a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix decreased by the float passed in.
	tempSubtractionMatrix.fm_22 = fm_22 - a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix decreased by the float passed in.
	return Matrix3x3(tempSubtractionMatrix);//Returns the decreased matrix.
}

Matrix3x3 Matrix3x3::operator-(const Vector3 &a_c_vVector3)const//Overloaded subtraction operation for Matrix3x3.
{
	vXAxis - a_c_vVector3;//decreases the vXAxis by the argument Vector3.
	vYAxis - a_c_vVector3;//decreases the vYAxis by the argument Vector3.
	vZAxis - a_c_vVector3;//decreases the vZAxis by the argument Vector3.
	return Matrix3x3(*this);//Returns the decreased matrix.
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded subtraction operation for Matrix3x3.
{
	Matrix3x3 tempSubtractionMatrix;//Creates a temporary matrix that will hold the subtracted matrix.
	tempSubtractionMatrix.fm_00 = fm_00 - a_c_mMatrix3x3.fm_00;//Makes temporary matrix equal to the first element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_01 = fm_01 - a_c_mMatrix3x3.fm_01;//Makes temporary matrix equal to the second element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_02 = fm_02 - a_c_mMatrix3x3.fm_02;//Makes temporary matrix equal to the third element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_10 = fm_10 - a_c_mMatrix3x3.fm_10;//Makes temporary matrix equal to the fourth element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_11 = fm_11 - a_c_mMatrix3x3.fm_11;//Makes temporary matrix equal to the fifth element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_12 = fm_12 - a_c_mMatrix3x3.fm_12;//Makes temporary matrix equal to the sixth element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_20 = fm_20 - a_c_mMatrix3x3.fm_20;//Makes temporary matrix equal to the seventh element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_21 = fm_21 - a_c_mMatrix3x3.fm_21;//Makes temporary matrix equal to the eighth element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	tempSubtractionMatrix.fm_22 = fm_22 - a_c_mMatrix3x3.fm_22;//Makes temporary matrix equal to the ninth element of the matrix decreased by the equivalent part of the matrix3x3 passed in.
	return Matrix3x3(tempSubtractionMatrix);//Returns the decreased matrix.	
}

Matrix3x3 Matrix3x3::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Matrix3x3.
{
	Matrix3x3 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied vector.
	tempMultiplicationMatrix.fm_00 = fm_00 * a_c_fScalar;//Makes temporary matrix equal to the first element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_01 = fm_01 * a_c_fScalar;//Makes temporary matrix equal to the second element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_02 = fm_02 * a_c_fScalar;//Makes temporary matrix equal to the third element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_10 = fm_10 * a_c_fScalar;//Makes temporary matrix equal to the fourth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_11 = fm_11 * a_c_fScalar;//Makes temporary matrix equal to the fifth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_12 = fm_12 * a_c_fScalar;//Makes temporary matrix equal to the sixth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_20 = fm_20 * a_c_fScalar;//Makes temporary matrix equal to the seventh element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_21 = fm_21 * a_c_fScalar;//Makes temporary matrix equal to the eighth element of the matrix multiplied by the float passed in.
	tempMultiplicationMatrix.fm_22 = fm_22 * a_c_fScalar;//Makes temporary matrix equal to the ninth element of the matrix multiplied by the float passed in.
	return Matrix3x3(tempMultiplicationMatrix);//Returns the multiplied matrix.
}

Vector3 Matrix3x3::operator*(const Vector3 &a_c_vVector3)const//Overloaded multiplication operation for Matrix3x3.
{
	return Vector3(//Returns the multiplied matrix.
		fm_00 * a_c_vVector3.getfX() + fm_01 * a_c_vVector3.getfY() + fm_02 * a_c_vVector3.getfZ(),//Dot product for the first row of the first matrix and the only column of the Vector3.
		fm_10 * a_c_vVector3.getfX() + fm_11 * a_c_vVector3.getfY() + fm_12 * a_c_vVector3.getfZ(),//Dot product for the second row of the first matrix and the only column of the Vector3.
		fm_20 * a_c_vVector3.getfX() + fm_21 * a_c_vVector3.getfY() + fm_22 * a_c_vVector3.getfZ());//Dot product for the third row of the first matrix and the only column of the Vector3.
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded multiplication operation for Matrix3x3.
{
	Matrix3x3 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied vector.
	tempMultiplicationMatrix.fm_00 = fm_00 * a_c_mMatrix3x3.fm_00 + fm_01 * a_c_mMatrix3x3.fm_10 + fm_02 * a_c_mMatrix3x3.fm_20;//Dot product for the first row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_01 = fm_00 * a_c_mMatrix3x3.fm_01 + fm_01 * a_c_mMatrix3x3.fm_11 + fm_02 * a_c_mMatrix3x3.fm_21;//Dot product for the first row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_02 = fm_00 * a_c_mMatrix3x3.fm_02 + fm_01 * a_c_mMatrix3x3.fm_12 + fm_02 * a_c_mMatrix3x3.fm_22;//Dot product for the first row of the first matrix and the third column of the second matrix.																																		  
	tempMultiplicationMatrix.fm_10 = fm_10 * a_c_mMatrix3x3.fm_00 + fm_11 * a_c_mMatrix3x3.fm_10 + fm_12 * a_c_mMatrix3x3.fm_20;//Dot product for the second row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_11 = fm_10 * a_c_mMatrix3x3.fm_01 + fm_11 * a_c_mMatrix3x3.fm_11 + fm_12 * a_c_mMatrix3x3.fm_21;//Dot product for the second row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_12 = fm_10 * a_c_mMatrix3x3.fm_02 + fm_11 * a_c_mMatrix3x3.fm_12 + fm_12 * a_c_mMatrix3x3.fm_22;//Dot product for the second row of the first matrix and the third column of the second matrix.																						  
	tempMultiplicationMatrix.fm_20 = fm_20 * a_c_mMatrix3x3.fm_00 + fm_21 * a_c_mMatrix3x3.fm_10 + fm_22 * a_c_mMatrix3x3.fm_20;//Dot product for the third row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_21 = fm_20 * a_c_mMatrix3x3.fm_01 + fm_21 * a_c_mMatrix3x3.fm_11 + fm_22 * a_c_mMatrix3x3.fm_21;//Dot product for the third row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_22 = fm_20 * a_c_mMatrix3x3.fm_02 + fm_21 * a_c_mMatrix3x3.fm_12 + fm_22 * a_c_mMatrix3x3.fm_22;//Dot product for the third row of the first matrix and the third column of the second matrix.
	return Matrix3x3(tempMultiplicationMatrix);//Returns the multiplied matrix.
}

Matrix3x3 Matrix3x3::operator/(const float &a_c_fScalar)const//Overloaded division operation for Matrix3x3.
{
	return Matrix3x3(*this * reciprocal(a_c_fScalar));//Returns the Matrix3x3 / the argument.
}

Vector3 Matrix3x3::operator/(const Vector3 &a_c_vVector3)const//Overloaded division operation for Matrix3x3.
{
	return Vector3(*this * a_c_vVector3.inverse());//Returns the Matrix3x3 / the argument.
}

Matrix3x3 Matrix3x3::operator/(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded division operation for Matrix3x3.
{
	Matrix3x3 tempMatrix = a_c_mMatrix3x3;
	tempMatrix.inverse();
	return Matrix3x3(*this * tempMatrix);//Returns the Matrix3x3 / the argument.
}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Matrix3x3 Matrix3x3::operator+=(const float &a_c_fScalar)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this + a_c_fScalar);//Returns the added equated matrix.
}

Matrix3x3 Matrix3x3::operator+=(const Vector3 &a_c_vVector3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this + a_c_vVector3);//Returns the added equated matrix.
}

Matrix3x3 Matrix3x3::operator+=(const Matrix3x3 &a_c_mMatrix3x3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this + a_c_mMatrix3x3);//Returns the added equated matrix.
}

Matrix3x3 Matrix3x3::operator-=(const float &a_c_fScalar)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this - a_c_fScalar);//Returns the subtracted equated matrix.
}

Matrix3x3 Matrix3x3::operator-=(const Vector3 &a_c_vVector3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this - a_c_vVector3);//Returns the subtracted equated matrix.
}

Matrix3x3 Matrix3x3::operator-=(const Matrix3x3 &a_c_mMatrix3x3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this - a_c_mMatrix3x3);//Returns the subtracted equated matrix.
}

Matrix3x3 Matrix3x3::operator=(const float &a_c_fScalar)//Overloaded equals operation for Matrix3x3.
{
	fm_00 = a_c_fScalar;//Makes the first element of the matrix equal to the scalar passed in.
	fm_01 = a_c_fScalar;//Makes the second element of the matrix equal to the scalar passed in.
	fm_02 = a_c_fScalar;//Makes the third element of the matrix equal to the scalar passed in.
	fm_10 = a_c_fScalar;//Makes the fourth element of the matrix equal to the scalar passed in.
	fm_11 = a_c_fScalar;//Makes the fifth element of the matrix equal to the scalar passed in.
	fm_12 = a_c_fScalar;//Makes the sixth element of the matrix equal to the scalar passed in.
	fm_20 = a_c_fScalar;//Makes the seventh element of the matrix equal to the scalar passed in.
	fm_21 = a_c_fScalar;//Makes the eighth element of the matrix equal to the scalar passed in.
	fm_22 = a_c_fScalar;//Makes the ninth element of the matrix equal to the scalar passed in.
	return Matrix3x3(*this);//Returns the equated matrix.
}

Matrix3x3 Matrix3x3::operator=(const Vector3 &a_c_vVector3)//Overloaded equals operation for Matrix3x3.
{
	vXAxis = a_c_vVector3;//Equates the vXAxis to the argument Vector3.
	vYAxis = a_c_vVector3;//Equates the vYAxis to the argument Vector3.
	vZAxis = a_c_vVector3;//Equates the vZAxis to the argument Vector3.
	return Matrix3x3(*this);//Returns the equated matrix.
}

Matrix3x3 Matrix3x3::operator=(const Matrix3x3 &a_c_mMatrix3x3)//Overloaded equals operation for Matrix3x3.
{
	fm_00 = a_c_mMatrix3x3.fm_00;//Makes the first element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_01 = a_c_mMatrix3x3.fm_01;//Makes the second element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_02 = a_c_mMatrix3x3.fm_02;//Makes the third element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_10 = a_c_mMatrix3x3.fm_10;//Makes the fourth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_11 = a_c_mMatrix3x3.fm_11;//Makes the fifth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_12 = a_c_mMatrix3x3.fm_12;//Makes the sixth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_20 = a_c_mMatrix3x3.fm_20;//Makes the seventh element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_21 = a_c_mMatrix3x3.fm_21;//Makes the eighth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fm_22 = a_c_mMatrix3x3.fm_22;//Makes the ninth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	return Matrix3x3(*this);//Returns the equated matrix.
}

Matrix3x3 Matrix3x3::operator*=(const float &a_c_fScalar)//Overloaded times equals operation for Matrix3x3.
{
    return Matrix3x3(*this = *this * a_c_fScalar);//Returns the multiplied equated matrix.
}

Matrix3x3 Matrix3x3::operator*=(const Vector3 &a_c_vVector3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this * a_c_vVector3);//Returns the multiplied equated matrix.
}

Matrix3x3 Matrix3x3::operator*=(const Matrix3x3 &a_c_mMatrix3x3)//Overloaded times equals operation for Matrix3x3.
{
    return Matrix3x3(*this = *this * a_c_mMatrix3x3);//Returns the multiplied equated matrix.
}

Matrix3x3 Matrix3x3::operator/=(const float &a_c_fScalar)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this / a_c_fScalar);//Returns the divided equated matrix.
}

Matrix3x3 Matrix3x3::operator/=(const Vector3 &a_c_vVector3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this / a_c_vVector3);//Returns the divided equated matrix.
}

Matrix3x3 Matrix3x3::operator/=(const Matrix3x3 &a_c_mMatrix3x3)//Overloaded times equals operation for Matrix3x3.
{
	return Matrix3x3(*this = *this / a_c_mMatrix3x3);//Returns the divided equated matrix.
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Matrix3x3::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Matrix3x3.
{
	return bool(//Checks to see if each element in the Matrix3x3 is not equal to the scalar argument passed in and returns true if one is not.
		fm_00 != a_c_fScalar || fm_01 != a_c_fScalar || fm_02 != a_c_fScalar ||
		fm_10 != a_c_fScalar || fm_11 != a_c_fScalar || fm_12 != a_c_fScalar ||
		fm_20 != a_c_fScalar || fm_21 != a_c_fScalar || fm_22 != a_c_fScalar);
}

bool Matrix3x3::operator!=(const Vector3 &a_c_vVector3)const//Overloaded not equals operation for Matrix3x3.
{
	return bool(//Checks to see if each axis in the Matrix3x3 is not equal to the Vector3 argument passed in and returns true if one is not.
		vXAxis != a_c_vVector3 ||
		vYAxis != a_c_vVector3 ||
		vZAxis != a_c_vVector3);
}

bool Matrix3x3::operator!=(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded not equals operation for Matrix3x3.
{
	return bool(//Checks each element in the Matrix3x3 against the passed in Matrix3x3 and if one element is not the same as the passed in matrix then return true.
		fm_00 != a_c_mMatrix3x3.fm_00 || fm_01 != a_c_mMatrix3x3.fm_01 || fm_02 != a_c_mMatrix3x3.fm_02 ||
		fm_10 != a_c_mMatrix3x3.fm_10 || fm_11 != a_c_mMatrix3x3.fm_11 || fm_12 != a_c_mMatrix3x3.fm_12 ||
		fm_20 != a_c_mMatrix3x3.fm_20 || fm_21 != a_c_mMatrix3x3.fm_21 || fm_22 != a_c_mMatrix3x3.fm_22);
}

bool Matrix3x3::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Matrix3x3.
{
	return bool(//Checks to see if each element in the Matrix3x3 is equal to the scalar argument passed in and returns true if every element is.
		fm_00 == a_c_fScalar && fm_01 == a_c_fScalar && fm_02 == a_c_fScalar &&
		fm_10 == a_c_fScalar && fm_11 == a_c_fScalar && fm_12 == a_c_fScalar &&
		fm_20 == a_c_fScalar && fm_21 == a_c_fScalar && fm_22 == a_c_fScalar);
}

bool Matrix3x3::operator==(const Vector3 &a_c_vVector3)const//Overloaded is equals operation for Matrix3x3.
{
	return bool(//Checks to see if every axis in the Matrix3x3 is equal to the argument vector and returns true if they are all equal.
		vXAxis == a_c_vVector3 &&
		vYAxis == a_c_vVector3 &&
		vZAxis == a_c_vVector3);
}

bool Matrix3x3::operator==(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded is equals operation for Matrix3x3.
{
	return bool(// Checks each element in the Matrix3x3 against the passed in Matrix3x3 and if all elements are the same return true.
		fm_00 == a_c_mMatrix3x3.fm_00 && fm_01 == a_c_mMatrix3x3.fm_01 && fm_02 == a_c_mMatrix3x3.fm_02 &&
		fm_10 == a_c_mMatrix3x3.fm_10 && fm_11 == a_c_mMatrix3x3.fm_11 && fm_12 == a_c_mMatrix3x3.fm_12 &&
		fm_20 == a_c_mMatrix3x3.fm_20 && fm_21 == a_c_mMatrix3x3.fm_21 && fm_22 == a_c_mMatrix3x3.fm_22);
}

//\===========================================================================================
//\ Rotate Around Euler Axis
//\===========================================================================================

void Matrix3x3::rotate(float &a_fAngle)//Rotates the Matrix3x3 by the angle in degrees around the z axis. 
{
	*this = *this * getRotationMatrix(a_fAngle);//Multiplies the matrix by the rotations matrix.
}

Matrix3x3 Matrix3x3::getRotationMatrix(float &a_fAngle)const//Returns the Rotation Matrix3x3 by the angle in degrees. 
{
	Matrix3x3 temp = *this;
	a_fAngle = degreesToRadians(a_fAngle);//Converts the float to radians.//\===================================
	const float co = cosf(a_fAngle);									  //\= Multiplies the Matrix3x3 by the rotation matrix which is:
	const float si = sinf(a_fAngle);									  //\= cos(θ), -sin(θ), 0,
	temp.fm_00 = co; temp.fm_01 = -si; temp.fm_02 = 0;  				  //\= sin(θ),  cos(θ), 0,
	temp.fm_10 = si; temp.fm_11 =  co; temp.fm_12 = 0;  				  //\=      0,       0, 1, 
	temp.fm_20 =  0; temp.fm_21 =   0; temp.fm_22 = 1;                    //\===================================
	return (temp);                                                       
}											
											
//\===========================================================================================
//\ Determinant
//\===========================================================================================

float Matrix3x3::determinant()const//A function to get the determinant of a Matrix3x3.
{
	return float(//Returns the determinant of the matrix3x3 using the equation 00*(11*22-12*21)+01*(12*20-10*22)+02*(10*21-11*20)
		fm_00 * (fm_11 * fm_22 - fm_12 * fm_21) +
		fm_01 * (fm_12 * fm_20 - fm_10 * fm_22) +
		fm_02 * (fm_10 * fm_21 - fm_11 * fm_20));
}

//\===========================================================================================
//\ Inversion
//\===========================================================================================

bool Matrix3x3::inverse()//A function that make a Matrix3x3 turn to its inverse.
{
	float fDeterminant = determinant();//Creates a float equal to the Matrix3x3 determinant.
	if (fDeterminant != 0.0f)//If the determinant isn't zero inverse it
	{
		const float fInverseDeterminant = reciprocal(fDeterminant);//Creates a constant float equal to the inverse of the determinant.
		Matrix3x3 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will inverse.
		fm_00 = (temp.fm_11 * temp.fm_22 - temp.fm_12 * temp.fm_21) * fInverseDeterminant;//00 = (11 * 22 - 12 * 21) * inverse determinant
		fm_01 = (temp.fm_02 * temp.fm_21 - temp.fm_01 * temp.fm_22) * fInverseDeterminant;//01 = (02 * 21 -	01 * 22) * inverse determinant
		fm_02 = (temp.fm_01 * temp.fm_12 - temp.fm_02 * temp.fm_11) * fInverseDeterminant;//02 = (01 * 12 -	02 * 11) * inverse determinant
		fm_10 = (temp.fm_12 * temp.fm_20 - temp.fm_10 * temp.fm_22) * fInverseDeterminant;//10 = (12 * 20 -	10 * 22) * inverse determinant
		fm_11 = (temp.fm_00 * temp.fm_22 - temp.fm_02 * temp.fm_20) * fInverseDeterminant;//11 = (00 * 22 -	02 * 20) * inverse determinant
		fm_12 = (temp.fm_02 * temp.fm_10 - temp.fm_00 * temp.fm_12) * fInverseDeterminant;//12 = (02 * 10 -	00 * 12) * inverse determinant
		fm_20 = (temp.fm_10 * temp.fm_21 - temp.fm_11 * temp.fm_20) * fInverseDeterminant;//20 = (10 * 21 -	11 * 20) * inverse determinant
		fm_21 = (temp.fm_01 * temp.fm_20 - temp.fm_00 * temp.fm_21) * fInverseDeterminant;//21 = (01 * 20 -	00 * 21) * inverse determinant
		fm_22 = (temp.fm_00 * temp.fm_11 - temp.fm_01 * temp.fm_10) * fInverseDeterminant;//22 = (00 * 11 -	01 * 10) * inverse determinant
		return bool(true);//Returns true if the matrix is inverted.																			  
	}
	return bool(false);//If the determinant is zero return false.
}

//\===========================================================================================
//\ Scale
//\===========================================================================================

void Matrix3x3::scale(const float &a_c_fXScale, float &a_c_fYScale)//Returns the scale Matrix3x3                     
{
	*this = *this * getScaleMatrix(a_c_fXScale, a_c_fYScale);//Multiplies the matrix by the scale matrix.
}

Matrix3x3 Matrix3x3::getScaleMatrix(const float &a_c_fXScale, float &a_c_fYScale)const//Returns the scale Matrix3x3. 
{
	Matrix3x3 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will scale matrix.	//\===================================
	temp.fm_00 = a_c_fXScale; temp.fm_01 = 0;           temp.fm_02 = 0;            							//\= xScale,       0,      0,
	temp.fm_10 = 0;   	      temp.fm_11 = a_c_fYScale; temp.fm_12 = 0;            							//\=      0,  yScale,      0,
	temp.fm_20 = 0;           temp.fm_21 = 0;           temp.fm_22 = 1;  							        //\=      0,       0,      1
	return Matrix3x3(temp);																					//\===================================
}																	   																	 
																	   
//\===========================================================================================
//\ Transpose A Point
//\===========================================================================================

void Matrix3x3::transpose()//Transposes the Matrix3x3. 
{
	Matrix3x3 temp = *this;//Creates a temporary matrix that is equal to the Matrx3x3 it will transpose.
	fm_01 = temp.fm_10;										       //\===================================
	fm_02 = temp.fm_20;										       //\= Makes the Matrix3x3 equal to the transpose matrix which is:
	fm_10 = temp.fm_01;										       //\= 00, 10, 20,
	fm_12 = temp.fm_21;										       //\= 01, 11, 21,
	fm_20 = temp.fm_02;										       //\= 02, 12, 22
	fm_21 = temp.fm_12;										       //\===================================
}

//\===========================================================================================
//\ Set To Identity
//\===========================================================================================

void Matrix3x3::setIdentity()//Makes the Matrix3x3 an identity matrix.
{									  							      
	*this = IDENTITY;
}									  							      
	
//\===========================================================================================
//\ Identity
//\===========================================================================================

Matrix3x3 Matrix3x3::identity()const//Returns a Matrix3x3 identity matrix.
{
	return Matrix3x3(IDENTITY);
}

//\===========================================================================================
//\ Set To Zero
//\===========================================================================================

void Matrix3x3::setZero()//Makes each Matrix3x3 element equal to 0. 
{//Set each element in the matrix3x3 to zero.
	*this = ZERO;
}

//\===========================================================================================
//\ Zero
//\===========================================================================================

Matrix3x3 Matrix3x3::zero()const//Returns a Matrix3x3 zero matrix.
{
	Matrix3x3 temp;
	temp.setZero();
	return Matrix3x3(temp);
}

//\===========================================================================================
//\ Special Points
//\===========================================================================================

const Matrix3x3 Matrix3x3::ZERO{ 0,0,0,0,0,0,0,0,0 };
const Matrix3x3 Matrix3x3::IDENTITY{ 1,0,0,0,1,0,0,0,1 };