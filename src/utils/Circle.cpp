//
//  Circle.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/13.
//

#include "Circle.hpp"

void Circle::init (float _x, float _y, int _eSize, float _speed) {
    
    xPos = _x;
    yPos = _y;
    eSize = _eSize;
    speed = _speed;
    
}

void Circle::update() {
    
    yPos += speed;
    if(yPos > ofGetWidth()) {
        yPos = 0;
    }
}

void Circle::display() {
    ofDrawCircle(xPos, yPos, eSize);
}
