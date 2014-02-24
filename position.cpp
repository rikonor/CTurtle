#include "position.h"

Position::Position() {
	x = 0;
	y = 0;
}

void Position::setXY(int newX, int newY) {
	x = newX;
	y = newY;
}

int Position::getX() {
	return x;
}

int Position::getY() {
	return y;
}