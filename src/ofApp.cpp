#include "ofApp.h"

float Ground_radius = 1000.0;
float Player_size = 100;
float mX = -999;  //-1 ~ 1
int frame_count;

//地面の大きいCircleのY座標を取得
float ofApp::getGround_yPos(){
    return Ground_radius + ofGetHeight()*0.7;
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    
    ground.init(Ground_radius, getGround_yPos());
    
    float initAngle = 0;
    float initY = -(cos(initAngle) * Ground_radius + Player_size) + getGround_yPos();
    player.init(ofGetWidth()/2, initY, Player_size);
    
    
    hokuyo.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float hokuyo_x = hokuyo.update();
    player.update(mX, Ground_radius, getGround_yPos(), hokuyo_x);
    
    for(int i = 0; i < circles.size(); i++) {
        circles[i].update();
        if(circles[i].yPos > ofGetHeight()) {
            circles.erase(circles.begin()+i);//要素削除
        }
    }
    
    //cirlcleとplayerの衝突判定
    checkCollision();
    
    if(setTimer(60)) {
        //60フレームに1度実行される
        circleInit();
    };
    
    
    frame_count ++;
}

//circleとplayerの衝突 衝突したら該当のcircle消す
void ofApp::checkCollision() {
    for (int i = 0; i < circles.size(); i++) {
        ofVec2f playerCenter;
        playerCenter.x = player.xPos + player.size/2;
        playerCenter.y = player.yPos + player.size/2;
        float dist = sqrt(pow(circles[i].xPos - playerCenter.x, 2) + pow(circles[i].yPos - playerCenter.y, 2));
        if(dist < Player_size/2 + circles[i].eSize/2) {
            player.color_value += 0.1;
            circles.erase(circles.begin()+i);//要素削除
        }
    }
}

bool ofApp::setTimer(int doCount) {
    if(frame_count % doCount == 0) {
        return true;
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ground.display();
    
    for(int i = 0; i < circles.size(); i ++){
        circles[i].display();
    }
    
    player.display();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    float mousePositionX = ofGetMouseX();
    float stageWidth = ofGetWidth();
    mX = (mousePositionX / stageWidth - 0.5) * 2;  //-1 ~ 1
}

//--------------------------------------------------------------

void ofApp::circleInit() {
    Circle circle;
    float x = ofRandom(ofGetWidth());
    circle.init(x, -100, 15, ofRandom(2) + 2, frame_count);
    circles.push_back(circle);
}
