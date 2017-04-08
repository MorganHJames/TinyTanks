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
	Matrix3x3 m_m3PosRot;

private:
	Node* m_nParent;
	
	std::set<Node*>m_nChildren;

public:

	friend class Sprite;

	//\===========================================================================================
	//\ Constructor
	//\===========================================================================================

	Node();

	//\===========================================================================================
	//\ Destructor (virtual as we will use node as a base class)
	//\===========================================================================================

	virtual ~Node();

	//\===========================================================================================
	//\ Set Node's Parent
	//\===========================================================================================

	void Node::setParent(Node* a_nParent);

	//\===========================================================================================
	//\ Add Child To Node
	//\===========================================================================================
	
	void addChild(Node* a_nChild);

	//\===========================================================================================
	//\ Remove a child from the node hierarchy structure
	//\===========================================================================================
	
	void removeChild(Node* a_nChild);

	//\===========================================================================================
	//\ Get World Transform (where is the node in the world? gotten by multiplying the node by all its parents and there parents in turn.
	//\===========================================================================================

	void getWorldTransform(Matrix3x3& a_m3Transform);

	//\===========================================================================================
	//\ Get The Local Transform For The Point
	//\===========================================================================================

	void getLocalTransform(Matrix3x3 a_m3Transform);

	//\===========================================================================================
	//\ Set The Translation
	//\===========================================================================================
	
	void setTranslation(Vector2 a_v2Translation);

	//\===========================================================================================
	//\ Rotate Node Around It's Z Axis
	//\===========================================================================================
	
	void rotateZ(float a_fRotation);

	//\===========================================================================================
	//\ Scales The Node
	//\===========================================================================================
	
	void scale(float a_fScale);

};

#endif
