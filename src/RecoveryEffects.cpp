//
//  RecoveryEffects.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//

#include "RecoveryEffects.hpp"

void RecoveryEffects::init(float _duration, float _size, float _parent_size, int _num) {
    cout << "recovery init" << endl;
    
    num = 2;
    
    for(int i = 0; i < num; i ++ ) {
        RecoveryEffect effect;
        effect.init(_duration, _size, _parent_size);
        effects.push_back(effect);
    }
    
    texture.load("imgs/effects/p_recovery.png");
}

void RecoveryEffects::update() {
    for(int i = 0; i < num; i ++ ) {
        effects[i].update();
    }
}

void RecoveryEffects::display() {
    for(int i = 0; i < num; i ++ ) {
        effects[i].display();
    }
}

void RecoveryEffects::effectStart() {
    for(int i = 0; i < num; i ++ ) {
        effects[i].effectStart();
    }
}
