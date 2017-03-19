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
	Matrix3x3 m3PosRot;

private:
	Node* m_pParent;
	std::set<Node*>m_pChildren;

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

	void Node::SetParent(Node* a_nParent);

	//\===========================================================================================
	//\ Add Child To Node
	//\===========================================================================================
	
	void AddChild(Node* a_nChild);

	//\===========================================================================================
	//\ Remove a child from the node hierarchy structure
	//\===========================================================================================
	
	void RemoveChild(Node* a_nChild);

	//\===========================================================================================
	//\ Get World Transform (where is the node in the world? gotten by multiplying the node by all its parents and there parents in turn.
	//\===========================================================================================

	void GetWorldTransform(Matrix3x3& a_m3Transform);

	//\===========================================================================================
	//\ Get The Local Transform For The Point
	//\===========================================================================================

	void GetLocalTransform(Matrix3x3 a_m3Transform);

	//\===========================================================================================
	//\ Set The Translation
	//\===========================================================================================
	
	void SetTranslation(Vector2 a_v2Translation);

	//\===========================================================================================
	//\ Rotate Node Around It's Z Axis
	//\===========================================================================================
	
	void RotateZ(float a_fRotation);

	//\===========================================================================================
	//\ Scales The Node
	//\===========================================================================================
	
	void Scale(float a_fScale);

};

#endif
