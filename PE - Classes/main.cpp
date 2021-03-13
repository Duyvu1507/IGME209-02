// PE - Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Player.h";

int main()
{
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
}


