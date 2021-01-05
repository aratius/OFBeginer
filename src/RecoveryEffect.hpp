//
//  RecoveryEffect.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//
#include "ofMain.h"

#ifndef RecoveryEffect_hpp
#define RecoveryEffect_hpp


#include <stdio.h>

class RecoveryEffect {
  
    public:
        void init(float _duration, float _size, float _parent_size);
        void update();
        void display();
        void effectStart();
    
        float duration;
        float size, max_size, parent_size, xPos, yPos;
        int num;
        
        ofImage texture;
};

#endif /* RecoveryEffect_hpp */

