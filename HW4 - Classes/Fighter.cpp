#include "Fighter.h"
#include "Player.h"
#include <iostream>
using namespace std;

Fighter::Fighter() {
	weaponSkill = (char*)"None";
}

Fighter::Fighter(char* pName, int str, int dx, int hp, char* weaponSk) {
	Player(pName, str, dx, hp);
	this->weaponSkill = (char*)weaponSk;
}

void Fighter::printFighter() {
	printPlayer();
	cout << "Weapon Skill: " << weaponSkill << endl;
}