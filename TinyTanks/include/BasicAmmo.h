#ifndef _BASICAMMO_H_
#define _BASICAMMO_H_

#include "Vector2.h"
#include "Sprite.h"

struct BasicAmmo
{
	Sprite* sBasicAmmo;//The default sprite for the bullet.

	Vector2 v2PosOffSet;//The coordinates to where the bullet is on the screen.

	bool active = false;//Whether or not the bullet is being shot.

	float fVelocity = 250.0f;//A float that will contain the current velocity of the bullet.

	float fLifeTimer = 0.0f;//How much time the bullet has left in it's life.

	Vector2 v2Forward;//Which direction the bullet is facing.
};

#endif