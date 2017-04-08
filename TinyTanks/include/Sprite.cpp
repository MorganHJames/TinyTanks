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

Sprite::Sprite(const char* a_c_cFileName, float a_c_fWidth, float a_c_fHeight, Vector2 a_c_v2Origin, Vector4 a_c_v4UVCoords)
{
	m_iSpriteID = UG::CreateSprite(a_c_cFileName, Vector2(a_c_fWidth, a_c_fHeight).getVector(), a_c_v2Origin.getVector(), a_c_v4UVCoords.getVector());

	UG::SetSpriteScale(m_iSpriteID, a_c_fWidth, a_c_fHeight);

	float fMat4x4[16];
	
	memset(fMat4x4, 0, sizeof(float) * 16);
	
	UG::GetSpriteMatrix(m_iSpriteID, fMat4x4);
	
	m_m3PosRot = Matrix3x3(fMat4x4[0], fMat4x4[1], fMat4x4[2], fMat4x4[4], fMat4x4[5], fMat4x4[6], fMat4x4[8], fMat4x4[9], 1.f);
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

void Sprite::setLayer(unsigned int a_uiLayer)
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}

//\===========================================================================================
//\ Update Sprites Data Each Frame
//\===========================================================================================

void Sprite::update()
{
	//OpenGL which is the underlying rendering pipeline that is being used by the framework
	//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
	//from the 3x3 matrix that we are using internally
	//set the sprites matrix

	Matrix3x3 m3WorldTx = Matrix3x3::IDENTITY;
	
	getWorldTransform(m3WorldTx);
	
	Matrix4x4 m4x4(
		m3WorldTx.getiMatrix(0), m3WorldTx.getiMatrix(1), m3WorldTx.getiMatrix(2), 0.f,
		m3WorldTx.getiMatrix(3), m3WorldTx.getiMatrix(4), m3WorldTx.getiMatrix(5), 0.f,
		0.f, 0.f, 1.f, 0.f,
		m3WorldTx.getiMatrix(6), m3WorldTx.getiMatrix(7), 0.f, 1.f);
	
	UG::SetSpriteMatrix(m_iSpriteID, m4x4.getMatrix());

}

//\===========================================================================================
//\ Move Sprite 
//\===========================================================================================

void Sprite::moveSprite(Vector3 a_v3MovementVec)
{
	// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
	Vector3 v3Pos;
	
	v3Pos = m_m3PosRot.getRow(2);
	//Multiplying the movement vector by our local transform will put that vector in the local space of this object
	//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
	//of our worldspace matrix
	v3Pos += a_v3MovementVec * m_m3PosRot;

	m_m3PosRot.setRow(2, v3Pos);
}

//\===========================================================================================
//\ Mark For Draw
//\===========================================================================================

void Sprite::markForDraw()
{
	UG::DrawSprite(m_iSpriteID);
}

//\===========================================================================================
//\ Stop Drawing
//\===========================================================================================

void Sprite::stopDrawing()
{
	UG::StopDrawingSprite(m_iSpriteID);
}

//\===========================================================================================
//\ Set Position
//\===========================================================================================

void Sprite::setPosition(Vector2 a_v2Pos)
{
	Vector3 v3NewPos = Vector3(a_v2Pos.getfX(), a_v2Pos.getfY(), 1.f);

	m_m3PosRot.setRow(2, v3NewPos);
}