//\===========================================================================================
//\ File: Upgrades.cpp
//\ Author: Morgan James
//\ Date Created: 23/05/2017
//\ Brief: Contains the function information for the class contained in Upgrades.h.
//\==========================================================================================

#include "Upgrades.h"
#include <cstdlib> 
#include <ctime> 
#include "UGFW.h"

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Upgrade::Upgrade(float a_fTileDimensions)
{
	m_sUpgrade = new Sprite("./images/upgrades.png", a_fTileDimensions, a_fTileDimensions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.25f, 1));//Creates a sprite for the upgrade.

	m_sUpgrade->setLayer(9);//Sets the layer of the upgrade so that it is rendered under the tank.

	m_sUpgrade->setPosition(Vector2(0,0));//Sets the position of the tanks base to be equal to the argument passed in.

	m_sUpgrade->setWidth(a_fTileDimensions);//Sets the width of the sprite to be the same as the member variable.

	m_sUpgrade->setHeight(a_fTileDimensions);//Sets the height of the sprite to be the same as the member variable.
}

void Upgrade::Update(Tile *a_tTileArray, int m_iLevelMap[], float a_fDeltaTime)//Updates the upgrade spawning it on different walkable tiles as different upgrades.
{
	m_fUpgradeTimer -= a_fDeltaTime;//Decrease the upgrade timer.

	if (m_fUpgradeTimer > 0)//If the upgrade timer is more than zero.
	{
		if (m_fUpgradeTimer <= 1)//If the upgrade timer is less than or equal to one.
		{
			m_sUpgrade->stopDrawing();//Stop drawing the upgrade.

			m_bActive = false;//Set the upgrades status to inactive.

			m_fUpgradeTimer = 0;//Sets the upgrade timer to zero.
		}
	}
	else if (m_bActive == true)//If the upgrade is active
	{
		m_sUpgrade->markForDraw();//Draw the upgrade.

		m_sUpgrade->update();//Update the upgrade.

		m_fUpgradeTimer = 6;//Set the upgrade timer to 6 which is its lifetime.
	}
	else
	{
		srand((unsigned)time(0));//Seed the random number generator with time.

		int iRand = (rand() % 425) + 25;//Set a random in for all the walkable tiles in the map.

		if (m_iLevelMap[iRand] == 0)//If the tile is walkable.
		{
			m_sUpgrade->setPosition(a_tTileArray[iRand].m_sTile->getPosition());//Sets the position of the upgrade to be equal to the argument passed in.
		
		    int iRandomType = (rand() % 20) + 1;//Create a random int between one and 20.
		    
		    switch (iRandomType)//Set the upgrade to the matching case. (the rarer upgrades(the bad ones) are in the pool less times)
		    {
		    case 1:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

		    	break;
		    case 2:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

		    	break;
		    case 3:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 4:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 5:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 6:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 7:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 8:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);//Set the UV coordinates to be equal to the first upgrade.

				m_iUpgradeType = 1;//Set the type of upgrade to be equal to the first upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 9:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

		    	break;
		    case 10:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 11:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 12:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 13:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 14:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 15:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);//Set the UV coordinates to be equal to the second upgrade.

				m_iUpgradeType = 2;//Set the type of upgrade to be equal to the second upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 16:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.25f, 0.0f, 0.5f, 1.0f);//Set the UV coordinates to be equal to the third upgrade.

				m_iUpgradeType = 3;//Set the type of upgrade to be equal to the third upgrade.

				m_bActive = true;//Activate the upgrade.

		    	break;
		    case 17:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.25f, 0.0f, 0.5f, 1.0f);//Set the UV coordinates to be equal to the third upgrade.

				m_iUpgradeType = 3;//Set the type of upgrade to be equal to the third upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 18:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.25f, 0.0f, 0.5f, 1.0f);//Set the UV coordinates to be equal to the third upgrade.

				m_iUpgradeType = 3;//Set the type of upgrade to be equal to the third upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    case 19:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.75f, 0.0f, 1.0f, 1.0f);//Set the UV coordinates to be equal to the fourth upgrade.

				m_iUpgradeType = 4;//Set the type of upgrade to be equal to the fourth upgrade.

				m_bActive = true;//Activate the upgrade.

		    	break;
		    case 20:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.75f, 0.0f, 1.0f, 1.0f);//Set the UV coordinates to be equal to the fourth upgrade.

				m_iUpgradeType = 4;//Set the type of upgrade to be equal to the fourth upgrade.

				m_bActive = true;//Activate the upgrade.

				break;
		    }
		}
	}
}

//\===========================================================================================
//\ Get sprite 
//\===========================================================================================

Sprite* Upgrade::getSprite()//Returns the sprite for the upgrade.
{
	return m_sUpgrade;//Returns the sprite.
}

//\===========================================================================================
//\ Get Active 
//\===========================================================================================

bool Upgrade::getActive()//Returns the upgrades status.
{
	return m_bActive;//Returns the upgrades status.
}

//\===========================================================================================
//\ Set Active 
//\===========================================================================================

void Upgrade::setActive(bool a_bActive)//Sets the upgrades status.
{
	m_bActive = a_bActive;
}

//\===========================================================================================
//\ Get type 
//\===========================================================================================

int Upgrade::getType()//Returns the upgrade type.
{
	return m_iUpgradeType;//Returns the upgrade type.
}

//\===========================================================================================
//\ Stop Drawing 
//\===========================================================================================

void Upgrade::stopDrawing()//Returns the upgrade type.
{
	m_sUpgrade->stopDrawing();//Returns the upgrade type.
}