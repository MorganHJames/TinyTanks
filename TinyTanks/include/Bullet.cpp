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

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Bullet::Bullet(const int a_c_iMaxBullets, char* a_c_cFileLocation, float a_c_fShotDelay)//The default constructor for the sprite.
{
	m_iMaxBullets = a_c_iMaxBullets;

	m_fShotDelay = a_c_fShotDelay;

	m_bBasicAmmoArray = new BasicAmmo[m_iMaxBullets];//Sets the array to hold only the max amount of bullets.

	for (int i = 0; i < m_iMaxBullets; ++i)//For each bullet.
	{
		m_bBasicAmmoArray[i].sBasicAmmo = new Sprite(a_c_cFileLocation, (float) m_iSpriteWidth, (float) m_iSpriteHeight, Vector2(0.5f, 0.5f), Vector4(0.0f, 0.0f, 1.0f, 1.0f));//Creates a sprite for the bullet.

		m_bBasicAmmoArray[i].sBasicAmmo->setWidth((float) m_iSpriteWidth);//Sets the width of the sprite to be the same as the member variable.

		m_bBasicAmmoArray[i].sBasicAmmo->setHeight((float) m_iSpriteHeight);//Sets the height of the sprite to be the same as the member variable.

		UG::SetSpriteLayer(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID(), 4);//Sets the current sprite layer to be under the turret.
	}
}

//\===========================================================================================
//\ Shoot Function 
//\===========================================================================================

void Bullet::shoot(const Vector2 a_c_v2Pos,  Vector4 a_c_v4Rotation)//A function to shoot bullets from the end of a turret.
{
	for (int i = 0; i < m_iMaxBullets; ++i)//For each bullet.
	{
		if (m_bBasicAmmoArray[i].active == false && m_fShotDelayTimer <= 0)//If the bullet is not active and the shot timer is less than or equal to zero.
		{
			float fSpriteMat[16];//Creates an array of 16 floats.

			UG::GetSpriteMatrix(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID(), fSpriteMat);//Gets the sprite matrix of the turret and sets it in the array.

			fSpriteMat[0] = a_c_v4Rotation.getfX();//Sets the float array's first element to be equal to the rotated matrix's counterpart.

			fSpriteMat[1] = a_c_v4Rotation.getfY();//Sets the float array's second element to be equal to the rotated matrix's counterpart.

			fSpriteMat[4] = a_c_v4Rotation.getfZ();//Sets the float array's fifth element to be equal to the rotated matrix's counterpart.

			fSpriteMat[5] = a_c_v4Rotation.getfW();//Sets the float array's sixth element to be equal to the rotated matrix's counterpart.

			UG::SetSpriteMatrix(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID(), fSpriteMat);//Set's the sprite matrix to be equal to the rotated version.

			m_bBasicAmmoArray[i].v2Forward = Vector2(a_c_v4Rotation.getfZ(), a_c_v4Rotation.getfW());//Sets the forward of the bullet.

			m_bBasicAmmoArray[i].v2PosOffSet = a_c_v2Pos + m_bBasicAmmoArray[i].v2Forward * m_fOffSet;//Sets the initial position of the bullet.
			
			m_bBasicAmmoArray[i].active = true;//Sets the bullet to be active.

			m_bBasicAmmoArray[i].sBasicAmmo->markForDraw();//Draws the current bullet.

			m_bBasicAmmoArray[i].fLifeTimer = m_fLifeTime;//Start the life timer for the bullet.

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
		if (m_bBasicAmmoArray[i].active == true)//if the bullet is active.
		{
			m_bBasicAmmoArray[i].fLifeTimer -= a_fDeltaTime;//Decrease the lifetime of the bullet.

			m_bBasicAmmoArray[i].sBasicAmmo->setVelocity(m_bBasicAmmoArray[i].v2Forward * m_bBasicAmmoArray[i].fVelocity * a_fDeltaTime);

			m_bBasicAmmoArray[i].v2PosOffSet += m_bBasicAmmoArray[i].sBasicAmmo->getVelocity();//Add forward and velocity to the position.

			m_bBasicAmmoArray[i].sBasicAmmo->setPosition(Vector2(m_bBasicAmmoArray[i].v2PosOffSet.getfX(), m_bBasicAmmoArray[i].v2PosOffSet.getfY()));

			UG::MoveSprite(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID(), m_bBasicAmmoArray[i].v2PosOffSet.getfX(), (m_bBasicAmmoArray[i].v2PosOffSet.getfY()));//Moves the sprite to the correct location on the screen.

			if (m_bBasicAmmoArray[i].fLifeTimer <= 0)//If the life timer is less than or equal to zero.
			{
				UG::StopDrawingSprite(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID());//Stops drawing the current bullet.

				m_bBasicAmmoArray[i].active = false;//Set the bullet to be false.
			}
		}
		else
		{
			UG::StopDrawingSprite(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID());//Stops drawing the current bullet.
			m_bBasicAmmoArray[i].sBasicAmmo->setPosition(Vector2(-100, -100));//Moves the bullets so they can respawn.
		}
	}
}

//\===========================================================================================
//\ Get Bullet Array 
//\===========================================================================================

BasicAmmo* Bullet::getBasicBulletArray()//Returns the bullet array.
{
	return m_bBasicAmmoArray;//Returns the bullet array.
}

//\===========================================================================================
//\ Set Shot  
//\===========================================================================================

void Bullet::setShot(float a_fShotDelay, float a_fShotVelocity, float a_fShotLifeTime)//Changes how fast the bullet moves, and is able to be fired again.
{
	m_fShotDelay = a_fShotDelay;//Sets the shot delay to be equal to the passed in argument.

	m_fLifeTime = a_fShotLifeTime;//Sets the shot life time to be equal to the passed in argument.

	for (int i = 0; i < m_iMaxBullets; ++i)//For each bullet.
	{
		m_bBasicAmmoArray[i].fVelocity = a_fShotVelocity;//Sets the shot velocity to be equal to the passed in argument.
	}
}

//\===========================================================================================
//\ Stop Drawing  
//\===========================================================================================

void Bullet::stopDrawing()//Stops drawing the bullets.
{
	for (int i = 0; i < m_iMaxBullets; ++i)//For each bullet.
	{
		UG::StopDrawingSprite(m_bBasicAmmoArray[i].sBasicAmmo->getSpriteID());//Stops drawing the current bullet.
	}
}