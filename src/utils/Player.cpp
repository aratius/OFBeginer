//
//  Player.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//

#include "Player.hpp"

#define degree 15

void GamePlayer::init(float _x, float _y, float _size) {
    
    xPos = _x;
    yPos = _y;
    size = _size;
    color_value = 0;
    imgangle = 0;
    
    playerImage.load("imgs/chara.png");
    playerShader.load("","shaders/player.frag");
    
    foot.init(0, size/2, footSize, size);
}

void GamePlayer::update(float mX,  float g_r, float g_y, float hokuyo_x) {
    if(hokuyo_x > -360 && hokuyo_x < 360) {
        last_active_pos = hokuyo_x;
    }else {
        //期待した値が来なかったら前回の有効値使う
        hokuyo_x = last_active_pos;
    }
    //だいたい-1~1の値に調整（ここは手動で）
    hokuyo_x /= 50;
    
//    float angle = hokuyo_x * PI / degree;  //case hokuyo
    float angle = mX * PI / degree;  //case mouse
    
    float x = sin(angle) * g_r;
    float y = -(cos(angle) * g_r);
    //中心移動+anchor分
    float xForImg = x + ofGetWidth()/2 - size/2;
    //中心移動
    float yForImg = y + g_y - size - footSize;
    
    xPos = xForImg;
    yPos = yForImg;
    
    imgangle = atan2(y, x) / PI * 180 + 90;
    
    foot.update();
}

void GamePlayer::display() {
//    ofSetColor(0,0,0);
//    ofDrawCircle(xPos, yPos, size);
    
    //player start
    //translate Matrix
    ofPushMatrix();
    ofTranslate(xPos+size/2, yPos+size/2);
    ofRotateZDeg(imgangle);
    
    //shader start
    playerShader.begin();
    playerImage.draw(-size/2, -size/2, size, size);  //image
    playerShader.end();
    //shader end
    
    //eye
//    ofSetColor(255, 255, 255);
//    ofDrawCircle(-size/10, -size*15/100, 5);
//    ofDrawCircle(size/10, -size*15/100, 5);
    
    //foot
    foot.display();
    
//    reset Matrix
    ofPopMatrix();
    //player end
    
}
