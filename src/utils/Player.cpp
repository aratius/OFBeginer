//
//  Player.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Player.hpp"

void GamePlayer::init(float _x, float _y, float _size) {
    
    xPos = _x;
    yPos = _y;
    size = _size;
    
}

void GamePlayer::update() {
//    cout << ofGetMouseX() << endl;
}

void GamePlayer::display() {
    ofDrawCircle(xPos, yPos, size);
}
