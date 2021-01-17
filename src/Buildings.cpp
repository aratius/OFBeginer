//
//  Buildings.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/06.
//

#include "Buildings.hpp"

void Buildings::init(float _size, float _yPos) {
    
    size = _size*3.6;
    yPos = _yPos;
    
    //真ん中
    bg_1.load("imgs/bg/bg_1.png");
    bg_1_alpha = 0.75;
    bg_1_speed_devide = 0.6;
    
    //奥
    bg_2.load("imgs/bg/bg_2.png");
    transparentShader.load("", "shaders/transparent.frag");
    bg_2_alpha = 0.9;
    bg_2_speed_devide = 0.4;
    
    //手前
    bg_3.load("imgs/bg/bg_3.png");
    transparentShader.load("", "shaders/transparent.frag");
    bg_3_alpha = 0.6;
    bg_3_speed_devide = 0.8;
    
}

void Buildings::update() {
}

void Buildings::display(int frame_count) {
    float frame = frame_count/50.0;
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, yPos);
    
    //奥
    ofSetColor(255, 255, 255);
    ofRotateZDeg(frame * bg_2_speed_devide);

    transparentShader.begin();
    transparentShader.setUniform1f("u_alpha", bg_2_alpha);
    bg_2.draw(- size/2, - size/2, size, size);
    transparentShader.end();

    //真ん中
    ofSetColor(255, 255, 255);
    ofRotateZDeg(frame * bg_1_speed_devide);

    transparentShader.begin();
    transparentShader.setUniform1f("u_alpha", bg_1_alpha);
    bg_1.draw(- size/2, - size/2, size, size);
    transparentShader.end();
    
    //手前
    ofSetColor(255, 255, 255);
    ofRotateZDeg(frame * bg_3_speed_devide);
    
    transparentShader.begin();
    transparentShader.setUniform1f("u_alpha", bg_3_alpha);
    bg_3.draw(- size/2, - size/2, size, size);
    transparentShader.end();
    
    ofPopMatrix();
}
