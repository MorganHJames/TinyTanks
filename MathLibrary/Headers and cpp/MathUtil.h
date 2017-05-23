//\===========================================================================================
//\ File: MathUtil.h
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the MathUtil class declarations.
//\===========================================================================================

#ifndef _MATHUTIL_H_
#define _MATHUTIL_H_

#include "Vector2.h"

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
* E        - e
* LOG2E    - log2(e)
* LOG10E   - log10(e)
* LN2      - ln(2)
* LN10     - ln(10)
* PI       - pi
* PI_2     - pi/2
* PI_4     - pi/4
* _1_PI    - 1/pi
* _2_PI    - 2/pi
* _2_SQRTPI- 2/sqrt(pi)
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

float degreesToRadians(const float a_c_fRadAngle);

//\===========================================================================================
//\ Reciprocal
//\===========================================================================================

float reciprocal(const float a_c_fScalar);

//\===========================================================================================
//\ Test Collision Functions
//\===========================================================================================

//Formula from https://www.gamedev.net/resources/_/technical/game-programming/swept-aabb-collision-detection-and-response-r3084

// describes an axis-aligned rectangle with a velocity
struct Box
{
	Box(Vector2 a_v2Position, float a_fWidth, float a_fHeight, Vector2 a_v2Veclocity)
	{
		x = a_v2Position.getfX() - (a_fWidth * 0.5f);
		y = a_v2Position.getfY() + (a_fHeight * 0.5f);
		w = a_fWidth;
		h = a_fHeight;
		vx = a_v2Veclocity.getfX();
		vy = a_v2Veclocity.getfY();
	}

	// position of top-left corner
	float x, y;

	// dimensions
	float w, h;

	// velocity
	float vx, vy;
};

// returns true if the boxes are colliding (velocities are not used)
bool AABBCheck(Box b1, Box b2);

// returns true if the boxes are colliding (velocities are not used)
// moveX and moveY will return the movement the b1 must move to avoid the collision
bool AABB(Box b1, Box b2, float& moveX, float& moveY);


/*
// returns a box the spans both a current box and the destination box
Box GetSweptBroadphaseBox(Box b);

// performs collision detection on moving box b1 and static box b2
// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
// getting the new position can be retrieved by box.x = box.x + box.vx * collisiontime
// normalx and normaly return the normal of the collided surface (this can be used to do a response)
float SweptAABB(Box b1, Box b2, float& normalx, float& normaly);
*/

//\===========================================================================================
//\ Min Value
//\===========================================================================================

//\===========================================================================================
//\ Max Value
//\===========================================================================================

template <typename T>
inline T const& Max(T const& a, T const& b);

//\===========================================================================================
//\ Clamp 
//\===========================================================================================

//\===========================================================================================
//\ Lerp 
//\===========================================================================================

float lerp(float v0, float v1, float t);

//\===========================================================================================
//\ Quad Bezzier
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

#endif
