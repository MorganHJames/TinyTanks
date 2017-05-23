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
#include "Vector4.h"
#include "BasicAmmo.h"

class Bullet
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

	float m_fOffSet = 55.0f;//How far away from the turrets center the bullet will appear.

	int m_iSpriteHeight = 16;//How long each bullet is.

	float m_fLifeTime = 5;//How long each bullet will travel for.

	int m_iSpriteWidth = 16;//How wide each bullet is.

	float m_fShotDelay = 1;//The time between shots.

	float m_fShotDelayTimer = 0;//How long left until a bullet can be fired.

	int m_iMaxBullets = 0;//How many bullets there will be available for the player to shoot.

	BasicAmmo *m_bBasicAmmoArray;//An array of tiles that will be moved to there correct position.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Bullet(const int a_c_iMaxBullets, char* a_c_cFileLocation, float a_c_fShotDelay);//The default initialize for the sprites.

	//\===========================================================================================
	//\ Shoot Function 
	//\===========================================================================================

	void shoot(const Vector2 a_c_v2Pos, Vector4 a_c_v4Rotation);//A function to shoot bullets from the end of a turret.

	//\===========================================================================================
	//\ Update Function 
	//\===========================================================================================

	void update(float a_fDeltaTime);//Updates the bullets to travel and change states.

};
#endif