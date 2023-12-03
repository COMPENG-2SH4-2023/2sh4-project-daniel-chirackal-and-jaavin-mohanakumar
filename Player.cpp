#include "Player.h"

//Intializes a player object and makes it use the previously made gamemechs as rules. 

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    //Player is intially still 
    myDir = STOP;
    //Intializes list of objPos on the heap 
    playerPosList = new objPosArrayList();

    //Creates temp object to act as the player, set to the middle of the board 
    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*' );


    playerPosList->insertHead(temp);

    // more actions to be included
}

//Destructor of allocated memory on the heap 

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

//Takes the temp objPos instance and increase objPos list length then appends a '*' to it 

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

//Updates the FSM logic so that the program can be updated as to what new directions can be used 

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

//Player position manipulation with explict x,y coords 

void Player::updatePlayerPos(int newX, int newY) {
    objPos newPos;
    newPos.setObjPos(newX, newY, '*');
    playerPosList->insertHead(newPos);
    playerPosList->removeTail();
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    // Get current position of the player
    int currentX = getPlayerPosX();
    int currentY = getPlayerPosY();

    // Check if the player collides with itself
    if (checkSelfCollision()) {
        // If self-collision occurs, set the game to exit
        mainGameMechsRef->setExitTrue();
        return;
    } else if (mainGameMechsRef->getGameBoardSymbol(currentX, currentY) == 'o') {
        // If the player's head touches a food symbol 'o'
        
        // Increase player length
        increasePlayerLen();

        // Store the position of the old food
        objPos oldFood;
        mainGameMechsRef->getFoodPos(oldFood);

        // Remove the old food symbol from the game board
        mainGameMechsRef->setGameBoardPos(oldFood.getX(), oldFood.getY(), ' ');

        // Generate a new food at a random position
        mainGameMechsRef->generateFood(getPlayerPos());
    }

    // Move the player based on the current direction
    switch (myDir) {
        case UP:
            // If moving UP, update the Y coordinate accordingly
            updatePlayerPos(currentX, (currentY == 1) ? mainGameMechsRef->getBoardSizeY() - 2 : currentY - 1);
            break;
        case DOWN:
            // If moving DOWN, update the Y coordinate accordingly
            updatePlayerPos(currentX, (currentY == mainGameMechsRef->getBoardSizeY() - 2) ? 1 : currentY + 1);
            break;
        case LEFT:
            // If moving LEFT, update the X coordinate accordingly
            updatePlayerPos((currentX == 1) ? mainGameMechsRef->getBoardSizeX() - 2 : currentX - 1, currentY);
            break;
        case RIGHT:
            // If moving RIGHT, update the X coordinate accordingly
            updatePlayerPos((currentX == mainGameMechsRef->getBoardSizeX() - 2) ? 1 : currentX + 1, currentY);
            break;
        default:
            break;
    }
}

// Check if the player collides with itself
bool Player::checkSelfCollision()
{
    // Get the position of the player's head
    objPos head;
    playerPosList->getHeadElement(head);

    // Iterate through the player's body to check for collisions
    for (int i = 1; i < playerPosList->getSize(); i++) {
        objPos temp;
        playerPosList->getElement(temp, i);
        // If the head collides with any other body part, return true
        if (head.getX() == temp.getX() && head.getY() == temp.getY()) {
            return true;
        }
    }
    // If no collision is detected, return false
    return false;
}
