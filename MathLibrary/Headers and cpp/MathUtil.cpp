//\===========================================================================================
//\ File: MathUtil.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in RPN MathUtil.h.
//\===========================================================================================

#include "MathUtil.h"
#include <cmath>

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

Vector3 vectorTimesMatrix3x3(const Vector3 &a_c_v3Vector3, const Matrix3x3 &a_c_fm3Matrix3x3)//Multiplication for a vector times a matrix as introducing this as an overload would cause circular dependency.
{
	return Vector3(//Returns the multiplied Vector3.
		a_c_v3Vector3.getfX() * a_c_fm3Matrix3x3.getiMatrix(1) + a_c_v3Vector3.getfY() * a_c_fm3Matrix3x3.getiMatrix(4) + a_c_v3Vector3.getfZ() * a_c_fm3Matrix3x3.getiMatrix(7),//Dot product for the only row of the Vector3 and the first row of the Matrix3x3.
		a_c_v3Vector3.getfX() * a_c_fm3Matrix3x3.getiMatrix(2) + a_c_v3Vector3.getfY() * a_c_fm3Matrix3x3.getiMatrix(5) + a_c_v3Vector3.getfZ() * a_c_fm3Matrix3x3.getiMatrix(8),//Dot product for the only row of the Vector3 and the second row of the Matrix3x3.
		a_c_v3Vector3.getfX() * a_c_fm3Matrix3x3.getiMatrix(3) + a_c_v3Vector3.getfY() * a_c_fm3Matrix3x3.getiMatrix(6) + a_c_v3Vector3.getfZ() * a_c_fm3Matrix3x3.getiMatrix(9));//Dot product for the only row of the Vector3 and the third row of the Matrix3x3.
}