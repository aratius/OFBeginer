//
//  Circle.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/13.

#include "ofMain.h"

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

class Circle {
    
public:
    
    void init(float _x, float _y, int _eSize, float _speed, float frame);
    void update(int now_frame);
    void display();
    
    float xPos, yPos, eSize, speed, start_frame, offsetX;
    float seed[2];
    
private:
    
};

#endif /* Circle_hpp */
