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
extern b2Vec2* targetLocations;
extern b2Vec2 currentLocation;

void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);
void processInput();
void applyForceUp(b2Body& player);
void applyForceDown(b2Body& player);
void applyForceLeft(b2Body& player);
void applyForceRight(b2Body& player);
void stopMoving(b2Body& player);
void reverseGravity(b2World& world);
void setUpTargets();
bool selectNextTarget();



