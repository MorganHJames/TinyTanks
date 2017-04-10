//\===========================================================================================
//\ File: Node.h
//\ Author: Morgan James
//\ Date Created: 17/03/2017
//\ Brief: Contains the Node class declarations.
//\===========================================================================================

#ifndef _NODE_H_
#define _NODE_H_

#include "Matrix4x4.h"
#include <set>

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Node
//\ Brief: This is a small structure/class that contains a matrix that is used to store rotation and positional data
//\ for an object. This node structure allows for parenting objects so that they can maintain a hierarchy for 
//\ matrix transformation detail, this permits easy parenting of objects like swords and other items onto a 
//\ character or in this scenario parenting a turret with a tank base.
//\===========================================================================================

class Node
{
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

protected:
	Matrix3x3 m_m3PosRot;//A matrix3x3 containing the positional rotation of the node.

private:
	Node* m_nParent;//A pointer to the node's parent.
	
	std::set<Node*>m_nChildren;//A set to hold the children of the node.

public:

	friend class Sprite;

	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Node();//The default constructor for a node.

	//\===========================================================================================
	//\ Destructor 
	//\===========================================================================================

	virtual ~Node();//The default destructor for a node (virtual as we will use node as a base class).

	//\===========================================================================================
	//\ Set Node's Parent
	//\===========================================================================================

	void Node::setParent(Node* a_nParent);//A function to set the parent to the node.

	//\===========================================================================================
	//\ Add Child To Node
	//\===========================================================================================
	
	void addChild(Node* a_nChild);//A function to add a child node to the node.

	//\===========================================================================================
	//\ Remove a child from the node hierarchy structure
	//\===========================================================================================
	
	void removeChild(Node* a_nChild);//A function to remove a child node from that node's set.

	//\===========================================================================================
	//\ Get World Transform (where is the node in the world? gotten by multiplying the node by all its parents and there parents in turn.
	//\===========================================================================================

	void getWorldTransform(Matrix3x3& a_m3Transform);//A function to set the argument passed in to be the world transformation.

	//\===========================================================================================
	//\ Get The Local Transform For The Point
	//\===========================================================================================

	void getLocalTransform(Matrix3x3 a_m3Transform);//A function to set the argument passed in to be the local transformation.

	//\===========================================================================================
	//\ Set The Translation
	//\===========================================================================================
	
	void setTranslation(Vector2 a_v2Translation);//A function to set the translation of the node equal to the argument passed in.

	//\===========================================================================================
	//\ Rotate Node Around It's Z Axis
	//\===========================================================================================
	
	void rotateZ(float a_fRotation);//A function to rotate the note around the z axis.

	//\===========================================================================================
	//\ Scales The Node
	//\===========================================================================================
	
	void scale(float a_fScale);//A function that scales the node by the argument.

};

#endif
