//\===========================================================================================
//\ File: Node.cpp
//\ Author: Morgan James
//\ Date Created: 21/02/2017
//\ Brief: Contains the function information for the class contained in Node.h.
//\===========================================================================================

#include "UGFW.h"
#include "Enumerations.h"
#include "MathUtil.h"
#include <iostream>
#include "Node.h"

//\===========================================================================================
//\ Constructor
//\===========================================================================================

Node::Node()//The default constructor for a node.
{
	m_nParent = nullptr;//Sets the parents to the node to be a null pointer.
	
	Matrix3x3 m_m3PosRot = Matrix3x3::IDENTITY;//Sets the position rotation of the node to be equal to the identity matrix.
}

//\===========================================================================================
//\ Destructor (virtual as we will use node as a base class)
//\===========================================================================================

Node::~Node()//The default destructor for a node.
{
	for (auto iter = m_nChildren.begin(); iter != m_nChildren.end(); ++iter)//For all children of the node.
	{
		removeChild(*iter);//Remove the child.
	}
	m_nParent = nullptr;//Make the parent node equal to a null pointer.
}

//\===========================================================================================
//\ Set Node's Parent
//\===========================================================================================

void Node::setParent(Node* a_nParent)
{
	if (a_nParent == this)
		return;

	if (m_nParent != nullptr)
        m_nParent->removeChild(this);
	
	m_nParent = a_nParent;

	m_nParent->addChild(this);
}

//\===========================================================================================
//\ Add Child To Node
//\===========================================================================================

void Node::addChild(Node* a_nChild)
{
	auto iter = m_nChildren.find(a_nChild);
	//Children are stored in a set. One of the features of a set is easy searching for an item
	//this allows us to see if the child already exists in the set of children. 
	//If it exists already we will not add it to the set multiple times.
	if (iter == m_nChildren.end())
		m_nChildren.emplace(a_nChild);
}

//\===========================================================================================
//\ Remove a child from the node hierarchy structure
//\===========================================================================================

void Node::removeChild(Node* a_nChild)
{
	//If we can find the child remove it, a successful find returns an iterator to the object
	//we are looking for. An unsuccessful find returns an iterator that is one item past the end of the set.
	auto iter = m_nChildren.find(a_nChild);
	
	if (iter != m_nChildren.end())
        m_nChildren.erase(iter);
}

//\===========================================================================================
//\ Get World Transform (where is the node in the world? gotten by multiplying the node by all its parents and there parents in turn.
//\===========================================================================================

void Node::getWorldTransform(Matrix3x3& transform)
{
	if (m_nParent)
	{
		m_nParent->getWorldTransform(transform);
		
		transform = m_m3PosRot * transform;
	}
	else
	    transform = m_m3PosRot;
}

//\===========================================================================================
//\ Get The Local Transform For The Point
//\===========================================================================================

void Node::getLocalTransform(Matrix3x3 a_m3Transform)
{
	a_m3Transform = m_m3PosRot;
}

//\===========================================================================================
//\ Set The Translation
//\===========================================================================================

void Node::setTranslation(Vector2 a_v2Translation)
{
	m_m3PosRot.setRow(2, Vector3(a_v2Translation));
}

//\===========================================================================================
//\ Rotate Node Around It's Z Axis
//\===========================================================================================

void Node::rotateZ(float a_fRotation)
{
	Matrix3x3 m3Rotation = Matrix3x3::IDENTITY;

	m3Rotation.rotate(a_fRotation);

	m_m3PosRot = m3Rotation * m_m3PosRot;
}

//\===========================================================================================
//\ Scales The Node
//\===========================================================================================

void Node::scale(float a_fScale)
{
	Vector3 v3Translation = Vector3::ZERO;
	
	v3Translation = m_m3PosRot.getRow(2);

	Matrix3x3 m3Scale = Matrix3x3::IDENTITY;
	
	m3Scale.scale(a_fScale, a_fScale);
	
	m_m3PosRot = m3Scale * m_m3PosRot;

	m_m3PosRot.setRow(2, v3Translation);
}
