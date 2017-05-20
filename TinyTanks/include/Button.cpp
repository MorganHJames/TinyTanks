//\===========================================================================================
//\ File: Button.cpp
//\ Author: Morgan James
//\ Date Created: 20/05/2017
//\ Brief: Contains the function information for the class contained in Button.h.
//\==========================================================================================

#include "Button.h"
#include "UGFW.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Button::Button(const char* a_c_cFilename, Vector2 a_c_v2Position, float a_c_fWidth, float a_c_fHeight, unsigned int a_c_uiKey)//The default constructor for a button.
{
	m_uiKey = a_c_uiKey;//sets the key to activate the button to be equal to the value passed in.

	m_v2Position = a_c_v2Position;//Sets the button's position to be equal to the vector 2 passed in.

	m_fButtonWidth = a_c_fWidth;//Sets the button's width to be equal to the value passed in.

	m_fButtonHeight = a_c_fHeight;//Sets the button's height to be equal to the value passed in.
	
	m_sButton = new Sprite(a_c_cFilename, a_c_fWidth, a_c_fHeight, Vector2(0.5f, 0.5f), Vector4(0.0f, 0.0f, 0.25f, 1.0f));//Creates a sprite for the button.

	m_sButton->setPosition(a_c_v2Position);//Sets the position of the button.

	m_sButton->setLayer(99);//Sets the layer of the button so that it is rendered as far forward as possible.
}

//\===========================================================================================
//\ Destructor 
//\===========================================================================================

Button::~Button()//The default destructor for a button.
{

}

//\===========================================================================================
//\ Button Logic 
//\===========================================================================================

bool Button::buttonLogic(double a_dMousePosX, double a_dMousePosY)//Will return true if the button is activated.
{
	if (UG::GetMouseButtonReleased(m_bMouseReleased))//If the mouse button is released.
	{
		m_bCanBePressed = true;//Allow the button to be pressed.
	}

	if (UG::GetMouseButtonDown(m_bMousePressed) == true && a_dMousePosX < m_v2Position.getfX() - (0.5 * m_fButtonWidth) || a_dMousePosX > m_v2Position.getfX() + (0.5 * m_fButtonWidth) || a_dMousePosY < m_v2Position.getfY() - (0.5 * m_fButtonHeight) || a_dMousePosY > m_v2Position.getfY() + (0.5 * m_fButtonHeight))//If the mouse is clicked outside of the button.
	{
		m_bCanBePressed = false;//Don't allow the button to be pressed.
	}
	
	if (a_dMousePosX < m_v2Position.getfX() - (0.5 * m_fButtonWidth) || a_dMousePosX > m_v2Position.getfX() + (0.5 * m_fButtonWidth) || a_dMousePosY < m_v2Position.getfY() - (0.5 * m_fButtonHeight) || a_dMousePosY > m_v2Position.getfY() + (0.5 * m_fButtonHeight))//If the mouse is outside of the button.
	{
		m_bBeingPressed = false;//Stop the button from being pressed.

		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0, 0, 0.25, 1);//Set the sprite to the non triggered state.
	}

	if (UG::IsKeyDown(m_uiKey) || m_bCanBePressed == true && m_bBeingPressed == true && UG::GetMouseButtonReleased(m_bMouseReleased) == true && a_dMousePosX > m_v2Position.getfX() - (0.5 * m_fButtonWidth) && a_dMousePosX < m_v2Position.getfX() + (0.5 * m_fButtonWidth) && a_dMousePosY > m_v2Position.getfY() - (0.5 * m_fButtonHeight) && a_dMousePosY < m_v2Position.getfY() + (0.5 * m_fButtonHeight))//If the key is pressed or the mouse is released after clicking within the button.
	{
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0.5, 0, 0.75, 1);//Sets the sprite to the pressed state.

		return true;//Exits the function with the true statement.
	}

	if (m_bCanBePressed == true && UG::GetMouseButtonDown(m_bMousePressed) == true && a_dMousePosX > m_v2Position.getfX() - (0.5 * m_fButtonWidth)&&a_dMousePosX < m_v2Position.getfX() + (0.5 * m_fButtonWidth)&& a_dMousePosY > m_v2Position.getfY() - (0.5 * m_fButtonHeight) && a_dMousePosY < m_v2Position.getfY() + (0.5 * m_fButtonHeight))//If the mouse is within the button and the mouse button is pressed whilst the button can be pressed.
	{
		UG::SetSpriteUVCoordinates( m_sButton->getSpriteID(),0.5,0,0.75,1);//Sets the sprite to the pressed state.
		
		m_bBeingPressed = true;//Indicate that the button is being pressed.
	}
	else if (a_dMousePosX > m_v2Position.getfX() - (0.5 * m_fButtonWidth)&&a_dMousePosX < m_v2Position.getfX() + (0.5 * m_fButtonWidth)&& a_dMousePosY > m_v2Position.getfY() - (0.5 * m_fButtonHeight) && a_dMousePosY < m_v2Position.getfY() + (0.5 * m_fButtonHeight))//If the mouse is just within the button.
	{
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0.25, 0, 0.5, 1);//Sets the sprite to the hovered state.
	}
	else
	{
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0, 0, 0.25, 1);//Sets the sprite to the default state.
	}

	return false;
}

//\===========================================================================================
//\ Draw Functions
//\===========================================================================================

void Button::markForDraw()//A function to draw the button.
{
	m_sButton->markForDraw();//Starts the drawing of the button.

	UG::MoveSprite(m_sButton->getSpriteID(), m_v2Position.getfX(), m_v2Position.getfY());//Moves the button to the correct position.
}

void Button::stopDrawing()//A function to stop drawing the button.
{
	m_sButton->stopDrawing();//Stops the drawing of the button.
}