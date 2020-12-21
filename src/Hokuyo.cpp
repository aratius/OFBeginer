//
//  Hokuyo.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/19.
//

#include "Hokuyo.hpp"

void HokuyoOsc::setup() {
    cout << "hokuyo setup" << endl;
    
    receiver.setup(PORT);
    frame = 0;
}

float HokuyoOsc::update() {
    //現在順番待ちのメッセージがある間は受信を続ける
//    if((frame % 60 == 0) == 1) {
        while (receiver.hasWaitingMessages()) {
            ofxOscMessage m;
            receiver.getNextMessage(m);
            if (m.getAddress() == "/hokuyo/x") {
                hokuyo_x = m.getArgAsFloat(0);
                cout<< hokuyo_x << endl;
            }
            
            return hokuyo_x;
        }
//    }
    frame ++;
}
