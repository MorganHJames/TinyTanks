//\===========================================================================================
//\ File: Tank.cpp
//\ Author: Morgan James
//\ Date Created: 18/03/2017
//\ Brief: Contains the function information for the class contained in Tank.h.
//\===========================================================================================

#include "Tank.h"
#include "UGFW.h"
#include "MathUtil.h"

//\===========================================================================================
//\ Player Constructor 
//\===========================================================================================

Tank::Tank(const Vector2 a_c_v2Position, unsigned int a_c_uiUp, unsigned int a_c_uiDown, unsigned int a_c_uiLeft, unsigned int a_c_uiRight, unsigned int a_c_uiRotateRight, unsigned int a_c_uiRotateLeft)
{
	//Create a sprite for our tank's base
	m_sTank = new Sprite("./images/tanks.png", 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));
	
	m_sTank->setPosition(a_c_v2Position);
	
	m_sTank->setLayer(0);

	//Create a sprite for our tank's turret
	m_sTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(0.5f, 0.25f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));
	
	m_sTurret->setParent(m_sTank);
	
	m_sTurret->setLayer(1);

	m_bPlayer = true;

	m_uiUp = a_c_uiUp;
	
	m_uiDown = a_c_uiDown;
	
	m_uiLeft = a_c_uiLeft;
	
	m_uiRight = a_c_uiRight;
	
	m_uiRotateLeft = a_c_uiRotateLeft;
	
	m_uiRotateRight = a_c_uiRotateRight;
}

//\===========================================================================================
//\ Enemy Constructor 
//\===========================================================================================

Tank::Tank(const Vector2 a_c_v2Position)
{
	//Create a sprite for our tank's base
	m_sTank = new Sprite("./images/tanks.png", 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));
	
	m_sTank->setPosition(a_c_v2Position);
	
	m_sTank->setLayer(0);

	//Create a sprite for our tank's turret
	m_sTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(0.5f, 0.25f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));

	m_sTurret->setParent(m_sTank);

	m_sTurret->setLayer(1);
}

//\===========================================================================================
//\ Draw Functions
//\===========================================================================================

void Tank::stopDrawing()
{
	m_sTank->stopDrawing();
	
	m_sTurret->stopDrawing();
}

void Tank::markforDraw()
{
	m_sTank->markForDraw();
	
	m_sTurret->markForDraw();
}
//\===========================================================================================
//\ Tank Movement 
//\===========================================================================================

void Tank::tankMovement(float a_fDeltaTime)
{
	m_sTank->update();
	
	m_sTurret->update();
	
	float xPos = 0; float yPos = 0;

	
	//We're going to be treating moving forward and backward as traversing along the sprite's Y axis
	//If our sprite was rotated 90 degrees on the sprite sheet then we would treat that direction as forward.
	float fAccelleration = 0.f;

	if (m_bPlayer = true)
	{
		if (UG::IsKeyDown(m_uiUp))
		{
			fAccelleration += 1.f;
	
			m_fDrag = 0.f;
		}

		if (UG::IsKeyDown(m_uiDown))
		{
			fAccelleration -= 0.75f;
			
			m_fDrag = 0.f;
		}

		if (!UG::IsKeyDown(m_uiDown) && !UG::IsKeyDown(m_uiUp))
			m_fDrag = 0.08f;

		//Tank Rotation
		if (UG::IsKeyDown(m_uiLeft))
			m_sTank->rotateZ(-0.5f);

		if (UG::IsKeyDown(m_uiRight))
			m_sTank->rotateZ(0.5f);

		//Turret Rotation
		if (UG::IsKeyDown(m_uiRotateLeft))
			m_sTurret->rotateZ(0.85f);

		if (UG::IsKeyDown(m_uiRotateRight))
			m_sTurret->rotateZ(-0.85f);
	}

	else
	{
		//AI goes here
	}

	m_fCurrentVelocity += fAccelleration * a_fDeltaTime;

	m_fCurrentVelocity -= m_fCurrentVelocity * m_fDrag;

	//max speed.

	if (fabsf(m_fCurrentVelocity) > m_fMaxVelocity)
	{
		m_fCurrentVelocity = m_fMaxVelocity ;
	}
	// Get tank Matrix
	Matrix3x3 mWorldTransform;
	
	m_sTank->getWorldTransform(mWorldTransform);

	// Get the position and forward vectors
	Vector2 v2XPosition = Vector2(mWorldTransform.getRow(2).getfX(), mWorldTransform.getRow(2).getfY());
	
	Vector2 v2XForward = Vector2(mWorldTransform.getRow(1).getfX(), mWorldTransform.getRow(1).getfY());


	if (fabsf(m_fCurrentVelocity) > 0.25f)
	{
		// Add forward and velocity to position
		v2XPosition += (v2XForward * m_fCurrentVelocity);
	
		m_sTank->setPosition(v2XPosition);
	}


}