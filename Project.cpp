#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM; 
Player* myPlayer; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

objPos Edge; 
objPos Space; 
objPos Null; 
objPos Player;


int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    myDir = STOP; 

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    Edge.setObjPos(0, 0, '#'); 
    Space.setObjPos(0, 0, ' '); 
    Null.setObjPos(0, 0, '\0'); 
    Player.setObjPos(10, 5, '*');

    myGM = new GameMechs(26, 13); 
    myPlayer = new Player(myGM); 

}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    int i = 0;
    int array_x = 0; 
    int array_y = 0; 

    char map_x_arr[mainGameMechsRef->getBoardSizeX] = {0};
       
        for (array_y = 0; array_y < mainGameMechsRef->getBoardSizeY; array_y++)
        {
            if (array_y == 0 || array_y == (mainGameMechsRef->getBoardSizeY-1)) // Printing the border (all '#' when y=0 or y=9)
            {
                for (i = 0; i <= (mainGameMechsRef->getBoardSizeX-2); i++)
                {
                    map_x_arr[i] = Edge.symbol;
                     
                } 
            }

            else if (array_y != 0 && array_y !=  (mainGameMechsRef->getBoardSizeY-1))
            {                       
                map_x_arr[0] = Edge.symbol;
                map_x_arr[(mainGameMechsRef->getBoardSizeX-2)] = Edge.symbol;

                for (i=0; i < (mainGameMechsRef->getBoardSizeX-2); i++) // For-loop purpose: Wherever there is no item/user, put a space
                {
                    if (map_x_arr[i] == Null.symbol)
                    {
                        map_x_arr[i] = Space.symbol;
                    }
                }

                if(array_y == Player.y)
                {
                    map_x_arr[Player.x] = Player.symbol; 
                }
            }

            MacUILib_printf("%s", map_x_arr);
            MacUILib_printf("\n");

            for (i = 0; i < (mainGameMechsRef->getBoardSizeX-1); i++) 
            {
                map_x_arr[i] = Null.symbol;
            }

        }     

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
