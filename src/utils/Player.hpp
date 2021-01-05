//
//  Ground.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//
#include "ofMain.h"

#ifndef Player.hpp
#define Player.hpp

#include "PlayerFoot.hpp"

#include <stdio.h>

#include "ofxTween.h"

class GamePlayer {
    
public:
    
    void init(float _x, float _y, float _size);
    void update(float mX, float g_r, float g_y, float hokuyo_x, string role, float mousesSpeed);
    void display();
    void recovery();
    void injury();
    void tweenManage();
    void dead();
    void tweenEnd(int &e);
    void revival();  //復活
    
    
    float xPos, yPos, size, red_value, last_active_pos, imgangle;
    float footSize = 20;
    float u_noiseAmount = 0.;
    float bounceOffset = 0;
    float imgangleOffset = 0;
    float mouseOffset = 0;
    float angleAmount = 1;
    bool life = true;  //生きてるか死んでるか
    bool angleFrag = true;  //trueの時はtweenの値を参照しない
    
    ofShader playerShader;
    ofImage playerImage;
    ofImage noiseTexture;
    
    PlayerFoot foot;
    
    ofxTween tweenUpDown;
    ofxTween tweenRotation;
    ofxTween tweenAngleAmount;
    
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
