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
	if (UG::GetMouseButtonReleased(m_bMouseReleased))
	{
		m_bCanBePressed = false;
	}

	if (UG::GetMouseButtonDown(m_bMousePressed) == true && a_dMousePosX < m_v2Position.getfX() - (0.5 * m_fButtonWidth) || a_dMousePosX > m_v2Position.getfX() + (0.5 * m_fButtonWidth) || a_dMousePosY < m_v2Position.getfY() - (0.5 * m_fButtonHeight) || a_dMousePosY > m_v2Position.getfY() + (0.5 * m_fButtonHeight))
	{
		m_bCanBePressed = true; 
		//pressed//clicked outside

	}
	//functions to make it so you have to reclick on each button instead of releasing on the button you want
	if (a_dMousePosX < m_v2Position.getfX() - (0.5 * m_fButtonWidth) || a_dMousePosX > m_v2Position.getfX() + (0.5 * m_fButtonWidth) || a_dMousePosY < m_v2Position.getfY() - (0.5 * m_fButtonHeight) || a_dMousePosY > m_v2Position.getfY() + (0.5 * m_fButtonHeight))
	{
		m_bBeingPressed = false;
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0, 0, 0.25, 1);
		//Leaves box
	}

	if (UG::GetMouseButtonDown(m_bMousePressed) == true && a_dMousePosX > m_v2Position.getfX() - (0.5 * m_fButtonWidth)&&a_dMousePosX < m_v2Position.getfX() - (0.5 * m_fButtonWidth)&& a_dMousePosY > m_v2Position.getfY() + (0.5 * m_fButtonHeight) && a_dMousePosY < m_v2Position.getfY() + (0.5 * m_fButtonHeight))
	{
		UG::SetSpriteUVCoordinates( m_sButton->getSpriteID(),0.5,0,0.75,1);
		//clicked
		m_bBeingPressed = true;
	}





	//when hovered over by mouse changes colour

	else if (a_dMousePosX > m_v2Position.getfX() - (0.5 * m_fButtonWidth)&&a_dMousePosX < m_v2Position.getfX() + (0.5 * m_fButtonWidth)&& a_dMousePosY > m_v2Position.getfY() - (0.5 * m_fButtonHeight) && a_dMousePosY < m_v2Position.getfY() + (0.5 * m_fButtonHeight))
	{
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0.25, 0, 0.5, 1);
		//hover
	}
	else
	{
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0, 0, 0.25, 1);
		//default
	}
	if (UG::IsKeyDown(m_uiKey) || m_bCanBePressed == false && m_bBeingPressed == true && UG::GetMouseButtonReleased(m_bMouseReleased) == true && a_dMousePosX > m_v2Position.getfX() - (0.5 * m_fButtonWidth) &&a_dMousePosX < m_v2Position.getfY() - (0.5 * m_fButtonHeight) && a_dMousePosY < m_v2Position.getfY() + (0.5 * m_fButtonHeight))
	{
		UG::SetSpriteUVCoordinates(m_sButton->getSpriteID(), 0.5, 0, 0.75, 1);
		//activate
		return true;
	}
	return false;
	
}

//\===========================================================================================
//\ Draw Functions
//\===========================================================================================

void Button::markForDraw()//A function to draw the button.
{
	m_sButton->markForDraw();//Starts the drawing of the button.

	UG::MoveSprite(m_sButton->getSpriteID(), m_v2Position.getfX(), m_v2Position.getfY());
}

void Button::stopDrawing()//A function to stop drawing the button.
{
	m_sButton->stopDrawing();//Stops the drawing of the button.
}