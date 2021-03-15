// HW2 - Gravity Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Box2D.h>
#include "snake.h"
#include <conio.h>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

using namespace std;

int main()
{
	bool play = true; // Bool to determine to continue or not
	int collidedCount = 0;
	int maxCollisions = 10;

	// --- SNAKE -- //
	// Define dynamic body
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	snakeBody = world.CreateBody(&bodyDef);

	// Define another box shape for dynamic body
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	
	// Fixture definition
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	// Add the shape to the body
	snakeBody->CreateFixture(&fixtureDef);

	// --- TARGET --- //
	//Define static body
	targetDef.type = b2_staticBody;
	targetDef.position.Set(1.0f, 4.0f);
	targetBody = world.CreateBody(&targetDef);

	// Define another box shape for static body
	b2PolygonShape staticBox;
	staticBox.SetAsBox(1.0f, 1.0f);

	// Fixture definition
	b2FixtureDef staticFixture;
	staticFixture.shape = &staticBox;
	staticFixture.density = 1.0f;
	staticFixture.friction = .3f;

	// Add the shape to the body
	targetBody->CreateFixture(&staticFixture);

	b2Vec2 snakePos = snakeBody->GetPosition();
	b2Vec2 targetPos = targetBody->GetPosition();
	moveTarget(targetPos.x, targetPos.y);

	// Create sfml window
	//sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");

	cout << "Let's play Gravity Snake" << endl;
	setUpTargets();
	while (play == true) {
		int input;
		display();
		processInput();
		
		snakePos = snakeBody->GetPosition();
		targetPos = targetBody->GetPosition();
		
		// Collission detection
		if ((snakePos.x - targetPos.x <= 2 && snakePos.x - targetPos.x >= -2) && (snakePos.y - targetPos.y <= 2 && snakePos.y - targetPos.y >= -2)) {
			moveTarget(targetPos.x, targetPos.y);
			collidedCount++;
		}

		// If 10 collissions, you win!
		if (collidedCount == maxCollisions) {
			play = false;
			cout << "You Win!" << endl;
		}

		update();	
	}

}


