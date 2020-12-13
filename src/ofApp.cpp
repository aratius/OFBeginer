#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    
    for(int i = 0; i <  NUM; i++) {
        circles[i].init(i*10, 5, i/10.0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < NUM; i++) {
        circles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    
    for(int i = 0; i < NUM; i ++){
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
