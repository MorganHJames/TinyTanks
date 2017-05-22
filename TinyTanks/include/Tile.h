#ifndef _TILE_H_
#define _TILE_H_

#include "Vector2.h"
#include "Sprite.h"

struct Tile
{
	Sprite* m_sTile;//The default sprite for the tile.
	Vector2 v2Pos;
	bool bWalkable = false;
};

#endif