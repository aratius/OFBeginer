//
//  Ground.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//
#include "ofMain.h"

#ifndef Ground_hpp
#define Ground_hpp

#include <stdio.h>

class Ground {
    
public:
    
    void init(float _radius, float _y);
    void display();
    
    float radius, yPos;
    
private:
    
};

#endif /* Ground_hpp */
