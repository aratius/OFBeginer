//
//  InjuryEffects.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//

#include "InjuryEffects.hpp"

void InjuryEffects::init(float _size) {
    cout << "injury init" << endl;
    
    inside_size = 0;
    inside_max_size = _size;
    xPos = -999;
    yPos = -999;
    
    inside_texture.load("imgs/effects/injury.png");
    outside_texture.load("imgs/effects/injury.png");
    
    ofAddListener(insideEffect.end_E, this, &InjuryEffects::tweenEnd);
    ofAddListener(outsideEffect.end_E, this, &InjuryEffects::tweenEnd);
    ofAddListener(tweenAlpha.end_E, this, &InjuryEffects::tweenEnd);
}

void InjuryEffects::update() {
    insideEffect.update();
    inside_size = insideEffect.getTarget(0);
    outsideEffect.update();
    outside_size = outsideEffect.getTarget(0);
    
    tweenAlpha.update();
    texture_alpha = tweenAlpha.getTarget(0);
}

void InjuryEffects::display() {
    ofSetColor(0, 0, 0, texture_alpha);
    inside_texture.draw(position.x - inside_size/2, position.y - inside_size/2, inside_size, inside_size);
    outside_texture.draw(position.x - outside_size/2, position.y - outside_size/2, outside_size, outside_size);
}

void InjuryEffects::effectStart(ofVec2f pos) {
    cout << pos.x << endl;
    position = pos;
    insideEffect.setParameters(1, ease_elastic, ofxTween::easeOut, inside_max_size * 0.2, inside_max_size * 0.6, 700, 50);
    outsideEffect.setParameters(2, ease_elastic, ofxTween::easeOut, inside_max_size * 0.6, inside_max_size * 1.2, 700, 0);
    tweenAlpha.setParameters(3, ease_circ, ofxTween::easeOut, 0, 255, 400, 0);
}

void InjuryEffects::tweenEnd(int &e) {
    cout << e << endl;
    if(e == 3 ) {
        tweenAlpha.setParameters(4, ease_circ, ofxTween::easeIn, 255, 0, 200, 0);
    }
}
