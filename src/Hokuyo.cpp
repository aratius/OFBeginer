//
//  Hokuyo.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/19.
//

#include "Hokuyo.hpp"

void HokuyoOsc::init() {
    
    receiver.setup(PORT);
    frame = 0;
}

float HokuyoOsc::update() {
    hokuyo_x = -999;
    //現在順番待ちのメッセージがある間は受信を続ける
        while (receiver.hasWaitingMessages()) {
            ofxOscMessage m;
            receiver.getNextMessage(m);
            if (m.getAddress() == "/hokuyo/x") {
                if(m.getArgAsFloat(0) != -999) {
                    hokuyo_x = m.getArgAsFloat(0);
                }
            }
            
        }
    
    return hokuyo_x;
    frame ++;
}
