//\===========================================================================================
//\ File: Tank.h
//\ Author: Morgan James
//\ Date Created: 18/03/2017
//\ Brief: Contains the Tank class declarations.
//\===========================================================================================

#ifndef _TANK_H_
#define _TANK_H_

#include "Sprite.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Tank
//\ Brief: A class that uses the sprite class to create the tank player or the tank enemies.
//\===========================================================================================

class Tank
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

	float fCurrentVelocity = 0.f;
	float fMaxVelocity = 10.f;
	float fDrag = 0.03f;
	bool bPlayer = true;
	//Controls
	unsigned int uiUp, uiDown, uiLeft, uiRight, uiRotateRight, uiRotateLeft = 0;
	//Default Sprites
	Sprite* sTank = new Sprite("./images/tanks.png", 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));
	Sprite* sTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(0.5f, 0.5f - 0.21f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));

public:
	//\===========================================================================================
	//\ Player Constructor 
	//\===========================================================================================

	Tank(const Vector2 a_c_v2Position, unsigned int a_c_uiUp, unsigned int a_c_uiDown, unsigned int a_c_uiLeft, unsigned int a_c_uiRight, unsigned int a_c_uiRotateRight, unsigned int a_c_uiRotateLeft, int a_c_iScreenWidth, int a_c_iScreenHeight);

	//\===========================================================================================
	//\ Enemy Constructor 
	//\===========================================================================================

	Tank(const Vector2 a_c_v2Position, int a_c_iScreenWidth, int a_c_iScreenHeight);

	//\===========================================================================================
	//\ Tank Movement 
	//\===========================================================================================

	void tankMovement(float a_fDeltaTime);

};

#endif