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
    
    void init(float _x, float _y, int _eSize, float _speed, float frame, string filename, string _role);
    void update();
    void display();
    
    float xPos, yPos, eSize, speed, start_frame, offsetX, angleValue, angle;
    float seed[2];
    string role;  //悪役かどうか
    
    ofImage textImage;
    ofShader goldShader;
    
private:
    
};

#endif /* Circle_hpp */
