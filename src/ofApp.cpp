#include "ofApp.h"

#define BALL_NUM 1000

float loc_x;
float loc_y;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    
    loc_x = 0;
    loc_y = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    loc_x += 3;
    loc_y += 2;
    
    if(loc_x < 0) {
        loc_x = ofGetWidth();
    }
    if(loc_x > ofGetWidth()) {
        loc_x = 0;
    }
    if(loc_y < 0) {
        loc_y = ofGetHeight();
    }
    if(loc_y > ofGetHeight()) {
        loc_y = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(31, 63, 255);
    ofCircle(loc_x, loc_y, 40);
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
