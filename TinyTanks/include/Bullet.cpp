//\===========================================================================================
//\ File: Bullet.cpp
//\ Author: Morgan James
//\ Date Created: 20/05/2017
//\ Brief: Contains the function information for the class contained in bullet.h.
//\===========================================================================================

#include "Bullet.h"
#include "Vector2.h"
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

		m_bBulletArray[i].iSpriteID = UG::CreateSprite(a_c_cFileLocation, m_iSpriteWidth, m_iSpriteHeight, true);

		UG::SetSpriteUVCoordinates(m_bBulletArray[i].iSpriteID, 0, 0, 1, 1);//Sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

		UG::SetSpriteLayer(m_bBulletArray[i].iSpriteID, 4);//Sets the current sprite layer to be under the turret.
	}
}

//\===========================================================================================
//\ Shoot Function 
//\===========================================================================================

void Bullet::shoot(const Vector2 a_c_v2Pos, Vector2 a_c_v2Forward)
{
	for (int i = 0; i < m_iMaxBullets; ++i)
	{
		if (m_bBulletArray[i].active == false && m_fShotDelayTimer <= 0)
		{
			m_bBulletArray[i].v2Pos = a_c_v2Pos;
			
			float fSpriteMat[16];//Creates an array of 16 floats.

			UG::GetSpriteMatrix(m_bBulletArray[i].iSpriteID, fSpriteMat);//Gets the sprite matrix of the turret and sets it in the array.

			Matrix4x4 m4SpriteMat(fSpriteMat);//Creates a 4x4 matrix from the float array.

			m_bBulletArray[i].vForward = a_c_v2Forward;

			m_bBulletArray[i].active = true;

			UG::DrawSprite(m_bBulletArray[i].iSpriteID);//Draws the current bullet.

			std::cout << "Draw: " << m_bBulletArray[i].iSpriteID << " x: " << m_bBulletArray[i].v2Pos.getfX() << " Y: " << m_bBulletArray[i].v2Pos.getfY() << std::endl;


			m_bBulletArray[i].fLifeTimer = m_fLifeTime;

			m_fShotDelayTimer = m_fShotDelay;
		}
	}
}

//\===========================================================================================
//\ Update Function 
//\===========================================================================================

void Bullet::update(float a_fDeltaTime)
{
	m_fShotDelayTimer -= a_fDeltaTime;

	for (int i = 0; i < m_iMaxBullets; ++i)
	{
		if (m_bBulletArray[i].active == true)
		{
			m_bBulletArray[i].fLifeTimer -= a_fDeltaTime;

			m_bBulletArray[i].fVelocity = 1;

			float fSpriteMat[16];//Creates an array of 16 floats.

			UG::GetSpriteMatrix(m_bBulletArray[i].iSpriteID, fSpriteMat);//Gets the sprite matrix of the turret and sets it in the array.

			Matrix4x4 m4SpriteMat(fSpriteMat);//Creates a 4x4 matrix from the float array.

			//Vector2 v2Forward = Vector2(m4SpriteMat.getRow(1).getfX(), m4SpriteMat.getRow(1).getfY());//Sets the forward vector.

			m_bBulletArray[i].v2Pos += (m_bBulletArray[i].v2Pos * (m_bBulletArray[i].fVelocity * a_fDeltaTime));//Add forward and velocity to the position.

			UG::MoveSprite(m_bBulletArray[i].iSpriteID, m_bBulletArray[i].v2Pos.getfX(), (m_bBulletArray[i].v2Pos.getfY()));//Moves the sprite to the correct location on the screen.


			if (m_bBulletArray[i].fLifeTimer <= 0)
			{
				UG::StopDrawingSprite(m_bBulletArray[i].iSpriteID);//Stops drawing the current bullet.

				m_bBulletArray[i].active = false;
			}
		}
	}
}
