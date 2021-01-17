//
//  Ground.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//
#include "ofMain.h"

#ifndef Ground_hpp
#define Ground_hpp

#include "ofxTween.h"

#include "Paper.hpp"

#include <stdio.h>

class Ground {
    
public:
    
    void init(float _radius, float _y);
    void display();
    void update(int frame_count);
    void startAnimation(string state);
    void tweenEnd(int &e);
    
    float radius, yPos;
    float y_offset = 0;
    float logo_alpha = 0;
    float logo_size_amount = 0;
    bool paper_display = false;
    
    ofImage logo;
    
    vector<Paper> papers;
    
    ofxTween tweenGround;
    ofxTween tweenlogoAlpha;
    ofxTween tweenlogoSize;

    //イージングを余分にいっぱい羅列している
    ofxEasingBounce ease_bounce;
    ofxEasingExpo ease_expo;
    ofxEasingQuad ease_quad;
    ofxEasingCirc ease_circ;
    ofxEasingElastic ease_elastic;
    ofxEasingBack ease_back;
    
private:
    
};

#endif /* Ground_hpp */
