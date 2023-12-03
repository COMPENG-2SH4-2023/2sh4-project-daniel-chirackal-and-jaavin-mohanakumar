#include "GameMechs.h"
#include "MacUILib.h" 


GameMechs::GameMechs()
{
    input = 0; 

    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10; 
}


GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0; 

    exitFlag = false;
    boardSizeX = boardX;

    boardSizeY = boardY; 
}

// do you need a destructor?

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

/*Retriving the character status of input*/

char GameMechs::getInput()
{
    return input;
}

/*Retriving the integer of the width of the board*/

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

/*Retriving the integer of the length of the board*/

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

/*Settermethod allowing for making exit conditions*/

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

/*Settermethod allowing for input manipulation*/

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

/*Settermethod allowing for input manipulation*/

void GameMechs::clearInput()
{
    input = 0;
}



