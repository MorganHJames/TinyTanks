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
	Sprite* sTank;
	Sprite* sTurret;

public:
	//\===========================================================================================
	//\ Player Constructor 
	//\===========================================================================================

	Tank(const Vector2 a_c_v2Position, unsigned int a_c_uiUp, unsigned int a_c_uiDown, unsigned int a_c_uiLeft, unsigned int a_c_uiRight, unsigned int a_c_uiRotateRight, unsigned int a_c_uiRotateLeft);

	//\===========================================================================================
	//\ Enemy Constructor 
	//\===========================================================================================

	Tank(const Vector2 a_c_v2Position);

	//\===========================================================================================
	//\ Tank Movement 
	//\===========================================================================================

	void tankMovement(float a_fDeltaTime);

};

#endif