//
//  RecoveryEffects.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//
#include "ofMain.h"
#include "ofxTween.h"

#ifndef RecoveryEffects_hpp
#define RecoveryEffects_hpp

#include "RecoveryEffect.hpp"

#include <stdio.h>

class RecoveryEffects {
  
    public:
        void init(float _duration, float _size, float _parent_size, int _num);
        void update();
        void display();
        void effectStart();
        void tweenEnd(int &e);
        void deleteParticle();
    
        int num;
        float size, max_size, duration, parent_size;
        
        vector<RecoveryEffect> effects;
    
        ofxTween sizeTween;
    
        //イージングを余分にいっぱい羅列している
        ofxEasingBounce ease_bounce;
        ofxEasingExpo ease_expo;
        ofxEasingQuad ease_quad;
        ofxEasingCirc ease_circ;
        ofxEasingElastic ease_elastic;
        ofxEasingBack ease_back;
};

#endif /* RecoveryEffects_hpp */
