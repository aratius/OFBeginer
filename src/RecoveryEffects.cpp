//
//  RecoveryEffects.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//

#include "RecoveryEffects.hpp"

void RecoveryEffects::init(float _duration, float _size, float _parent_size, int _num) {
    
    num = _num;
    size = 0;
    max_size = _size;
    duration = _duration;
    parent_size = _parent_size;
    
    ofAddListener(sizeTween.end_E, this, &RecoveryEffects::tweenEnd);
}

void RecoveryEffects::update() {
    sizeTween.update();
    size = sizeTween.getTarget(0);
    
    for(int i = 0; i < effects.size(); i ++ ) {
        effects[i].update(size);
    }
}

void RecoveryEffects::display() {
    for(int i = 0; i < effects.size(); i ++ ) {
        effects[i].display();
    }
}

void RecoveryEffects::effectStart() {
    for(int i = 0; i < num; i ++ ) {
        RecoveryEffect effect;
        effect.init(duration, parent_size);
        effects.push_back(effect);
    }
    
    //インスタンス内でtween生成したらバグったのでこっちで一つの値を使うことにした
    sizeTween.setParameters(1, ease_circ, ofxTween::easeOut, 0, max_size, duration, 0);
    
    for(int i = 0; i < effects.size(); i ++ ) {
        effects[i].effectStart();
    }
}

void RecoveryEffects::tweenEnd(int &e) {
    if(e == 1) {
        sizeTween.setParameters(2, ease_circ, ofxTween::easeIn, max_size, 0, duration, 0);
    }else if(e == 2) {
        deleteParticle();  //配列削除
    }
}

void RecoveryEffects::deleteParticle(){
        effects.clear();
}
