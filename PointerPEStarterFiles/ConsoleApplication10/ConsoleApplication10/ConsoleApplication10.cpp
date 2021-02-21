// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << &boss << endl;
	cout << &pOne << endl;
	cout << &fakeMonster << endl;

	boss->xPos = 5;
	boss->yPos = 5;

	pOne->xPos = 10;
	pOne->yPos = 10;

	fakeMonster->xPos = 15;
	fakeMonster->yPos = 15;

	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();

	/*
	delete boss;
	delete pOne;
	delete fakeMonster;
	*/

	_getch();
    return 0;
}

