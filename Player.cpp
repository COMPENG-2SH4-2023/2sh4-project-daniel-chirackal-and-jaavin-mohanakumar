#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();

    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*' );


    playerPosList->insertHead(temp);

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

void Player::increasePlayerLen(){
    objPos temp;
    mainGameMechsRef->getFoodPos(temp);
    temp.setObjPos(temp.getX(), temp.getY(), '*');
    playerPosList->insertTail(temp);
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

    // check if touch food
    if (checkSelfCollision()) {
        mainGameMechsRef->setExitTrue();
        return;
    } else if (mainGameMechsRef->getGameBoardSymbol(currentX, currentY) == 'o') {
        increasePlayerLen();

        objPos oldFood;
        mainGameMechsRef->getFoodPos(oldFood);
        mainGameMechsRef->setGameBoardPos(oldFood.getX(), oldFood.getY(), ' ');

        mainGameMechsRef->generateFood(getPlayerPos());
    }

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

bool Player::checkSelfCollision()
{
    objPos head;
    playerPosList->getHeadElement(head);

    for (int i = 1; i < playerPosList->getSize(); i++) {
        objPos temp;
        playerPosList->getElement(temp, i);
        if (head.getX() == temp.getX() && head.getY() == temp.getY()) {
            return true;
        }
    }
    return false;
}