#include "Food.h"
#include "GameMechs.h"
#include <cstdlib>
#include <ctime>
#include "objPos.h"
#include "objPosArrayList.h"

Food::Food(GameMechs &Gamemechs)
{
    gamemechs = &Gamemechs; 
    foodPos.x = 0; 
    foodPos.y = 0; 
    foodPos.symbol = 'o';
}

void Food::generateFood(objPosArrayList &blockOFF){

    //Setting the random x,y coords 
    int randX = rand() % (gamemechs->getBoardSizeX() - 2) + 1;
    int randY = rand() % (gamemechs->getBoardSizeY() - 2) + 1;
    //Making sure the food doesn't spwan on the player's body 
    while (gamemechs->gameBoard[randY][randX].getSymbol() != ' '){
        for (int i = 0; i < blockOFF.getSize(); i++){
            objPos temp;
            blockOFF.getElement(temp, i);
            if (temp.getX() == randX && temp.getY() == randY){
                randX = rand() % (gamemechs->getBoardSizeX() - 2) + 1;
                randY = rand() % (gamemechs->getBoardSizeY() - 2) + 1;
                break;
            }
        }
    }
    //Setting the food as an objPos 
    foodPos.setObjPos(randX, randY, 'o');
    gamemechs->gameBoard[randY][randX].setObjPos(foodPos);
}

void Food::foodbucket(objPosArrayList &blockOFF)
{
    char myarray [5] = {'o', '$', '@', '?', 'Q'};
    int randX = rand() % (gamemechs->getBoardSizeX() - 2) + 1;
    int randY = rand() % (gamemechs->getBoardSizeY() - 2) + 1;
    char randsym = rand() % 5; 
        for (int i = 0; i < blockOFF.getSize(); i++)
    {
        objPos temp;
        blockOFF.getElement(temp, i);
        if (temp.getX() == randX && temp.getY() == randY)
        {
            randX = rand() % (gamemechs->getBoardSizeX() - 2) + 1;
            randY = rand() % (gamemechs->getBoardSizeY() - 2) + 1;
            break;
        }
        foodPos.setObjPos(randX, randY, myarray[randsym]);
        gamemechs->gameBoard[randY][randX].setObjPos(foodPos);
    }
}