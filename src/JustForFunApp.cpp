#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "rectangle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class JustForFunApp : public AppBasic {
  public:
	// methods
	void prepareSettings(Settings* settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void clearWindow(uint8_t* pixels);
	void drawRectangle(rectangle rec, uint8_t* pixels);

	// window size constants
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	static const int kSurfaceSize=1024;

	// surface variables
	Surface* mySurface;
	uint8_t* myPixels;
};

void JustForFunApp::prepareSettings(Settings* settings)
{
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void JustForFunApp::setup()
{
	// initialize surface
	mySurface = new Surface(kSurfaceSize,kSurfaceSize,false);
	myPixels = (*mySurface).getData();

	// clear window
	clearWindow(myPixels);

	// color
	Color8u c = Color8u(0, 250, 0);
	Color8u red = Color8u(250, 0, 0);

	// create rectangle
	rectangle rectangle1 = rectangle();
	rectangle rectangle2 = rectangle(400, 300, 100, 100, c);

	// draw rectangles
	drawRectangle(rectangle2, myPixels);

	// draw a center point red
	int index = 3*(400+300*kSurfaceSize);
	myPixels[index] = red.r;
	myPixels[index+1] = red.g;
	myPixels[index+2] = red.b;
}

void JustForFunApp::mouseDown( MouseEvent event )
{
}

void JustForFunApp::update()
{
}

void JustForFunApp::clearWindow(uint8_t* pixels){
	Color c = Color(0, 0, 0);
	for(int y = 0; y < kSurfaceSize; y++){
		for(int x = 0; x < kSurfaceSize; x++){
			int index = 3*(x + y*kSurfaceSize);
			pixels[index] = c.r;
			pixels[index+1] = c.g;
			pixels[index+2] = c.b;
		}
	}
}

void JustForFunApp::drawRectangle(rectangle rec, uint8_t* pixels) {
	for (int y = (rec.yCord-(rec.height/2)); y < ((rec.yCord-(rec.height/2)) + rec.height); y++) {
		for (int x = (rec.xCord-(rec.width/2)); x < ((rec.xCord-(rec.width/2)) + rec.width);) {
			if (x > kAppWidth || y > kAppHeight)
				x++;
			else {
				int index = 3*(x + y*kSurfaceSize);
				pixels[index] = rec.redColor();
				pixels[index+1] = rec.greenColor();
				pixels[index+2] = rec.blueColor();
				x++;
			}
		}
	}
}

void JustForFunApp::draw()
{
	gl::draw(*mySurface);
}

CINDER_APP_BASIC( JustForFunApp, RendererGl )
