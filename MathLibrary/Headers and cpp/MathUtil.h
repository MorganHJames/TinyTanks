//\===========================================================================================
//\ File: MathUtil.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the MathUtil class declarations.
//\===========================================================================================

#ifndef _MATHUTIL_H_
#define _MATHUTIL_H_

#include "Matrix4x4.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Brief: Multiple #defines for constants E.G. PI, 2PI, HALF_PI.
//\ Functions to test for collisions E.G.RayPointIntersection testing, AABB testing,
//\ Functions for Min / Max value, Clamp, Lerp, Slerp, SmoothStep etc.
//\===========================================================================================

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

//\===========================================================================================
//\ Test collision functions
//\===========================================================================================
float degreesToRadians(const float a_c_fRadAngle);


float reciprocal(const float a_c_fScalar);


Vector3 vector3Inverse(const Vector3 a_c_vVector3);


#endif
