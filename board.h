#ifndef BOARD_H
#define BOARD_H

#include "turtle.h"

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20

class Board {
	char board[BOARD_WIDTH][BOARD_HEIGHT];

  public:
    Turtle * turtle;

    Board(void);
	void initBoard(void);
	void printBoard(void);
	
	void fixTurtle(void);
	char getPos(int, int);
	void setPos(int, int, char);

	void act(int);
};

#endif