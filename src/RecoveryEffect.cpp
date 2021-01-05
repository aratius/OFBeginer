//
//  RecoveryEffect.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//

#include "RecoveryEffect.hpp"

void RecoveryEffect::init(float _duration, float _parent_size) {
    
    duration = _duration;
    parent_size = _parent_size;
    xPos = (ofRandom(1.0)-0.5) * parent_size;
    yPos = parent_size/2;  //地面の位置
    speed = ofRandom(3)+0.1;
    size_offset = -ofRandom(10);
    
    texture.load("imgs/effects/p_recovery.png");
    
}

void RecoveryEffect::update(float _size) {
    
    yPos -= speed;
    size = _size + size_offset;
    if(size < 0) size = 0;
}

void RecoveryEffect::display() {
    texture.draw(ofVec2f(-size/2+xPos, -size/2+yPos), size, size);
}

void RecoveryEffect::effectStart() {
    yPos = parent_size/2 + 40;  //ポジション初期化
}
