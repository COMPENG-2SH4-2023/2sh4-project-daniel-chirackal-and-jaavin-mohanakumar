#include "objPos.h"

/*Default object constructor*/

objPos::objPos()
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

/*Copy Object constructor used create a new object through the reference of another*/

objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

/*Object constructor with explicit coordinates and symbol*/

objPos::objPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

/*Setter method used for object manipulation*/

void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

/*Setter method used for explict object manipulation, of the coords and symbols*/

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

/*Getter method used for coordinate and symbol manipulation*/

void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol);
}

char objPos::getSymbol()
{
    return symbol;
}

//Boolean checker to see if objects have equal positions via the given objPos  

bool objPos::isPosEqual(const objPos* refPos)
{
    return (refPos->x == x && refPos->y == y);
}

//An addition to the above method, a getter used for symbol manipulation 

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}