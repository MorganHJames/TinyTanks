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

	int m_iScreenWidth = 0, m_iScreenHeight = 0;//Integers to save to screen height and width.

	float m_fDeltaTime = 0;//A float used to hold the time between the current time and the last time the processor was called.

	float m_fSplashTimer = 0;//A float used to count time passed for how long the splash screen should be displayed.

	double m_dMousePosX = 0;//The mouse x position on the screen.

	double m_dMousePosY = 0;//The mouse y position on the screen.

public:
	//\===========================================================================================
	//\ Constructor 
	//\===========================================================================================

	Game(const int a_c_iWidth, int a_c_iHeight);//Creates a game with a switch statement for game state control.
	
};
#endif