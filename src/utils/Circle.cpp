//
//  Circle.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/13.
//

#include "Circle.hpp"

#define amplitude 30
#define frame_devide 1

void Circle::init (float _x, float _y, int _eSize, float _speed, float frame, string filename, string _role) {
    
    xPos = _x;
    yPos = _y;
    eSize = _eSize;
    speed = _speed;
    start_frame = frame;
    offsetX = 0;
    angleValue = (ofRandom(1)-0.5) * speed;
    angle = ofRandom(1) * 360;
    role = _role;
    
    seed[0] = ofRandom(2) + 1;
    seed[1] = ofRandom(2) + 2;
    
    textImage.load(filename);
}

void Circle::update() {
    float frame = ofGetElapsedTimef();
    
    offsetX = (sin(frame * seed[0] * frame_devide) - sin(frame * seed[1] * frame_devide)) * amplitude;
    
    yPos += speed;
    if(yPos > ofGetWidth()) {
        yPos = 0;
    }
    
    angle += angleValue;
}

void Circle::display() {
    //player start
    //translate Matrix
    ofPushMatrix();
    ofTranslate(xPos + offsetX, yPos);
    ofRotateZDeg(angle);
    
    ofSetColor(0, 0, 0);
//    ofDrawCircle(0, 0, eSize);
    textImage.draw(-eSize/2, -eSize/2, eSize, eSize);
    
    
//    reset Matrix
    ofPopMatrix();
//    player end
}
