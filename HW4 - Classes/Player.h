#pragma once
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	Player(char* playername, int strength, int dexterity, int health);
	void printPlayer();
	~Player() {
		cout << "Destroying Player Object" << endl;
	}
	void *getName() {
		return playername;
	}
	virtual void attack(Player* player) {
		cout << getName()  << " attacks " << player->playername << "!" << endl;
	}
	
private:
	char* playername;
	int strength;
	int dexterity;
	int	health;
};

