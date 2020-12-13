#include "ofApp.h"

#define BALL_NUM 1000

float loc_x[BALL_NUM];
float loc_y[BALL_NUM];
float speed_x[BALL_NUM];
float speed_y[BALL_NUM];
float radius[BALL_NUM];
float red[BALL_NUM];
float green[BALL_NUM];
float blue[BALL_NUM];
bool mouse_pressed;
float gravity;
float friction;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    mouse_pressed = false;
    gravity = 0.1;
    friction = 0.999;
    
    for(int i = 0; i < BALL_NUM; i ++) {
        loc_x[i] = ofRandom(0, ofGetWidth());
        loc_y[i] = ofRandom(0, ofGetHeight());
        speed_x[i] = ofRandom(-5, 5);
        speed_y[i] = ofRandom(-5, 5);
        radius[i] = ofRandom(4, 40);
        red[i] = ofRandom(0, 255*i/BALL_NUM);
        green[i] = ofRandom(0, 255*i/BALL_NUM);
        blue[i] = ofRandom(0, 255*i/BALL_NUM);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < BALL_NUM; i ++) {
        
        //if mouse_pressed balls follows to mouse
        if(mouse_pressed) {
            speed_x[i] = (mouseX - loc_x[i]) / 8.0;
            speed_y[i] = (mouseY - loc_y[i]) / 8.0;
        }
        
        //update speed
        speed_x[i] *= friction;
        speed_y[i] *= friction;
        speed_y[i] += gravity;
        
        //update position
        loc_x[i] += speed_x[i];
        loc_y[i] += speed_y[i];
        
        if(loc_x[i] < 0) {
            speed_x[i] *= -1;
        }
        if(loc_x[i] > ofGetWidth()) {
            speed_x[i] *= -1;
        }
        if(loc_y[i] < 0) {
            speed_y[i] *= -1;
        }
        if(loc_y[i] > ofGetHeight()) {
            speed_y[i] *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < BALL_NUM; i ++) {
        ofSetColor(red[i], green[i], blue[i], 130);
        ofCircle(loc_x[i], loc_y[i], radius[i]);
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
    mouse_pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse_pressed = false;
    
    for(int i = 0; i < BALL_NUM; i ++ ){
        speed_x[i] = ofRandom(-5, 5);
        speed_y[i] = ofRandom(-5, 5);
    }
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
