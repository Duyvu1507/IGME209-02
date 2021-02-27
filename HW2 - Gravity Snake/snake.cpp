#include <iostream>
#include <Box2D.h>
#include "snake.h"
#include <conio.h>


using namespace std;

// Vars to update time
float32 timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

// Create world
b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);
b2BodyDef bodyDef;
b2BodyDef targetDef;

// Declare snakebody and target body
b2Body* snakeBody;
b2Body* targetBody;

void update() {
	world.Step(timeStep, velocityIterations, positionIterations);
}

void display() {
	b2Vec2 snakePos = snakeBody->GetPosition();
	b2Vec2 targetPos = targetBody->GetPosition();

	cout << "Target " << targetPos.x << ", " << targetPos.y << " --> Snake " << snakePos.x << ", " << snakePos.y << endl;
}

void applyForces() {
	char input = _getch();

	float xToMove;
	float yToMove;

	if (input == 'w') {
		yToMove = 25;
	}

	else if (input == 'a') {
		xToMove = -25;
	}

	else if (input == 's') {
		yToMove = -25;
	}

	else if (input == 'd') {
		xToMove = 25;
	}

	snakeBody->ApplyForceToCenter(b2Vec2(xToMove, yToMove), true);
}

void moveTarget(float& xPos, float& yPos) {
	srand((int)time(0));
	
	float newTargetPosX = (rand() % 10) - 5.0f;
	float newTargetPosY = (rand() % 10) - 5.0f;

	targetBody->SetTransform(b2Vec2(newTargetPosX, newTargetPosY), targetBody->GetAngle());
}