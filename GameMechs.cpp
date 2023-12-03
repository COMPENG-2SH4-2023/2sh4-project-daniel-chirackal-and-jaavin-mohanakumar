#include "GameMechs.h"
#include <cstdlib>
#include <ctime>

/*The contructor below intialises the default set of game mechanics. 
Player input is set to NULL as the game is waiting for the player to
interact. The game board is set to 40 X 20, delayConst (speed) is set to 100000 
mircoseconds. All flags are set to false and the gameboard is set to be a pointer 
towards the objpos class*/

GameMechs::GameMechs()
{
    // Player input set to NULL 
    input = 0; 
    // Flags set to false 
    exitFlag = false;
    loseFlag = false;
    // Score set to 0 
    score = 0;
    // Area of board is 40 * 20 
    boardSizeX = 40;    
    boardSizeY = 20;

    delayConst = 100000;

    //Putting the entire gameboard onto the heap 
    gameBoard = new objPos*[boardSizeY];
    for (int i = 0; i < boardSizeY; i++)
    {
        gameBoard[i] = new objPos[boardSizeX];
    }
    //Seeding the random number generator 
    std::srand(std::time(0));

    initGameBoard();
}

/*This constructor is nearly identical to the one about but allows 
the changing of the gameboards area.*/

GameMechs::GameMechs(int boardX, int boardY)
{
    // Player input set to NULL 
    input = 0;
    // Flags set to false 
    exitFlag = false;
    loseFlag = false;
    // Score set to 0 
    score = 0;
    // Area of board is (X) * Y 
    boardSizeX = boardX;
    boardSizeY = boardY;

    delayConst = 100000;

    gameBoard = new objPos*[boardY];

    //Putting the entire gameboard onto the heap 
    for (int i = 0; i < boardY; i++)
    {
        gameBoard[i] = new objPos[boardX];
    }
    
    //Seeding the random number generator 
    std::srand(std::time(0));

    initGameBoard();
}

/*Freeing any allocated memebers from the heap*/

GameMechs::~GameMechs()
{
    // delete any heap members here
    for (int i = 0; i < boardSizeY; i++)
    {
        delete [] gameBoard[i];
    }
    delete [] gameBoard;

}

/*Retriving the boolean status of exitflag*/

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

/*Gettermethod allowing for declay constant manipulation*/

int GameMechs::getDelayConst()
{
    return delayConst;
}

/*Method thats used to construct the boarder of the game display, taking
in the current board dimensions*/

void GameMechs::initGameBoard(){
    for (int i = 0; i < boardSizeY; i++){
        for (int j = 0; j < boardSizeX; j++){
            if (i == 0 || i == boardSizeY - 1 || j == 0 || j == boardSizeX - 1){
                setGameBoardPos(j, i, '#'); // Boarder character 
            } else{
                setGameBoardPos(j, i, ' '); // Space between 
            }
        }
    }
}

/*Used for character placement on the game board*/

void GameMechs::setGameBoardPos(int xPos, int yPos, char sym){
    gameBoard[yPos][xPos].setObjPos(xPos, yPos, sym);
}

/*Used to retrive character placement on the game board*/

char GameMechs::getGameBoardSymbol(int xPos, int yPos){
    return gameBoard[yPos][xPos].getSymbol();
}

/*Generates random a 'food' characters to increase the score, and the length of
the snake. The place of the food is randomized on the board.*/

void GameMechs::generateFood(objPosArrayList &blockOFF){

    //Setting the random x,y coords 
    int randX = rand() % (boardSizeX - 2) + 1;
    int randY = rand() % (boardSizeY - 2) + 1;
    //Making sure the food doesn't spwan on the player's body 
    while (gameBoard[randY][randX].getSymbol() != ' '){
        for (int i = 0; i < blockOFF.getSize(); i++){
            objPos temp;
            blockOFF.getElement(temp, i);
            if (temp.getX() == randX && temp.getY() == randY){
                randX = rand() % (boardSizeX - 2) + 1;
                randY = rand() % (boardSizeY - 2) + 1;
                break;
            }
        }
    }
    //Setting the food as an objPos 
    foodPos.setObjPos(randX, randY, 'o');
    gameBoard[randY][randX].setObjPos(foodPos);
}

/*Return the foods position for manipulation*/
void GameMechs::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos);
}