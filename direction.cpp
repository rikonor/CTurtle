#include "direction.h"

Direction::Direction() {
	// Default direction is EAST (RIGHT)
  	xDirection = 1;
	yDirection = 0;
}

// GET
int Direction::getXDirection() {
	return xDirection;
}

int Direction::getYDirection() {
  return yDirection;
}

// SET
void Direction::setXDirection(int newDirection) {
  // Valid values are -1, 0, +1
  	if ( !(newDirection >= -1 && newDirection <= 1) )
    	xDirection = 0;
  	else
    	xDirection = newDirection;
}

void Direction::setYDirection(int newDirection) {
  	// Valid values are -1, 0, +1
  	if ( !(newDirection >= -1 && newDirection <= 1) )
    	yDirection = 0;
  	else
    	yDirection = newDirection;
}

void Direction::setDirection(int newXDirection, int newYDirection) {
  	setXDirection(newXDirection);
  	setYDirection(newYDirection);
}

// TURN
void Direction::turnLeft() {
  	// Change according to a 90' transformation matrix
  	int tmp = xDirection;
  	xDirection = -yDirection;
  	yDirection = tmp;
}

void Direction::turnRight() {
  // Change according to a 90' transformation matrix
  	int tmp = xDirection;
  	xDirection = yDirection;
  	yDirection = -tmp;
}