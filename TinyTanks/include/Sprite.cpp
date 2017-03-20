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
//\ Constructor -- Makes A UG Sprite Object 
//\===========================================================================================

Sprite::Sprite(const char* a_fileName, float a_width, float a_height, Vector2 a_origin, Vector4 a_UVCoords)
{
	m_iSpriteID = UG::CreateSprite(a_fileName, Vector2(a_width, a_height).getVector(), a_origin.getVector(), a_UVCoords.getVector());
	float mat4x4[16];
	memset(mat4x4, 0, sizeof(float) * 16);
	UG::GetSpriteMatrix(m_iSpriteID, mat4x4);
	m3PosRot = Matrix3x3(mat4x4[0], mat4x4[1], mat4x4[2], mat4x4[4], mat4x4[5], mat4x4[6], mat4x4[7], mat4x4[8], 1.f);

}

//\===========================================================================================
//\ Destructor
//\===========================================================================================

Sprite::~Sprite()
{
	UG::DestroySprite(m_iSpriteID);
}

//\===========================================================================================
//\ Set The Sprite Layer
//\===========================================================================================

void Sprite::SetLayer(unsigned int a_uiLayer)
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}

//\===========================================================================================
//\ Update Sprites Data Each Frame
//\===========================================================================================

void Sprite::Update()
{
	//OpenGL which is the underlying rendering pipeline that is being used by the framework
	//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
	//from the 3x3 matrix that we are using internally
	//set the sprites matrix

	Matrix3x3 worldTx = Matrix3x3::IDENTITY;
	GetWorldTransform(worldTx);
	Matrix4x4 m4x4(
		worldTx.getiMatrix(0), worldTx.getiMatrix(1), worldTx.getiMatrix(2), 0.f,
		worldTx.getiMatrix(4), worldTx.getiMatrix(5), worldTx.getiMatrix(6), 0.f,
		0.f, 0.f, 1.f, 0.f,
		worldTx.getiMatrix(12), worldTx.getiMatrix(13), 0.f, 1.f);
		UG::SetSpriteMatrix(m_iSpriteID, m4x4.getMatrix());

}

//\===========================================================================================
//\ Move Sprite 
//\===========================================================================================

void Sprite::MoveSprite(Vector3 a_movementVec)
{
	// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
	Vector3 pos;
	pos = m3PosRot.getRow(2);
	//Multiplying the movement vector by our local transform will put that vector in the local space of this object
	//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
	//of our worldspace matrix
	pos += vectorTimesMatrix3x3(a_movementVec, m3PosRot);

	m3PosRot.setRow(2, pos);
}

//\===========================================================================================
//\ Mark For Draw
//\===========================================================================================

void Sprite::MarkForDraw()
{
	UG::DrawSprite(m_iSpriteID);
}

//\===========================================================================================
//\ Stop Drawing
//\===========================================================================================

void Sprite::StopDrawing()
{
	UG::StopDrawingSprite(m_iSpriteID);
}

//\===========================================================================================
//\ Set Position
//\===========================================================================================

void Sprite::SetPosition(Vector2 a_pos)
{
	Vector3 np = Vector3(a_pos.getfX(), a_pos.getfY(), 1.f);
	m3PosRot.setRow(2, np);

}