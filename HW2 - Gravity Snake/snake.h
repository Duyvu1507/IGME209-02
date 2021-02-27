#pragma once
#include <iostream>
#include <Box2D.h>
#include "snake.h"
#include "snake.cpp"
#include <conio.h>

void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);


