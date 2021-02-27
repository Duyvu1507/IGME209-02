#pragma once
#include <iostream>
#include <Box2D.h>
#include "snake.h"
#include <conio.h>

extern b2BodyDef bodyDef;
extern b2BodyDef targetDef;
extern b2Body* snakeBody;
extern b2Body* targetBody;
extern b2Vec2 gravity;
extern b2World world;

void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);


