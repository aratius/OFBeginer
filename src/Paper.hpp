//
//  Paper.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/06.
//
#include "ofMain.h"

#ifndef Paper_hpp
#define Paper_hpp

#include <stdio.h>

class Paper {
public:
    void init(float _size);
    void update();
    void display(float alpha);
    
    float xPos, yPos, size, x_offset, seed, frame;
    
    float e = 0.995;
    ofVec2f v_zero;
    ofVec2f pos;
    ofVec2f pos_offset;
    
    ofVec3f seed_rotarion;
    ofVec3f rotation;
    
    ofVec3f color;
    
    ofImage texture;
    ofShader randomColShader;
};

#endif /* Paper_hpp */
