//\===========================================================================================
//\ File: Game.h
//\ Author: Morgan James
//\ Date Created: 18/03/2017
//\ Brief: Contains the Game class declarations.
//\===========================================================================================

#ifndef _GAME_H_
#define _GAME_H_

//\===========================================================================================
//\ Author: Morgan James
//\ Class: Game
//\ Brief: A class that is used to implement the game loop.
//\===========================================================================================

class Game
{
private:
	//\===========================================================================================
	//\ Member Variables 
	//\===========================================================================================

	int iScreenWidth = 0, iScreenHeight = 0;
	float fDeltaTime = 0;
	float fSplashTimer = 0;

public:
	//\===========================================================================================
	//\ Constructor 
	//\===========================================================================================

	Game(int a_c_iWidth, int a_c_iHeight);
	
};
#endif