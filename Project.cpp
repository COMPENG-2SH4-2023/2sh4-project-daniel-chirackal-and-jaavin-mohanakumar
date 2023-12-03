#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

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


    gameMechs = new GameMechs(30, 10);

    player = new Player(gameMechs);

    gameMechs->generateFood(player->getPlayerPos());
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        gameMechs->setInput(MacUILib_getChar());
    }
   
}

void RunLogic(void)
{

    if (gameMechs->getInput() != 0)  // if not null character
    {

        if (gameMechs->getInput() == ' ') {
            gameMechs->setExitTrue();
        } else if (gameMechs->getInput() == 't'){

            gameMechs->generateFood(player->getPlayerPos());
        }
        else {
            player->updatePlayerDir();
        }
        gameMechs->clearInput();
    }

    player->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    for(int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {

            bool isPlayer = false;
            for (int k = 0; k < player->getPlayerPos().getSize(); k++) {
                objPos temp;
                player->getPlayerPos().getElement(temp, k);
                if (temp.getX() == j && temp.getY() == i) {
                    MacUILib_printf("%c", temp.getSymbol());
                    isPlayer = true;
                }
            }
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 || j == 0 || j == gameMechs->getBoardSizeX() - 1){
                MacUILib_printf("%c", '#');
            } else if (!isPlayer) {
                MacUILib_printf("%c", gameMechs->getGameBoardSymbol(j, i));
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("--------------------\n");
    MacUILib_printf("Score: %d\n", player->getPlayerPos().getSize() - 1);
    MacUILib_printf("Press space to exit\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(gameMechs->getDelayConst());
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_printf("Game Over!\n");
    MacUILib_printf("Your score is: %d\n", player->getPlayerPos().getSize() - 1);

    MacUILib_uninit();
}
