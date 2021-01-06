//
//  Buildings.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/06.
//
#include "ofMain.h"

#ifndef Buildings_hpp
#define Buildings_hpp

#include <stdio.h>

class Buildings {
public:
    void init(float _size, float _yPos);
    void update();
    void display();
    
    float size;
    float yPos;
    
    ofImage bg_1;
    float bg_1_alpha;
    float bg_1_speed_devide;
    
    ofImage bg_2;
    float bg_2_alpha;
    float bg_2_speed_devide;
    
    ofImage bg_3;
    float bg_3_alpha;
    float bg_3_speed_devide;
    
    ofShader transparentShader;
    
};

#endif /* Buildings_hpp */
