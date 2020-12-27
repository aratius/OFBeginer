//
//  Player.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Player.hpp"

#define degree 15

void GamePlayer::init(float _x, float _y, float _size) {
    
    xPos = _x;
    yPos = _y;
    size = _size;
    color_value = 0;
    
    playerImage.load("player.png");
}

void GamePlayer::update(float mX,  float g_r, float g_y, float hokuyo_x) {
    if(hokuyo_x > -360 && hokuyo_x < 360) {
        last_active_pos = hokuyo_x;
    }else {
        //期待した値が来なかったら前回の有効値使う
        hokuyo_x = last_active_pos;
    }
    hokuyo_x /= 50;
//    cout << hokuyo_x << endl;
    float angle = hokuyo_x * PI / degree;  //case hokuyo
//    float angle = mX * PI / degree;  //case mouse
    float x = sin(angle) * g_r + ofGetWidth()/2;
    float y = -(cos(angle) * g_r + size) + g_y;
    cout << y << endl;
    xPos = x;
    yPos = y;
}

void GamePlayer::display() {
    ofSetColor(0,0,0);
    
    ofDrawCircle(xPos, yPos, size);
    
}
