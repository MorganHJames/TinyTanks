//\===========================================================================================
//\ File: Tank.cpp
//\ Author: Morgan James
//\ Date Created: 18/03/2017
//\ Brief: Contains the function information for the class contained in Tank.h.
//\==========================================================================================

#include "Tank.h"
#include "UGFW.h"
#include "MathUtil.h"

//\===========================================================================================
//\ Player Constructor 
//\===========================================================================================

Tank::Tank(const Vector2 a_c_v2Position, bool a_c_bMouse, unsigned int a_c_uiUp, unsigned int a_c_uiDown, unsigned int a_c_uiLeft, unsigned int a_c_uiRight, unsigned int a_c_uiRotateRight, unsigned int a_c_uiRotateLeft, unsigned int a_c_uiFire, char* a_c_cFilename)//A constructor for the tank that takes in the in position of where you want to the tank to be and the controls for tank.
	: normalBullets(4, "./images/bullet.png", 1)//Creates the normal bullets.
{
	m_sTank = new Sprite(a_c_cFilename, m_fTankWidth, m_fTankHeight, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));//Creates a sprite for the tanks base.

	m_sTank->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.
	
	m_sTank->setLayer(10);//Sets the layer of the tank so that it is rendered as far back as possible.

	m_sTank->setWidth(m_fTankWidth);//Sets the width of the sprite to be the same as the member variable.

	m_sTank->setHeight(m_fTankHeight);//Sets the height of the sprite to be the same as the member variable.

	m_sTurret = new Sprite(a_c_cFilename, m_fTurretWidth, m_fTurretHeight, Vector2(0.5f, 0.25f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));//Creates a sprite for the tanks turret.
	
	m_sTurret->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.
	
	m_sTurret->setLayer(11);//Sets the layer of tank turret so that it is rendered on top of the base.

	m_sTurret->setWidth(m_fTankWidth);//Sets the width of the sprite to be the same as the member variable.

	m_sTurret->setHeight(m_fTankWidth);//Sets the height of the sprite to be the same as the member variable.

	m_bPlayer = true;//Sets the player boolean to true as if the controls are defined the tank must be a player.

	m_bMouse = a_c_bMouse;

	m_uiUp = a_c_uiUp;//Assigns the up control to be equal to the up control passed in.
	
	m_uiDown = a_c_uiDown;//Assigns the down control to be equal to the down control passed in.
	
	m_uiLeft = a_c_uiLeft;//Assigns the left control to be equal to the left control passed in.
	
	m_uiRight = a_c_uiRight;//Assigns the right control to be equal to the right control passed in.
	
	m_uiRotateLeft = a_c_uiRotateLeft;//Assigns the rotate left control to be equal to the rotate left control passed in.
	
	m_uiRotateRight = a_c_uiRotateRight;//Assigns the rotate right control to be equal to the rotate right control passed in. 

	m_uiFire = a_c_uiFire;//Assigns the fire control to be equal to the fire control passed in.
}

//\===========================================================================================
//\ Enemy Constructor 
//\===========================================================================================

Tank::Tank(const Vector2 a_c_v2Position)//A constructor for the tank that takes in the in position of where you want to the tank to be.
	: normalBullets(4, "./images/bullet.png", 1)//Creates the normal bullets.
{
	m_sTank = new Sprite("./images/tanks2.png", m_fTankWidth, m_fTankHeight, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));//Creates a sprite for the tanks base.

	m_sTank->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.

	m_sTank->setLayer(10);//Sets the layer of the tank so that it is rendered as far back as possible.

	m_sTank->setWidth(m_fTankWidth);//Sets the width of the sprite to be the same as the member variable.

	m_sTank->setHeight(m_fTankHeight);//Sets the height of the sprite to be the same as the member variable.

	m_sTurret = new Sprite("./images/tanks2.png", m_fTurretWidth, m_fTurretHeight, Vector2(0.5f, 0.25f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));//Creates a sprite for the tanks turret.

	m_sTurret->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.

	m_sTurret->setLayer(11);//Sets the layer of tank turret so that it is rendered on top of the base.

	m_sTurret->setWidth(m_fTurretWidth);//Sets the width of the sprite to be the same as the member variable.

	m_sTurret->setHeight(m_fTurretHeight);//Sets the height of the sprite to be the same as the member variable.
}

//\===========================================================================================
//\ Draw Functions
//\===========================================================================================

void Tank::markForDraw()//A function to start drawing the parts of the tank.
{
	m_sTank->markForDraw();//Starts the drawing of the tank base.
	
	m_sTurret->markForDraw();//Starts the drawing of the tanks turret.
	
}

void Tank::stopDrawing()//A function to stop drawing the parts of the tank.
{
	m_sTank->stopDrawing();//Stops the drawing of the tank base.

	m_sTurret->stopDrawing();//Stops the drawing of the tanks turret.
}

//\===========================================================================================
//\ Tank Logic 
//\===========================================================================================

void Tank::tankLogic(float a_fDeltaTime, double a_dMousePosX, double a_dMousePosY)//A function that should be put in the update area to move the tank.
{
	m_fUpgradeTimer -= a_fDeltaTime;//Decreases the upgrade timer.

	if (m_fUpgradeTimer <= 0)
	{
		m_iCurrentUpgrade = 0;
	}

	normalBullets.update(a_fDeltaTime);//Updates the bullets.

	m_sTank->update();//Updates the base of the tank.

	m_sTurret->update();//Updates the turret of the tank.

	//\===========================================================================================
	//\ Player Movement 
	//\===========================================================================================

	float fAccelleration = 0.f;//A float to hold the tanks acceleration.

	if (m_bPlayer == true)//If the tank is a player.
	{
		if (UG::IsKeyDown(m_uiUp))//If the up key for the tank is pressed.
		{
			fAccelleration += 2.f;//Increase the acceleration of the tank.

			m_fDrag = 0.f;//Sets the drag of the tank to zero.
		}

		if (UG::IsKeyDown(m_uiDown))//If the down key for the tank is pressed.
		{
			fAccelleration -= 1.5f;//Decrease the acceleration.

			m_fDrag = 0.f;//Sets the drag of the tank to zero.
		}

		if (!UG::IsKeyDown(m_uiDown) && !UG::IsKeyDown(m_uiUp))//If neither the up or down key of the tank is pressed.
			m_fDrag = 0.01f;//Set the drag of the tank to 0.1f.

		//\===========================================================================================
		//\ Tank Rotation  
		//\===========================================================================================

		if (UG::IsKeyDown(m_uiLeft))//If the left button of the tank is pressed.
			m_sTank->rotateZ(-0.5f);//Rotate the tank counter clockwise.

		if (UG::IsKeyDown(m_uiRight))//If the right button of the tank is pressed.
			m_sTank->rotateZ(0.5f);//Rotate the tank clockwise.

		//\===========================================================================================
		//\ Campaign Turret Rotation  
		//\===========================================================================================

		if (m_bMouse == true)//If the mouse boolean is true then execute the following code.
		{
			float fSpriteMat[16];//Creates an array of 16 floats.

			UG::GetSpriteMatrix(m_sTurret->getSpriteID(), fSpriteMat);//Gets the sprite matrix of the turret and sets it in the array.

			Matrix4x4 m4SpriteMat(fSpriteMat);//Creates a 4x4 matrix from the float array.

			Vector2 v2TurretPos(m4SpriteMat.getiMatrix(12), m4SpriteMat.getiMatrix(13));//Gets the turrets current position.

			Vector2 v2MousePos((float)a_dMousePosX, (float)a_dMousePosY);//Gets the mouse current position.

			float rotation = -(atan2(v2TurretPos.getfX() - v2MousePos.getfX(), v2TurretPos.getfY() - v2MousePos.getfY()) * 180 / PI) + 180;//Gets the rotation between the two points.

			m4SpriteMat.rotateZ(rotation);//Rotates the 4x4 matrix by the angle difference.

			fSpriteMat[0] = m4SpriteMat.getiMatrix(0);//Sets the float array's first element to be equal to the rotated matrix's counterpart.

			fSpriteMat[1] = m4SpriteMat.getiMatrix(1);//Sets the float array's second element to be equal to the rotated matrix's counterpart.

			fSpriteMat[4] = m4SpriteMat.getiMatrix(4);//Sets the float array's fifth element to be equal to the rotated matrix's counterpart.

			fSpriteMat[5] = m4SpriteMat.getiMatrix(5);//Sets the float array's sixth element to be equal to the rotated matrix's counterpart.

			UG::SetSpriteMatrix(m_sTurret->getSpriteID(), fSpriteMat);//Set's the sprite matrix to be equal to the rotated version.
		
	        //\===========================================================================================
	        //\ Campaign Shooting
	        //\===========================================================================================
			
	        if (UG::GetMouseButtonDown(m_bMousePressed) == true || UG::IsKeyDown(m_uiFire))//If the mouse controls are true and the mouse is being pressed or the fire key is being pressed.
	        {
	             float fSpriteTurretMat[16];//Creates an array of 16 floats.
		        
			     UG::GetSpriteMatrix(m_sTurret->getSpriteID(), fSpriteTurretMat);//Gets the sprite matrix of the turret and sets it in the array.
		        
			     Matrix4x4 m4SpriteTurretMat(fSpriteTurretMat);//Creates a 4x4 matrix from the float array.

				 Vector2 v2TurretPosition = Vector2(m4SpriteTurretMat.getRow(3).getfX(), m4SpriteTurretMat.getRow(3).getfY());//Sets the position vector.

				 Vector4 v4TurretRotation = Vector4(m4SpriteTurretMat.getRow(0).getfX(), m4SpriteTurretMat.getRow(0).getfY(), m4SpriteTurretMat.getRow(1).getfX(), m4SpriteTurretMat.getRow(1).getfY());//Sets the position vector.

	             normalBullets.shoot(v2TurretPosition, v4TurretRotation);//Shoots a bullets.
	        }
		}
		else
		{
			//\===========================================================================================
			//\ Versus Turret Rotation  
			//\===========================================================================================
			if (UG::IsKeyDown(m_uiRotateRight))//If the right rotation button of the tank is being pressed.
				m_sTurret->rotateZ(0.85f);//Rotate the turret clockwise.

			if (UG::IsKeyDown(m_uiRotateLeft))//If the left rotation button of the tank is being pressed.
				m_sTurret->rotateZ(-0.85f);//Rotate the turret counter clockwise.

			//\===========================================================================================
			//\ Versus Shooting
			//\===========================================================================================

			if (UG::IsKeyDown(m_uiFire))//If the fire key is being pressed.
			{
				float fSpriteTurretMat[16];//Creates an array of 16 floats.

				UG::GetSpriteMatrix(m_sTurret->getSpriteID(), fSpriteTurretMat);//Gets the sprite matrix of the turret and sets it in the array.

				Matrix4x4 m4SpriteTurretMat(fSpriteTurretMat);//Creates a 4x4 matrix from the float array.

				Vector2 v2TurretPosition = Vector2(m4SpriteTurretMat.getRow(3).getfX(), m4SpriteTurretMat.getRow(3).getfY());//Sets the position vector.

				Vector4 v4TurretRotation = Vector4(m4SpriteTurretMat.getRow(0).getfX(), m4SpriteTurretMat.getRow(0).getfY(), m4SpriteTurretMat.getRow(1).getfX(), m4SpriteTurretMat.getRow(1).getfY());//Sets the position vector.

				normalBullets.shoot(v2TurretPosition, v4TurretRotation);//Shoots a bullets.
			}
		}
	}

	//\===========================================================================================
	//\ Enemy AI  
	//\===========================================================================================

	else//If the tank is not a player
	{
		//Enemy AI goes here
	}

	//\===========================================================================================
	//\ Tank Movement 
	//\===========================================================================================

	if (m_iCurrentUpgrade == 1)//If the current upgrade type is 1.
	{
		m_fMaxVelocity = 400.f;//Increase the max forward velocity.

		m_fMaxNegativeVelocity = -300.0f;//Decrease the max backwards velocity.
	}
	else if (m_iCurrentUpgrade == 2)
	{
		normalBullets.setShot(0.5f,500.0f,2.5f);
	}
	else if (m_iCurrentUpgrade == 3)//If the current upgrade is 3.
	{
		m_fMaxVelocity = 100.0f;//Decrease the max forward velocity.

		m_fMaxNegativeVelocity = -75.0f;//Increase the max backwards velocity.
	}
	else if (m_iCurrentUpgrade == 4)
	{
		normalBullets.setShot(1.5f, 125.0f, 7.5f);
	}
	else
	{
		m_fMaxVelocity = 200.0f;
		m_fMaxNegativeVelocity = -150.0f;
		normalBullets.setShot(1.0f, 250.0f, 5.0f);
	}

	m_fCurrentVelocity += fAccelleration;//Increases the current velocity by the accelerations multiplied by the delta time.

	m_fCurrentVelocity -= m_fCurrentVelocity * m_fDrag;//Decreases the current velocity by the current velocity multiplied by the drag.

	if (m_fCurrentVelocity > m_fMaxVelocity)//If the current velocity is above the max velocity.
	{
		m_fCurrentVelocity = m_fMaxVelocity;//Set the current velocity to the max velocity.
	}

	if (m_fCurrentVelocity < m_fMaxNegativeVelocity)//If the current velocity is less than the max  negative velocity.
	{
		m_fCurrentVelocity = m_fMaxNegativeVelocity;//Set the current velocity to the max velocity.
	}

	Matrix3x3 m3WorldTransform;//Creates a matrix3x3 called world transform to hold the world transformation.

	m_sTank->getWorldTransform(m3WorldTransform);//Sets the newly created matrix to the tanks world transformation matrix.

	Vector2 v2Position = Vector2(m3WorldTransform.getRow(2).getfX(), m3WorldTransform.getRow(2).getfY());//Sets the position vector.

	Vector2 v2Forward = Vector2(m3WorldTransform.getRow(1).getfX(), m3WorldTransform.getRow(1).getfY());//Sets the forward vector.

	if (fabsf(m_fCurrentVelocity) > 74.0f)//If the current velocity is higher than 0.25f.
	{
		m_sTank->setVelocity(v2Forward * (m_fCurrentVelocity * a_fDeltaTime));

		v2Position += m_sTank->getVelocity();//Add forward and velocity to the position.

		m_sTank->setPosition(v2Position);//Sets the position of the tank to be the new position vector.

		m_sTurret->setPosition(v2Position);//Sets the position of the tank to be the new position vector.
	}
}

//\===========================================================================================
//\ Tank Sprite Get 
//\===========================================================================================

Sprite* Tank::getSprite()//A function to return the sprite.
{
	return m_sTank;//Returns the tank sprite.
}

//\===========================================================================================
//\ Get Bullet Array 
//\===========================================================================================

BasicAmmo* Tank::getBasicBulletArray()//Returns the bullet array.
{
	return normalBullets.getBasicBulletArray();//Returns the bullet array.
}

//\===========================================================================================
//\ Set Alive 
//\===========================================================================================

bool Tank::getAlive()//Returns the status of the tank.
{
	return m_bAlive;//Returns whether or not the tank is alive.
}	

//\===========================================================================================
//\ Set Alive 
//\===========================================================================================

void Tank::setAlive(bool a_bStatus)//Returns the status of the tank.
{
	m_bAlive = a_bStatus;
}

//\===========================================================================================
//\ Set Upgrade 
//\===========================================================================================

void Tank::setUpgrade(int a_iUpgrateType)//Sets the upgrade for the tank.
{
	m_iCurrentUpgrade = a_iUpgrateType;//Sets the current upgrade to the one passed in.

	m_fUpgradeTimer = m_fUpgradeTime;//Sets the upgrade timer to 5.
}