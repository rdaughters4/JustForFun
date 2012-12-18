#include "rectangle.h"

rectangle::rectangle() {
	xCord = NULL;
	yCord = NULL;
	width = NULL;
	height = NULL;
	color = Color8u(0, 0, 0);
}

rectangle::rectangle(double x, double y, double wid, double ht, Color8u c) {
	xCord = x;
	yCord = y;
	width = wid;
	height = ht;
	color = c;
}

void rectangle::setCordinates(double xCord, double yCord) {
	xCord = xCord;
	yCord = yCord;
}

void rectangle::setSize(double width, double height) {
	width = width;
	height = height;
}

void rectangle::setColor(Color8u c) {
	color = c;
}

int rectangle::redColor() {
	return color.r;
}

int rectangle::greenColor() {
	return color.g;
}

int rectangle::blueColor() {
	return color.b;
}