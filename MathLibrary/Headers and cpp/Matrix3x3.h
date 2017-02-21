/*
//\=====================================================================================
///
/// @file   Matrix3.h
/// @author Jamie Stewart
/// @date   18th April 2013
///
//\=====================================================================================
#include "mathLib.h"


#pragma once
#ifndef _MATRIX3_H_
#define _MATRIX3_H_


//\=====================================================================================
///
/// @author Jamie Stewart
///     Matrix3 class
///
/// Class that implements a 3 by 3 homgenous matrix.
///
//\=====================================================================================
class ML_API CMatrix3
{
public:
	//\===========================================================================================
	//\ Member Variables held in unnamed union for accessibility
	//\===========================================================================================
	union
	{
		float   m[3][3];
		struct
		{
			float   m_11, m_12, m_13;
			float   m_21, m_22, m_23;
			float   m_31, m_32, m_33;
		};
	};
	//\===========================================================================================
	//\ Constants
	//\===========================================================================================
	static const CMatrix3 ONE;
	static const CMatrix3 ZERO;
	static const CMatrix3 IDENTITY;
	//\===========================================================================================
	//\ Constructors
	//\===========================================================================================
	CMatrix3();
	CMatrix3(const float* mat);
	CMatrix3(float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33);
	CMatrix3(CMatrix3& a_m3);
	//\===========================================================================================
	//\ Casting operators
	//\===========================================================================================
	operator float*  ();
	operator const float*  () const;
	//\===========================================================================================
	//\ Component access operators
	//\===========================================================================================
	float&                  operator            () (int iRow, int iCol);
	float                   operator            () (int iRow, int iCol) const;
	//\===========================================================================================
	//\ Cols & Rows Access
	//\===========================================================================================
	void                     SetCol(int iCol, const CVector3& vCol);
	void                     SetRow(int iRow, const CVector3& vRow);
	CVector3                 GetCol(int iCol) const;
	CVector3                 GetRow(int iRow) const;
	void                     GetCol(int iCol, CVector3& vCol) const;
	void                     GetRow(int iRow, CVector3& vRow) const;
	//\===========================================================================================
	//\ Equivalence Operators
	//\===========================================================================================
	bool                    operator  ==        (const CMatrix3& a_m3) const;
	bool                    operator  !=        (const CMatrix3& a_m3) const;
	//\===========================================================================================
	//\ Negative Operator
	//\===========================================================================================
	const CMatrix3          operator  -         () const;
	//\===========================================================================================
	//\ Operator overloads for Addition
	//\===========================================================================================
	const CMatrix3          operator  +         (const CMatrix3& a_m3) const;
	const CMatrix3&         operator  +=        (const CMatrix3& a_m3);
	//\===========================================================================================
	//\ Operator overloads for Subtraction
	//\===========================================================================================
	const CMatrix3          operator  -         (const CMatrix3& a_m3) const;
	const CMatrix3&         operator  -=        (const CMatrix3& a_m3);
	//\===========================================================================================
	//\ Operator overloads for multiplication
	//\===========================================================================================
	const CMatrix3          operator  *         (const float a_fScalar) const;
	friend ML_API const CMatrix3    operator  *         (const float a_fScalar, const CMatrix3& a_m3);
	const CMatrix3&         operator  *=        (const float a_fScalar);

	const CVector3          operator  *         (const CVector3& a_v3) const;
	friend ML_API const CVector3    operator  *         (const CVector3& a_v3, const CMatrix3& a_m3);

	const CMatrix3          operator  *         (const CMatrix3& a_m3) const;
	const CMatrix3&         operator  *=        (const CMatrix3& a_m3);
	//\===========================================================================================
	//\ Transpose Matrix - Transform from Row to Column
	//\===========================================================================================
	void                    Transpose();
	void                    GetTranspose(CMatrix3 &a_m3) const;
	//\===========================================================================================
	//\ Inverse - Get the inverse of the matrix
	//\===========================================================================================
	float                   Determinant() const;
	bool                    Inverse();
	bool                    GetInverse(CMatrix3 &a_m3) const;
	//\===========================================================================================
	//\ Rotation Functions
	//\===========================================================================================
	void                     RotateX(float fAngle);
	void                     RotateY(float fAngle);
	void                     RotateZ(float fAngle);
	//\===========================================================================================
	//\ Orthonormalisation functions
	//\===========================================================================================
	void                     OrthoNormalise();
	void                     GramSchmidtOrtho();
	//\===========================================================================================
	//\ Scale Functionality
	//\===========================================================================================
	void                     Scale(const CVector3& a_v3);
	void                     Scale(float a_fScalar);
	//\===========================================================================================
	//\ General matrix functions
	//\===========================================================================================
	void                     Identity();
	void                     Zero();

};

#endif //_MATRIX3_H_
*/