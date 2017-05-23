//\===========================================================================================
//\ File: Upgrades.h
//\ Author: Morgan James
//\ Date Created: 23/05/2017
//\ Brief: Contains the Upgrades class declarations.
//\===========================================================================================

#ifndef _UPGRADES_H_
#define _UPGRADES_H_

#include "Sprite.h"
#include "Tile.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Upgrades
//\ Brief: A class that uses the tile class to create an upgrade for the tank.
//\===========================================================================================

class Upgrade
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================
	
	Sprite* m_sUpgrade;//The default sprite for the Upgrade.

	bool m_bActive = false;//The current state of the upgrades's existence.

	int m_iUpgradeType = 0;//The type of upgrade the upgrade currently is.

	float m_fUpgradeTimer = 0;//How long the upgrade has left to exist.

public:
	//\===========================================================================================
	//\ Constructor 
	//\===========================================================================================

	Upgrade(float a_fTileDimensions);//The constructor for the upgrades that creates the sprite.

	//\===========================================================================================
	//\ Update 
	//\===========================================================================================

	void Update(Tile *a_tTileArray, int m_iLevelMap[], float a_fDeltaTime);//The update for the upgrades that randomly spawns them on usable tiles.
	
	//\===========================================================================================
	//\ Get sprite 
	//\===========================================================================================
	
	Sprite* getSprite();//Returns the sprite for the upgrade.

	//\===========================================================================================
	//\ Get Active 
	//\===========================================================================================

	bool getActive();//Returns the upgrades status.

	//\===========================================================================================
	//\ Set Active 
	//\===========================================================================================

	void setActive(bool a_bActive);//Sets the upgrades status.

	//\===========================================================================================
	//\ Get type 
	//\===========================================================================================

	int getType();//Returns the upgrade type.

	//\===========================================================================================
	//\ Stop Drawing 
	//\===========================================================================================

	void Upgrade::stopDrawing();//Returns the upgrade type.

};

#endif