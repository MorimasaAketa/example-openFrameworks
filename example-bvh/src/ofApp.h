#pragma once

#include "ofMain.h"
#include "ofxBvh.h" // アドオン、ofxBvhを使用する

class ofApp : public ofBaseApp{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	vector<ofxBvh> bvh; // ofxBvhのベクター型bvhを宣言する。
	ofEasyCam cam; // 3D視点を簡単に切り替えるためのofEasyCamクラスのオブジェクトcam
	
};
