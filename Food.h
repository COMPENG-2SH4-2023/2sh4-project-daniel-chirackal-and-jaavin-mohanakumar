#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include "GameMechs.h"

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs;

class Food
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
    GameMechs* gamemechs; 
    objPos foodPos; 


public:

    Food(GameMechs& Gamemechs); 
    void (generateFood(objPosArrayList &blockOFF));
    void (foodbucket(objPosArrayList &blockOFF)); 
    

};

#endif