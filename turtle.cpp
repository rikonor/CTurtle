#include "turtle.h"

Turtle::Turtle() {
	pen = new Pen();
	position = new Position();
	direction = new Direction();		
}

// Movement
void Turtle::moveForward(int steps) {
	position->setXY(
		position->getX() + steps*direction->getXDirection(),
		position->getY() + steps*direction->getYDirection()
	);
}

// Turning
void Turtle::turnLeft() {
	direction->turnLeft();
}

void Turtle::turnRight() {
	direction->turnRight();
}

// Location
void Turtle::moveTo(int newX, int newY) {
	position->setXY(newX, newY);
} // JUMP

int Turtle::getX() {
	return position->getX();
}

int Turtle::getY() {
	return position->getY();
}

// Drawing related
bool Turtle::isActive() {
	return pen->isActive();
}

void Turtle::togglePen() {
	pen->toggle();
}

void Turtle::changeBrush(char newBrush) {
	pen->setShape(newBrush);
}

char Turtle::getBrush() {
	return pen->getShape();
}