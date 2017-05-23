//\===========================================================================================
//\ File: Sprite.h
//\ Author: Morgan James
//\ Date Created: 17/03/2017
//\ Brief: Contains the Sprite class declarations.
//\===========================================================================================

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Node.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Sprite
//\ Brief: A very simple sprite class that extends from node allowing us to have a sprite hierarchy tree in our game
//\===========================================================================================

class Sprite : public Node 
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

	int m_iSpriteID = -1;//A integer representing the sprites identification.

	int m_iWidth = 0;//An integer that represent how wide the sprite is to be rendered.

	int m_iHeight = 0;//An integer that represent how tall the sprite is to be rendered.
	
	Vector2 m_v2Origin;//A vector2 which contains the position of which the sprite is to be drawn from.

	Vector2 m_v2Velocity;//A vector 2 that contains the velocity of the sprite.

public:
	//\===========================================================================================
	//\ Constructor -- Makes A UG Sprite Object 
	//\===========================================================================================
	
	Sprite(const char* a_c_cFileName, float a_c_fWidth, float a_c_fHeight, Vector2 a_c_v2Origin, Vector4 a_c_v4UVCoords);//Sprite constructor that makes a UG sprite object with the name of the first argument the size of the next two arguments and the origin of the next vector with the UV coordinates of the last Vector.

    //\===========================================================================================
    //\ Destructor
    //\===========================================================================================
    
    virtual ~Sprite();//The default destructor for the sprite.
    
    //\===========================================================================================
    //\ Set The Sprite Layer
    //\===========================================================================================
    
    void setLayer(unsigned int a_uiLayer);//A function to set the layer of the sprite equal to the argument passed in on which it is to be rendered.

    //\===========================================================================================
    //\ Update Sprites Data Each Frame
    //\===========================================================================================
    
    void update();//The update function for the sprite.
    
    //\===========================================================================================
    //\ Move Sprite 
    //\===========================================================================================
    
    void moveSprite(Vector3 a_v3MovementVec);//A function to move the sprite.
    
    //\===========================================================================================
    //\ Mark For Draw
    //\===========================================================================================
    
    void markForDraw();//A function to set the sprite to be drawn on the screen.
    
    //\===========================================================================================
    //\ Stop Drawing
    //\===========================================================================================
    
    void stopDrawing();//A function to set the sprite to stop being drawn on the screen.
    
    //\===========================================================================================
    //\ Set Position
    //\===========================================================================================
    
    void setPosition(Vector2 a_v2Pos);//A function set the current position of the sprite to the argument passed in.

	//\===========================================================================================
	//\ Get Position
	//\===========================================================================================

	Vector2 getPosition();//A function get the current position of the sprite.

	//\===========================================================================================
	//\ Set Velocity
	//\===========================================================================================

	void setVelocity(Vector2 a_v2Velocity);//A function set the current velocity of the sprite to the argument passed in.

	//\===========================================================================================
	//\ Get Velocity
	//\===========================================================================================

	Vector2 getVelocity();//A function get the current velocity of the sprite.

	//\===========================================================================================
	//\ Set Width
	//\===========================================================================================

	void setWidth(float a_fWidth);//A function set the current width of the sprite to the argument passed in.

	//\===========================================================================================
	//\ Get Width
	//\===========================================================================================

	float getWidth();//A function get the current width of the sprite.

	//\===========================================================================================
	//\ Set Height
	//\===========================================================================================

	void setHeight(float a_fHeight);//A function set the current height of the sprite to the argument passed in.

	//\===========================================================================================
	//\ Get Height
	//\===========================================================================================

	float getHeight();//A function get the current height of the sprite.

	//\===========================================================================================
	//\ Get Sprite ID
	//\===========================================================================================
	
	int getSpriteID();//A function to get the sprites ID.
	
};

#endif