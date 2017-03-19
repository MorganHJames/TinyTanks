//\===========================================================================================
//\ File: Node.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Vector2.h.
//\===========================================================================================

#include "UGFW.h"
#include "Enumerations.h"
#include "MathUtil.h"
#include <iostream>
#include "Node.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Node::Node()
{
	m_pParent = nullptr;
	Matrix3x3 m3PosRot = Matrix3x3::IDENTITY;

}

//\===========================================================================================
//\ Destructor (virtual as we will use node as a base class)
//\===========================================================================================

Node::~Node()
{
	for (auto iter = m_pChildren.begin(); iter != m_pChildren.end(); ++iter)
	{
		RemoveChild(*iter);
	}
	m_pParent = nullptr;
}

//\===========================================================================================
//\ Set Node's Parent
//\===========================================================================================

void Node::SetParent(Node* a_parent)
{
	if (a_parent == this)
		return;

	if (m_pParent != nullptr)
        m_pParent->RemoveChild(this);
	
	m_pParent = a_parent;
	m_pParent->AddChild(this);
}

//\===========================================================================================
//\ Add Child To Node
//\===========================================================================================

void Node::AddChild(Node* a_child)
{
	auto iter = m_pChildren.find(a_child);
	//Children are stored in a set. One of the features of a set is easy searching for an item
	//this allows us to see if the child already exists in the set of children. 
	//If it exists already we will not add it to the set multiple times.
	if (iter == m_pChildren.end())
		m_pChildren.emplace(a_child);
}

//\===========================================================================================
//\ Remove a child from the node hierarchy structure
//\===========================================================================================

void Node::RemoveChild(Node* a_child)
{
	//If we can find the child remove it, a successful find returns an iterator to the object
	//we are looking for. An unsuccessful find returns an iterator that is one item past the end of the set.
	auto iter = m_pChildren.find(a_child);
	if (iter != m_pChildren.end())
        m_pChildren.erase(iter);
	
}

//\===========================================================================================
//\ Get World Transform (where is the node in the world? gotten by multiplying the node by all its parents and there parents in turn.
//\===========================================================================================

void Node::GetWorldTransform(Matrix3x3& transform)
{
	if (m_pParent)
	{
		m_pParent->GetWorldTransform(transform);
		transform = m3PosRot * transform;
	}
	else
	    transform = m3PosRot;
	
}

//\===========================================================================================
//\ Get The Local Transform For The Point
//\===========================================================================================

void Node::GetLocalTransform(Matrix3x3 a_m3Transform)
{
	a_m3Transform = m3PosRot;
}

//\===========================================================================================
//\ Set The Translation
//\===========================================================================================

void Node::SetTranslation(Vector2 a_v2Translation)
{
	m3PosRot.setRow(2, Vector3(a_v2Translation));
}

//\===========================================================================================
//\ Rotate Node Around It's Z Axis
//\===========================================================================================

void Node::RotateZ(float a_fRotation)
{
	Matrix3x3 m3Rotation = Matrix3x3::IDENTITY;
	m3Rotation.rotate(a_fRotation);
	m3PosRot = m3Rotation * m3PosRot;
}

//\===========================================================================================
//\ Scales The Node
//\===========================================================================================

void Node::Scale(float a_fScale)
{
	Vector3 translation = Vector3::ZERO;
	translation = m3PosRot.getRow(2);

	Matrix3x3 scale = Matrix3x3::IDENTITY;
	scale.scale(a_fScale, a_fScale);
	m3PosRot = scale * m3PosRot;

	m3PosRot.setRow(2, translation);
}
