//\===========================================================================================
//\ File: Button.h
//\ Author: Morgan James
//\ Date Created: 17/03/2017
//\ Brief: Contains the button class declarations.
//\===========================================================================================

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Sprite.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Button
//\ Brief: A class to create intractable buttons from an image containing 3 buttons states(unpressed, hovered and pressed) from left to right.
//\===========================================================================================

class Button
{
private:
	unsigned int m_uiKey = 0;//The key that will activate the button.

	char* m_cFilename;//The location of the sprite image.

	Sprite* m_sButton;//The default sprite for the button.

	float m_fButtonWidth = 0;//A float to hold the button's width.

	float m_fButtonHeight = 0;//A float to hold the button's height.

	Vector2 m_v2Position;//A vector 2 to hold position.

	bool m_bCanBePressed = true;//A boolean to indicate if the button may be pressed or not.

	bool m_bBeingPressed = false;//A boolean to indicated whether or not the user is pressing down on the button.

	bool m_bMousePressed = false;//If the mouse is pressed this well be true.

	bool m_bMouseReleased = false;//If the mouse is not being pressed this will be false.

public:
	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Button(const char* a_c_cFilename, Vector2 a_c_v2Position, float a_c_fWidth, float a_c_fHeight, unsigned int a_c_uiKey);//The default constructor for a button.

	//\===========================================================================================
	//\ Destructor 
	//\===========================================================================================

	~Button();//The default destructor for a button.

	//\===========================================================================================
	//\ Button Logic 
	//\===========================================================================================

	bool buttonLogic(double a_dMousePosX, double a_dMousePosY);//Will return true if the button is activated.
	
	//\===========================================================================================
	//\ Draw Functions
	//\===========================================================================================

	void markForDraw();//A function to draw the button.

	void stopDrawing();//A function to stop drawing the button.			
};

#endif
