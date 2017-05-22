//\===========================================================================================
//\ File: Bullet.h
//\ Author: Morgan James
//\ Date Created: 20/05/2017
//\ Brief: Contains the Bullet class declarations.
//\===========================================================================================

#ifndef _BULLET_H_
#define _BULLET_H_

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Bullet
//\ Brief: A class that is used to create projectiles.
//\===========================================================================================

#include "Vector2.h"

class Bullet
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

	struct basic
	{
		int iSpriteID = -1;//The ID of the sprite.

		Vector2 v2Pos;//The coordinates to where the bullet is on the screen.

		bool active = false;//Whether or not the bullet is being shot.

		float fVelocity = 250.0f;//A float that will contain the current velocity of the bullet.

		float fLifeTimer = 0.0f;

		Vector2 v2Forward;
	};
	float m_fOffSet = 55.0f;

	int m_iSpriteHeight = 32;

	float m_fLifeTime = 5;

	int m_iSpriteWidth = 32;

	float m_fShotDelay = 1;

	float m_fShotDelayTimer = 0;

	int m_iMaxBullets = 0;//How many bullets there will be available for the player to shoot.

	basic m_bBulletArray[4];//An array of tiles that will be moved to there correct position.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Bullet(const int a_c_iMaxBullets, char* a_c_cFileLocation, float a_c_fShotDelay);//The default initialize for the sprite.

	//\===========================================================================================
	//\ Shoot Function 
	//\===========================================================================================

	void shoot(const Vector2 a_c_v2Pos, Vector2 a_c_v2Forward, Vector2 a_c_v2Rotation);

	//\===========================================================================================
	//\ Update Function 
	//\===========================================================================================

	void update(float a_fDeltaTime);


};
#endif