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
    void update(float mX, float g_r, float g_y, float hokuyo_x);
    void display();
    
    float xPos, yPos, size, color_value, last_active_pos;
    
    ofShader playerShader;
    ofImage playerImage;
    
private:
    
};

#endif /* Ground_hpp */
