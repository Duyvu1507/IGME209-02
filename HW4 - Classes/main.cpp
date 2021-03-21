// HW4 - Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;

int main()
{
    // PART 1 - CLASSES
    Player p1; // Stack Default Constructor

    Player p2((char*)"Dwee", 5, 6, 7); // Stack Paramatarized Constructor

    Player* p3 = new Player(); // Heap Default Constructor

    Player* p4 = new Player((char*)"Bob", 6, 7, 8); // Heap Paramatarized Constructor

    p1.printPlayer();
    cout << endl;

    p2.printPlayer();
    cout << endl;

    (*p3).printPlayer();
    cout << endl;

    (*p4).printPlayer();
    cout << endl;

    delete p3;
    delete p4;

    // Part 2 - Inheritence
    Fighter f1; // Default Constructor

    Fighter f2((char*)"Bob", 5, 5, 5, (char*)"Swordsmanship");

    cout << endl;
    f1.printFighter();

    cout << endl;
    f2.printFighter();

    cout << endl;


    // Part 3 - Virtual Methods and Destructors
    cout << "TOURNAMENT OF DEATH" << endl;
    int randomNum;
    int randomNum2;
    int deadEnemies = 0;
    Player* battlers[10];

    // Creates 10 Player or Fighter Objs based on random number
    for (int i = 0; i < 10; i++) {
        randomNum = rand() % 2;
        
        // If randomNum = 0, create player
        if (randomNum == 0) {
            Player* p = new Player((char*)"Player" + (char)i, randomNum, randomNum, randomNum);
            battlers[i] = p;
            delete p;
        }
        // Else if randomNum = 1, create fighter
        else if (randomNum == 1) {
            Fighter* f = new Fighter((char*)"Fighter" + (char)i, randomNum, randomNum, randomNum, (char*)"Magic");
            battlers[i] = f;
            delete f;
        }
    }

    // Makes them battle it out until there is 1 winner
    while (deadEnemies != 9) {
        randomNum = rand() % 10;
        randomNum2 = rand() % 10;
        while (randomNum == randomNum2) {
            randomNum = rand() % 11;
            randomNum2 = rand() % 11;
        }
        battlers[randomNum]->attack(battlers[randomNum2]);
        battlers[randomNum2] = nullptr;
        deadEnemies += 1;
        delete battlers[randomNum2];
    }

    for (int i = 0; i < 10; i++) {
        if (battlers[i] != nullptr) {
            cout << "The winner is " << battlers[i] << endl;
        }
    }

}


