//
//  Player.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Player.hpp"

#define degree 20

void GamePlayer::init(float _x, float _y, float _size) {
    
    xPos = _x;
    yPos = _y;
    size = _size;
    color_value = 0;
}

void GamePlayer::update(float mX,  float g_r, float g_y, float hokuyo_x) {
    float angle = mX * PI / degree;  //case hokuyo
//    float angle = mX * PI / degree;  //case mouse
    float x = sin(angle) * g_r + ofGetWidth()/2;
    float y = -(cos(angle) * g_r + size) + g_y;
    xPos = x;
    yPos = y;
}

void GamePlayer::display() {
    ofSetColor(color_value, 0, 0);
    ofDrawCircle(xPos, yPos, size);
}
