//
//  PlayerFoot.hpp
//  beginner
//
//  Created by 松本新 on 2021/01/02.
//

#include "ofMain.h"

#ifndef PlayerFoot_hpp
#define PlayerFoot_hpp

#include <stdio.h>

class PlayerFoot {
    
public:
    
    void init(float _x, float _y, float _size, float _parentSize);
    void update();
    void display();
    
    float angle, xPos, yPos, yOffset, parentSize, size;
    
private:
    
};

#endif /* Ground_hpp */
