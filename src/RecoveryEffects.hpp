//
//  RecoveryEffects.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/05.
//
#include "ofMain.h"

#ifndef RecoveryEffects_hpp
#define RecoveryEffects_hpp

#include "RecoveryEffect.hpp"

#include <stdio.h>

class RecoveryEffects {
  
    public:
        void init(float _duration, float _size, float _parent_size, int _num);
        void update();
        void display();
        void effectStart();
    
        int num;
        
        ofImage texture;
        vector<RecoveryEffect> effects;
};

#endif /* RecoveryEffects_hpp */
