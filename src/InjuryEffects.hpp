//
//  InjuryEffects.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//
#include "ofMain.h"
#include "ofxTween.h"

#ifndef InjuryEffects_hpp
#define InjuryEffects_hpp

#include <stdio.h>

class InjuryEffects {
public:
    void init(float _size);
    void update();
    void display();
    void effectStart(ofVec2f pos);
    void tweenEnd(int &e);
    
    float inside_size, inside_max_size, outside_size, outside_max_size, texture_alpha;
    float xPos = 0;
    float yPos = 0;
    ofVec2f position;
    
    ofImage inside_texture;
    ofImage outside_texture;
    
    ofxTween insideEffect;
    ofxTween outsideEffect;
    ofxTween tweenAlpha;
    
    //イージングを余分にいっぱい羅列している
    ofxEasingBounce ease_bounce;
    ofxEasingExpo ease_expo;
    ofxEasingQuad ease_quad;
    ofxEasingCirc ease_circ;
    ofxEasingElastic ease_elastic;
    ofxEasingBack ease_back;
};

#endif /* InjuryEffects_hpp */
