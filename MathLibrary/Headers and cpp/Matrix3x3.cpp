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
	fmMatrix[0][0] = a_c_fmMatrix[0][0];//Sets the matrix's first element of the matrix to the same as the matrix passed in.
	fmMatrix[1][0] = a_c_fmMatrix[1][0];//Sets the matrix's second element of the matrix to the same as the matrix passed in.
	fmMatrix[2][0] = a_c_fmMatrix[2][0];//Sets the matrix's third element of the matrix to the same as the matrix passed in.
	fmMatrix[0][1] = a_c_fmMatrix[0][1];//Sets the matrix's fourth element of the matrix to the same as the matrix passed in.
	fmMatrix[1][1] = a_c_fmMatrix[1][1];//Sets the matrix's fifth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][1] = a_c_fmMatrix[2][1];//Sets the matrix's sixth element of the matrix to the same as the matrix passed in.
	fmMatrix[0][2] = a_c_fmMatrix[0][2];//Sets the matrix's seventh element of the matrix to the same as the matrix passed in.
	fmMatrix[1][2] = a_c_fmMatrix[1][2];//Sets the matrix's eighth element of the matrix to the same as the matrix passed in.
	fmMatrix[2][2] = a_c_fmMatrix[2][2];//Sets the matrix's ninth element of the matrix to the same as the matrix passed in.
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
//\ Arithmetic Operation Overloads
//\===========================================================================================

Matrix3x3 Matrix3x3::operator+(const float &a_c_fScalar)const//Overloaded addition operation for Matrix3x3.
{
	fiMatrix[0] + a_c_fScalar;//Makes the first element of the matrix increase by the float passed in.
	fiMatrix[1] + a_c_fScalar;//Makes the second element of the matrix increase by the float passed in.
	fiMatrix[2] + a_c_fScalar;//Makes the third element of the matrix increase by the float passed in.
	fiMatrix[3] + a_c_fScalar;//Makes the fourth element of the matrix increase by the float passed in.
	fiMatrix[4] + a_c_fScalar;//Makes the fifth element of the matrix increase by the float passed in.
	fiMatrix[5] + a_c_fScalar;//Makes the sixth element of the matrix increase by the float passed in.
	fiMatrix[6] + a_c_fScalar;//Makes the seventh element of the matrix increase by the float passed in.
	fiMatrix[7] + a_c_fScalar;//Makes the eighth element of the matrix increase by the float passed in.
	fiMatrix[8] + a_c_fScalar;//Makes the ninth element of the matrix increase by the float passed in.
	return Matrix3x3(fmMatrix);//Returns the increased matrix.
}

Matrix3x3 Matrix3x3::operator+(const Vector3 &a_c_vVector3)const//Overloaded addition operation for Matrix3x3.
{
	vXAxis + a_c_vVector3;//Increases the vXAxis by the argument Vector3.
	vYAxis + a_c_vVector3;//Increases the vYAxis by the argument Vector3.
	vZAxis + a_c_vVector3;//Increases the vZAxis by the argument Vector3.
	return Matrix3x3(fmMatrix);//Returns the increased matrix.
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded addition operation for Matrix3x3.
{
	fiMatrix[0] + a_c_mMatrix3x3.fiMatrix[0];//Makes the first element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[1] + a_c_mMatrix3x3.fiMatrix[1];//Makes the second element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[2] + a_c_mMatrix3x3.fiMatrix[2];//Makes the third element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[3] + a_c_mMatrix3x3.fiMatrix[3];//Makes the fourth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[4] + a_c_mMatrix3x3.fiMatrix[4];//Makes the fifth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[5] + a_c_mMatrix3x3.fiMatrix[5];//Makes the sixth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[6] + a_c_mMatrix3x3.fiMatrix[6];//Makes the seventh element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[7] + a_c_mMatrix3x3.fiMatrix[7];//Makes the eighth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	fiMatrix[8] + a_c_mMatrix3x3.fiMatrix[8];//Makes the ninth element of the matrix increase by the equivalent part of the matrix3x3 passed in.
	return Matrix3x3(fmMatrix);//Returns the increased matrix.
}

Matrix3x3 Matrix3x3::operator-(const float &a_c_fScalar)const//Overloaded subtraction operation for Matrix3x3.
{
	fiMatrix[0] - a_c_fScalar;//Makes the first element of the matrix decrease by the float passed in.
	fiMatrix[1] - a_c_fScalar;//Makes the second element of the matrix decrease by the float passed in.
	fiMatrix[2] - a_c_fScalar;//Makes the third element of the matrix decrease by the float passed in.
	fiMatrix[3] - a_c_fScalar;//Makes the fourth element of the matrix decrease by the float passed in.
	fiMatrix[4] - a_c_fScalar;//Makes the fifth element of the matrix decrease by the float passed in.
	fiMatrix[5] - a_c_fScalar;//Makes the sixth element of the matrix decrease by the float passed in.
	fiMatrix[6] - a_c_fScalar;//Makes the seventh element of the matrix decrease by the float passed in.
	fiMatrix[7] - a_c_fScalar;//Makes the eighth element of the matrix decrease by the float passed in.
	fiMatrix[8] - a_c_fScalar;//Makes the ninth element of the matrix decrease by the float passed in.
	return Matrix3x3(fmMatrix);//Returns the decreased matrix.
}

Matrix3x3 Matrix3x3::operator-(const Vector3 &a_c_vVector3)const//Overloaded subtraction operation for Matrix3x3.
{
	vXAxis - a_c_vVector3;//Decreases the vXAxis by the argument Vector3.
	vYAxis - a_c_vVector3;//Decreases the vYAxis by the argument Vector3.
	vZAxis - a_c_vVector3;//Decreases the vZAxis by the argument Vector3.
	return Matrix3x3(fmMatrix);//Returns the decreased matrix.
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded subtraction operation for Matrix3x3.
{
	fiMatrix[0] - a_c_mMatrix3x3.fiMatrix[0];//Makes the first element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[1] - a_c_mMatrix3x3.fiMatrix[1];//Makes the second element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[2] - a_c_mMatrix3x3.fiMatrix[2];//Makes the third element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[3] - a_c_mMatrix3x3.fiMatrix[3];//Makes the fourth element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[4] - a_c_mMatrix3x3.fiMatrix[4];//Makes the fifth element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[5] - a_c_mMatrix3x3.fiMatrix[5];//Makes the sixth element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[6] - a_c_mMatrix3x3.fiMatrix[6];//Makes the seventh element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[7] - a_c_mMatrix3x3.fiMatrix[7];//Makes the eighth element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	fiMatrix[8] - a_c_mMatrix3x3.fiMatrix[8];//Makes the ninth element of the matrix decrease by the equivalent part of the matrix3x3 passed in.
	return Matrix3x3(fmMatrix);//Returns the decreased matrix.	
}

Matrix3x3 Matrix3x3::operator*(const float &a_c_fScalar)const//Overloaded multiplication operation for Matrix3x3.
{
	fiMatrix[0] * a_c_fScalar;//Makes the first element of the matrix multiplied by the float passed in.
	fiMatrix[1] * a_c_fScalar;//Makes the second element of the matrix multiplied by the float passed in.
	fiMatrix[2] * a_c_fScalar;//Makes the third element of the matrix multiplied by the float passed in.
	fiMatrix[3] * a_c_fScalar;//Makes the fourth element of the matrix multiplied by the float passed in.
	fiMatrix[4] * a_c_fScalar;//Makes the fifth element of the matrix multiplied by the float passed in.
	fiMatrix[5] * a_c_fScalar;//Makes the sixth element of the matrix multiplied by the float passed in.
	fiMatrix[6] * a_c_fScalar;//Makes the seventh element of the matrix multiplied by the float passed in.
	fiMatrix[7] * a_c_fScalar;//Makes the eighth element of the matrix multiplied by the float passed in.
	fiMatrix[8] * a_c_fScalar;//Makes the ninth element of the matrix multiplied by the float passed in.
	return Matrix3x3(fmMatrix);//Returns the multiplied matrix.
}

Vector3 Matrix3x3::operator*(const Vector3 &a_c_vVector3)const//Overloaded multiplication operation for Matrix3x3.
{
	Vector3 tempMultiplicationVector(0,0,0);//Creates a temporary matrix that will hold the multiplied vector.
	tempMultiplicationVector.setfX(fm_00 * a_c_vVector3.getfX + fm_01 * a_c_vVector3.getfY + fm_02 * a_c_vVector3.getfZ);//Dot product for the first row of the first matrix and the only column of the Vector3.
	tempMultiplicationVector.setfY(fm_10 * a_c_vVector3.getfX + fm_11 * a_c_vVector3.getfY + fm_12 * a_c_vVector3.getfZ);//Dot product for the second row of the first matrix and the only column of the Vector3.
	tempMultiplicationVector.setfZ(fm_20 * a_c_vVector3.getfX + fm_21 * a_c_vVector3.getfY + fm_22 * a_c_vVector3.getfZ);//Dot product for the third row of the first matrix and the only column of the Vector3.
	return Vector3(tempMultiplicationVector);//Returns the multiplied matrix.
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded multiplication operation for Matrix3x3.
{
	Matrix3x3 tempMultiplicationMatrix;//Creates a temporary matrix that will hold the multiplied vector.
	//Row one.
	tempMultiplicationMatrix.fm_00 = fm_00 * a_c_mMatrix3x3.fm_00 + fm_01 * a_c_mMatrix3x3.fm_10 + fm_02 * a_c_mMatrix3x3.fm_20;//Dot product for the first row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_01 = fm_00 * a_c_mMatrix3x3.fm_01 + fm_01 * a_c_mMatrix3x3.fm_11 + fm_02 * a_c_mMatrix3x3.fm_21;//Dot product for the first row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_02 = fm_00 * a_c_mMatrix3x3.fm_02 + fm_01 * a_c_mMatrix3x3.fm_12 + fm_02 * a_c_mMatrix3x3.fm_22;//Dot product for the first row of the first matrix and the third column of the second matrix.
	//Row two.																																													  
	tempMultiplicationMatrix.fm_10 = fm_10 * a_c_mMatrix3x3.fm_00 + fm_11 * a_c_mMatrix3x3.fm_10 + fm_12 * a_c_mMatrix3x3.fm_20;//Dot product for the second row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_11 = fm_10 * a_c_mMatrix3x3.fm_01 + fm_11 * a_c_mMatrix3x3.fm_11 + fm_12 * a_c_mMatrix3x3.fm_21;//Dot product for the second row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_12 = fm_10 * a_c_mMatrix3x3.fm_02 + fm_11 * a_c_mMatrix3x3.fm_12 + fm_12 * a_c_mMatrix3x3.fm_22;//Dot product for the second row of the first matrix and the third column of the second matrix.
	//Row three.																																												  
	tempMultiplicationMatrix.fm_20 = fm_20 * a_c_mMatrix3x3.fm_00 + fm_21 * a_c_mMatrix3x3.fm_10 + fm_22 * a_c_mMatrix3x3.fm_20;//Dot product for the third row of the first matrix and the first column of the second matrix.
	tempMultiplicationMatrix.fm_21 = fm_20 * a_c_mMatrix3x3.fm_01 + fm_21 * a_c_mMatrix3x3.fm_11 + fm_22 * a_c_mMatrix3x3.fm_21;//Dot product for the third row of the first matrix and the second column of the second matrix.
	tempMultiplicationMatrix.fm_22 = fm_20 * a_c_mMatrix3x3.fm_02 + fm_21 * a_c_mMatrix3x3.fm_12 + fm_22 * a_c_mMatrix3x3.fm_22;//Dot product for the third row of the first matrix and the third column of the second matrix.
	return Matrix3x3(tempMultiplicationMatrix.fmMatrix);//Returns the multiplied matrix.
}

Matrix3x3 Matrix3x3::operator/(const float &a_c_fScalar)const//Overloaded division operation for Matrix3x3.
{
	
}

Matrix3x3 Matrix3x3::operator/(const Vector3 &a_c_vVector3)const//Overloaded division operation for Matrix3x3.
{

}

Matrix3x3 Matrix3x3::operator/(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded division operation for Matrix3x3.
{

}

//\===========================================================================================
//\ Assignment Operation Overloads
//\===========================================================================================

Matrix3x3 Matrix3x3::operator=(const float &a_c_fScalar)//Overloaded equals operation for Matrix3x3.
{
	fiMatrix[0] = a_c_fScalar;//Makes the first element of the matrix equal to the scalar passed in.
	fiMatrix[1] = a_c_fScalar;//Makes the second element of the matrix equal to the scalar passed in.
	fiMatrix[2] = a_c_fScalar;//Makes the third element of the matrix equal to the scalar passed in.
	fiMatrix[3] = a_c_fScalar;//Makes the fourth element of the matrix equal to the scalar passed in.
	fiMatrix[4] = a_c_fScalar;//Makes the fifth element of the matrix equal to the scalar passed in.
	fiMatrix[5] = a_c_fScalar;//Makes the sixth element of the matrix equal to the scalar passed in.
	fiMatrix[6] = a_c_fScalar;//Makes the seventh element of the matrix equal to the scalar passed in.
	fiMatrix[7] = a_c_fScalar;//Makes the eighth element of the matrix equal to the scalar passed in.
	fiMatrix[8] = a_c_fScalar;//Makes the ninth element of the matrix equal to the scalar passed in.

	return Matrix3x3(fmMatrix);//Returns the equated matrix.
}

Matrix3x3 Matrix3x3::operator=(const Vector3 &a_c_vVector3)//Overloaded equals operation for Matrix3x3.
{
	vXAxis = a_c_vVector3;//Equates the vXAxis to the argument Vector3.
	vYAxis = a_c_vVector3;//Equates the vYAxis to the argument Vector3.
	vZAxis = a_c_vVector3;//Equates the vZAxis to the argument Vector3.
	return Matrix3x3(fmMatrix);//Returns the equated matrix.
}

Matrix3x3 Matrix3x3::operator=(const Matrix3x3 &a_c_mMatrix3x3)//Overloaded equals operation for Matrix3x3.
{
	fiMatrix[0] = a_c_mMatrix3x3.fiMatrix[0];//Makes the first element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[1] = a_c_mMatrix3x3.fiMatrix[1];//Makes the second element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[2] = a_c_mMatrix3x3.fiMatrix[2];//Makes the third element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[3] = a_c_mMatrix3x3.fiMatrix[3];//Makes the fourth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[4] = a_c_mMatrix3x3.fiMatrix[4];//Makes the fifth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[5] = a_c_mMatrix3x3.fiMatrix[5];//Makes the sixth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[6] = a_c_mMatrix3x3.fiMatrix[6];//Makes the seventh element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[7] = a_c_mMatrix3x3.fiMatrix[7];//Makes the eighth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	fiMatrix[8] = a_c_mMatrix3x3.fiMatrix[8];//Makes the ninth element of the matrix equal to the equivalent part of the matrix3x3 passed in.
	return Matrix3x3(fmMatrix);//Returns the equated matrix.
}

//\===========================================================================================
//\ Relational Operation Overloads
//\===========================================================================================

bool Matrix3x3::operator!=(const float &a_c_fScalar)const//Overloaded not equals operation for Matrix3x3.
{
	return (
		fiMatrix[0] != a_c_fScalar ||
		fiMatrix[1] != a_c_fScalar ||
		fiMatrix[2] != a_c_fScalar ||
		fiMatrix[3] != a_c_fScalar ||
		fiMatrix[4] != a_c_fScalar ||
		fiMatrix[5] != a_c_fScalar ||
		fiMatrix[6] != a_c_fScalar ||
		fiMatrix[7] != a_c_fScalar ||
		fiMatrix[8] != a_c_fScalar);//Checks to see if each element in the Matrix3x3 is not equal to the scalar argument passed in and returns true if one is not.
}

bool Matrix3x3::operator!=(const Vector3 &a_c_vVector3)const//Overloaded not equals operation for Matrix3x3.
{
	return (
		vXAxis != a_c_vVector3 ||
		vYAxis != a_c_vVector3 ||
		vZAxis != a_c_vVector3);
}

bool Matrix3x3::operator!=(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded not equals operation for Matrix3x3.
{
	return (
		fiMatrix[0] != a_c_mMatrix3x3.fiMatrix[0] ||
		fiMatrix[1] != a_c_mMatrix3x3.fiMatrix[1] ||
		fiMatrix[2] != a_c_mMatrix3x3.fiMatrix[2] ||
		fiMatrix[3] != a_c_mMatrix3x3.fiMatrix[3] ||
		fiMatrix[4] != a_c_mMatrix3x3.fiMatrix[4] ||
		fiMatrix[5] != a_c_mMatrix3x3.fiMatrix[5] ||
		fiMatrix[6] != a_c_mMatrix3x3.fiMatrix[6] ||
		fiMatrix[7] != a_c_mMatrix3x3.fiMatrix[7] ||
		fiMatrix[8] != a_c_mMatrix3x3.fiMatrix[8]);//Checks each element in the Matrix3x3 against the passed in Matrix3x3 and if one element is not the same as the passed in matrix then return true.
}

bool Matrix3x3::operator==(const float &a_c_fScalar)const//Overloaded is equals operation for Matrix3x3.
{
	return (
		fiMatrix[0] == a_c_fScalar &&
		fiMatrix[1] == a_c_fScalar &&
		fiMatrix[2] == a_c_fScalar &&
		fiMatrix[3] == a_c_fScalar &&
		fiMatrix[4] == a_c_fScalar &&
		fiMatrix[5] == a_c_fScalar &&
		fiMatrix[6] == a_c_fScalar &&
		fiMatrix[7] == a_c_fScalar &&
		fiMatrix[8] == a_c_fScalar);//Checks to see if each element in the Matrix3x3 is equal to the scalar argument passed in and returns true if every element is.

}

bool Matrix3x3::operator==(const Vector3 &a_c_vVector3)const//Overloaded is equals operation for Matrix3x3.
{
	return (
		vXAxis == a_c_vVector3 &&
		vYAxis == a_c_vVector3 &&
		vZAxis == a_c_vVector3);
}

bool Matrix3x3::operator==(const Matrix3x3 &a_c_mMatrix3x3)const//Overloaded is equals operation for Matrix3x3.
{
	return (
		fiMatrix[0] == a_c_mMatrix3x3.fiMatrix[0] &&
		fiMatrix[1] == a_c_mMatrix3x3.fiMatrix[1] &&
		fiMatrix[2] == a_c_mMatrix3x3.fiMatrix[2] &&
		fiMatrix[3] == a_c_mMatrix3x3.fiMatrix[3] &&
		fiMatrix[4] == a_c_mMatrix3x3.fiMatrix[4] &&
		fiMatrix[5] == a_c_mMatrix3x3.fiMatrix[5] &&
		fiMatrix[6] == a_c_mMatrix3x3.fiMatrix[6] &&
		fiMatrix[7] == a_c_mMatrix3x3.fiMatrix[7] &&
		fiMatrix[8] == a_c_mMatrix3x3.fiMatrix[8]);//Checks each element in the Matrix3x3 against the passed in Matrix3x3 and if all elements are the same return true.
}

//\===========================================================================================
//\ Rotate Around Euler Axis
//\===========================================================================================
/*
cos(θ) −sin(θ) 0
sin(θ)  cos(θ) 0
0        0     1
*/
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
