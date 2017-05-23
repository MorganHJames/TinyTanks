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
//\ Functions for Max value, Clamp, Lerp, Slerp, SmoothStep etc.
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
bool AABB(Box b1, Box b2, Vector2& a_v2Pos);


// performs collision detection on moving box b1 and static box b2
// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
// getting the new position can be retrieved by box.x = box.x + box.vx * collisiontime
// normalx and normaly return the normal of the collided surface (this can be used to do a response)
float SweptAABB(Box b1, Box b2, float& normalx, float& normaly);
/*
//Do nothing
float normalx, normaly;
float collisiontime = SweptAABB(box, block, out normalx, out normaly);
box.x += box.vx * collisiontime;
box.y += box.vy * collisiontime;

float remainingtime = 1.0f - collisiontime;

// push
float magnitude = sqrt((box.vx * box.vx + box.vy * box.vy)) * remainingtime;
float dotprod = box.vx * normaly + box.vy * normalx;
if (dotprod > 0.0f)
dotprod = 1.0f;
else if (dotprod < 0.0f)
	dotprod = -1.0f;
NewBox.vx = dotprod * normaly * magnitude;
NewBox.vy = dotprod * normalx * magnitude;



// deflect
box.vx *= remainingtime;
box.vy *= remainingtime;
if (abs(normalx) > 0.0001f)
box.vx = -box.vx;
if (abs(normaly) > 0.0001f)
box.vy = -box.vy;

// slide
float dotprod = (box.vx * normaly + box.vy * normalx) * remainingtime;
NewBox.vx = dotprod * normaly;
NewBox.vy = dotprod * normalx;
*/

//\===========================================================================================
//\ Max Value
//\===========================================================================================

template <typename T>
inline T const& Max(T const& a, T const& b);

//\===========================================================================================
//\ Clamp 
//\===========================================================================================

float clamp(float x, float min, float max);

//\===========================================================================================
//\ Lerp 
//\===========================================================================================

float lerp(float v0, float v1, float t);

//\===========================================================================================
//\ Quad Bezzier
//\===========================================================================================

//Sourced from https://stackoverflow.com/questions/785097/how-do-i-implement-a-b%C3%A9zier-curve-in-c

Vector2 getBezierPoint(Vector2* points, int numPoints, float t);

//\===========================================================================================
//\ Slerp 
//\===========================================================================================

// Code sourced from https https://en.wikipedia.org/wiki/Slerp

//Vector3 slerp(float a_fT, Vector3 a_v3V0, Vector3 a_v3V1);

//\===========================================================================================
//\ Smoothstep
//\===========================================================================================

float smoothstep(float edge0, float edge1, float x);
//\===========================================================================================
//\ Smootherstep
//\===========================================================================================

float smootherstep(float edge0, float edge1, float x);

#endif
