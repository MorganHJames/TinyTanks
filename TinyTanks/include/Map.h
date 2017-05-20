//\===========================================================================================
//\ File: Map.h
//\ Author: Morgan James
//\ Date Created: 17/05/2017
//\ Brief: Contains the map class declarations.
//\===========================================================================================

#ifndef _MAP_H
#define _MAP_H

#include "string"
#include "Vector2.h"
#include "Tile.h"

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Map
//\ Brief: A class reads from a .TXT file to generate a map using tiles.
//\===========================================================================================

class Map
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

	int m_iTilesHigh = 18;//How many tiles high the map is.

	int m_iTilesWide = 25;//How many tiles wide the map is.

	int m_iLevelMap[25 * 18];//An array to hold the type of tile in each position.

	float m_iSpriteDimentions = 0;//A float to represent the height and the width of each tile.

	Tile *m_tTileArray = new Tile[25 * 18];//An array of tiles that will be moved to there correct position.

public:
	//\===========================================================================================
	//\ Constructor 
	//\===========================================================================================

	Map(const int a_c_iWidth, char* a_c_sFilename, char* a_c_sTileSet);//A constructor for a map that takes in the screen height and width along with the map file location and the tile set location that will be used.

	//\===========================================================================================
	//\ Destructor
	//\===========================================================================================

	~Map();//A default destructor for the Map.

	//\===========================================================================================
	//\ Draw Functions
	//\===========================================================================================

	void markForDraw();//A function to draw the map.

	void stopDrawing();//A function to stop drawing the map.

	//\===========================================================================================
	//\ Get Tile
	//\===========================================================================================

	Tile& getTile(const int a_iCol, int a_iRow);//Gets the tile at the desired position in the tile array.

	int getTileType(const int a_iCol, int a_iRow);//Gets the tile type from iLevelMap array.

};

#endif
