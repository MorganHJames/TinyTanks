#ifndef _TILE_H_
#define _TILE_H_

#include "Vector2.h"

struct Tile
{
	int iSpriteID = -1;
	Vector2 v2Pos;
	bool bWalkable = false;
};

#endif