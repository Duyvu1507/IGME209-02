#pragma once
#include "Player.h"
#include <iostream>
using namespace std;

class Fighter : public Player
{
public:
	Fighter();
	Fighter(char* playerName, int strength, int dexterity, int health, char* weaponSkill);
	void printFighter();
	~Fighter() {
		cout << "Destroying Fighter Object" << endl;
	}
	void attack(Player* player) {
		cout << playerName << " attack's " << getName() << " with a weapon!" << endl;
	}

private:
	char* playerName;
	int strength;
	int dexterity;
	int health;
	char* weaponSkill;
};

