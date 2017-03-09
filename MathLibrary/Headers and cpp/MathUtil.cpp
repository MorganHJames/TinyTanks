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
* E        - e
* LOG2E    - log2(e)
* LOG10E   - log10(e)
* LN2      - ln(2)
* LN10     - ln(10)
* PI       - pi
* PI_2     - pi/2
* PI_4     - pi/4
* 1_PI     - 1/pi
* 2_PI     - 2/pi
* 2_SQRTPI - 2/sqrt(pi)
* SQRT2    - sqrt(2)
* SQRT1_2  - 1/sqrt(2)
*/
#define E         2.7182818f//A float equal to e.
#define LOG2E     1.4426950f//A float equal to log2(e).
#define LOG10E    0.4342944f//A float equal to log10(e).
#define LN2       0.6931471f//A float equal to ln(2).
#define LN10      2.3025851f//A float equal to ln(10).
#define PI        3.1415927f//A float equal to pi.
#define PI_2      1.5707963f//A float equal to pi/2.
#define PI_4      0.7853982f//A float equal to pi/4
#define _1_PI     0.3183099f//A float equal to 1/pi.
#define _2_PI     0.6366198f//A float equal to 2/pi.
#define _2_SQRTPI 1.1283792f//A float equal to 2/sqrt(pi).
#define SQRT2     1.4142136f//A float equal to sqrt(2).
#define SQRT1_2   0.7071068f//A float equal to 1/sqrt(2).

//\===========================================================================================
//\ Degrees To Radians
//\===========================================================================================

float degreesToRadians(const float a_c_fRadAngle)
{
	return (a_c_fRadAngle * (PI / 180));
}

//\===========================================================================================
//\ Reciprocal
//\===========================================================================================

float reciprocal(const float a_c_fScalar)
{
	return (1 / a_c_fScalar);
}


//\===========================================================================================
//\ Test Collision Functions
//\===========================================================================================

/*
CheckCollision(BallObject &one, GameObject &two) // AABB - Circle collision
{
	// Get center point circle first 
	glm::vec2 center(one.Position + one.Radius);
	// Calculate AABB info (center, half-extents)
	glm::vec2 aabb_half_extents(two.Size.x / 2, two.Size.y / 2);
	glm::vec2 aabb_center(
		two.Position.x + aabb_half_extents.x,
		two.Position.y + aabb_half_extents.y
	);
	// Get difference vector between both centers
	glm::vec2 difference = center - aabb_center;
	glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
	// Add clamped value to AABB_center and we get the value of box closest to circle
	glm::vec2 closest = aabb_center + clamped;
	// Retrieve vector between center circle and closest point AABB and check if length <= radius
	difference = closest - center;
	return glm::length(difference) < one.Radius;
}

checkCollision(GameObject &one, GameObject &two) // AABB - AABB collision
{
	// Collision x-axis?
	bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
		two.Position.x + two.Size.x >= one.Position.x;
	// Collision y-axis?
	bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
		two.Position.y + two.Size.y >= one.Position.y;
	// Collision only if on both axes
	return collisionX && collisionY;
}
*/

//\===========================================================================================
//\ Min Value
//\===========================================================================================

//\===========================================================================================
//\ Max Value
//\===========================================================================================

//\===========================================================================================
//\ Clamp 
//\===========================================================================================

//\===========================================================================================
//\ Lerp 
//\===========================================================================================

//\===========================================================================================
//\ Slerp 
//\===========================================================================================

//\===========================================================================================
//\ Smoothstep
//\===========================================================================================

//\===========================================================================================
//\ Smootherstep
//\===========================================================================================
