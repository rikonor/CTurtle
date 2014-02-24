#include "pen.h"

Pen::Pen() {
	active = true;
	shape  = 'x';
}

bool Pen::isActive() {
	return active;
}

void Pen::toggle() {
	active = !active;
}

char Pen::getShape() {
	return shape;
}

void Pen::setShape(char newShape) {
	shape = newShape;
}