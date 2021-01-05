//
//  Player.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Player.hpp"

#define degree 10

void GamePlayer::init(float _x, float _y, float _size) {
    
    xPos = _x;
    yPos = _y;
    size = _size;
    color_value = 0;
    imgangle = 0;
    
    playerImage.load("imgs/chara.png");
    noiseTexture.load("imgs/noise.png");
    playerShader.load("","shaders/player.frag");
    
    foot.init(0, size/2, footSize, size);
    
    ofAddListener(tweenUpDown.end_E, this, &GamePlayer::tweenEnd);
    ofAddListener(tweenAngleAmount.end_E, this, &GamePlayer::tweenEnd);
}

void GamePlayer::update(float mX,  float g_r, float g_y, float hokuyo_x, string role, float mouseSpeed) {
    if(hokuyo_x > -360 && hokuyo_x < 360) {
        last_active_pos = hokuyo_x;
    }else {
        //期待した値が来なかったら前回の有効値使う
        hokuyo_x = last_active_pos;
    }
    //だいたい-1~1の値に調整（ここは手動で）
    hokuyo_x /= 50;
    
//    float angle = hokuyo_x * PI / degree;  //case hokuyo
    float angle = mX * PI / degree * angleAmount;  //case mouse
    float dist = g_r + bounceOffset;
    
    float x = sin(angle) * dist;
    float y = -(cos(angle) * dist);
    //中心移動+anchor分
    float xForImg = x + ofGetWidth()/2 - size/2;
    //中心移動
    float yForImg = y + g_y - size - footSize;
    
    xPos = xForImg;
    yPos = yForImg;
    
    imgangle = atan2(y, x) / PI * 180 + 90;
    foot.update();
    
    //circleが衝突してダメージを受けている状態あと生きてる時限定
    if(role != "" && life) {
        if(role == "good") {
            recovery();
        }else if(role=="bad") {
            injury();
        }
    }
    u_noiseAmount *= 0.99;
    
    //これでtweenの時間が進行する
    tweenUpDown.update();
    bounceOffset = tweenUpDown.getTarget(0);
    tweenRotation.update();
    imgangleOffset = tweenRotation.getTarget(0);
    tweenAngleAmount.update();
    if(!angleFrag) {
        angleAmount = tweenAngleAmount.getTarget(0);
    }
    
    //勢いつけて移動した時に前傾姿勢になる
    mouseOffset *= 0.95;
    mouseOffset += mouseSpeed * 30;
    
//    cout<<angleAmount<<endl;
}

void GamePlayer::recovery(){
    //回復
    u_noiseAmount = 0.;
    if(color_value > 0) color_value -= 0.2;
    
    float duration = 2000;
    tweenRotation.setParameters(10, ease_elastic, ofxTween::easeOut, 0, 720, duration, 0);
}

void GamePlayer::injury() {
    //ダメージ
    u_noiseAmount = 2.;
    color_value += 0.1;
    
    float duration = 300;
    //setParametersを呼ぶことでTween開始
    tweenUpDown.setParameters(1, ease_circ, ofxTween::easeOut, 0, 50, duration, 0);
    
    if(color_value >= 1.) {
        dead();
        life = false;
    }
}

void GamePlayer::display() {
//    ofSetColor(0,0,0);
//    ofDrawCircle(xPos, yPos, size);
    
    //player start
    //translate Matrix
    ofPushMatrix();
    ofTranslate(xPos+size/2, yPos+size/2);
    ofRotateZDeg(imgangle + imgangleOffset + mouseOffset);
    
    //shader start
    playerShader.begin();
    playerImage.draw(-size/2, -size/2, size, size);  //image
    playerShader.setUniformTexture("tex1", noiseTexture, 1);  //テクスチャとして渡す
    playerShader.setUniform1f("u_noiseAmount", u_noiseAmount);
    playerShader.setUniform1f("u_color_value", color_value);
    
    //eye
//    ofSetColor(255, 255, 255);
//    ofDrawCircle(-size/10, -size*15/100, 5);
//    ofDrawCircle(size/10, -size*15/100, 5);
    
    //foot
    foot.display();
    
    playerShader.end();
    //shader end
    
//    reset Matrix
    ofPopMatrix();
    //player end
    
}

void GamePlayer::dead() {
    float duration = 600;
    //setParametersを呼ぶことでTween開始
    tweenUpDown.setParameters(2, ease_circ, ofxTween::easeOut, 0, 100, duration, 0);
    tweenRotation.setParameters(3, ease_elastic, ofxTween::easeOut, 0,  720, 1000, 0);
    
}

void GamePlayer::tweenEnd(int &e) {
    cout<<"callback"<<endl;
    if(e == 4) {
        revival();
    }else if(e == 10) {
        tweenUpDown.setParameters(5, ease_bounce, ofxTween::easeOut, ofGetHeight()*0.4, 0, 500, 0);
        angleFrag = false;
        tweenAngleAmount.setParameters(9, ease_circ, ofxTween::easeOut, 0, 1, 2000, 500);
    }else if(e == 1) {
        tweenUpDown.setParameters(3, ease_bounce, ofxTween::easeOut, 50, 0, 500, 0);
    }else if(e == 2) {
        tweenUpDown.setParameters(4, ease_bounce, ofxTween::easeOut, 100, -200, 500, 0);
    }else if(e == 9) {
        life = true;
    }
}

//色々な復活処理
void GamePlayer::revival() {
    cout<<"revival"<<endl;
    color_value = 0.;
    angleAmount = 0;
    angleFrag = true;
    tweenUpDown.setParameters(10, ease_circ, ofxTween::easeOut, -200, ofGetHeight()*0.4, 5000, 4000);
}
