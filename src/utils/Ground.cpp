//
//  Ground.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Ground.hpp"

void Ground::init(float _radius, float _y) {
 
    radius = _radius;
    yPos = _y;
    
}

void Ground::display () {
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWidth()/2, yPos, radius);
}
