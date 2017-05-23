//\===========================================================================================
//\ File: Map.cpp
//\ Author: Morgan James
//\ Date Created: 17/05/2017
//\ Brief: Contains the function information for the class contained in Map.h.
//\==========================================================================================

#include "Map.h"
#include "UGFW.h"
#include <fstream>
#include <sstream>
#include "Sprite.h"

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Map::Map(const int a_c_iWidth, char* a_c_sFilename, char* a_c_sTileSet)//A constructor for a map that takes in the screen height and width along with the map file location and the tile set location that will be used.
{
	m_iSpriteDimentions = (float)a_c_iWidth / (float)m_iTilesWide;//Sets the sprite dimensions equal to the width of the screen divided by how many tiles wide the map will be.

	m_tTileArray = new Tile[m_iTilesWide * m_iTilesHigh];//An array of tiles that will be moved to there correct position.

	std::ifstream levelMap;//Sets the stream directory.

	levelMap.open(a_c_sFilename);//Opens the level map.

	if (levelMap.is_open())//If the map text file is open execute the following code.
	{
		for (int i = 0; i < m_iTilesHigh * m_iTilesWide; ++i)//Iterates through each tile in the array.
		{
			levelMap >> m_iLevelMap[i];//Sets every number in the int array to be equivalent to the counterpart in the text file.
		}

		levelMap.close();//Closes the text file.
	}

	for (int iCol = 0; iCol < m_iTilesWide; ++iCol)//For every column of the map.
	{
		for (int iRow = 0; iRow < m_iTilesHigh; ++iRow)//For every row of the map.
		{
			Tile &trCurrentTile = this->getTile(iCol, iRow);//Gets a reference to the current tile.

			int iTileType = getTileType(iCol, iRow);//Creates an integer equal to the type of tile the code is currently assigning.

			if (iTileType == 0)//If the tile type is equal to the floor tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.5f, 0.0f, 0.75f, 0.25f));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.bWalkable = true;//Sets the current tile's boolean value of walkable to be equal to true therefore allowing the player to move across it.
				
				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 1)//If the tile type is equal to the solid no side tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.25f, 0.0f, 0.5f, 0.25f));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 2)//If the tile type is equal to the bottom solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.0f, 0.0f, 0.25f, 0.25f));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.
			
				trCurrentTile.m_sTile->rotateZ(180);//Rotates the current tile 180 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 3)//If the tile type is equal to the left solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.25, 0.25));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(90);//Rotates the current tile 270 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 4)//If the tile type is equal to the top solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.25, 0.25));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 5)//If the tile type is equal to the right solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.25, 0.25));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(270);//Rotates the current sprite 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 6)//If the tile type is equal to the top right solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.125, 0.125));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(0);//Rotates the current tile 270 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 7)//If the tile type is equal to the bottom right solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.125, 0.125));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(90);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 8)//If the tile type is equal to the bottom left solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.125, 0.125));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(180);//Rotates the current sprite 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 9)//If the tile type is equal to the top left solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0, 0.125, 0.125));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(270);//Rotates the current sprite 180 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 10)//If the tile type is equal to the left and right solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0.25, 0.25, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 11)//If the tile type is equal to the top and bottom solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0, 0.25, 0.25, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.
				
				trCurrentTile.m_sTile->rotateZ(90);//Rotates the current tile 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 12)//If the tile type is equal to the left, right and top solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.5, 0.25, 0.75, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(180);//Rotates the current tile 180 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 13)//If the tile type is equal to the bottom, right and top solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.5, 0.25, 0.75, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.
				
				trCurrentTile.m_sTile->rotateZ(90);//Rotates the current tile 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 14)//If the tile type is equal to the left, bottom and right solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.5, 0.25, 0.75, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 15)//If the tile type is equal to the left, bottom and top solid tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.5, 0.25, 0.75, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(270);//Rotates the current sprite 180 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 16)//If the tile type is equal to the bottom left corner tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.25, 0.25, 0.5, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(90);//Rotates the current sprite 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 17)//If the tile type is equal to the top left corner tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.25, 0.25, 0.5, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(0);//Rotates the current sprite 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 18)//If the tile type is equal to the top right corner tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.25, 0.25, 0.5, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(270);//Rotates the current sprite 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
			else if (iTileType == 19)//If the tile type is equal to the bottom right corner tile.
			{
				trCurrentTile.m_sTile = new Sprite(a_c_sTileSet, m_iSpriteDimentions, m_iSpriteDimentions, Vector2(0.5f, 0.5f), Vector4(0.25, 0.25, 0.5, 0.5));//Creates a sprite for the tile and sets the UV coordinates of the sprite to be equal to it's tile type of no rotation.

				trCurrentTile.m_sTile->setLayer(0);//Sets the current sprite layer to be in the background.

				trCurrentTile.m_sTile->rotateZ(180);//Rotates the current sprite 90 degrees.

				trCurrentTile.m_sTile->setWidth(m_iSpriteDimentions);//Sets the width of the sprite to be the same as the member variable.

				trCurrentTile.m_sTile->setHeight(m_iSpriteDimentions);//Sets the height of the sprite to be the same as the member variable.
			}
		}
	}
}

//\===========================================================================================
//\ Destructor
//\===========================================================================================

Map::~Map()//A default destructor for the Map.
{

}

//\===========================================================================================
//\ Draw Functions
//\===========================================================================================

void Map::markForDraw()//A function to draw the map.
{
	for (int iRow = 0; iRow < m_iTilesHigh; ++iRow)//For each row of the map.
	{
		for (int iCol = 0; iCol < m_iTilesWide; ++iCol)//For each column of the map.
		{
			Tile &trCurrentTile = getTile(iCol, iRow);//Gets a reference to the current tile.

			trCurrentTile.m_sTile->markForDraw();//Draws the current tile.

			float iHalfSize = m_iSpriteDimentions * 0.5f;//a float used to start off of the origin by half of the sprites dimensions.

			trCurrentTile.m_sTile->setPosition(Vector2(iCol * m_iSpriteDimentions + iHalfSize, iRow * m_iSpriteDimentions + iHalfSize));

			trCurrentTile.m_sTile->update();//Updates the sprites.
        }
	}
}

void Map::stopDrawing()//A function to stop drawing the map.
{
	for (int iRow = 0; iRow < m_iTilesHigh; ++iRow)
	{
		for (int iCol = 0; iCol < m_iTilesWide; ++iCol)
		{
			Tile &trCurrentTile = getTile(iCol, iRow);//Gets a reference to the current tile.

			trCurrentTile.m_sTile->stopDrawing();//Stops drawing the current sprite.
		}
	}
}

//\===========================================================================================
//\ Get Tile
//\===========================================================================================

Tile& Map::getTile(const int a_c_iCol, int a_c_iRow)//Gets the tile at the desired position in the tile array.
{
	return m_tTileArray[(a_c_iRow * m_iTilesWide) + a_c_iCol];//Returns a reference to the tile at the specified position.
}

int Map::getTileType(const int a_c_iCol, int a_c_iRow)//Gets the tile type from iLevelMap array.
{
	return m_iLevelMap[(a_c_iRow * m_iTilesWide) + a_c_iCol];//Returns the type of the tile at the specified location.
}

//\===========================================================================================
//\ Get Tile Array
//\===========================================================================================

Tile* Map::getTileArray()//Returns the tile array.
{
	return m_tTileArray;//Returns the tile array.
}

//\===========================================================================================
//\ Get Tile Array Index
//\===========================================================================================

int* Map::getTileArrayIndex()//Returns the tile array Index.
{
	return m_iLevelMap;//Returns the tile array index.
}

//\===========================================================================================
//\ Get Tile Dimensions
//\===========================================================================================

float Map::getTileDimensions()//Returns the tile dimensions.
{
	return m_iSpriteDimentions;//Returns the tile dimensions.
}