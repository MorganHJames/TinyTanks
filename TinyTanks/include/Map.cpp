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

	for (int i = 0; i < 1960; ++i)//Iterates through each tile in the array.
	{
		levelMap >> iLevelMap[i];
	}

	levelMap.close();

	for (int iCol = 0; iCol < 56; ++iCol)
	{
		for (int iRow = 0; iRow < 35; ++iRow)
		{

			Tile &rCurrentTile = this->getTile(iCol, iRow);

			if (iLevelMap[iRow, iCol] == 0)
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, a_c_iWidth / 56.0f, a_c_iHeight / 35.0f, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 1, 1);

			}
			else if (iLevelMap[iRow , iCol] == 1)
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, a_c_iWidth / 56.0f, a_c_iHeight / 35.0f, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 1, 1);

			}

			int iWidthPositionIncs = (int)((a_c_iWidth * 0.7f) / 56);//Will be changed.

			int iHeightPositionIncs = (int)((a_c_iHeight * 0.4f) / 35);//Will be changed.

			int iStartingWidth = (int)(a_c_iWidth * 0.15f);//Will be changed.

			int iStartingHeight = (int)(a_c_iHeight * 0.55f);//Will be changed.

			rCurrentTile.v2Pos.setfX((iStartingWidth + iWidthPositionIncs * (iCol + 0.5f)));//Will be changed.

			rCurrentTile.v2Pos.setfY((iStartingHeight + iHeightPositionIncs * (iRow - 0.5f)));//Will be changed.


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
	for (int iRow = 0; iRow < 35; ++iRow)
	{
		for (int iCol = 0; iCol < 56; ++iCol)
		{
			Tile &rcurrentTile = getTile(iCol, iRow);
			UG::DrawSprite(rcurrentTile.iSpriteID);
			UG::MoveSprite(rcurrentTile.iSpriteID,iCol*(a_c_iWidth / 56.0f))
		}
	}
}

void Map::stopDrawing()
{
	for (int iRow = 0; iRow < 35; ++iRow)
	{
		for (int iCol = 0; iCol < 56; ++iCol)
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
	return pTileArray[a_iRow * 56 + a_iCol];
}
