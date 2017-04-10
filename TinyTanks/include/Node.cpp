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
//\ Destructor
//\===========================================================================================

Node::~Node()//The default destructor for a node (virtual as we will use node as a base class).
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

void Node::setParent(Node* a_nParent)//A function to set the parent to the node.
{
	if (a_nParent == this)//If the argument passed in is the same as the node you are trying to parent.
		return;//Exit the function (do nothing).

	if (m_nParent != nullptr)//If the parent of this node is not a null pointer.
        m_nParent->removeChild(this);//Remove the children from this node.
	
	m_nParent = a_nParent;//Set the parent of this node equal to the node passed in.

	m_nParent->addChild(this);//Adds a child to this node equal to this node.
}

//\===========================================================================================
//\ Add Child To Node
//\===========================================================================================

void Node::addChild(Node* a_nChild)//A function to add a child node to the node.
{
	auto iter = m_nChildren.find(a_nChild);//Sets the iterator equal to the position of the argument if it is found within the node's set else sets the iterator to m_nChildren.end().
	
	if (iter == m_nChildren.end())//If the argument is not already a child of the node.
		m_nChildren.emplace(a_nChild);//Puts the passed in argument in the node's set.
}

//\===========================================================================================
//\ Remove a child from the node hierarchy structure
//\===========================================================================================

void Node::removeChild(Node* a_nChild)//A function to remove a child node from that node's set.
{
	auto iter = m_nChildren.find(a_nChild);//Sets the iterator equal to the position of the argument if it is found within the node's set else sets the iterator to m_nChildren.end().
	
	if (iter != m_nChildren.end())//If the argument is a child of the node.
        m_nChildren.erase(iter);//Erase the argument at the iterator location.
}

//\===========================================================================================
//\ Get World Transform (where is the node in the world? gotten by multiplying the node by all its parents and there parents in turn.
//\===========================================================================================

void Node::getWorldTransform(Matrix3x3& a_m3Transform)//A function to set the argument passed in to be the world transformation.
{
	if (m_nParent)//If the node has a parent.
	{
		m_nParent->getWorldTransform(a_m3Transform);//Set the argument equal to the parents world transform.
		
		a_m3Transform = m_m3PosRot * a_m3Transform;//Set the argument equal to the positional rotation multiplied by the world transform of the parent.
	}
	else//If the node doesn't have a parent.
		a_m3Transform = m_m3PosRot;//Set the argument equal to the positional rotation of the node.
}

//\===========================================================================================
//\ Get The Local Transform For The Point
//\===========================================================================================

void Node::getLocalTransform(Matrix3x3 a_m3Transform)//A function to set the argument passed in to be the local transformation.
{
	a_m3Transform = m_m3PosRot;//Set the argument equal to the positional rotation of the node.
}

//\===========================================================================================
//\ Set The Translation
//\===========================================================================================

void Node::setTranslation(Vector2 a_v2Translation)//A function to set the translation of the node equal to the argument passed in.
{
	m_m3PosRot.setRow(2, Vector3(a_v2Translation));//Sets the translation row of the node equal to the argument.
}

//\===========================================================================================
//\ Rotate Node Around It's Z Axis
//\===========================================================================================

void Node::rotateZ(float a_fRotation)//A function to rotate the note around the z axis.
{
	Matrix3x3 m3Rotation = Matrix3x3::IDENTITY;//Creates a matrix3x3 equal to the identity matrix.

	m3Rotation.rotate(a_fRotation);//Rotates the matrix set to the identity matrix by the angle given by the argument.

	m_m3PosRot = m3Rotation * m_m3PosRot;//Sets the nodes positional rotation equal to the current positional rotation multiplied by the new rotation.
}

//\===========================================================================================
//\ Scales The Node
//\===========================================================================================

void Node::scale(float a_fScale)//A function that scales the node by the argument.
{
	Vector3 v3Translation = Vector3::ZERO;//Creates a vector 3 equal to zero.
	
	v3Translation = m_m3PosRot.getRow(2);//Sets the translation vector equal to the 2nd row of the nodes positional rotation matrix.

	Matrix3x3 m3Scale = Matrix3x3::IDENTITY;//Creates a matrix3x3 equal to the identity matrix.
	
	m3Scale.scale(a_fScale, a_fScale);//Scales the matrix by the argument assuming both the x and y scaling.
	
	m_m3PosRot = m3Scale * m_m3PosRot;//Sets the positional rotation of the node to be equal to the new scale multiplied by the previous positional rotation.

	m_m3PosRot.setRow(2, v3Translation);//Sets the second row of the positional rotation matrix equal to the translation.
}
