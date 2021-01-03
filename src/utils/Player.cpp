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
    noiseTexture.load("imgs/noise.png");
    playerShader.load("","shaders/player.frag");
    
    foot.init(0, size/2, footSize, size);
}

void GamePlayer::update(float mX,  float g_r, float g_y, float hokuyo_x, string role) {
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
    
    //circleが衝突してダメージを受けている状態
    if(role != "") {
        if(role == "good") {
            u_noiseAmount = 0.;
            color_value -= 0.1;
        }else if(role=="bad") {
            u_noiseAmount = 2.;
            color_value += 0.1;
        }
    }
    u_noiseAmount *= 0.99;
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
