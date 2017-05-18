#ifndef _TILE_H_
#define _TILE_H_

#include "Vector2.h"

class Tile
{
public:
	int iSpriteID = -1;
	Vector2 v2Pos;
	bool bWalkable = false;
};

#endif