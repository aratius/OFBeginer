//
//  Paper.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/06.
//

#include "Paper.hpp"

void Paper::init(float _size) {
    
    texture.load("imgs/paper.png");
    randomColShader.load("", "shaders/randomCol.frag");
    
    size = _size;
    
    x_offset = 0;
    
    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());
    
    seed = ofRandom(2) + 1;
    
    seed_rotarion = ofVec3f(ofRandom(20) + 1);
    
    color = ofVec3f(ofRandom(1.) + 0., ofRandom(1.) + 0., ofRandom(1.) + 0.);
    
    frame = 0;
}

void Paper::update(int frame_count) {
    float frame = frame_count / 50.0;
    
    x_offset = sin(frame * seed) * 30;
    yPos += seed;
    if(yPos > ofGetHeight() + size) {
        yPos = 0 - size;
    }
    
    rotation = ofVec3f(frame * seed_rotarion.x, frame * seed_rotarion.y, frame * seed_rotarion.z);
    
}

void Paper::display(float alpha) {
    ofPushMatrix();
    ofTranslate(xPos + x_offset, yPos);
    
    ofRotateXDeg(rotation.x);
    ofRotateYDeg(rotation.y);
    ofRotateZDeg(rotation.z);
    
    randomColShader.begin();
    randomColShader.setUniform3f("u_color_val", color.x, color.y, color.z);
    randomColShader.setUniform1f("u_alpha", alpha);
    
    texture.draw(0, 0, size, size);
    
    randomColShader.end();
    
    ofPopMatrix();
}
