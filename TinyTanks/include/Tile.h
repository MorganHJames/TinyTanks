#ifndef _TILE_H_
#define _TILE_H_

#include "Vector2.h"
#include "Sprite.h"

struct Tile
{
	Sprite* m_sTile;//The default sprite for the tile.

	bool bWalkable = false;//If the tile is walkable or not.
};

#endif