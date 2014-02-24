#include "board.h"
#include <iostream>

using namespace std;

Board::Board() {
	turtle = new Turtle();
	initBoard();
}

void Board::initBoard() {
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
			board[i][j] = '.';
}

void Board::printBoard() {
	// Start drawing from the top (makes sense)
	for (int j = (BOARD_HEIGHT-1); j >= 0; j--) {
		for (int i = 0; i < BOARD_WIDTH; i++) {
			cout << board[i][j] << ' ';
		}
		cout << endl << endl;
	}
}

void Board::fixTurtle() {
	// This function checks the turtle is not out of bounds.
    // If it is, it brings it back inside. (Stick to wall behaviour)
    int turtleX = turtle->getX();
    int turtleY = turtle->getY();
    if      ( turtleX > (BOARD_WIDTH-1)  ) turtle->moveTo(BOARD_WIDTH-1, turtleY);
	else if ( turtleY > (BOARD_HEIGHT-1) ) turtle->moveTo(turtleX, BOARD_HEIGHT-1);
	else if ( turtleX < 0 ) turtle->moveTo(0, turtleY);
	else if ( turtleY < 0 ) turtle->moveTo(turtleX, 0);
}

char Board::getPos(int x, int y) {
	// Check if (x, y) outside of board
	if ( !(x >= 0 && x <= BOARD_WIDTH) || !(y >= 0 && y <= BOARD_HEIGHT) ) return '\0';
	else return board[x][y];
}

void Board::setPos(int x, int y, char c) {
	// Check if (x, y) outside of board
	if ( !(x >= 0 && x <= BOARD_WIDTH) || !(y >= 0 && y <= BOARD_HEIGHT) ) return;
	else board[x][y] = c;
}

void Board::act(int steps) {
	// This function moves the turtle, validates/fixes its position, and 'draws' if the pen is active.
	for (int i = 0; i < steps; i++) {
		// Draw the current location (Put it first - for now)
		if (turtle->isActive()) setPos(turtle->getX(), turtle->getY(), turtle->getBrush());

		// Move the turtle
		turtle->moveForward(1);
	
		// Fix, if necessary 
		fixTurtle();
	}
}