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

	float m_fCurrentVelocity = 0.f;//A float that will contain the current velocity of the tank.
	
	float m_fMaxVelocity = 0.75f;//The maximum velocity that the tank may travel at.

	float m_fMaxNegativeVelocity = -0.75f;//The maximum velocity that the tank may travel at.
	
	float m_fDrag = 0.03f;//The amount of drag applied to the tank whilst moving.
	
	bool m_bPlayer = true;//A boolean value indicating whether or not the tank is a player or an AI.
	
	unsigned int m_uiUp, m_uiDown, m_uiLeft, m_uiRight, m_uiRotateRight, m_uiRotateLeft = 0;//The controls for the tank movement
	
	Sprite* m_sTank;//The default sprite for the tank.
	
	Sprite* m_sTurret;//The default sprite for the turret.

public:
	//\===========================================================================================
	//\ Player Constructor 
	//\===========================================================================================

	Tank(const Vector2 a_c_v2Position, unsigned int a_c_uiUp, unsigned int a_c_uiDown, unsigned int a_c_uiLeft, unsigned int a_c_uiRight, unsigned int a_c_uiRotateRight, unsigned int a_c_uiRotateLeft);//A constructor for the tank that takes in the in position of where you want to the tank to be and the controls for tank.

	//\===========================================================================================
	//\ Enemy Constructor 
	//\===========================================================================================

	Tank(const Vector2 a_c_v2Position);//A constructor for the tank that takes in the in position of where you want to the tank to be.

	//\===========================================================================================
	//\ Draw Functions
	//\===========================================================================================

	void markforDraw();//A function to start drawing the parts of the tank.

	void stopDrawing();//A function to stop drawing the parts of the tank.

	//\===========================================================================================
	//\ Tank Movement 
	//\===========================================================================================

	void tankMovement(float a_fDeltaTime);//A function that should be put in the update area to move the tank.

};

#endif