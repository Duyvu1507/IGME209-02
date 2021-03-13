#pragma once
class Player
{
public :
	Player();
	Player(char* name, int str, int dx, int hp);
	Player(char name, int str, int dx, int hp);
	void printPlayer();
	void PrintPlayer();	

private: 
	char* playername;
	int strength;
	int dexterity;
	int health;
};

