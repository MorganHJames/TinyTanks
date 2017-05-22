//\===========================================================================================
//\ File: Sprite.cpp
//\ Author: Morgan James
//\ Date Created: 17/03/2017
//\ Brief: Contains the function information for the class contained in Sprite.h.
//\===========================================================================================

#include "Sprite.h"
#include "UGFW.h"
#include "MathUtil.h"

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Sprite::Sprite(const char* a_c_cFileName, float a_c_fWidth, float a_c_fHeight, Vector2 a_c_v2Origin, Vector4 a_c_v4UVCoords)//Sprite constructor that makes a UG sprite object with the name of the first argument the size of the next two arguments and the origin of the next vector with the UV coordinates of the last Vector.
{
	m_iSpriteID = UG::CreateSprite(a_c_cFileName, Vector2(a_c_fWidth, a_c_fHeight).getVector(), a_c_v2Origin.getVector(), a_c_v4UVCoords.getVector());//Creates a new spriteID with the arguments passed in.

	UG::SetSpriteScale(m_iSpriteID, a_c_fWidth, a_c_fHeight);//Scales the sprite to the dimensions passed into the functions.

	float fMat4x4[16];//Creates a new array of 16 floats. 
	
	memset(fMat4x4, 0, sizeof(float) * 16);//Sets each position of the fMat4x4 array to be equal to 0.
	
	UG::GetSpriteMatrix(m_iSpriteID, fMat4x4);//Sets the fMat4x4 to be the sprite matrix of the sprite being created.
	
	m_m3PosRot = Matrix3x3(fMat4x4[0], fMat4x4[1], fMat4x4[2], fMat4x4[4], fMat4x4[5], fMat4x4[6], fMat4x4[8], fMat4x4[9], 1.f);//Sets the positional rotation of the sprite equal to the relevant parts of the matrix4x4.
}

//\===========================================================================================
//\ Destructor
//\===========================================================================================

Sprite::~Sprite()//The default destructor for the sprite.
{
	UG::DestroySprite(m_iSpriteID);//Destroys the created sprite.
}

//\===========================================================================================
//\ Set The Sprite Layer
//\===========================================================================================

void Sprite::setLayer(unsigned int a_uiLayer)//A function to set the layer of the sprite equal to the argument passed in on which it is to be rendered.
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);//Sets the sprite layer in accordance to the argument passed in.
}

//\===========================================================================================
//\ Update Sprites Data Each Frame
//\===========================================================================================

void Sprite::update()//The update function for the sprite.
{
	Matrix3x3 m3WorldTx = Matrix3x3::IDENTITY;//Creates a matrix3x3 to hold the world transformation by initializing it to the identity matrix.
	
	getWorldTransform(m3WorldTx);//Sets the newly created matrix to the world transformation.
	
	Matrix4x4 m4x4(
		m3WorldTx.getiMatrix(0), m3WorldTx.getiMatrix(1), m3WorldTx.getiMatrix(2), 0.f,
		m3WorldTx.getiMatrix(3), m3WorldTx.getiMatrix(4), m3WorldTx.getiMatrix(5), 0.f,
		0.f, 0.f, 1.f, 0.f,
		m3WorldTx.getiMatrix(6), m3WorldTx.getiMatrix(7), 0.f, 1.f);//Creates a matrix4x4 from the matrix3x3 as OpenGL which is the underlying rendering pipeline that is being used by the framework draws all components using a 4x4 matrix to represent their world coordinates.
	UG::SetSpriteMatrix(m_iSpriteID, m4x4.getMatrix());//Sets the sprite matrix of the sprite to be equal to the m4x4.
}

//\===========================================================================================
//\ Move Sprite 
//\===========================================================================================

void Sprite::moveSprite(Vector3 a_v3MovementVec)//A function to move the sprite.
{
	Vector3 v3Pos;//Creates a vector3 to hold the position of the sprite.
	
	v3Pos = m_m3PosRot.getRow(2);//Sets the vector equal to the second row of the positional rotation of the sprite.

	v3Pos += a_v3MovementVec * m_m3PosRot;//Sets the positional vector of the sprite equal to the multiplication of the movement vector by our local transform which puts that vector in the local space of this object.

	m_m3PosRot.setRow(2, v3Pos);//Sets the row of the local transform equal to the positional vector.
}

//\===========================================================================================
//\ Mark For Draw
//\===========================================================================================

void Sprite::markForDraw()//A function to set the sprite to be drawn on the screen.
{
	UG::DrawSprite(m_iSpriteID);//Sets the sprite to be drawn on the screen.
}

//\===========================================================================================
//\ Stop Drawing
//\===========================================================================================

void Sprite::stopDrawing()//A function to set the sprite to stop being drawn on the screen.
{
	UG::StopDrawingSprite(m_iSpriteID);//Sets the sprite to stop being drawn on the screen.
}

//\===========================================================================================
//\ Set Position
//\===========================================================================================

void Sprite::setPosition(Vector2 a_v2Pos)//A function set the current position of the sprite to the argument passed in.
{ 
	m_m3PosRot.setRow(2, Vector3(a_v2Pos.getfX(), a_v2Pos.getfY(), 1.f));//Sets the new position of the local transform to the argument passed in.
}

//\===========================================================================================
//\ Get Position
//\===========================================================================================

Vector2 Sprite::getPosition()//A function get the current position of the sprite.
{ 
	return Vector2(m_m3PosRot.getRow(2).getfX(), m_m3PosRot.getRow(2).getfY());//Sets the new position of the local transform to the argument passed in.
}

//\===========================================================================================
//\ Set Velocity
//\===========================================================================================

void Sprite::setVelocity(Vector2 a_v2Velocity)//A function set the current velocity of the sprite to the argument passed in.
{
	m_v2Velocity = a_v2Velocity;
}

//\===========================================================================================
//\ Get Velocity
//\===========================================================================================

Vector2 Sprite::getVelocity()//A function get the current velocity of the sprite.
{
	return m_v2Velocity;
}

//\===========================================================================================
//\ Set Width
//\===========================================================================================

void Sprite::setWidth(float a_fWidth)//A function set the current velocity of the sprite to the argument passed in.
{
	m_iWidth = a_fWidth;
}

//\===========================================================================================
//\ Get Width
//\===========================================================================================

float Sprite::getWidth()//A function get the current velocity of the sprite.
{
	return m_iWidth;
}

//\===========================================================================================
//\ Set Height
//\===========================================================================================

void Sprite::setHeight(float a_fHeight)//A function set the current velocity of the sprite to the argument passed in.
{
	m_iHeight = a_fHeight;
}

//\===========================================================================================
//\ Get Height
//\===========================================================================================

float Sprite::getHeight()//A function get the current velocity of the sprite.
{
	return m_iHeight;
}

//\===========================================================================================
//\ Get Sprite ID
//\===========================================================================================

int Sprite::getSpriteID()//A function to get the sprites ID.
{
	return m_iSpriteID;//Returns the sprite ID.
}