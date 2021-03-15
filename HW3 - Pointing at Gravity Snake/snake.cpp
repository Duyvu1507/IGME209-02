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

b2Vec2* targetLocations; // Stores multiple b2vec2 for each position of the target for the game
b2Vec2 currentLocation; // Variable for the position of each target

typedef b2Body& Body;

int numTargets = 0;

// Updates the world
void update() {
	world.Step(timeStep, velocityIterations, positionIterations);
}

// Displays the position of the target and snake body
void display() {
	b2Vec2 snakePos = snakeBody->GetPosition();
	b2Vec2 targetPos = targetBody->GetPosition();

	cout << "Target " << targetPos.x << ", " << targetPos.y << " --> Snake " << snakePos.x << ", " << snakePos.y << endl;
}

// Apply force to snake based on user input
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

// Moves target
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

void processInput() {
	char input; // User input var
	if (_kbhit()) {
		input = _getch();

		if (input == 'w') {
			applyForceUp(*snakeBody);
		}

		else if (input == 'a') {
			applyForceLeft(*snakeBody);
		}

		else if (input == 's') {
			applyForceDown(*snakeBody);
		}

		else if (input == 'd') {
			applyForceRight(*snakeBody);
		}

		// Exits program if esc is pressed
		else if (int(input) == 27) {
			exit;
		}
	}
}

void applyForceUp(Body player) {
	snakeBody->ApplyForceToCenter(b2Vec2(0, 20), true);
}

void applyForceDown(Body player) {
	snakeBody->ApplyForceToCenter(b2Vec2(0, -20), true);
}

void applyForceLeft(Body player) {
	snakeBody->ApplyForceToCenter(b2Vec2(-20, 0), true);
}

void applyForceRight(Body player) {
	snakeBody->ApplyForceToCenter(b2Vec2(20, -20), true);
}

void stopMoving(Body player) {
	snakeBody->SetAngularVelocity(0);
}

void reverseGravity(b2World& world) {
	if (gravity.y == -9.8) {
		gravity.y = 9.8;
	}
	else if (gravity.y == 9.8) {
		gravity.x = -9.8;
	}
	world.SetGravity(gravity);
}

void setUpTargets() {
	int input = -1;
	bool validInput = false;
	while (validInput == false) {
		if (input <= 0 || input > 10) {
			cout << "\nPlease enter the number of targets (1-10): ";
			cin >> input;
		}
		else {
			validInput = true;
		}
	}
	targetLocations = new b2Vec2[input+1];
	numTargets = input + 1;

	for (int i = 0; i < input; i++) {
		int x = (rand() % 10) - 5.0f;
		int y = (rand() % 10) - 5.0f;
		b2Vec2 target((float)x, (float)y);
		targetLocations[i] = target;
	}
	targetLocations[input+1] = b2Vec2(-1000, -1000);
}

bool selectNextTarget() {
	for (int i = 0; i < numTargets; i++) {
		currentLocation = targetLocations[i];
		return true;
	}
	return false;
}