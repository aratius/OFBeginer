//
//  Ground.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//
#include "ofMain.h"

#ifndef Player.hpp
#define Player.hpp

#include <stdio.h>

class GamePlayer {
    
public:
    
    void init(float _x, float _y, float _size);
    void update(float mX, float g_r, float g_y);
    void display();
    
    float xPos, yPos, size, color_value;
    
private:
    
};

#endif /* Ground_hpp */
