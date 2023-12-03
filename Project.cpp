#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

//Creates reference to the game mechanics and the player movement/body 

GameMechs* gameMechs;
Player* player;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!gameMechs->getExitFlagStatus())
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //Choosen gameboard dimensions via constructor 
    //All references are allocated on the heap 
    gameMechs = new GameMechs(30, 10);

    player = new Player(gameMechs);
    //Food generation
    gameMechs->generateFood(player->getPlayerPos());
}

void GetInput(void)
{
    //Capturing user input from keyboard 
    if (MacUILib_hasChar()) {
        gameMechs->setInput(MacUILib_getChar());
    }
   
}

// Update game logic
void RunLogic(void)
{
    // Check if there is input from the user
    if (gameMechs->getInput() != 0)  // if not null character
    {
        // Process different inputs
        if (gameMechs->getInput() == ' ') {
            // If space key is pressed, set the game to exit
            gameMechs->setExitTrue();
        } else if (gameMechs->getInput() == 't'){
            // If 't' key is pressed, generate a new food at the player's position
            gameMechs->generateFood(player->getPlayerPos());
        }
        else {
            // Otherwise, update the player's direction based on the input
            player->updatePlayerDir();
        }

        // Clear the input buffer after processing
        gameMechs->clearInput();
    }

    // Move the player based on its current direction
    player->movePlayer();
}

// Draw the game screen
void DrawScreen(void)
{
    // Clear the screen
    MacUILib_clearScreen();

    // Iterate through each position on the game board
    for(int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {

            // Check if the current position belongs to the player's body
            bool isPlayer = false;
            for (int k = 0; k < player->getPlayerPos().getSize(); k++) {
                objPos temp;
                player->getPlayerPos().getElement(temp, k);
                if (temp.getX() == j && temp.getY() == i) {
                    // If it's part of the player, print the player's symbol
                    MacUILib_printf("%c", temp.getSymbol());
                    isPlayer = true;
                }
            }

            // Check if the current position is on the border
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 || j == 0 || j == gameMechs->getBoardSizeX() - 1){
                // If it's on the border, print a wall symbol
                MacUILib_printf("%c", '#');
            } else if (!isPlayer) {
                // If it's neither part of the player nor on the border, print the symbol from the game board
                MacUILib_printf("%c", gameMechs->getGameBoardSymbol(j, i));
            }
        }

        // Move to the next line after printing each row
        MacUILib_printf("\n");
    }

    // Display additional information below the game board
    MacUILib_printf("--------------------\n");
    MacUILib_printf("Score: %d\n", player->getPlayerPos().getSize() - 1);
    MacUILib_printf("Press space to exit\n");
}

// Introduce a delay in the game loop
void LoopDelay(void)
{
    // Delay the execution based on the game's configured delay constant
    MacUILib_Delay(gameMechs->getDelayConst());
}

// Clean up resources and display game-over information
void CleanUp(void)
{
    // Clear the screen
    MacUILib_clearScreen();    

    // Display game-over message and the final score
    MacUILib_printf("Game Over!\n");
    MacUILib_printf("Your score is: %d\n", player->getPlayerPos().getSize() - 1);

    // Uninitialize the MacUILib library
    MacUILib_uninit();
}
