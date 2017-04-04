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

Tank::Tank(const Vector2 a_c_v2Position, unsigned int a_c_uiUp, unsigned int a_c_uiDown, unsigned int a_c_uiLeft, unsigned int a_c_uiRight, unsigned int a_c_uiRotateRight, unsigned int a_c_uiRotateLeft, int a_c_iScreenWidth, int a_c_iScreenHeight)
{
	//Create a sprite for our tank's base
	sTank = new Sprite("./images/tanks.png", 66, 72, a_c_v2Position, Vector4(0.058f, 0.536f, 0.442f, 0.964f));
	sTank->SetPosition(Vector2(a_c_iScreenWidth * 0.5f, a_c_iScreenHeight * 0.5f));
	sTank->MarkForDraw();
	sTank->SetLayer(0);

	//Create a sprite for our tank's turret
	sTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(a_c_v2Position.getfX(), a_c_v2Position.getfY() - 0.21f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));
	sTurret->SetParent(sTank);
	sTurret->MarkForDraw();
	sTurret->SetLayer(1);

	bPlayer = true;

	uiUp = a_c_uiUp;
	uiDown = a_c_uiDown;
	uiLeft = a_c_uiLeft;
	uiRight = a_c_uiRight;
	uiRotateLeft = a_c_uiRotateLeft;
	uiRotateRight = a_c_uiRotateRight;
}

//\===========================================================================================
//\ Enemy Constructor 
//\===========================================================================================

Tank::Tank(const Vector2 a_c_v2Position, int a_c_iScreenWidth, int a_c_iScreenHeight)
{
	//Create a sprite for our tank's base
	sTank = new Sprite("./images/tanks.png", 66, 72, a_c_v2Position, Vector4(0.058f, 0.536f, 0.442f, 0.964f));
	sTank->SetPosition(Vector2(a_c_iScreenWidth * 0.5f, a_c_iScreenHeight * 0.5f));
	sTank->MarkForDraw();
	sTank->SetLayer(0);

	//Create a sprite for our tank's turret
	sTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(a_c_v2Position.getfX()-19, a_c_v2Position.getfY()-32), Vector4(0.622f, 0.607f, 0.843f, 0.988f));
	sTurret->SetParent(sTank);
	sTurret->MarkForDraw();
	sTurret->SetLayer(1);
}

//\===========================================================================================
//\ Tank Movement 
//\===========================================================================================

void Tank::tankMovement(float a_fDeltaTime)
{

	float dt = a_fDeltaTime;
	sTank->Update();
	sTurret->Update();
	float xPos = 0; float yPos = 0;

	//Create a vector to store our movement
	Vector3 movementVector = Vector3::UNIT_Y;
	//We're going to be treating moving forward and backward as traversing along the sprite's Y axis
	//If our sprite was rotated 90 degrees on the sprite sheet then we would treat that direction as forward.
	float fAccelleration = 0.f;

	if (bPlayer = true)
	{
		if (UG::IsKeyDown(uiUp))
		{
			fAccelleration += 1.f;
			fDrag = 0.f;
		}

		if (UG::IsKeyDown(uiDown))
		{
			fAccelleration -= 0.75f;
			fDrag = 0.f;
		}

		if (!UG::IsKeyDown(uiDown) && !UG::IsKeyDown(uiUp))
			fDrag = 0.08f;

		//Tank Rotation
		if (UG::IsKeyDown(uiLeft))
			sTank->RotateZ(0.5f);

		if (UG::IsKeyDown(uiRight))
			sTank->RotateZ(-0.5f);

		//Turret Rotation
		if (UG::IsKeyDown(uiRotateLeft))
			sTurret->RotateZ(0.85f);

		if (UG::IsKeyDown(uiRotateRight))
			sTurret->RotateZ(-0.85f);
	}

	else
	{
		//AI goes here
	}

	fCurrentVelocity += fAccelleration * dt;
	fCurrentVelocity -= fCurrentVelocity * fDrag;

	if (fabsf(fCurrentVelocity) > fMaxVelocity)
	{
		fCurrentVelocity = fMaxVelocity * sinf(fCurrentVelocity);
	}

	if (fabsf(fCurrentVelocity) > E)
	{
		movementVector *= fCurrentVelocity;
		sTank->MoveSprite(movementVector);
	}

}