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
//            if (m.getAddress() == "/hokuyo/x") {
//                if(m.getArgAsFloat(0) != -999) {
//                    hokuyo_x = m.getArgAsFloat(0);
//                }
//            }
            cout << m << endl;
            if (m.getAddress() == "/button/right") {
                if(m.getArgAsFloat(0) != -999) {
                    hokuyo_x = m.getArgAsInt(0);
                }
            }else if(m.getAddress() == "/button/left") {
//                if()
                hokuyo_x = -m.getArgAsInt(0);
            }
//            cout << hokuyo_x << endl;
            
        }
    return hokuyo_x;
}
