#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	//ofAppGlutWindow window; // create a window

	//Set dimensions to the size of the image we are loading
	ofSetupOpenGL(800,800,OF_WINDOW);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
