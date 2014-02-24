#include "board.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void clearScreen() {
	// Kinda slow, but use this for now
	for (int i = 0; i < 50; i++) cout << endl;
}

void printMenu() {
	cout << "1 Toggle Pen\t| 2 Turn (L=0/R=1)\t| 3 Move Forward| 4 Print Board" << endl << "5 Change Brush\t| 6 Erase Board\t| 7 Jump (X,Y) \t| 8 Show Menu\t| 9 Exit" << endl << endl; 
}

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

// Consider a 'getArgument' function instead. Recieves a string, empty * int, and index to begin looking.
int getUserSelection(char in[]) {
	if (isDigit(in[0])) return (in[0]-'0');
	else return 0;
}

int getArgument(char in[], int * arg, int i) {
	int result = 0;
	while (isDigit(in[i])) result = 10*result + (in[i++]-'0');
	*arg = result;
	return (i+1);
}

void actUserSelection(char in[], Board * board) {

	int selection;
	int arg1Index = getArgument(in, &selection, 0);
	int arg2Index;
	int arg1, arg2;

	switch(selection) {
		case 1:
			board->turtle->togglePen();
			break;
		case 2:
			getArgument(in, &arg1, arg1Index);
			if		(arg1 == 0) board->turtle->turnLeft();
			else if (arg1 == 1) board->turtle->turnRight();
			else cout << "Unrecognized argument..." << endl;
			break;
		case 3:
			getArgument(in, &arg1, arg1Index);
			board->act(arg1);
			break;
		case 4:
			board->printBoard();
			break;
		case 5:
			break;
		case 6:
			board->initBoard();
			cout << "Board Reset..." << endl;
			break;
		case 7:
			arg2Index = getArgument(in, &arg1, arg1Index);
			getArgument(in, &arg2, arg2Index);
			board->turtle->moveTo(arg1, arg2);
			break;
		case 8:
			printMenu();
			break;
		default:
			cout << "Unrecognized command." << endl;
	}
}

int main() {
	// Intro
	cout << "----- CTurtle ------" << endl << endl;
	
	// Actuacl program
	Board * board = new Board();

	printMenu();

	char in[16];
	while(true) {
		cout << "> ";
		gets(in);
		if (!strcmp(in, "9")) break;

		actUserSelection(in, board);
	}

	// Exit
	cout << endl << "Press enter to exit...";
	getchar();
}