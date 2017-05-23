//\===========================================================================================
//\ File: MathUtil.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in RPN MathUtil.h.
//\===========================================================================================

#include "MathUtil.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include "Vector2.h"
#include "Vector3.h"

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

// returns true if the boxes are colliding (velocities are not used)
bool AABBCheck(Box b1, Box b2)
{
	return !(b1.x + b1.w < b2.x || b1.x > b2.x + b2.w || b1.y + b1.h < b2.y || b1.y > b2.y + b2.h);
}

// returns true if the boxes are colliding (velocities are not used)
// moveX and moveY will return the movement the b1 must move to avoid the collision
bool AABB(Box b1, Box b2, Vector2& a_v2Pos)
{
	a_v2Pos = 0.0f;

	float l = b2.x - (b1.x + b1.w);
	float r = (b2.x + b2.w) - b1.x;
	float t = b2.y - (b1.y + b1.h);
	float b = (b2.y + b2.h) - b1.y;

	// check that there was a collision
	if (l > 0 || r < 0 || t > 0 || b < 0)
		return false;

	// find the offset of both sides
	a_v2Pos.setfX(abs(l) < r ? l : r);
	a_v2Pos.setfY(abs(t) < b ? t : b);

	// only use whichever offset is the smallest
	if (abs(a_v2Pos.getfX()) < abs(a_v2Pos.getfY()))
		a_v2Pos.setfY(0.0f);
	else
		a_v2Pos.setfX(0.0f);

	return true;
}

// performs collision detection on moving box b1 and static box b2
// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
// getting the new position can be retrieved by box.x = box.x + box.vx * collisiontime
// normalx and normaly return the normal of the collided surface (this can be used to do a response)
float SweptAABB(Box b1, Box b2, float& normalx, float& normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (b1.vx > 0.0f)
	{
		xInvEntry = b2.x - (b1.x + b1.w);
		xInvExit = (b2.x + b2.w) - b1.x;
	}
	else
	{
		xInvEntry = (b2.x + b2.w) - b1.x;
		xInvExit = b2.x - (b1.x + b1.w);
	}

	if (b1.vy > 0.0f)
	{
		yInvEntry = b2.y - (b1.y + b1.h);
		yInvExit = (b2.y + b2.h) - b1.y;
	}
	else
	{
		yInvEntry = (b2.y + b2.h) - b1.y;
		yInvExit = b2.y - (b1.y + b1.h);
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1.vx;
		xExit = xInvExit / b1.vx;
	}

	if (b1.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1.vy;
		yExit = yInvExit / b1.vy;
	}

	// find the earliest/latest times of collision
	float entryTime = std::max(xEntry, yEntry);
	float exitTime = std::min(xExit, yExit);

	// if there was no collision
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else // if there was a collision
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// return the time of collision
		return entryTime;
	}
}

//\===========================================================================================
//\ Max Value
//\===========================================================================================

template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}

//\===========================================================================================
//\ Clamp 
//\===========================================================================================

float clamp(float x, float min, float max)
{
	if (x < min) 
		x = min;
	else if (x > max) 
		x = max;
	return x;
}

//\===========================================================================================
//\ Lerp 
//\===========================================================================================

float lerp(float v0, float v1, float t)
{
	return (1 - t) * v0 + t * v1;
}

//\===========================================================================================
//\ Quad Bezzier
//\===========================================================================================

//Sourced from https://stackoverflow.com/questions/785097/how-do-i-implement-a-b%C3%A9zier-curve-in-c
/*
Vector2 getBezierPoint(Vector2* points, int numPoints, float t)
{
	Vector2* tmp = new Vector2[numPoints];
	memcpy(tmp, points, numPoints * sizeof(Vector2));
	int i = numPoints - 1;
	while (i > 0)
	{
		for (int k = 0; k < i; k++)
			tmp[k] = tmp[k] + t * (tmp[k + 1] - tmp[k]);
		i--;
	}
	Vector2 answer = tmp[0];
	delete[] tmp;
	return answer;
}*/

//\===========================================================================================
//\ Slerp 
//\===========================================================================================

// Code sourced from https https://en.wikipedia.org/wiki/Slerp
/*
Vector3 slerp(float a_fT, Vector3 a_v3V0, Vector3 a_v3V1)
{
	a_v3V0.normalise();
	a_v3V1.normalise();

	float fDot = a_v3V0.dotProduct(a_v3V1);

	const float c_fDotThreshold = 0.999f;
	if (fabs(fDot) > c_fDotThreshold)
	{
		Vector3 v3Result = (a_v3V1 - a_v3V0) * (a_v3V0 + a_fT);
		v3Result.normalise();
		return v3Result;
	}

	if (fDot < 0.0f)
	{
		a_v3V1.setfX(-a_v3V1.getfX());
		a_v3V1.setfY(-a_v3V1.getfY());
		a_v3V1.setfZ(-a_v3V1.getfZ());
		fDot = -fDot;
	}

	clamp(fDot, -1.f, 1.f);
	float fTheta_0 = acos(fDot);
	float fTheta = fTheta_0 * a_fT;

	Vector3 v3V2 = a_v3V1 * fDot;
	v3V2.normalise();

	return a_v3V0 * cos(fTheta) + v3V2 * sin(fTheta);
}
*/

//\===========================================================================================
//\ Smoothstep
//\===========================================================================================

float smoothstep(float edge0, float edge1, float x)
{
	// Scale, bias and saturate x to 0..1 range
	x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	// Evaluate polynomial
	return x*x*(3 - 2 * x);
}

//\===========================================================================================
//\ Smootherstep
//\===========================================================================================

float smootherstep(float edge0, float edge1, float x)
{
	// Scale, and clamp x to 0..1 range
	x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	// Evaluate polynomial
	return x*x*x*(x*(x * 6 - 15) + 10);
}
