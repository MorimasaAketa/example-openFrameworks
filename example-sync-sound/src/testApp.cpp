#include "testApp.h"

class Tracker // 点を追跡するtrackerクラス
{
public:
	
	const ofxBvhJoint *joint; // 定数としてofxBvhJointクラスのポインタ変数 *jointを宣言
	deque<ofVec3f> points; // ofVec3fの配列を、STLのdequeとして作り、名前をpointsにする
    // deque(デック): double ended queue; 先頭にも追加しやすいvector

    // Trackerのsetup()メソッド
    void setup(const ofxBvhJoint *o) // 初期化
	{
		joint = o; // Trackerのメンバー変数jointに指定されたoを設定する
	}
	
    // Trackerのupdate()メソッド
    void update()
	{
        if (joint->getBvh()->isFrameNew()){ // jointのフレームが新しくなったか
            // 3dベクター p にjointの位置を取得
			const ofVec3f &p = joint->getPosition();
			
            // pointsの一番先頭に(0番目に)現在の位置を追加
            points.push_front(joint->getPosition());
			

            if (points.size() > 15){  // pointsの数が15以上だったら
				points.pop_back();   // pointsのおしり(15番目)を削除する
            }
        }
	}

    // Trackerのdraw()メソッド
	void draw()
	{
		if (points.empty()) return; // pointsの内容がなかったらdraw()を終了
		
		glBegin(GL_LINE_STRIP); // GL描画をGL_LINE_STRIPモードで開始
		for (int i = 0; i < points.size() - 1; i++) //pointsの数だけ
		{
			float a = ofMap(i, 0, points.size() - 1, 1, 0, true);
			
            ofVec3f &p0 = points[i];     // i番目の点をp0に
			ofVec3f &p1 = points[i + 1]; // i+1 番目の点をp1に
			
			float d = p0.distance(p1); // p0とp1の点の距離を計算しdに代入
			a *= ofMap(d, 3, 5, 0, 1, true); // 係数aを計算
			
			glColor4f(1, 1, 1, a); // 係数aをαとして線の描画色に設定
            // i番目の点をポインターとしてglVertex3fvに与える
            glVertex3fv(points[i].getPtr());
		}
		glEnd(); //GL描画を終了
	}
};

vector<Tracker*> trackers; // グローバルにtrakerクラスのベクター型trakersを宣言
const float trackDuration = 64.28; // 定数 trackDurationを設定

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60); //フレームレートを60fpsに設定
	ofSetVerticalSync(true);
	
	ofBackground(0); // 背景を黒に
	
	play_rate = play_rate_t = 1; // play_rate, play_rateを1に
	rotate = 0; // rotateを0に

	bvh.resize(3); //ofxBvhのベクター型bvhの個数を3に設定する
	
	// You have to get motion and sound data from http://www.perfume-global.com
	
	// setup bvh
	bvh[0].load("bvhfiles/aachan.bvh");    // bin/data/bvhfilesにあるaachan.bvh
	bvh[1].load("bvhfiles/kashiyuka.bvh"); // bin/data/bvhfilesにあるkashyuka.bvh
	bvh[2].load("bvhfiles/nocchi.bvh");    // bin/data/bvhfilesにあるnocchi.bvh
	
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].setFrame(1); // bvhi番目のフレームを1に設定
	}

    // bin/dataの音楽ファイルを読み込み
    track.loadSound("Perfume_globalsite_sound.wav");
	track.play(); //音源の再生開始
	track.setLoop(true); // 音源を繰り返しモードに
	
	// setup tracker 関節の残像、trackerを作る
	for (int i = 0; i < bvh.size(); i++)
	{
		ofxBvh &b = bvh[i]; // bはbvhのi番目
		
		for (int n = 0; n < b.getNumJoints(); n++) // 関節の数繰り返し
		{
			const ofxBvhJoint *o = b.getJoint(n); // bvhのn番目の関節を取得
			Tracker *t = new Tracker; // Trackerの新しいオブジェクトtを作る
			t->setup(o);              //  tをoでセットアップする
			trackers.push_back(t);    // trackersにtを追加
		}
	}
}

//--------------------------------------------------------------
void testApp::update()
{
	rotate += 0.1; // 回転量rotateに0.1を加算
	
	play_rate += (play_rate_t - play_rate) * 0.3; // 再生速度を設定
	track.setSpeed(play_rate); // 音楽の再生速度をplay_rateに設定

    // 音源のどこを再生しているかををgetPositionで取得し、trackDurationを掛ける
	float t = (track.getPosition() * trackDuration);
	t = t / bvh[0].getDuration(); // tがbvh[0]の長さのうちどこになるかを取得
	
	for (int i = 0; i < bvh.size(); i++)
	{
		bvh[i].setPosition(t); // bvh[i]の再生位置をtに設定
		bvh[i].update(); // bvh[i]をupdate
	}
	
	for (int i = 0; i < trackers.size(); i++)
	{
		trackers[i]->update(); // trackerもupdateを実行
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    glEnable(GL_DEPTH_TEST); // gl描画開始
	
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
	ofPushMatrix(); // 現在の座標位置を保存。「プッシュして」今の座標位置を積んでおく
	{
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2); // 画面の中心に原点を設定
		ofTranslate(0, 150); // y方向に150移動
		
		ofRotate(-15, 1, 0, 0); // 回転
		ofRotate(rotate, 0, 1, 0); //回転
		
		ofScale(1, -1, 1); // 大きさをy軸方向に-1
		
		ofSetColor(ofColor::white); // 描画色を白に設定
		
		ofFill();
		
		// draw ground 地面を描画
		ofPushMatrix(); // 現在の座標位置を保存
		ofRotate(90, 1, 0, 0); // 回転
		ofLine(100, 0, -100, 0); // 線
		ofLine(0, 100, 0, -100); // 線
		ofPopMatrix();  // 地面は描画したので現在の座標位置をもどす
		
		// draw actor
		for (int i = 0; i < bvh.size(); i++)
		{
			bvh[i].draw(); // bvhの描画
		}

		// draw tracker
		glDisable(GL_DEPTH_TEST); //一旦gl描画を停止
		ofEnableBlendMode(OF_BLENDMODE_ADD); // 重ね書きモードを変える
		
		ofSetColor(ofColor::white, 80); // 色を80に
		for (int i = 0; i < trackers.size(); i++)
		{
			trackers[i]->draw(); // trackerを描画
		}
	}
	ofPopMatrix(); //先にpushして積んだ今の座標位置を取り出して戻す
	
	ofSetColor(255); // 色を白に
	ofDrawBitmapString("press any key to scratch\nplay_rate: " + ofToString(play_rate, 1), 10, 20); // 文字の表示
}

//--------------------------------------------------------------
//キーを押していたら
void testApp::keyPressed(int key){
	play_rate_t = -1; // play_rate_tを-1に
}

//--------------------------------------------------------------
//キーを押していなかったら
void testApp::keyReleased(int key){
	play_rate_t = 1; // play_rate_tを1に
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
}
