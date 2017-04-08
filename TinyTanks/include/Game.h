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

	int iScreenWidth = 0, iScreenHeight = 0;//Integers to save to screen height and width.
	float fDeltaTime = 0;//A float used to hold the time between the current time and the last time the processor was called.
	float fSplashTimer = 0;//A float used to count time passed for how long the splash screen should be displayed.

public:
	//\===========================================================================================
	//\ Constructor 
	//\===========================================================================================

	Game(const int a_c_iWidth, int a_c_iHeight);//Creates a game with a switch statement for game state control.
	
};
#endif