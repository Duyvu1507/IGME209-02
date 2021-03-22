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

    p2.printPlayer();

    (*p3).printPlayer();

    (*p4).printPlayer();

    delete p3;
    delete p4;
    cout << endl;

    // Part 2 - Inheritence
    Fighter f1; // Default Constructor

    Fighter f2((char*)"Bill", 5, 5, 5, (char*)"Swordsmanship");

    f1.printFighter();

    f2.printFighter();


    // Part 3 - Virtual Methods and Destructors
    cout << "-----TOURNAMENT OF DEATH-----\n" << endl;
    int randomNum;
    int randomNum2;
    int deadEnemies = 0;
    int creationCount = 0;
    Player* battlers[10];
    const char* playerNames[6] = { "Bob", "Bill", "Jack", "Greg", "Jill", "Nick"};
    const char* fighterNames[6] = { "John", "Alan", "Jackson", "Tyler", "Phill", "Steve" };

    // Creates 10 Player or Fighter Objs based on random number
    for (int i = 0; i < 10; i++) {
        randomNum = rand() % 2;
        // If randomNum = 0, create player
        if (randomNum == 0) {
            randomNum2 = rand() % 6;
            Player* p = new Player((char*)playerNames[randomNum2], randomNum, randomNum2, randomNum);
            battlers[i] = p;
        }
        // Else if randomNum = 1, create fighter
        else if (randomNum == 1) {
            randomNum2 = rand() % 6;
            Fighter* f = new Fighter((char*)fighterNames[randomNum2], randomNum, randomNum2, randomNum, (char*)"Magic");
            battlers[i] = f;
        }
    }

    // Makes them battle it out until there is 1 winner
    while (deadEnemies != 9) {
        randomNum = rand() % 10;
        randomNum2 = rand() % 10;
        while (randomNum == randomNum2 || battlers[randomNum] == nullptr || battlers[randomNum2] == nullptr) {
            randomNum = rand() % 10;
            randomNum2 = rand() % 10;
        }
        battlers[randomNum]->attack(battlers[randomNum2]);
        battlers[randomNum2] = nullptr;
        deadEnemies += 1;
    }

    // Prints out the winner
    for (int i = 0; i < 10; i++) {
        if (battlers[i] != nullptr) {
            cout << "\nThe winner is " << (char*)battlers[i]->getName() << "\n" << endl;
        }
    }

    // Deletes all remaining objects
    for (int i = 0; i < 10; i++) {
        delete battlers[i];
    }

}


