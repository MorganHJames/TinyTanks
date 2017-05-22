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
#include "Map.h"
#include "Button.h"

//\===========================================================================================
//\ Constructor 
//\===========================================================================================

Game::Game(const int a_c_iWidth, int a_c_iHeight)//Creates a game with a switch statement for game state control.
{
	if (UG::Create(a_c_iWidth, a_c_iHeight, false, "Tiny Tanks", 100, 100))//An if statement calling the UG::create that returns true, and creates a window with the height and width passed in at the position passed in called the name passed in.
	{
        //\===========================================================================================
        //\ Initialization
        //\===========================================================================================

		UG::GetScreenSize(m_iScreenWidth, m_iScreenHeight);//Sets the corresponding integers to the correct values for height and width.

		UG::SetBackgroundColor(UG::SColour(0x2A, 0x57, 0x66, 0xFF));//Sets the background color of the screen to match the values of colors passed in.

		UG::AddFont("./fonts/invaders.fnt");//Adds the invaders font to the game.

		UG::SetFont("./fonts/invaders.fnt");//Sets the font of the game to be the invaders font.

		GameState currentState = SPLASH;//Defines the first state of the game.

		Tank tCampaignPlayer(Vector2(0.5f * m_iScreenWidth, 0.5f * m_iScreenHeight), true, 87, 83, 65, 68, 69, 81, "./images/tanks.png");//Initializes the players tank for campaign.

		Tank tVersusPlayer1(Vector2(0.25f * m_iScreenWidth, 0.5f * m_iScreenHeight), false, 87, 83, 65, 68, 69, 81, "./images/tanks.png");//Initializes the player1 tank for versus.
		
		Tank tVersusPlayer2(Vector2(0.75f * m_iScreenWidth, 0.5f * m_iScreenHeight), false, 328, 325, 324, 326, 329, 327, "./images/tanks.png");//Initializes the player2 tank for versus.

		Map mCampaignLevel1(a_c_iWidth, "./maps/level1.txt","./images/tileSetOne.png");//Initializes the first map.

		Button bCampaign("./images/start.png", Vector2((float)m_iScreenWidth * 0.5, (float) m_iScreenHeight * 0.75), 100, 100, 257);

		Button bVS("./images/start.png", Vector2((float) m_iScreenWidth * 0.5, (float) m_iScreenHeight * 0.5), 100, 100, 257);

		Button bExit("./images/start.png", Vector2((float) m_iScreenWidth * 0.5, (float) m_iScreenHeight * 0.25), 100, 100, 257);

		//\===========================================================================================
		//\ Update
		//\===========================================================================================

		do//Do whilst the framework updates successfully.
		{
			if (UG::IsKeyDown(256))//If ESC is pressed.
				UG::Close();//Close the game.

			m_fDeltaTime = UG::GetDeltaTime();//Sets the float m_fDeltaTime to be equal to the time between now and the last call of the processor.
		
			UG::ClearScreen();//Clears the screen.

			UG::GetMousePos(m_dMousePosX, m_dMousePosY);//Sets the mouse position equal to the mouse position on the screen.

			m_dMousePosY = a_c_iHeight - m_dMousePosY;

			switch (currentState)//The switch statement containing all the different stages of the game.
			{
			case SPLASH://The splash screen state that shows some text and after a moment goes to the menu.
			{
				UG::DrawString("Tiny Tanks", (int)(m_iScreenWidth*0.0f), (int)(m_iScreenHeight * 0.6f), (1.5));//Draws the string Tiny Tanks to the screen like a title.
				
				UG::DrawString("Produced by Morgan James", (int)(m_iScreenWidth*0.075f), (int)(m_iScreenHeight * 0.4f), (1.5));//Draws the string Produced by Morgan James to the screen like a produced by tag.
				
				m_fSplashTimer += m_fDeltaTime;//Starts the incrementation of the variable that controls how long the screen is displayed for.

				if (m_fSplashTimer > 1)//If splash timer gets above 1 move to the menu screen.
				{
					m_fSplashTimer = 0;//Reset the splash timer.

					//\===========================================================================================
					//\ MENU Setup
					//\===========================================================================================
					
					currentState = MENU;//Sets the current state of game play to the menu.

					bCampaign.markForDraw();//Sets the campaign button to be drawn.

					bVS.markForDraw();//Sets the versus button to be drawn.

					bExit.markForDraw();//Sets the Exit button to be drawn.
				}
				break;
			}

			case MENU://The Menu state where buttons should be present to navigate the application.
			{
				//\===========================================================================================
				//\ CAMPAIGN Setup
				//\===========================================================================================
				
				if (bCampaign.buttonLogic(m_dMousePosX, m_dMousePosY))
				{
					currentState = CAMPAIGN;//Sets the current state of game play to the main game.

					tCampaignPlayer.markForDraw();//Sets the player tank to be drawn.

					mCampaignLevel1.markForDraw();//Sets the first map to be drawn.

					bCampaign.stopDrawing();//Stops the campaign button from being drawn.

					bVS.stopDrawing();//Stops the versus button from being drawn.

					bExit.stopDrawing();//Stops the exit button from being drawn.
				}
				
				//\===========================================================================================
				//\ VERSUS Setup
				//\===========================================================================================
				
				if (bVS.buttonLogic(m_dMousePosX, m_dMousePosY))
				{
					currentState = VERSUS;//Sets the current state of game play to the main game.

					mCampaignLevel1.markForDraw();//Sets the first map to be drawn.

					tVersusPlayer1.markForDraw();//Sets the player tank to be drawn.

					tVersusPlayer2.markForDraw();//Sets the player tank to be drawn.

					bCampaign.stopDrawing();//Stops the campaign button from being drawn.

					bVS.stopDrawing();//Stops the versus button from being drawn.

					bExit.stopDrawing();//Stops the exit button from being drawn.
				}
				
				//\===========================================================================================
				//\ EXIT 
				//\===========================================================================================
				
				if (bExit.buttonLogic(m_dMousePosX, m_dMousePosY))
				{
					bCampaign.stopDrawing();//Stops the campaign button from being drawn.

					bVS.stopDrawing();//Stops the versus button from being drawn.

					bExit.stopDrawing();//Stops the exit button from being drawn.

					UG::Dispose();//Unloads loaded components of the framework.

					UG::Close();//Closes the game.
				}

				break;
			}

			case CAMPAIGN://The game play state where the game will be played and the user should be the majority of the time.
			{
				tCampaignPlayer.tankLogic(m_fDeltaTime, m_dMousePosX, m_dMousePosY);//Allows for movement of the player tank.
				break;
			}
			case VERSUS://The game play state where the game will be played and the user should be the majority of the time.
			{
				tVersusPlayer1.tankLogic(m_fDeltaTime, m_dMousePosX, m_dMousePosY);//Allows for movement of the player1 tank.

				tVersusPlayer2.tankLogic(m_fDeltaTime, m_dMousePosX, m_dMousePosY);//Allows for movement of the player1 tank.
				break;
			}
			default://The default statement which should never be used.
				break;
			}

		} while (UG::Process());//Returns true if the framework updates successfully and false if not.

		//\===========================================================================================
		//\ Clean Up
		//\===========================================================================================

		UG::Dispose();//Unloads loaded components of the framework.

	}
}