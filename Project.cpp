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
            player->increasePlayerLen();
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


//    for (int i = 0; i < player->getPlayerPos().getSize(); i++) {
//        objPos temp;
//        player->getPlayerPos().getElement(temp, i);
//        MacUILib_printf("Player X: %d\n", temp.getX());
//        MacUILib_printf("Player Y: %d\n", temp.getY());
//    }
}

void LoopDelay(void)
{
    MacUILib_Delay(gameMechs->getDelayConst());
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
