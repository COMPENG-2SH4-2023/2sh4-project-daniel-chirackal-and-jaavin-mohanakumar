#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        objPos foodPos;

        int boardSizeX;
        int boardSizeY;

        int delayConst;


        void initGameBoard();


public:
        GameMechs();
        GameMechs(int boardX, int boardY);

        ~GameMechs();


        bool getExitFlagStatus();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        int getDelayConst();

        void setGameBoardPos(int xPos, int yPos, char sym);
        char getGameBoardSymbol(int xPos, int yPos);

        void generateFood(objPosArrayList &blockOFF);
        void getFoodPos(objPos &returnPos);


        objPos** gameBoard;

};

#endif