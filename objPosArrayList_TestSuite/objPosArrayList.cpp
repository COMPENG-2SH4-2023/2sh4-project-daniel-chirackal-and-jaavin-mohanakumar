#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction,
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; // 256 elements on the heap
    listSize = 0;                      // no valid element in the list upon startup
    arrayCapacity = ARRAY_MAX_CAP;     // Capacity in array should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;  //delete [] to destruct all of the elements in the objPos list
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //still need error check - what if listSize is at capacity?
    // - check if listSize is equal to arrayCapacity. If yes, at capacity, don't insert.

    if (listSize < ARRAY_MAX_CAP)
    {
        for (int i = (listSize); i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }
        aList[0].setObjPos(thisPos);

        listSize++;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < ARRAY_MAX_CAP)
    {
        aList[listSize].setObjPos(thisPos);
        listSize++;
    }

}

void objPosArrayList::removeHead()
{
    if (listSize > 0)
    {
        for (int i = 0; i < listSize; i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0)
    {
        listSize--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}