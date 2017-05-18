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

Map::Map(const int a_c_iWidth, int a_c_iHeight, std::string &a_c_sFilename, char* a_c_sTileSet)
{
	std::ifstream levelMap;//Sets the stream directory.

	levelMap.open(a_c_sFilename);//Opens the level map.

	std::string row;

	while (std::getline(levelMap, row))
	{
		int iRow = 0;
		std::istringstream iss(row);

		char column[56];

		while (iss >> column)
		{
			for (int iColumn = 0; iColumn < 57; ++iColumn)
			{
				Tile &rcurrentTile = getTile(pTileArray, iColumn, iRow);

				if (column[iColumn] == '0')
				{
					rcurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, a_c_iWidth / 56.0f, a_c_iHeight / 35.0f, true);
					UG::SetSpriteUVCoordinates(rcurrentTile.iSpriteID, 0, 0, 1, 1);
				}
				else if (column[iColumn] == '1')
				{

				}
				int iWidthPositionIncs = (int)((a_c_iWidth * 0.7f) / 56);

				int iHeightPositionIncs = (int)((a_c_iHeight * 0.4f) / 35);

				int iStartingWidth = (int)(a_c_iWidth * 0.15f);

				int iStartingHeight = (int)(a_c_iHeight * 0.55f);

				rcurrentTile.v2Pos.setfX((iStartingWidth + iWidthPositionIncs * (iColumn + 0.5f)));

				rcurrentTile.v2Pos.setfY((iStartingHeight + iHeightPositionIncs * (iRow - 0.5f)));
			}

		}
	
		iRow++;
	}
	levelMap.close();

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
	for (int iRow = 0; iRow < 36; ++iRow)
	{
		for (int iCol = 0; iCol < 57; ++iCol)
		{
			Tile &rcurrentTile = getTile(pTileArray, iCol, iRow);
			UG::DrawSprite(rcurrentTile.iSpriteID);
		}
	}
}

void Map::stopDrawing()
{
	for (int iRow = 0; iRow < 36; ++iRow)
	{
		for (int iCol = 0; iCol < 57; ++iCol)
		{
			Tile &rcurrentTile = getTile(pTileArray, iCol, iRow);
			UG::StopDrawingSprite(rcurrentTile.iSpriteID);
		}
	}
}

//\===========================================================================================
//\ Get Tile
//\===========================================================================================

Tile& Map::getTile(Tile *a_pTileArray, int a_iCol, int a_iRow)
{
	return pTileArray[a_iRow * 56 + a_iCol];
}
