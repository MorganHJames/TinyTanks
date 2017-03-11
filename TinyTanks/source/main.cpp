//\===========================================================================================
//\ File: TinyTanks/main.cpp
//\ Author: Morgan James
//\ Date Created: 20/02/2017
//\ Brief: A recreation of the game Tiny Tanks using c++.
//\===========================================================================================

#include "UGFW.h"
#include "Enumerations.h"
#include "Matrix4x4.h"
#include "MathUtil.h"
#include <iostream>
#include <set>

//\===========================================================================================================
//\ Node -
//\   This is a small structure/class that contains a matrix that is used to store rotation and positional data
//\ for an object. This node structure allows for parenting objects so that they can maintain a hierarchy for 
//\ matrix transformation detail, this permits easy parenting of objects like swords and other items onto a 
//\ character or in this scenario parenting a turret with a tank base.
//\===========================================================================================================
struct Node
{
	//Constructor
	Node()
	{
		m_pParent = nullptr;
		Matrix3x3 m3PosRot = m3PosRot.identity();

	}
	//destructor (virtual as we will use node as a base class)
	virtual ~Node()
	{
		for (auto iter = m_pChildren.begin(); iter != m_pChildren.end(); ++iter)
		{
			RemoveChild(*iter);
		}
		m_pParent = nullptr;
	}

	//Function to set this node's parent 
	void SetParent(Node* a_parent)
	{
		if (a_parent == this)
			return;

		if (m_pParent != nullptr)
		{
			m_pParent->RemoveChild(this);
		}
		m_pParent = a_parent;
		m_pParent->AddChild(this);
	}
	//Function to add a child to the node
	void AddChild(Node* a_child)
	{
		auto iter = m_pChildren.find(a_child);
		//Children are stored in a set. One of the features of a set is easy searching for an item
		//this allows us to see if the child already exists in the set of children. 
		//If it exists already we will not add it to the set multiple times.
		if (iter == m_pChildren.end())
		{
			m_pChildren.emplace(a_child);
		}
	}
	//Remove a child from our node hierarchy structure
	void RemoveChild(Node* a_child)
	{
		//if we can find the child remove it, a successful find returns an iterator to the object
		//we are looking for. An unsuccessful find returns an iterator that is one item past the end of the set
		auto iter = m_pChildren.find(a_child);
		if (iter != m_pChildren.end())
		{
			m_pChildren.erase(iter);
		}
	}
	//Where is this node in the world 
	// this requires us to transform (multiply) this node by any parents it may have (and their parents in turn).
	void GetWorldTransform(Matrix3x3& transform)
	{
		if (m_pParent)
		{
			m_pParent->GetWorldTransform(transform);
			transform = m3PosRot * transform;
		}
		else
		{
			transform = m3PosRot;
		}
	}
	//Get the local transform for our point
	void GetLocalTransform(Matrix3x3 a_m3Transform)
	{
		a_m3Transform = m3PosRot;
	}
	//Set our translation
	void SetTranslation(Vector2 a_v2Translation)
	{
		m3PosRot.setRow(2, Vector3(a_v2Translation));
	}
	//Rotate this node around it's z axis
	void RotateZ(float a_fRotation)
	{
		Matrix3x3 m3Rotation = m3Rotation.identity();
		m3Rotation.rotate(a_fRotation);
		m3PosRot = m3Rotation * m3PosRot;
	}
	//scale this node
	void Scale(float a_fScale)
	{
		Vector3 translation = translation.zero();
		translation = m3PosRot.getRow(2);

		Matrix3x3 scale = scale.identity();
		scale.scale(a_fScale, a_fScale);
		m3PosRot = scale * m3PosRot;

		m3PosRot.setRow(2, translation);
	}

protected:
	Matrix3x3 m3PosRot;
private:
	Node* m_pParent;
	std::set<Node*>m_pChildren;

};

//A very simple sprite class that extends from node allowing us to have a sprite hierarchy tree in our game
struct Sprite : public Node {
	//Constructor -- makes a UG Sprite object for us to use
	Sprite(const char* a_fileName, float a_width, float a_height, Vector2 a_origin, Vector4 a_UVCoords)
	{
		m_iSpriteID = UG::CreateSprite(a_fileName, Vector2(a_width, a_height), a_origin, a_UVCoords);
		float mat4x4[16];
		memset(mat4x4, 0, sizeof(float) * 16);
		UG::GetSpriteMatrix(m_iSpriteID, mat4x4);
		m3PosRot = Matrix3x3(mat4x4[0], mat4x4[1], mat4x4[2], mat4x4[4], mat4x4[5], mat4x4[6], mat4x4[7], mat4x4[8], 1.f);

	}
	//Destructor
	virtual ~Sprite()
	{
		UG::DestroySprite(m_iSpriteID);
	}
	//Set our sprite layer
	void SetLayer(unsigned int a_uiLayer)
	{
		UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
	}
	//an update function to call each frame to update our sprites data
	void Update(float a_fdt)
	{
		//OpenGL which is the underlying rendering pipeline that is being used by the framework
		//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
		//from the 3x3 matrix that we are using internally
		//set the sprites matrix

		Matrix3x3 worldTx = worldTx.identity();
		GetWorldTransform(worldTx);
		Matrix4x4 m4x4(
	        worldTx.getiMatrix(0), worldTx.getiMatrix(1), worldTx.getiMatrix(2), 0.f,
			worldTx.getiMatrix(4), worldTx.getiMatrix(5), worldTx.getiMatrix(6), 0.f,
			0.f, 0.f, 1.f, 0.f,
			worldTx.getiMatrix(12), worldTx.getiMatrix(13), 0.f, 1.f);
		UG::SetSpriteMatrix(m_iSpriteID, m4x4);

	}
	//Function to move our sprite
	// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
	void MoveSprite(Vector3 a_movementVec)
	{
		Vector3 pos;
		pos = m3PosRot.getRow(2);
		//Multiplying the movement vector by our local transform will put that vector in the local space of this object
		//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
		//of our worldspace matrix
		pos += a_movementVec * m3PosRot;

		m3PosRot.setRow(2, pos);
	}

	void MarkForDraw()
	{
		UG::DrawSprite(m_iSpriteID);
	}

	void StopDrawing()
	{
		UG::StopDrawingSprite(m_iSpriteID);
	}

	void SetPosition(Vector2 a_pos)
	{
		Vector3 np = Vector3(a_pos.getfX(), a_pos.getfY(), 1.f);
		m3PosRot.setRow(2, np);

	}

private:
	int m_iSpriteID;
	int m_iWidth;
	int m_iHeight;
	Vector2 m_v2Origin;

};

int main(int argv, char* argc[])
{
	if (UG::Create(1024, 768, false, "Matrix Demo", 100, 100))
	{

		int iScreenWidth = 0, iScreenHeight = 0;
		UG::GetScreenSize(iScreenWidth, iScreenHeight);

		UG::SetBackgroundColor(UG::SColour(0x2A, 0x57, 0x66, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");

		//Create a sprite for our tank's base
		Sprite* pTank = new Sprite("./images/tanks.png", 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));
		pTank->SetPosition(Vector2(iScreenWidth * 0.5f, iScreenHeight * 0.5f));
		pTank->MarkForDraw();
		pTank->SetLayer(0);

		//Create a sprite for our tank's turret
		Sprite* pTurret = new Sprite("./images/tanks.png", 38, 64, Vector2(0.5f, 0.29f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));
		pTurret->SetParent(pTank);
		pTurret->MarkForDraw();
		pTurret->SetLayer(1);

		//We will be using some simple physics to move our tank
		//Lets use a value for max speed for our tank to be 100
		//our cut off speed can be set to 5 so if we are below that then don't move
		float fCurrentVelocity = 0.f;
		float fMaxVelocity = 10.f;
		float fDrag = 0.03f;
		do
		{
			float dt = UG::GetDeltaTime();
			float xPos = 0; float yPos = 0;

			//Create a vector to store our movement
			Vector3 movementVector = Vector3::AXIS_Y;
			//We're going to be treating moving forward and backward as traversing along the sprite's Y axis
			//If our sprite was rotated 90 degrees on the sprite sheet then we would treat that direction as forward.
			float fAccelleration = 0.f;

			if (UG::IsKeyDown(UG::KEY_W))
			{
				fAccelleration += 3.f;
				fDrag = 0.f;
			}
			if (UG::IsKeyDown(UG::KEY_S))
			{
				fAccelleration -= 2.f;
				fDrag = 0.f;
			}
			if (!UG::IsKeyDown(UG::KEY_S) && !UG::IsKeyDown(UG::KEY_W))
			{
				fDrag = 0.08f;
			}

			fCurrentVelocity += fAccelleration * dt;
			fCurrentVelocity -= fCurrentVelocity * fDrag;
			if (fabsf(fCurrentVelocity) > fMaxVelocity)
			{
				fCurrentVelocity = fMaxVelocity * Signf(fCurrentVelocity);
			}
			if (fabsf(fCurrentVelocity) > E)
			{
				movementVector *= fCurrentVelocity;
				pTank->MoveSprite(movementVector);
			}

			//Tank Rotation
			if (UG::IsKeyDown(UG::KEY_A))
			{
				pTank->RotateZ(0.05f);
			}
			if (UG::IsKeyDown(UG::KEY_D))
			{
				pTank->RotateZ(-0.05f);
			}

			//Turret Rotation
			if (UG::IsKeyDown(UG::KEY_Q))
			{
				pTurret->RotateZ(0.085f);
			}
			if (UG::IsKeyDown(UG::KEY_E))
			{
				pTurret->RotateZ(-0.085f);
			}



			// quit our application when escape is pressed
			if (UG::IsKeyDown(UG::KEY_ESCAPE))
				UG::Close();



			//Draw some text
			UG::ClearScreen();

			pTank->Update(dt);
			pTurret->Update(dt);

			//UG::SetFont("./fonts/invaders.fnt");
			//UG::DrawString("Nodes Demo", (int)(iScreenWidth * 0.47f), iScreenHeight - 2, 1.f);

			//\==============================================================================================================================
			//Some simple Line drawing to draw the lines on the court.
			//Top and Bottom lines
			//UG::DrawLine(0, iScreenHeight - 40, iScreenWidth, iScreenHeight - 40, UG::SColour(0xFF, 0xFF, 0xFF, 0xFF));
			//UG::DrawLine(0, 40, iScreenWidth, 40, UG::SColour(0xFF, 0xFF, 0xFF, 0xFF));
			//\==============================================================================================================================

			//UG::SetFont(nullptr);

		} while (UG::Process());


		UG::Dispose();


	}
	return 0;
}
