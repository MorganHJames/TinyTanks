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
	: normalBullets(4, "./images/tanks.png", 1)//Creates the normal bullets.
{
	m_sTank = new Sprite(a_c_cFilename, 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));//Creates a sprite for the tanks base.

	m_sTank->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.
	
	m_sTank->setLayer(10);//Sets the layer of the tank so that it is rendered as far back as possible.

	m_sTurret = new Sprite(a_c_cFilename, 38, 64, Vector2(0.5f, 0.25f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));//Creates a sprite for the tanks turret.
	
	m_sTurret->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.
	
	m_sTurret->setLayer(11);//Sets the layer of tank turret so that it is rendered on top of the base.

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
	: normalBullets(4, "./images/tanks.png", 1)//Creates the normal bullets.
{
	m_sTank = new Sprite("./images/tanks.png", 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));//Creates a sprite for the tanks base.

	m_sTank->setPosition(a_c_v2Position);//Sets the position of the tanks base to be equal to the argument passed in.

	m_sTank->setLayer(0);//Sets the layer of the tank so that it is rendered as far back as possible.

	m_sTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(0.5f, 0.25f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));//Creates a sprite for the tanks turret.

	m_sTurret->setParent(m_sTank);//Sets the parent of the turret to be the base of the tank.

	m_sTurret->setLayer(2);//Sets the layer of tank turret so that it is rendered on top of the base.
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
	normalBullets.update(a_fDeltaTime);//Updates the bullets.

	m_sTank->update();//Updates the base of the tank.

	m_sTurret->update();//Updates the turret of the tank.

	//\===========================================================================================
	//\ Player Movement 
	//\===========================================================================================

	float fAccelleration = 0.f;//A float to hold the tanks acceleration.

	if (m_bPlayer = true)//If the tank is a player.
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

	if (fabsf(m_fCurrentVelocity) > 125.0f)//If the current velocity is higher than 0.25f.
	{
		v2Position += (v2Forward * (m_fCurrentVelocity * a_fDeltaTime));//Add forward and velocity to the position.

		m_sTank->setPosition(v2Position);//Sets the position of the tank to be the new position vector.

		m_sTurret->setPosition(v2Position);//Sets the position of the tank to be the new position vector.
	}
}

