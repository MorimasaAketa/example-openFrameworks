#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(0);
	
	bvh.resize(3);
	
	// setup bvh
	bvh[0].load("A_test.bvh");
	bvh[1].load("B_test.bvh");
	bvh[2].load("C_test.bvh");
	
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].play();
		bvh[i].setLoop(true);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	glEnable(GL_DEPTH_TEST);
	
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	cam.begin();
	
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].draw();
	}
	
	cam.end();

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
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}
