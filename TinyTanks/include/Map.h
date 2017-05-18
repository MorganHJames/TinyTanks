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
	

	int iLevelMap[1961];

	Tile *pTileArray = new Tile[1961];

public:
	//\===========================================================================================
	//\ Constructor 
	//\===========================================================================================

	Map(const int a_c_iWidth, int a_c_iHeight, char* a_c_sFilename, char* a_c_sTileSet);

	//\===========================================================================================
	//\ Destructor
	//\===========================================================================================

	~Map();

	//\===========================================================================================
	//\ Draw Functions
	//\===========================================================================================

	void markForDraw();

	void stopDrawing();

	//\===========================================================================================
	//\ Get Tile
	//\===========================================================================================

	Tile& getTile(int a_iCol, int a_iRow);

};

#endif