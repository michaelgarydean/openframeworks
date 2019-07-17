//Code from https://openframeworks.cc/ofBook/chapters/generativemesh.html

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	//load image file
    image.load("stars.png");
	image.resize(200, 200);

    //Set mech vertices to points
	mesh.setMode(OF_PRIMITIVE_POINTS);
	// mesh.setMode(OF_PRIMITIVE_LINES);
	// mesh.enableIndices();

    //Use color on vertives
    mesh.enableColors();

    //Loop over the image's pixels and create a vertex if the intensity is greater than 150
    float intensityThreshold = 150.0;

    int w = image.getWidth();
    int h = image.getHeight();

    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {

        	//Get pixel information
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();

            //Only create vertices greater than the threshold
            if (intensity >= intensityThreshold) {


			    float saturation = c.getSaturation();
			    float z = ofMap(saturation, 0, 255, -1000, 1000);
			    ofVec3f pos(x*4, y*4, z);
			    mesh.addVertex(pos);
			    mesh.addColor(c);
            }
        }
    }

	//     // Let's add some lines!
	// float connectionDistance = 30;
	// int numVerts = mesh.getNumVertices();
	// for (int a=0; a<numVerts; ++a) {
	//     ofVec3f verta = mesh.getVertex(a);
	//     for (int b=a+1; b<numVerts; ++b) {
	//         ofVec3f vertb = mesh.getVertex(b);
	//         float distance = verta.distance(vertb);
	//         if (distance <= connectionDistance) {
	//             // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
	//             // connected to form a line
	//             mesh.addIndex(a);
	//             mesh.addIndex(b);
	//         }
	//     }
	// }
}

//--------------------------------------------------------------
void ofApp::draw(){
 

    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
            mesh.draw();
        ofPopMatrix();
    easyCam.end();

    mesh.save("mesh.ply");

}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
