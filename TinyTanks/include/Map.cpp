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

			if (iLevelMap[iRow, iCol] == 0)//Floor
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.5, 0, 0.75, 0.25);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = true;
			}
			else if (iLevelMap[iRow, iCol] == 1)//Solid no side 
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.25, 0, 0.5, 0.25);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 2)//Under solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.25, 0.25);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 3)//Left solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.25, 0.25);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 90);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 4)//Top solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.25, 0.25);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 180);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 5)//Right solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.25, 0.25);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 270);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 6)//Top right solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.125, 0.125);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 7)//Bottom right solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.125, 0.125);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 90);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 8)//Bottom left solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.125, 0.125);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 180);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 9)//Top left solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0, 0.125, 0.125);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 270);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 10)//Left and right solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0.25, 0.25, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 11)//Top and bottom solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0, 0.25, 0.25, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 90);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 12)//Left, right and top solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.5, 0.25, 0.75, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 13)//Bottom, right and top solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.5, 0.25, 0.75, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 90);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 14)//Left, bottom and right solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.5, 0.25, 0.75, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 180);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 15)//Left, bottom and top solid
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.5, 0.25, 0.75, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 270);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 16)//Bottom left corner
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.25, 0.25, 0.5, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 17)//Top left corner
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.25, 0.25, 0.5, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 90);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 18)//Top right corner
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.25, 0.25, 0.5, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 180);

				rCurrentTile.bWalkable = false;

			}
			else if (iLevelMap[iRow, iCol] == 19)//Bottom right corner
			{
				rCurrentTile.iSpriteID = UG::CreateSprite(a_c_sTileSet, iSpriteDimentions, iSpriteDimentions, true);

				UG::SetSpriteUVCoordinates(rCurrentTile.iSpriteID, 0.25, 0.25, 0.5, 0.5);

				UG::SetSpriteLayer(rCurrentTile.iSpriteID, 0);

				UG::RotateSprite(rCurrentTile.iSpriteID, 270);

				rCurrentTile.bWalkable = false;

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
