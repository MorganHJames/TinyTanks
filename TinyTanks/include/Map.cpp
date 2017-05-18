//\===========================================================================================
//\ File: Map.cpp
//\ Author: Morgan James
//\ Date Created: 17/05/2017
//\ Brief: Contains the function information for the class contained in Map.h.
//\==========================================================================================

#include "Map.h"
#include "UGFW.h"
#include <iostream>
#include <fstream>
#include <sstream>

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Map::Map(const int a_c_iWidth, int a_c_iHeight, char* a_c_sFilename, char* a_c_sTileSet)
{
	std::ifstream levelMap;//Sets the stream directory.

	levelMap.open(a_c_sFilename);//Opens the level map.

	iWidth = a_c_iWidth;

	iHeight = a_c_iHeight;

	for (int i = 0; i < iTilesHigh*iTilesWide; ++i)//Iterates through each tile in the array.
	{
		levelMap >> iLevelMap[i];
	}

	levelMap.close();

	for (int iCol = 0; iCol < iTilesWide; ++iCol)
	{
		for (int iRow = 0; iRow < iTilesHigh; ++iRow)
		{

			Tile &rCurrentTile = this->getTile(iCol, iRow);

			if (iLevelMap[iRow, iCol] == 0)
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 1, 1);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

			}
			else if (iLevelMap[iRow , iCol] == 1)
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 1, 1);

			}


		}
	}

}

//\===========================================================================================
//\ Destructor
//\===========================================================================================

Map::~Map()
{

}


//\===========================================================================================
//\ Draw Functions
//\===========================================================================================

void Map::markForDraw()
{
	for (int iRow = 0; iRow < iTilesHigh; ++iRow)
	{
		for (int iCol = 0; iCol < iTilesWide; ++iCol)
		{
			Tile &rcurrentTile = getTile(iCol, iRow);
			UG::DrawSprite(rcurrentTile.iSpriteID);
			UG::MoveSprite(rcurrentTile.iSpriteID, iCol * iSpriteDimentions, iRow * iSpriteDimentions);
		}
	}
}

void Map::stopDrawing()
{
	for (int iRow = 0; iRow < iTilesHigh; ++iRow)
	{
		for (int iCol = 0; iCol < iTilesWide; ++iCol)
		{
			Tile &rcurrentTile = getTile(iCol, iRow);
			UG::StopDrawingSprite(rcurrentTile.iSpriteID);
		}
	}
}

//\===========================================================================================
//\ Get Tile
//\===========================================================================================

Tile& Map::getTile(int a_iCol, int a_iRow)
{
	return pTileArray[a_iRow * iTilesWide + a_iCol];
}
