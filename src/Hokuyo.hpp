//
//  Hokuyo.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/19.
//

#include "ofMain.h"
#include "ofxOsc.h"

#ifndef Hokuyo_hpp
#define Hokuyo_hpp

#include <stdio.h>

#define PORT 8000

class HokuyoOsc {
    
public:
    void init();
    float update();
    
    //OSCメッセージを受信するインスタンス
    ofxOscReceiver receiver;
    float hokuyo_x = 0;
    int frame;
    
};

#endif /* Hokuyo_hpp */
