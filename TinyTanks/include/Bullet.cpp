//\===========================================================================================
//\ File: Bullet.cpp
//\ Author: Morgan James
//\ Date Created: 20/05/2017
//\ Brief: Contains the function information for the class contained in bullet.h.
//\===========================================================================================

#include "Bullet.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "UGFW.h"
#include <iostream>

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Bullet::Bullet(const int a_c_iMaxBullets, char* a_c_cFileLocation, float a_c_fShotDelay)//The default constructor for the sprite.
{
	m_iMaxBullets = a_c_iMaxBullets;

	m_fShotDelay = a_c_fShotDelay;

	for (int i = 0; i < m_iMaxBullets; ++i)
	{
		m_bBulletArray[i].iSpriteID = UG::CreateSprite(a_c_cFileLocation, (float) m_iSpriteWidth, (float) m_iSpriteHeight, true);

		UG::SetSpriteUVCoordinates(m_bBulletArray[i].iSpriteID, 0, 0, 1, 1);//Sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

		UG::SetSpriteLayer(m_bBulletArray[i].iSpriteID, 4);//Sets the current sprite layer to be under the turret.
	}
}

//\===========================================================================================
//\ Shoot Function 
//\===========================================================================================

void Bullet::shoot(const Vector2 a_c_v2Pos,  Vector4 a_c_v4Rotation)//A function to shoot bullets from the end of a turret.
{
	for (int i = 0; i < m_iMaxBullets; ++i)//For each bullet.
	{
		if (m_bBulletArray[i].active == false && m_fShotDelayTimer <= 0)//If the bullet is not active and the shot timer is less than or equal to zero.
		{
			float fSpriteMat[16];//Creates an array of 16 floats.

			UG::GetSpriteMatrix(m_bBulletArray[i].iSpriteID, fSpriteMat);//Gets the sprite matrix of the turret and sets it in the array.

			fSpriteMat[0] = a_c_v4Rotation.getfX();//Sets the float array's first element to be equal to the rotated matrix's counterpart.

			fSpriteMat[1] = a_c_v4Rotation.getfY();//Sets the float array's second element to be equal to the rotated matrix's counterpart.

			fSpriteMat[4] = a_c_v4Rotation.getfZ();//Sets the float array's fifth element to be equal to the rotated matrix's counterpart.

			fSpriteMat[5] = a_c_v4Rotation.getfW();//Sets the float array's sixth element to be equal to the rotated matrix's counterpart.

			UG::SetSpriteMatrix(m_bBulletArray[i].iSpriteID, fSpriteMat);//Set's the sprite matrix to be equal to the rotated version.

			m_bBulletArray[i].v2Forward = Vector2(a_c_v4Rotation.getfZ(), a_c_v4Rotation.getfW());//Sets the forward of the bullet.

			m_bBulletArray[i].v2Pos = a_c_v2Pos + m_bBulletArray[i].v2Forward * m_fOffSet;//Sets the initial position of the bullet.
			
			m_bBulletArray[i].active = true;//Sets the bullet to be active.

			UG::DrawSprite(m_bBulletArray[i].iSpriteID);//Draws the current bullet.

			m_bBulletArray[i].fLifeTimer = m_fLifeTime;//Start the life timer for the bullet.

			m_fShotDelayTimer = m_fShotDelay;//Start the shot delay timer.
		}
	}
}

//\===========================================================================================
//\ Update Function 
//\===========================================================================================

void Bullet::update(float a_fDeltaTime)//Updates the bullets to travel and change states.
{
	m_fShotDelayTimer -= a_fDeltaTime;//Decreases the shot delay timer.

	for (int i = 0; i < m_iMaxBullets; ++i)//For each bullet.
	{
		if (m_bBulletArray[i].active == true)//if the bullet is active.
		{
			m_bBulletArray[i].fLifeTimer -= a_fDeltaTime;//Decrease the lifetime of the bullet.

			m_bBulletArray[i].v2Pos += (m_bBulletArray[i].v2Forward * m_bBulletArray[i].fVelocity * a_fDeltaTime);//Add forward and velocity to the position.

			UG::MoveSprite(m_bBulletArray[i].iSpriteID, m_bBulletArray[i].v2Pos.getfX(), (m_bBulletArray[i].v2Pos.getfY()));//Moves the sprite to the correct location on the screen.

			if (m_bBulletArray[i].fLifeTimer <= 0)//If the life timer is less than or equal to zero.
			{
				UG::StopDrawingSprite(m_bBulletArray[i].iSpriteID);//Stops drawing the current bullet.

				m_bBulletArray[i].active = false;//Set the bullet to be false.
			}
		}
	}
}
