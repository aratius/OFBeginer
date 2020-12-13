#include "ofApp.h"

#define BALL_NUM 1000

float x[BALL_NUM];
float y[BALL_NUM];
float radius[BALL_NUM];

//--------------------------------------------------------------
void ofApp::setup(){
    int i;
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    ofSetCircleResolution(64);
    
    for(i = 0; i < BALL_NUM; i++) {
        x[i] = ofRandom(0, ofGetWidth());
        y[i] = ofRandom(0, ofGetHeight());
        radius[i] = ofRandom(10, 40);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int i;
    ofSetColor(31, 63, 255, 63);
    
    for(i = 0; i < BALL_NUM; i++) {
        ofCircle(x[i], y[i], radius[i]);
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
