#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60); //フレームレートを60fpsに設定
	ofSetVerticalSync(true); //垂直同期を設定
	
	ofBackground(0); //背景を真っ黒に設定
	
	bvh.resize(3); //ofxBvhのベクター型bvhの個数を3に設定する
	
	// setup bvh
	bvh[0].load("A_test.bvh"); // bvhの0番目にA_test.bvhを読み込む
	bvh[1].load("B_test.bvh"); // bvhの1番目にB_test.bvhを読み込む
	bvh[2].load("C_test.bvh"); // bvhの2番目にC_test.bvhを読み込む
    
    // bvh.size()は3を返す。
    
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].play();        // bvh[i]のplay()メソッドを実行する。
		bvh[i].setLoop(true); // bvh[i]のsetLoop(true)メソッドを実行する
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].update(); // bvh[i]を更新する
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	glEnable(GL_DEPTH_TEST); // 3Dグラフィックスモード GLを開始

    // 3Dグラフィックスのブレンドモードを設定
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    cam.begin();    // 画面に描画するカメラを開始
	
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].draw(); // bvh[i]のdrawメソッドを実行
	}
	
	cam.end();        //カメラを終了

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
