#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class rectangle {
public:
	// constructors
	rectangle();
	rectangle(double x, double y, double wid, double ht, Color8u c);

	// methods
	void setCordinates(double xCord, double yCord);
	void setSize(double width, double height);
	void setColor(Color8u c);
	int redColor();
	int greenColor();
	int blueColor();

	// variables
	double xCord;
	double yCord;
	double width;
	double height;
	Color8u color;

};