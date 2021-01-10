//
//  OscReciever.hpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/10.
//
#include "ofMain.h"
#include "ofxOsc.h"

#ifndef OscReciever_hpp
#define OscReciever_hpp

#include <stdio.h>

#define PORT 8000

class OscReciever {
public:
    void init();
    ofVec3f update();
    
    //OSCメッセージを受信するインスタンス
    ofxOscReceiver receiver;
    
    float osc_right;
    float osc_left;
};

#endif /* OscReciever_hpp */
