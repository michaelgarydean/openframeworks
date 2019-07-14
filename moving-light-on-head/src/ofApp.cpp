#include "ofApp.h"

/*
Loads a model of a head and moves a light around with a mouse
*/

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);

  // load the  model
	model.loadModel("male_head.obj");
	model.setScale(0.9, 0.9, 0.9);
  //model.setRotation(0, 180, 0, 1, 0);

  // set the orientation of the model so it faces the viewer
	meshNode.setOrientation(glm::angleAxis(ofDegToRad(-90.f), glm::vec3{1.f, 0.f, 0.f}));
	model.setRotation(0, -170, 1, 0, 0);
	model.setRotation(1, 180, 0, 1, 0);
	model.setScale(0.9, 0.9, 0.9);

  // set up the light
  light.setPosition(100, 200, 1000);

  // set up the camera
	cameraOrbit = 0;
	cam.setDistance(700);

  //set help text to display by default
  bHelpText  = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	mouseX = ((ofGetMouseX()/(float)ofGetWindowWidth())-0.5)*float(ofGetWindowWidth());
	light.setPosition(mouseX, ofGetMouseY(), 0);
	//lightOrbit += ofGetLastFrameTime() * 20.; // 20 degrees per second;
	//light.setOrientation(lightOrbit, 0., cam.getDistance(), {0., 0., 0.});
}

//--------------------------------------------------------------
void ofApp::draw(){

	// so the model isn't see through.
	ofEnableDepthTest();

  light.enable();

	cam.begin();

	ofColor(255,255);

	// draws all the other file types which are loaded into model.
	model.drawFaces();
	cam.end();

  light.disable();

	ofDisableDepthTest();

  // display help text if it is enable
  if(bHelpText) {
      stringstream ss;
      ss << "FPS: " << ofToString(ofGetFrameRate(),0) << endl << endl;
      ss << "Test application loading models"<<endl;
      ss << ofGetMouseX()<<endl;
      ofDrawBitmapString(ss.str().c_str(), 20, 20);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            default:
                break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
