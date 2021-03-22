#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	playername = (char*)"Unknown";
	strength = 10;
	dexterity = 10;
	health = 10;
}

Player::Player(char* name, int str, int dx, int hp) {
	this->playername = (char*)name;
	this->strength = str;
	this->dexterity = dx;
	this->health = hp;
}

void Player::printPlayer() {
	cout << "Player Name: " << playername << endl;
	cout << "Strength: " << strength << endl;
	cout << "Dexterity: " << dexterity << endl;
	cout << "Health: " << health << endl;
}




