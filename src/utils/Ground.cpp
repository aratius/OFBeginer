//
//  Ground.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Ground.hpp"

void Ground::init(float _radius, float _y) {
 
    radius = _radius;
    yPos = _y;
    
    ofAddListener(tweenGround.end_E, this, &Ground::tweenEnd);
    ofAddListener(tweenlogoAlpha.end_E, this, &Ground::tweenEnd);
    ofAddListener(tweenlogoSize.end_E, this, &Ground::tweenEnd);
    
    
}

void Ground::update() {
    tweenGround.update();
    
    y_offset = tweenGround.getTarget(0);
    
    tweenlogoAlpha.update();
    logo_alpha = tweenlogoAlpha.getTarget(0);
    
    tweenlogoSize.update();
    logo_size_amount = tweenlogoSize.getTarget(0);
    
    for (int i = 0; i < papers.size(); i++) {
        papers[i].update();
    }
    
    
}

void Ground::startAnimation (string state) {
    //2種類のロゴからランダムに選択
    int random = ofRandom(1, 3);
    string filename = "imgs/logo" + to_string(random) + ".png";
    logo.load(filename);
    
    tweenGround.setParameters(1, ease_circ, ofxTween::easeOut, 0, -radius, 3000, 2000);
    tweenlogoAlpha.setParameters(3, ease_circ, ofxTween::easeOut, 0, 255, 1000, 3000);
    
    logo_size_amount = -100;
    tweenlogoSize.setParameters(5, ease_elastic, ofxTween::easeOut, -100, 100, 1000, 3000);
    
    if(state == "clear") {
        for (int i = 0; i < 100; i ++ ) {
            Paper paper;
            paper.init(20);
            papers.push_back(paper);
        }
    }
}

void Ground::display () {
    
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWidth()/2, yPos + y_offset, radius);  //Ground (big)
    
    ofSetColor(255, 255, 255, logo_alpha);
    float w = ofGetWidth() * 0.8 + logo_size_amount;
    float h = w * 0.7 + logo_size_amount;
    logo.draw(ofGetWidth()/2 - w/2, ofGetHeight()/2 - h/2, w, h);
    
    for (int i = 0; i < papers.size(); i++) {
        papers[i].display(logo_alpha);
    }
}

void Ground::tweenEnd(int &e) {
    if(e == 1) {
        //戻る
        tweenGround.setParameters(2, ease_circ, ofxTween::easeOut, -radius, 0, 3000, 3500);
    }else if (e == 2) {
        y_offset = 0;
        papers.clear();
    }else if (e == 3) {
        tweenlogoAlpha.setParameters(4, ease_circ, ofxTween::easeIn, 255, 0, 1000, 3300);
    }
}
