//\===========================================================================================
//\ File: Game.cpp
//\ Author: Morgan James
//\ Date Created: 19/03/2017
//\ Brief: Contains the function information for the class contained in Game.h.
//\===========================================================================================

#include "Game.h"
#include "UGFW.h"
#include "GameStates.h"
#include "Vector2.h"
#include "Tank.h"

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Game::Game(int a_c_iWidth, int a_c_iHeight)
{
	if (UG::Create(a_c_iWidth, a_c_iHeight, false, "Tiny Tanks", 100, 100))
	{
		//Initialization
		UG::GetScreenSize(iScreenWidth, iScreenHeight);
		UG::SetBackgroundColor(UG::SColour(0x2A, 0x57, 0x66, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");

		UG::SetFont("./fonts/invaders.fnt");

		Tank player(Vector2(0.5f, 0.5f), 87, 83, 65, 68, 69, 81, iScreenWidth, iScreenHeight);
		Tank Enemy1(Vector2(0.8f, 0.8f), iScreenWidth, iScreenHeight);
		Tank Enemy2(Vector2(0.3f, 0.3f), iScreenWidth, iScreenHeight);

		//Defines the first state of play.
		GameState currentState = SPLASH;


		do
		{
			// quit our application when escape is pressed
			if (UG::IsKeyDown(256))
				UG::Close();


			float fDeltaTime = UG::GetDeltaTime();

				//Draw some text
				UG::ClearScreen();

			//The switch statement containing all the different stages of the game.
			switch (currentState)
			{

			case SPLASH:
			{
				//Draws the string Tiny Tanks to the screen like a title.
				UG::DrawString("Tiny Tanks", iScreenWidth*(int)0.0f, iScreenHeight * (int)0.6f, (3));

				//Draws the string Produced by Morgan James to the screen like a produced by tag.
				UG::DrawString("Produced by Morgan James", iScreenWidth*(int)0.075f, iScreenHeight * (int)0.4f, (1.5));

				//Starts the incrementation of the variable that controls how long the screen is displayed for.
				fSplashTimer += fDeltaTime;

				//After splash timer gets above the time below move to the menu screen.
				if (fSplashTimer > 1)
				{

					int fSplashTimer = 0;

					//Sets the current state of game play to the menu.
					currentState = MENU;

				}
				break;
			}

			case MENU:
			{
				currentState = GAMEPLAY;
				
				break;
			}

			case GAMEPLAY:
			{
				player.tankMovement(fDeltaTime);
				Enemy1.tankMovement(fDeltaTime);
				Enemy2.tankMovement(fDeltaTime);
				
				break;
			}

			case OPTIONS:
			{

				break;
			}

			case HIGHSCORE:
			{

				break;
			}

			default:
				break;

			}




		} while (UG::Process());


		UG::Dispose();


	}
}