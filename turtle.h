#ifndef TURTLE_H
#define TURTLE_H

#include "pen.h"
#include "direction.h"
#include "position.h"

class Turtle {
  	Pen 	  * pen;
    Position  * position;
    Direction * direction;

  public:
  	Turtle(void);

  	// Movement
  	void moveForward(int);

  	// Turning
  	void turnLeft(void);
  	void turnRight(void);

  	// Location
  	void moveTo(int, int); // JUMP
    int  getX(void);
    int  getY(void);

  	// Drawing related
  	bool isActive(void);
    void togglePen(void);
  	void changeBrush(char);
	char getBrush(void);
};

#endif