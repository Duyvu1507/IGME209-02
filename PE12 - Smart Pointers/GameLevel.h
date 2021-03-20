#pragma once
#include <iostream>
#include <memory>
using namespace std;

class GameLevel
{
public:
	GameLevel() {
		enemies = new int[10];
		cout << "created" << endl;
	}
	~GameLevel() {
		delete[] enemies;
		cout << "deleted" << endl;
	}

private:
	int* enemies;
};

