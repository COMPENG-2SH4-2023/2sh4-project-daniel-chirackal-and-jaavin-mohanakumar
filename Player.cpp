#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    char input = mainGameMechsRef->getInput();  

    switch(input)
        {
                              
            case 'w':
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case 'a':
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                
                break;

            case 's':
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                
                break;

            case 'd':
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;

        }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic


    
}

