//\===========================================================================================
//\ File: Bullet.cpp
//\ Author: Morgan James
//\ Date Created: 20/05/2017
//\ Brief: Contains the function information for the class contained in bullet.h.
//\===========================================================================================

#include "Bullet.h"
#include "Vector2.h"
#include "Matrix3x3.h"
#include "UGFW.h"

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Bullet::Bullet(const int a_c_iMaxBullets, char* a_c_cFileLocation, float a_c_fShotDelay)//The default constructor for the sprite.
{
	m_iMaxBullets = a_c_iMaxBullets;

	m_fShotDelay = a_c_fShotDelay;

	for (int i = 0; i < m_iMaxBullets; ++i)
	{
		basic &currentBullet = m_bBulletArray[i];

		currentBullet.iSpriteID = UG::CreateSprite(a_c_cFileLocation, m_iSpriteWidth, m_iSpriteHeight, true);

		UG::SetSpriteUVCoordinates(currentBullet.iSpriteID, 0, 0, 1, 1);//Sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

		UG::SetSpriteLayer(currentBullet.iSpriteID, 1);//Sets the current sprite layer to be under the turret.
	}
}

//\===========================================================================================
//\ Shoot Function 
//\===========================================================================================

void Bullet::shoot(const Vector2 a_c_v2Pos, Vector2 a_c_v2Forward, float a_fDeltaTime)
{
	for (int i = 0; i < m_iMaxBullets; ++i)
	{
		basic &currentBullet = m_bBulletArray[i];

		float fShotDelayTimer = 0; 

		fShotDelayTimer -= a_fDeltaTime;

		if (currentBullet.active == false && fShotDelayTimer <= 0)
		{
			currentBullet.v2Pos = a_c_v2Pos;
			currentBullet.v2Forward = a_c_v2Forward;
			currentBullet.active = true;
			currentBullet.fLifeTimer = m_fLifeTime;
			fShotDelayTimer = m_fShotDelay;
		}
	}
}

//\===========================================================================================
//\ Update Function 
//\===========================================================================================

void Bullet::update(float a_fDeltaTime)
{
	for (int i = 0; i < m_iMaxBullets; ++i)
	{
		basic &currentBullet = m_bBulletArray[i];

		if (currentBullet.active == true)
		{
			UG::DrawSprite(currentBullet.iSpriteID);//Draws the current bullet.

			currentBullet.fLifeTimer -= a_fDeltaTime;

			currentBullet.v2Pos += (currentBullet.v2Forward * currentBullet.fVelocity * a_fDeltaTime);//Add forward and velocity to the position.

			UG::MoveSprite(currentBullet.iSpriteID, currentBullet.v2Pos.getfX(), currentBullet.v2Pos.getfY());//Moves the sprite to the correct location on the screen.

			if (currentBullet.fLifeTimer <= 0)
			{
				UG::StopDrawingSprite(currentBullet.iSpriteID);//Stops drawing the current bullet.

				currentBullet.active = false;
			}
		}
	}
}