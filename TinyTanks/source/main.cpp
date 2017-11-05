//\===========================================================================================
//\ File: TinyTanks/main.cpp
//\ Author: Morgan James
//\ Date Created: 20/02/2017
//\ Brief: A recreation of the game Tiny Tanks using c++.
//\===========================================================================================

#include "Game.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")//Stops the console from appearing.

int main()
{
	
	Game newGame(1200, 864);
	return 0;
}
