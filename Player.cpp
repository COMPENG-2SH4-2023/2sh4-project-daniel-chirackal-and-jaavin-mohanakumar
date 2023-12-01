#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();

    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*' );


    playerPosList->insertHead(temp);
//
//    objPos temp2;
//    temp2.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2 + 1, '*' );
//    playerPosList->insertHead(temp2);
//
//    objPos temp3;
//    temp3.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2 + 2, '*' );
//    playerPosList->insertHead(temp3);

    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList& Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return *playerPosList;
}

bool Player::increasePlayerLen(){
    objPos temp;
    // get food position!!!!!
    temp.setObjPos(getPlayerPosX(), getPlayerPosY(), '*');
    playerPosList->insertHead(temp);
}

int Player::getPlayerPosX()
{
    objPos head;
    playerPosList->getHeadElement(head);
    return head.getX();
}

int Player::getPlayerPosY()
{
    objPos head;
    playerPosList->getHeadElement(head);
    return head.getY();
}


void Player::updatePlayerDir()
{

    switch (mainGameMechsRef->getInput()) {
        case 'w':
            if (myDir != DOWN) {
                myDir = UP;
            }
            break;
        case 'a':
            if (myDir != RIGHT) {
                myDir = LEFT;
            }
            break;
        case 's':
            if (myDir != UP) {
                myDir = DOWN;
            }
            break;
        case 'd':
            if (myDir != LEFT) {
                myDir = RIGHT;
            }
            break;

        default:
            break;
    }

}


void Player::updatePlayerPos(int newX, int newY) {
    objPos newPos;
    newPos.setObjPos(newX, newY, '*');
    playerPosList->insertHead(newPos);
    playerPosList->removeTail();
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logc

    int currentX = getPlayerPosX();
    int currentY = getPlayerPosY();

    switch (myDir) {
        case UP:
            updatePlayerPos(currentX, (currentY == 1) ? mainGameMechsRef->getBoardSizeY() - 2 : currentY - 1);
            break;
        case DOWN:
            updatePlayerPos(currentX, (currentY == mainGameMechsRef->getBoardSizeY() - 2) ? 1 : currentY + 1);
            break;
        case LEFT:
            updatePlayerPos((currentX == 1) ? mainGameMechsRef->getBoardSizeX() - 2 : currentX - 1, currentY);
            break;
        case RIGHT:
            updatePlayerPos((currentX == mainGameMechsRef->getBoardSizeX() - 2) ? 1 : currentX + 1, currentY);
            break;
        default:
            break;
    }
}

