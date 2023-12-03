#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 256

#include "objPos.h"

class objPosArrayList
{
private:
    objPos* aList;
    int listSize;
    int arrayCapacity;

public:
    //Constructor
    objPosArrayList();
    //Destructor
    ~objPosArrayList();
    //Getters
    int getSize();
    //Body manipualtion
    void insertHead(objPos thisPos);
    void insertTail(objPos thisPos);
    void removeHead();
    void removeTail();
    //More Getters
    void getHeadElement(objPos &returnPos);
    void getTailElement(objPos &returnPos);
    void getElement(objPos &returnPos, int index);
};

#endif