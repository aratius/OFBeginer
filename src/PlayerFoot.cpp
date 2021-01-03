//
//  PlayerFoot.cpp
//  beginner
//
//  Created by 松本新 on 2021/01/02.
//

#include "PlayerFoot.hpp"

void PlayerFoot::init(float _x, float _y, float _size, float _parentSize) {
    cout<<"playerfoot"<<endl;
    
    xPos = _x;
    yPos = _y;
    size = _size;
    parentSize = _parentSize;
}

void PlayerFoot::update(){
    float time = ofGetElapsedTimeMillis()/100.0;
     
    yOffset = sin(time) * size/2;
}

void PlayerFoot::display() {
    ofSetColor(0, 0, 0);
    ofDrawCircle(xPos - parentSize/5, yPos + yOffset, size/2);
    ofDrawCircle(xPos + parentSize/5, yPos - yOffset, size/2);
}
