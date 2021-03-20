// PE12 - Smart Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "GameLevel.h";

class SmartPtr {
    GameLevel* smartPtr;
public:
    void SmartPointer() {
        smartPtr = new GameLevel();
        delete smartPtr;
    }
};


void NormalPointer() {
    GameLevel* normalPtr = new GameLevel();
    delete normalPtr;
}

int main()
{
    shared_ptr<SmartPtr> smartPrt(new SmartPtr());
    smartPrt->SmartPointer();

    NormalPointer();
}

