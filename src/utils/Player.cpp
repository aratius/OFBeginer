//
//  Player.cpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//
// Tween番号の割り振り法則
// 0 : コールバックなし
// 30番台 : クリア時の演出
// 40番台 : ゲームオーバー時の演出
// 90番台 : 復活演出3,4共通
// 50番台 : ダメージ演出
// 60番台 : 回復演出

#include "Player.hpp"

#define degree 10

void GamePlayer::init(float _x, float _y, float _size) {
    
    xPos = _x;
    yPos = _y;
    size = _size;
    
    playerImage.load("imgs/chara.png");
    noiseTexture.load("imgs/noise.png");
    playerShader.load("","shaders/player.frag");
    
    //foot
    foot.init(0, size/2, footSize, size);
    //recover effect
    recover_effect.init(500, 30, size, 20);
    
    ofAddListener(tweenUpDown.end_E, this, &GamePlayer::tweenEnd);
    ofAddListener(tweenAngleAmount.end_E, this, &GamePlayer::tweenEnd);
    
    ofEnableAlphaBlending();
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
    float angle = mX * PI / degree * position_angleAmount;  //case mouse
    float dist = g_r + bounce_offset;
    
    //character_angleを計算するための仮のx, y 実際にimageに指定するxとyはimageのアンカー分を考えてずらす必要がある
    float x = sin(angle) * dist;
    float y = -(cos(angle) * dist);
    character_angle = atan2(y, x) / PI * 180 + 90;
    
    //Groundの中心移動+anchor分
    float xForImg = x + ofGetWidth()/2 - size/2;
    //Groundの中心移動
    float yForImg = y + g_y - size - footSize;
    
    xPos = xForImg;
    yPos = yForImg;
    
    foot.update();
    recover_effect.update();
    
    //circleが衝突してダメージを受けている状態あと生きてる時限定
    if(role != "" && life) {
        if(role == "good") {
            recovery();
        }else if(role=="bad") {
            injury();
        }
    }
    
    u_noiseAmount *= 0.99;
    //勢いつけて移動した時に前傾姿勢になる
    mouse_offset *= 0.95;
    mouse_offset += mouseSpeed * 30;
    character_angle_acceleration_offset = mouse_offset;
    eye_offset = mouse_offset;
    
    //[tween].update()を一括で実行する関数
    tweenManage();
    
}


//回復
void GamePlayer::recovery(){
    recover_effect.effectStart();
    
    u_noiseAmount = 0.;
    life_count -= 0.2;
    u_red_value = life_count;
    
    if(life_count <= -1){
        clear();
        life = false;
    }else {
        float duration = 2000;
        tweenRotationZ.setParameters(0, ease_elastic, ofxTween::easeOut, 0, 720, duration, 0);
    }
}

//負傷
void GamePlayer::injury() {
    
    //ダメージ
    u_noiseAmount = 2.;
    life_count += 0.1;
    u_red_value = life_count;
    
    //真っ赤になったとき死
    if(life_count >= 1.) {
        dead();
        life = false;
    }else {
        float duration = 300;
        //setParametersを呼ぶことでTween開始
        tweenUpDown.setParameters(51, ease_circ, ofxTween::easeOut, 0, 50, duration, 0);
    }
}

void GamePlayer::clear() {
    for(int i = 0; i < 100; i ++ ){
        cout << "clear()" <<endl;
    }
    float duration = 600;
    tweenUpDown.setParameters(31, ease_circ, ofxTween::easeOut, 0, 300, duration*2, 0);  //ジャンプ
    tweenRotationY.setParameters(0, ease_elastic, ofxTween::easeOut, 0,  720*2, 2000, 0);
    angleFrag = false;  //falseにすることで
    tweenAngleAmount.setParameters(0, ease_circ, ofxTween::easeOut, 1, 0, 2000, 0);
}

//死（ゲームオーバー）
void GamePlayer::dead() {
    float duration = 600;
    //setParametersを呼ぶことでTween開始
    tweenUpDown.setParameters(41, ease_circ, ofxTween::easeOut, 0, 100, duration, 0);  //ジャンプ
    tweenRotationZ.setParameters(0, ease_elastic, ofxTween::easeOut, 0,  720, 1000, 0);  //ジャンプ中回転
    
}

//復活時(各種パラメータのイニシャライズも）
void GamePlayer::revival() {
    life_count = u_red_value = 0.;
    position_angleAmount = 0;
    angleFrag = true;
    tweenUpDown.setParameters(91, ease_circ, ofxTween::easeOut, -200, ofGetHeight()*0.4, 5000, 7000);
}
//復活時(各種パラメータのイニシャライズも）
void GamePlayer::revival_clear() {
    life_count = u_red_value = 0.;
    position_angleAmount = 0;
    angleFrag = true;
    tweenUpDown.setParameters(91, ease_circ, ofxTween::easeOut, 0, ofGetHeight()*0.4, 5000, 7000);
}


void GamePlayer::display() {
    
//    player start
    
//    translate Matrix
    ofPushMatrix();
    ofTranslate(xPos+size/2, yPos+size/2);  //中心へ移動
    
//    座標変換1 : Groundの傾斜に伴うちょっと回転 これはエフェクトも影響受ける
    ofRotateZDeg(character_angle);
    
    //座標変換2 : 回復時のクルクルと加速移動の前傾姿勢分回転（エフェクトまで回転するのは変なのでここにエフェクト描画は含めない）
    ofRotateZDeg(character_angle_offset + character_angle_acceleration_offset);
    ofRotateYDeg(character_angle_y);  //y回転
    //shader start
    playerShader.begin();
    
    playerImage.draw(ofVec2f(-size/2), size, size);  //image
    playerShader.setUniformTexture("tex1", noiseTexture, 1);  //テクスチャとして渡す
    playerShader.setUniform1f("u_noiseAmount", u_noiseAmount);
    playerShader.setUniform1f("u_color_value", u_red_value);
    
    //foot
    foot.display();
    
    playerShader.end();
    //shader end
    
    //eye
    ofSetColor(255, 255, 255);
    ofDrawCircle(-size/10 + eye_offset, -size*15/100, 5);
    ofDrawCircle(size/10 + eye_offset, -size*15/100, 5);
    
//    エフェクトは座標変換2の影響を受けて欲しくないのでその分戻す（かつzindex前に表示されて欲しい)
    ofRotateZDeg(-(character_angle_offset + character_angle_acceleration_offset));
    ofSetColor(255, 255, 255, 100);
//    recover recover_effect
    recover_effect.display();
    
//    reset Matrix
    ofPopMatrix();
    
}



//tweenを一括で実行する関数
void GamePlayer::tweenManage(){
    //これでtweenの時間が進行する
    
    tweenUpDown.update();
    bounce_offset = tweenUpDown.getTarget(0);
    
    tweenRotationZ.update();
    character_angle_offset = tweenRotationZ.getTarget(0);
    
    //これはちょっとややこしい。position_angleAmountがtweenの値を参照し続けちゃうのでゲーム中はこれを無視
    tweenAngleAmount.update();
    if(!angleFrag) {
        position_angleAmount = tweenAngleAmount.getTarget(0);
    }
    
    tweenRotationY.update();
    character_angle_y = tweenRotationY.getTarget(0);
}

void GamePlayer::tweenEnd(int &e) {
    if(e == 42) {
        revival();
    }else if(e == 91) {
        tweenUpDown.setParameters(92, ease_bounce, ofxTween::easeOut, ofGetHeight()*0.4, 0, 500, 0);
        angleFrag = false;
        tweenAngleAmount.setParameters(93, ease_circ, ofxTween::easeOut, 0, 1, 2000, 500);
    }else if(e == 51) {
        tweenUpDown.setParameters(52, ease_bounce, ofxTween::easeOut, 50, 0, 500, 0);
    }else if(e == 41) {
        //地面にめり込む
        tweenUpDown.setParameters(42, ease_bounce, ofxTween::easeOut, 100, -200, 500, 0);
    }else if(e == 93) {
        life = true;
    }else if(e == 31) {
        //かっこよく着地
        tweenUpDown.setParameters(32, ease_bounce, ofxTween::easeOut, 300, 0, 500, 0);
    }else if(e == 32) {
        revival_clear();
    }
}

bool GamePlayer::isLife() {
    return life;
}
