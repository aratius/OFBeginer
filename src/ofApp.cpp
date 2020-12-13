#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    
    c1.init(100, 10, 1.0);
    c2.init(300, 40, 3.5);
}

//--------------------------------------------------------------
void ofApp::update(){
    c1.update();
    c2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    
    c1.display();
    c2.display();
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
