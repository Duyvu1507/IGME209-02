#include "Fighter.h"
#include "Player.h"
#include <iostream>
using namespace std;

Fighter::Fighter() {
	weaponSkill = (char*)"None";
}

Fighter::Fighter(char* fName, int str, int dx, int hp, char* weaponSk) : Player(fName, str, dx, hp) {
	this->fighterName = (char*)fName;
	this->strength = str;
	this->dexterity = dx;
	this->health = hp;
	this->weaponSkill = (char*)weaponSk;
}

void Fighter::printFighter() {
	printPlayer();
	cout << "Weapon Skill: " << weaponSkill << endl;
}