#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 40;
    boardSizeY = 20;

    delayConst = 100000;

    gameBoard = new objPos*[boardSizeY];
    for (int i = 0; i < boardSizeY; i++)
    {
        gameBoard[i] = new objPos[boardSizeX];
    }

    initGameBoard();
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;

    delayConst = 100000;

    gameBoard = new objPos*[boardY];
    for (int i = 0; i < boardY; i++)
    {
        gameBoard[i] = new objPos[boardX];
    }

    initGameBoard();
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // delete any heap members here
    for (int i = 0; i < boardSizeY; i++)
    {
        delete [] gameBoard[i];
    }
    delete [] gameBoard;

}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getDelayConst()
{
    return delayConst;
}



void GameMechs::initGameBoard(){
    for (int i = 0; i < boardSizeY; i++){
        for (int j = 0; j < boardSizeX; j++){
            if (i == 0 || i == boardSizeY - 1 || j == 0 || j == boardSizeX - 1){
                setGameBoardPos(j, i, '#');
            } else{
                setGameBoardPos(j, i, ' ');
            }
        }
    }
}

void GameMechs::setGameBoardPos(int xPos, int yPos, char sym){
    gameBoard[yPos][xPos].setObjPos(xPos, yPos, sym);
}

char GameMechs::getGameBoardSymbol(int xPos, int yPos){
    return gameBoard[yPos][xPos].getSymbol();
}