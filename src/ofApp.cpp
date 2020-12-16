#include "ofApp.h"

#define Ground_radius 1000.0
#define Player_size  100
float mX = -999;  //-1 ~ 1

//地面の大きいCircleのY座標を取得
float ofApp::getGround_yPos(){
    return Ground_radius + ofGetHeight()*0.7;
}

//--------------------------------------------------------------
void ofApp::setup(){
    float cosA = (pow(ofGetWidth(), 2) - pow(Ground_radius, 2) * 2) / (- 2 * Ground_radius * 2);
    
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    
    ground.init(Ground_radius, getGround_yPos());
    
    float initAngle = 0;
    float initY = -(cos(initAngle) * Ground_radius + Player_size) + getGround_yPos();
    player.init(ofGetWidth()/2, initY, Player_size);
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
    
    for(int i = 0; i < circles.size(); i++) {
        circles[i].update();
        if(circles[i].yPos > ofGetHeight()) {
            circles.erase(circles.begin()+i);//要素削除
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.display();
    ground.display();
    
    for(int i = 0; i < circles.size(); i ++){
        circles[i].display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    float mousePositionX = ofGetMouseX();
    float stageWidth = ofGetWidth();
    mX = (mousePositionX / stageWidth - 0.5) * 2;  //-1 ~ 1
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Circle circle;
    circle.init(mouseX, mouseY, 10, 10);
    circles.push_back(circle);
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
