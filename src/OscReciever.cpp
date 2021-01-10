//
//  OscReciever.cpp
//  OFBeginer-main
//
//  Created by 松本新 on 2021/01/10.
//

#include "OscReciever.hpp"

void OscReciever::init() {
    receiver.setup(PORT);
    cout << "/osc" << endl;
}

ofVec3f OscReciever::update() {
    ofVec3f buttonState = ofVec3f(-999, -999, -999);
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if (m.getAddress() == "/button/right") {
            buttonState.x = m.getArgAsFloat(0);
        }
        if(m.getAddress() == "/button/left") {
            buttonState.y = m.getArgAsFloat(0);
        }
        if(m.getAddress() == "/button/jump") {
            buttonState.z = m.getArgAsFloat(0);
        }
    }
    cout << "/" << buttonState.x << endl;
    return buttonState;
}
