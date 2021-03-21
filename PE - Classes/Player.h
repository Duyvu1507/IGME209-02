#pragma once
class Player
{
public :
	Player();
	Player(char* name, int str, int dx, int hp);
	Player(char name, int str, int dx, int hp);
	void printPlayer();

private: 
	char* playername;
	int strength;
	int dexterity;
	int health;
};

