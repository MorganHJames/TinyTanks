//\===========================================================================================
//\ File: MathUtil.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in RPN MathUtil.h.
//\===========================================================================================

#include "MathUtil.h"
#include <cmath>

//\===========================================================================================
//\ Definitions for constants
//\===========================================================================================

/* Definitions of useful mathematical constants
* M_E        - e
* M_LOG2E    - log2(e)
* M_LOG10E   - log10(e)
* M_LN2      - ln(2)
* M_LN10     - ln(10)
* M_PI       - pi
* M_PI_2     - pi/2
* M_PI_4     - pi/4
* M_1_PI     - 1/pi
* M_2_PI     - 2/pi
* M_2_SQRTPI - 2/sqrt(pi)
* M_SQRT2    - sqrt(2)
* M_SQRT1_2  - 1/sqrt(2)
*/
#define M_E  2.71828182845904523536
#define M_LOG2E  1.44269504088896340736
#define M_LOG10E  0.434294481903251827651
#define M_LN2  0.693147180559945309417
#define M_LN10  2.30258509299404568402
#define PI         cosf(-1)//A float equal to pi.
#define PI_2  1.57079632679489661923
#define PI_4  0.785398163397448309616
#define _1_PI  0.318309886183790671538
#define _2_PI  0.636619772367581343076
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2  1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

float degreesToRadians(const float a_c_fRadAngle)
{
	return (a_c_fRadAngle * (PI / 180));
}

float reciprocal(const float a_c_fScalar)
{
	return (1 / a_c_fScalar);
}

Vector3 vector3Inverse(const Vector3 a_c_vVector3)
{
	return(a_c_vVector3 * -1);
}