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

void Upgrade::Update(Tile *a_tTileArray, int m_iLevelMap[], float a_fDeltaTime)
{
	m_fUpgradeTimer -= a_fDeltaTime;

	if (m_fUpgradeTimer > 0)
	{
		if (m_fUpgradeTimer <= 1)
		{
			m_sUpgrade->stopDrawing();

			m_bActive = false;

			m_fUpgradeTimer = 0;
		}
	}
	else if (m_bActive == true)
	{
		m_sUpgrade->markForDraw();

		m_sUpgrade->update();

		m_fUpgradeTimer = 6;
	}
	else
	{
		srand((unsigned)time(0));

		int iRand = (rand() % 425) + 25;

		if (m_iLevelMap[iRand] == 0)
		{
			m_sUpgrade->setPosition(a_tTileArray[iRand].m_sTile->getPosition());//Sets the position of the upgrade to be equal to the argument passed in.
		
		    int iRandomType = (rand() % 20) + 1;
		    
		    switch (iRandomType)
		    {
		    case 1:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

		    	break;
		    case 2:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

		    	break;
		    case 3:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

				break;
		    case 4:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

				break;
		    case 5:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

				break;
		    case 6:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

				break;
		    case 7:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

				break;
		    case 8:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.0f, 0.0f, 0.25f, 1.0f);

				m_iUpgradeType = 1;

				m_bActive = true;

				break;
		    case 9:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

		    	break;
		    case 10:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

				break;
		    case 11:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

				break;
		    case 12:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

				break;
		    case 13:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

				break;
		    case 14:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

				break;
		    case 15:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.5f, 0.0f, 0.75f, 1.0f);

				m_iUpgradeType = 2;

				m_bActive = true;

				break;
		    case 16:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.25f, 0.0f, 0.5f, 1.0f);

				m_iUpgradeType = 3;

				m_bActive = true;

		    	break;
		    case 17:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.25f, 0.0f, 0.5f, 1.0f);

				m_iUpgradeType = 3;

				m_bActive = true;

				break;
		    case 18:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.25f, 0.0f, 0.5f, 1.0f);

				m_iUpgradeType = 3;

				m_bActive = true;

				break;
		    case 19:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.75f, 0.0f, 1.0f, 1.0f);

				m_iUpgradeType = 4;

				m_bActive = true;

		    	break;
		    case 20:
				UG::SetSpriteUVCoordinates(m_sUpgrade->getSpriteID(), 0.75f, 0.0f, 1.0f, 1.0f);

				m_iUpgradeType = 4;

				m_bActive = true;

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
	return m_sUpgrade;
}

//\===========================================================================================
//\ Get Active 
//\===========================================================================================

bool Upgrade::getActive()//Returns the upgrades status.
{
	return m_bActive;
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