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
b2Vec2 gravity(0.0f, -9.8f);
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

	float xToMove = 0;
	float yToMove = 0;

	if (input == 'w') {
		yToMove = 20;
	}

	else if (input == 'a') {
		xToMove = -20;
	}

	else if (input == 's') {
		yToMove = -20;
	}

	else if (input == 'd') {
		xToMove = 20;
	}

	snakeBody->ApplyForceToCenter(b2Vec2(xToMove, yToMove), true);
}

void moveTarget(float& xPos, float& yPos) {
	if (xPos > 4.9) {
		xPos -= 0.5;
	}
	else if (xPos < -5.0) {
		xPos += 0.5;
	}
	else if (yPos > 4.9) {
		yPos -= 0.5;
	}
	else if (yPos < -4.9) {
		yPos += 0.5;
	}
	
	targetBody->SetTransform(b2Vec2(xPos, yPos), targetBody->GetAngle());
}