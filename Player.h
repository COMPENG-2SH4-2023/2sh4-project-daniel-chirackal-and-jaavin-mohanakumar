#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList& getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();

        // debug
        int getPlayerPosX();
        int getPlayerPosY();

        void increasePlayerLen();
        bool getcheckSelfCollision(); 




    private:
        objPosArrayList* playerPosList;

        enum Dir myDir;

        bool checkSelfCollision();


        void updatePlayerPos(int newX, int newY);
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif