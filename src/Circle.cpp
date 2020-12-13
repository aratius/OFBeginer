//
//  Circle.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/13.
//

#include "Circle.hpp"

void Circle::init (float _y, int _eSize, float _speed) {
    
    xPos = 0.0;
    yPos = _y;
    eSize = _eSize;
    speed = _speed;
    
}

void Circle::update() {
    
    xPos += speed;
    if(xPos > ofGetWidth()) {
        xPos = 0;
    }
}

void Circle::display() {
    ofDrawCircle(xPos, yPos, eSize);
}
