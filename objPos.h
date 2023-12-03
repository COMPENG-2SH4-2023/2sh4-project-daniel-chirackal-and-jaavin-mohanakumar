#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
    public:
        int x;
        int y;
        char symbol;
        //Constructors
        objPos();
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);
        //Setters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        //Getters
        void getObjPos(objPos &returnPos);
        int getX();
        int getY();
        void setX(int xPos);
        void setY(int yPos);
        char getSymbol();

        bool isPosEqual(const objPos* refPos);
        
        char getSymbolIfPosEqual(const objPos* refPos);
};

#endif