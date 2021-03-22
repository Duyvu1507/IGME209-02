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

    Fighter f2((char*)"Bill", 5, 5, 5, (char*)"Swordsmanship");

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
    int creationCount = 0;
    Player* battlers[10];
    const char* names[6] = { "Bob", "Bill", "Jack", "Greg", "Jill", "Nick"};

    // Creates 10 Player or Fighter Objs based on random number
    for (int i = 0; i < 10; i++) {
        randomNum = rand() % 2;
        // If randomNum = 0, create player
        if (randomNum == 0) {
            randomNum2 = rand() % 6;
            Player* p = new Player((char*)names[randomNum2], randomNum, randomNum2, randomNum);
            battlers[i] = p;
        }
        // Else if randomNum = 1, create fighter
        else if (randomNum == 1) {
            randomNum2 = rand() % 6;
            Fighter* f = new Fighter((char*)names[randomNum2], randomNum, randomNum2, randomNum, (char*)"Magic");
            battlers[i] = f;
        }
    }

    // Makes them battle it out until there is 1 winner
    while (deadEnemies != 9) {
        randomNum = rand() % 10;
        randomNum2 = rand() % 10;
        while (randomNum == randomNum2 || battlers[randomNum] == nullptr || battlers[randomNum2] == nullptr) {
            randomNum = rand() % 11;
            randomNum2 = rand() % 11;
        }
        battlers[randomNum]->attack(battlers[randomNum2]);
        battlers[randomNum2] = nullptr;
        deadEnemies += 1;
    }

    for (int i = 0; i < 10; i++) {
        if (battlers[i] != nullptr) {
            cout << "The winner is " << battlers[i] << endl;
        }
        else if (battlers[i] == nullptr) {
            delete battlers[i];
        }
    }

}


