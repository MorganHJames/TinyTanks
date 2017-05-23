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
#include "MathUtil.h"
#include "Upgrades.h"

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

		float fTitleWidth = 400.0f;//The titles width.

		float fTitleHeight = 100.0f;//The title's height.

		bool bIncrease = true;//Whether or not the title is increasing in size.

		Sprite title("./images/title.png", fTitleWidth, fTitleHeight, Vector2(0.5f,0.5f),Vector4(0,0,1,1));//Initializes the title image.

		GameState currentState = SPLASH;//Defines the first state of the game.

		Tank tCampaignPlayer(Vector2(0.5f * m_iScreenWidth, 0.5f * m_iScreenHeight), true, 87, 83, 65, 68, 69, 81, 32, "./images/tanks.png");//Initializes the players tank for campaign.

		Tank tCampaignAI1(Vector2(0.75f * m_iScreenWidth, 0.5f * m_iScreenHeight));//Initializes the AI tank for campaign.

		Tank tCampaignAI2(Vector2(0.25f * m_iScreenWidth, 0.5f * m_iScreenHeight));//Initializes the AI tank for campaign.

		Tank tVersusPlayer1(Vector2(0.25f * m_iScreenWidth, 0.5f * m_iScreenHeight), false, 87, 83, 65, 68, 69, 81, 32, "./images/tanks.png");//Initializes the player1 tank for versus.
		
		Tank tVersusPlayer2(Vector2(0.75f * m_iScreenWidth, 0.5f * m_iScreenHeight), false, 328, 325, 324, 326, 329, 327, 335, "./images/tanks2.png");//Initializes the player2 tank for versus.

		Map mMenu(a_c_iWidth, "./maps/level1.txt","./images/tileSetOne.png");//Initializes the first map.

		mMenu.markForDraw();//Sets the menu map to be drawn.

		Map mCampaignLevel1(a_c_iWidth, "./maps/level2.txt", "./images/tileSetOne.png");//Initializes the first map.

		Button bCampaign("./images/campaign.png", Vector2((float)m_iScreenWidth * 0.5f, (float) m_iScreenHeight * 0.65f), 200, 200, 257);//Initializes the campaign button.

		Button bVS("./images/versus.png", Vector2((float) m_iScreenWidth * 0.5f, (float) m_iScreenHeight * 0.4f), 200, 200, 257);//Initializes the versus button.

		Button bExit("./images/quit.png", Vector2((float) m_iScreenWidth * 0.5f, (float) m_iScreenHeight * 0.15f), 200, 200, 257);//Initializes the exit button.																											  //Explosion set up.

		Upgrade powerUp(mCampaignLevel1.getTileDimensions());//Initializes the upgrades.

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

			m_dMousePosY = a_c_iHeight - m_dMousePosY;//Sets the mouse position to be the height of the screen minus the current mouse height.

			switch (currentState)//The switch statement containing all the different stages of the game.
			{
			case SPLASH://The splash screen state that shows some text and after a moment goes to the menu.
			{
				UG::DrawString("Tiny Tanks", (int)(m_iScreenWidth*0.4f), (int)(m_iScreenHeight * 0.65f), (1.5));//Draws the string Tiny Tanks to the screen like a title.
				
				UG::DrawString("Produced by Morgan James", (int)(m_iScreenWidth*0.28f), (int)(m_iScreenHeight * 0.5f), (1.5));//Draws the string Produced by Morgan James to the screen like a produced by tag.
				
				m_fSplashTimer += m_fDeltaTime;//Starts the incrementation of the variable that controls how long the screen is displayed for.

				if (m_fSplashTimer > 3)//If splash timer gets above 1 move to the menu screen.
				{
					m_fSplashTimer = 0;//Reset the splash timer.

					//\===========================================================================================
					//\ MENU Setup
					//\===========================================================================================
					
					currentState = MENU;//Sets the current state of game play to the menu.

					title.setPosition(Vector2(0.5f * m_iScreenWidth, 0.85f * m_iScreenHeight));//Sets the position of the title image.

					title.update();//Updates the title image.

					title.markForDraw();//Sets the title image to be drawn.

					bCampaign.markForDraw();//Sets the campaign button to be drawn.

					bVS.markForDraw();//Sets the versus button to be drawn.

					bExit.markForDraw();//Sets the Exit button to be drawn.
				}
				break;
			}

			case MENU://The Menu state where buttons should be present to navigate the application.
			{
				if (bIncrease == true)//If increase is true.
				{
					fTitleWidth += 20 * m_fDeltaTime;//Increase the titles' width.

					fTitleHeight += 20 * m_fDeltaTime;//Increase the titles' height

					if (fTitleHeight >= 200)//If the titles' height is 200.
					{
						bIncrease = false;//Set increase to be false.
					}
				}
				else//If increase is not true.
				{
					fTitleWidth -= 20 * m_fDeltaTime;//Decrease the titles' width.

					fTitleHeight -= 20 * m_fDeltaTime;//Decrease the titles' height.

					if (fTitleHeight <= 100)//If the titles height is 100.
					{
						bIncrease = true;//Set increase to be true.
					}
				}

				UG::SetSpriteScale(title.getSpriteID(), fTitleWidth, fTitleHeight);//Sets the title's scale.

				title.update();//Updates the title image.

				//\===========================================================================================
				//\ CAMPAIGN Setup
				//\===========================================================================================

				if (bCampaign.buttonLogic(m_dMousePosX, m_dMousePosY))//If the campaign button is pressed.
				{
					currentState = CAMPAIGN;//Sets the current state of game play to the main game.

					mMenu.stopDrawing();//Stops drawing the menu background.

					title.stopDrawing();//Stops drawing the title.

					tCampaignPlayer.markForDraw();//Sets the player tank to be drawn.

					mCampaignLevel1.markForDraw();//Sets the first map to be drawn.

					bCampaign.stopDrawing();//Stops the campaign button from being drawn.

					bVS.stopDrawing();//Stops the versus button from being drawn.

					bExit.stopDrawing();//Stops the exit button from being drawn.

					tCampaignAI1.markForDraw();//Sets the campaign AI to be drawn

					tCampaignAI2.markForDraw();//Sets the campaign AI to be drawn
				}
				
				//\===========================================================================================
				//\ VERSUS Setup
				//\===========================================================================================
				
				if (bVS.buttonLogic(m_dMousePosX, m_dMousePosY))//If the versus button is pressed.
				{
					currentState = VERSUS;//Sets the current state of game play to the main game.

					mMenu.stopDrawing();//Sets the first map to be drawn.

					title.stopDrawing();//Stops drawing the title.

					tVersusPlayer1.markForDraw();//Sets the player tank to be drawn.

					tVersusPlayer2.markForDraw();//Sets the player tank to be drawn.

					mCampaignLevel1.markForDraw();//Sets the first map to be drawn.

					bCampaign.stopDrawing();//Stops the campaign button from being drawn.

					bVS.stopDrawing();//Stops the versus button from being drawn.

					bExit.stopDrawing();//Stops the exit button from being drawn.

				}
				
				//\===========================================================================================
				//\ EXIT 
				//\===========================================================================================
				
				if (bExit.buttonLogic(m_dMousePosX, m_dMousePosY))//If the exit button is pressed.
				{
					UG::Close();//Closes the game.
				}

				break;
			}

			case CAMPAIGN://The game play state where the game will be played and the user should be the majority of the time.
			{
				powerUp.Update(mCampaignLevel1.getTileArray(), mCampaignLevel1.getTileArrayIndex(), m_fDeltaTime);//Updates the upgrades.
				//Collision for player and AI one.
				
				Vector2 v2CoordinatesToEvade1;//A vector to hold the coordinates that pertain to avoiding the object.
			
				if (tCampaignAI1.getAlive() == true && true == AABB(Box(tCampaignPlayer.getSprite()->getPosition(), tCampaignPlayer.getSprite()->getWidth(), tCampaignPlayer.getSprite()->getHeight(), tCampaignPlayer.getSprite()->getVelocity()), Box(tCampaignAI1.getSprite()->getPosition(), tCampaignAI1.getSprite()->getWidth(), tCampaignAI1.getSprite()->getHeight(), tCampaignAI1.getSprite()->getVelocity()), v2CoordinatesToEvade1))
				{
					tCampaignPlayer.getSprite()->setPosition(Vector2(tCampaignPlayer.getSprite()->getPosition().getfX() + v2CoordinatesToEvade1.getfX(), tCampaignPlayer.getSprite()->getPosition().getfY() + v2CoordinatesToEvade1.getfY()));//Move the player.
				}
				
				//Collision for player and AI two.
				
				Vector2 v2CoordinatesToEvade2;//A vector to hold the coordinates that pertain to avoiding the object.
				
				if (tCampaignAI2.getAlive() == true && true == AABB(Box(tCampaignPlayer.getSprite()->getPosition(), tCampaignPlayer.getSprite()->getWidth(), tCampaignPlayer.getSprite()->getHeight(), tCampaignPlayer.getSprite()->getVelocity()), Box(tCampaignAI2.getSprite()->getPosition(), tCampaignAI2.getSprite()->getWidth(), tCampaignAI2.getSprite()->getHeight(), tCampaignAI2.getSprite()->getVelocity()), v2CoordinatesToEvade2))
				{
					tCampaignPlayer.getSprite()->setPosition(Vector2(tCampaignPlayer.getSprite()->getPosition().getfX() + v2CoordinatesToEvade2.getfX(), tCampaignPlayer.getSprite()->getPosition().getfY() + v2CoordinatesToEvade2.getfY()));//Move the player.
				}
				
				//Collision for player and tiles.

				Vector2 v2CoordinatesToEvade3;//A vector to hold the coordinates that pertain to avoiding the object.

				for (int i = 0; i < 450; ++i)//For every tile.
				{
					if (mCampaignLevel1.getTileArray()[i].bWalkable == false)//If the tile is not walkable.
					{
						if (true == AABB(Box(tCampaignPlayer.getSprite()->getPosition(), tCampaignPlayer.getSprite()->getWidth(), tCampaignPlayer.getSprite()->getHeight(), tCampaignPlayer.getSprite()->getVelocity()), Box(mCampaignLevel1.getTileArray()[i].m_sTile->getPosition(), mCampaignLevel1.getTileArray()[i].m_sTile->getWidth(), mCampaignLevel1.getTileArray()[i].m_sTile->getHeight(), mCampaignLevel1.getTileArray()[i].m_sTile->getVelocity()), v2CoordinatesToEvade3))//If there is a collision.
						{
							tCampaignPlayer.getSprite()->setPosition(Vector2(tCampaignPlayer.getSprite()->getPosition().getfX() + v2CoordinatesToEvade3.getfX(), tCampaignPlayer.getSprite()->getPosition().getfY() + v2CoordinatesToEvade3.getfY()));//Move the player.
						}
					}
				}

				//Collision for AI one and normal bullets.

				Vector2 v2CoordinatesToEvade4;//A vector to hold the coordinates that pertain to avoiding the object.

				for (int i = 0; i < 4; ++i)//For every bullet.
				{
					if (tCampaignPlayer.getBasicBulletArray()[i].active == true && tCampaignAI1.getAlive() == true)//If the bullet is active.
					{
						if (true == AABB(Box(tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getPosition(), tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getWidth(), tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getHeight(), tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getVelocity()), Box(tCampaignAI1.getSprite()->getPosition(), tCampaignAI1.getSprite()->getWidth(), tCampaignAI1.getSprite()->getHeight(), tCampaignAI1.getSprite()->getVelocity()), v2CoordinatesToEvade3))//If there is a collision.
						{
							tCampaignPlayer.getBasicBulletArray()[i].active = false;

							tCampaignAI1.setAlive(false);//Sets the tank's alive status to false.

							tCampaignAI1.stopDrawing();//Stops drawing the tank.
						}
					}
				}

				//Collision for AI two and normal bullets.

				for (int i = 0; i < 4; ++i)//For every bullet.
				{
					if (tCampaignPlayer.getBasicBulletArray()[i].active == true && tCampaignAI2.getAlive() == true)//If the bullet is active.
					{
						if (true == AABB(Box(tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getPosition(), tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getWidth(), tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getHeight(), tCampaignPlayer.getBasicBulletArray()[i].sBasicAmmo->getVelocity()), Box(tCampaignAI2.getSprite()->getPosition(), tCampaignAI2.getSprite()->getWidth(), tCampaignAI2.getSprite()->getHeight(), tCampaignAI2.getSprite()->getVelocity()), v2CoordinatesToEvade3))//If there is a collision.
						{
							tCampaignPlayer.getBasicBulletArray()[i].active = false;

							tCampaignAI2.setAlive(false);//Sets the tank's alive status to false.

							tCampaignAI2.stopDrawing();//Stops drawing the tank.
						}
					}
				}

				//Collision for player and upgrades.

				if (powerUp.getActive() == true && true == AABB(Box(tCampaignPlayer.getSprite()->getPosition(), tCampaignPlayer.getSprite()->getWidth(), tCampaignPlayer.getSprite()->getHeight(), tCampaignPlayer.getSprite()->getVelocity()), Box(powerUp.getSprite()->getPosition(), powerUp.getSprite()->getWidth(), powerUp.getSprite()->getHeight(), powerUp.getSprite()->getVelocity()), v2CoordinatesToEvade2))
				{
					powerUp.setActive(false);

					powerUp.stopDrawing();

					if (powerUp.getType() == 1)
					{
						tCampaignPlayer.setUpgrade(1);
					}
					else if (powerUp.getType() == 2)
					{
						tCampaignPlayer.setUpgrade(2);
					}
					else if (powerUp.getType() == 3)
					{
						tCampaignPlayer.setUpgrade(3);
					}
					else if (powerUp.getType() == 4)
					{
						tCampaignPlayer.setUpgrade(4);
					}
				}

				tCampaignAI1.tankLogic(m_fDeltaTime, m_dMousePosX, m_dMousePosY);//Updates the tank AI.

				tCampaignAI2.tankLogic(m_fDeltaTime, m_dMousePosX, m_dMousePosY);//Updates the tank AI.

				tCampaignPlayer.tankLogic(m_fDeltaTime, m_dMousePosX, m_dMousePosY);//Allows for movement of the player tank.
				break;
			}
			case VERSUS://The game play state where the game will be played and the user should be the majority of the time.
			{
				powerUp.Update(mCampaignLevel1.getTileArray(), mCampaignLevel1.getTileArrayIndex(), m_fDeltaTime);//Updates the upgrades.

				//Collision for both tank's touching each other to stop them pushing each other around.

				Vector2 v2CoordinatesToEvade6;//A vector to hold the coordinates that pertain to avoiding the object.

				Vector2 v2CoordinatesToEvade5;//A vector to hold the coordinates that pertain to avoiding the object.

				if (true == AABB(Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(), tVersusPlayer2.getSprite()->getVelocity()), v2CoordinatesToEvade6) && (true == AABB(Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(), tVersusPlayer2.getSprite()->getVelocity()), Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), v2CoordinatesToEvade5)))//If there is a collision with both tanks.
				{
					tVersusPlayer1.getSprite()->setPosition(tVersusPlayer1.getSprite()->getPosition() + (tVersusPlayer1.getSprite()->getVelocity() * -1));//Move the player.
					tVersusPlayer2.getSprite()->setPosition(tVersusPlayer2.getSprite()->getPosition() + (tVersusPlayer2.getSprite()->getVelocity() * -1));//Move the player.
				}
		        else
		        {   
					//Collision for player1 and player2.
		        	
					Vector2 v2CoordinatesToEvade1;//A vector to hold the coordinates that pertain to avoiding the object.
		        	
		        	if (true == AABB(Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(), tVersusPlayer2.getSprite()->getVelocity()), v2CoordinatesToEvade1))//If there is a collision.
		        	{
		        		tVersusPlayer1.getSprite()->setPosition(Vector2(tVersusPlayer1.getSprite()->getPosition().getfX() + v2CoordinatesToEvade1.getfX(), tVersusPlayer1.getSprite()->getPosition().getfY() + v2CoordinatesToEvade1.getfY()));//Move the player.
		        	}

					//Collision for player2 and player1.

		        	Vector2 v2CoordinatesToEvade2;//A vector to hold the coordinates that pertain to avoiding the object.
		        	
		        	if (true == AABB(Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(), tVersusPlayer2.getSprite()->getVelocity()), Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), v2CoordinatesToEvade2))//If there is a collision.
		        	{
		        		tVersusPlayer2.getSprite()->setPosition(Vector2(tVersusPlayer2.getSprite()->getPosition().getfX() + v2CoordinatesToEvade2.getfX(), tVersusPlayer2.getSprite()->getPosition().getfY() + v2CoordinatesToEvade2.getfY()));//Move the player.
		        	}
		        }

				//Collision for player1 and tiles.

			    Vector2 v2CoordinatesToEvade3;//A vector to hold the coordinates that pertain to avoiding the object.
			    
			    
			    for (int i = 0; i < 450; ++i)//For every tile.
			    {
			    	if (mCampaignLevel1.getTileArray()[i].bWalkable == false)//If the tile is not walkable.
			    	{
			    		if (true == AABB(Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), Box(mCampaignLevel1.getTileArray()[i].m_sTile->getPosition(), mCampaignLevel1.getTileArray()[i].m_sTile->getWidth(), mCampaignLevel1.getTileArray()[i].m_sTile->getHeight(), mCampaignLevel1.getTileArray()[i].m_sTile->getVelocity()), v2CoordinatesToEvade3))//If there is a collision.
			    		{
							tVersusPlayer1.getSprite()->setPosition(Vector2(tVersusPlayer1.getSprite()->getPosition().getfX() + v2CoordinatesToEvade3.getfX(), tVersusPlayer1.getSprite()->getPosition().getfY() + v2CoordinatesToEvade3.getfY()));//Move the player.
			    		}
			    	}
			    }

				//Collision for player2 and tiles.
				
				Vector2 v2CoordinatesToEvade4;//A vector to hold the coordinates that pertain to avoiding the object.

				for (int i = 0; i < 450; ++i)//For every tile.
				{
					if (mCampaignLevel1.getTileArray()[i].bWalkable == false)//If the tile is not walkable.
					{
						if (true == AABB(Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(), tVersusPlayer2.getSprite()->getVelocity()), Box(mCampaignLevel1.getTileArray()[i].m_sTile->getPosition(), mCampaignLevel1.getTileArray()[i].m_sTile->getWidth(), mCampaignLevel1.getTileArray()[i].m_sTile->getHeight(), mCampaignLevel1.getTileArray()[i].m_sTile->getVelocity()), v2CoordinatesToEvade4))//If there is a collision.
						{
							tVersusPlayer2.getSprite()->setPosition(Vector2(tVersusPlayer2.getSprite()->getPosition().getfX() + v2CoordinatesToEvade4.getfX(), tVersusPlayer2.getSprite()->getPosition().getfY() + v2CoordinatesToEvade4.getfY()));//Move the player.
						}
					}

				}

				//Collision for player1's bullets and player 2.

				Vector2 v2CoordinatesToEvade7;//A vector to hold the coordinates that pertain to avoiding the object.

				for (int i = 0; i < 4; ++i)//For every bullet.
				{
					if (tVersusPlayer1.getBasicBulletArray()[i].active == true && tVersusPlayer2.getAlive() == true)//If the bullet is active.
					{
						if (true == AABB(Box(tVersusPlayer1.getBasicBulletArray()[i].sBasicAmmo->getPosition(), tVersusPlayer1.getBasicBulletArray()[i].sBasicAmmo->getWidth(), tVersusPlayer1.getBasicBulletArray()[i].sBasicAmmo->getHeight(), tVersusPlayer1.getBasicBulletArray()[i].sBasicAmmo->getVelocity()),Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(),	tVersusPlayer2.getSprite()->getVelocity()), v2CoordinatesToEvade3))//If there is a collision.
						{
							tVersusPlayer1.getBasicBulletArray()[i].active = false;

							tVersusPlayer2.setAlive(false);//Sets the tank's alive status to false.

							tVersusPlayer2.stopDrawing();//Stops drawing the tank.
						}
					}
				}

				//Collision for player1's bullets and player 2.

				for (int i = 0; i < 4; ++i)//For every bullet.
				{
					if (tVersusPlayer2.getBasicBulletArray()[i].active == true && tVersusPlayer1.getAlive() == true)//If the bullet is active.
					{
						if (true == AABB(Box(tVersusPlayer2.getBasicBulletArray()[i].sBasicAmmo->getPosition(), tVersusPlayer2.getBasicBulletArray()[i].sBasicAmmo->getWidth(), tVersusPlayer2.getBasicBulletArray()[i].sBasicAmmo->getHeight(), tVersusPlayer2.getBasicBulletArray()[i].sBasicAmmo->getVelocity()), Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), v2CoordinatesToEvade3))//If there is a collision.
						{
							tVersusPlayer2.getBasicBulletArray()[i].active = false;

							tVersusPlayer1.setAlive(false);//Sets the tank's alive status to false.

							tVersusPlayer1.stopDrawing();//Stops drawing the tank.
						}
					}
				}

				//Collision for player1 and upgrades.

				if (powerUp.getActive() == true && true == AABB(Box(tVersusPlayer1.getSprite()->getPosition(), tVersusPlayer1.getSprite()->getWidth(), tVersusPlayer1.getSprite()->getHeight(), tVersusPlayer1.getSprite()->getVelocity()), Box(powerUp.getSprite()->getPosition(), powerUp.getSprite()->getWidth(), powerUp.getSprite()->getHeight(), powerUp.getSprite()->getVelocity()), v2CoordinatesToEvade3))
				{
					powerUp.setActive(false);

					powerUp.stopDrawing();

					if (powerUp.getType() == 1)
					{
						tVersusPlayer1.setUpgrade(1);
					}
					else if (powerUp.getType() == 2)
					{
						tVersusPlayer1.setUpgrade(2);
					}
					else if (powerUp.getType() == 3)
					{
						tVersusPlayer1.setUpgrade(3);
					}
					else if (powerUp.getType() == 4)
					{
						tVersusPlayer1.setUpgrade(4);
					}
				}

				//Collision for player2 and upgrades.

				if (powerUp.getActive() == true && true == AABB(Box(tVersusPlayer2.getSprite()->getPosition(), tVersusPlayer2.getSprite()->getWidth(), tVersusPlayer2.getSprite()->getHeight(), tVersusPlayer2.getSprite()->getVelocity()), Box(powerUp.getSprite()->getPosition(), powerUp.getSprite()->getWidth(), powerUp.getSprite()->getHeight(), powerUp.getSprite()->getVelocity()), v2CoordinatesToEvade3))
				{
					powerUp.setActive(false);

					powerUp.stopDrawing();

					if (powerUp.getType() == 1)
					{
						tVersusPlayer2.setUpgrade(1);
					}
					else if (powerUp.getType() == 2)
					{
						tVersusPlayer2.setUpgrade(2);
					}
					else if (powerUp.getType() == 3)
					{
						tVersusPlayer2.setUpgrade(3);
					}
					else if (powerUp.getType() == 4)
					{
						tVersusPlayer2.setUpgrade(4);
					}
				}
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