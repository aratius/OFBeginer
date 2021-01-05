//
//  RecoveryEffect.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//

#include "RecoveryEffect.hpp"

void RecoveryEffect::init(float _duration, float _size, float _parent_size) {
    cout << "recovery init" << endl;
    
    duration = _duration;
    size = 10;
    max_size = _size;
    parent_size = _parent_size;
    xPos = (ofRandom(1.)-0.5) * parent_size;
    yPos = parent_size/2;  //地面の位置
    
    texture.load("imgs/effects/p_recovery.png");
    
//    ofAddListener(tweenRecover_size.end_E, this, &RecoveryEffect::tweenEnd);
//    ofAddListener(tweenRecover_yPos.end_E, this, &RecoveryEffect::tweenEnd);
}

void RecoveryEffect::update() {
//    tweenRecover_size.update();
//    size = tweenRecover_size.getTarget(0);
//
//    tweenRecover_yPos.update();
//    yPos = tweenRecover_yPos.getTarget(0);
    
    yPos -= 4;
}

void RecoveryEffect::display() {
    texture.draw(ofVec2f(-size/2+xPos, -size/2+yPos), size, size);
}

void RecoveryEffect::effectStart() {
//    tweenRecover_size.setParameters(1, ease_circ, ofxTween::easeOut, 0, max_size, duration, 0);
//    tweenRecover_yPos.setParameters(1, ease_circ, ofxTween::easeOut, parent_size, -parent_size, duration*2, 0);
    yPos = parent_size/2;  //ポジション初期化
}

//void RecoveryEffect::tweenEnd(int &e){
//    cout<< "tween end" << endl;
//    if(e == 1) {
////        tweenRecover_size.setParameters(2, ease_circ, ofxTween::easeIn, max_size, 0, duration, 0);
//    }
//}
