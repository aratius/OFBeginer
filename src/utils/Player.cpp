// Tween番号の割り振り法則
// 0 : コールバックなし
// 30番台 : クリア時の演出
// 40番台 : ゲームオーバー時の演出
// 90番台 : 復活演出3,4共通
// 50番台 : ダメージ演出
// 60番台 : 回復演出
// 70番台 : ジャンプ

#include "Player.hpp"

#define degree 10 
//#define degree 4

#define input_type "osc"
#define key_pos_bounce 2.0
#define key_max_speed 0.04

#define angle_offset_devide 60

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
    recover_effect.init(500, 60, size, 20);
    
    ofAddListener(tweenUpDown.end_E, this, &GamePlayer::tweenEnd);
    ofAddListener(tweenAngleAmount.end_E, this, &GamePlayer::tweenEnd);
    ofAddListener(tweenJump.end_E, this, &GamePlayer::tweenEnd);
    ofAddListener(tweenEmpty.end_E, this, &GamePlayer::tweenEnd);
    
    ofEnableAlphaBlending();
}

void GamePlayer::update(float mX,  float g_r, float g_y, float hokuyo_x, ofVec3f osc_value, string role, float mouseSpeed) {
    
    float angle;
    if(input_type == "hokuyo") {
        if(hokuyo_x > -360 && hokuyo_x < 360 && !(hokuyo_x > -0.5 && hokuyo_x < 0.5)) {
            last_active_pos = hokuyo_x;
        }else {
            //期待した値が来なかったら前回の有効値使う
            hokuyo_x = last_active_pos;
        }
        //だいたい-1~1の値に調整（ここは手動で）
        hokuyo_x /= 50;
        angle = hokuyo_x * PI / degree;  //case hokuyo
    }else if (input_type == "osc") {
        
        if(!(osc_value.x == -999 && osc_value.y == -999 && osc_value.z == -999)){
            
            if(osc_value.x == 0 || osc_value.y == 0) {
                osc_direction = 0;
            }
            if(osc_value.x == 1) {
                osc_direction = -1;
            }else if (osc_value.y == 1) {
                osc_direction = 1;
            }
            
            if(osc_value.z == 1) {
                if(jumpable) {
                    tweenJump.setParameters(71, ease_circ, ofxTween::easeOut, 0, 300, 400, 0);
                    jumpable = false;
                };
            }
        }
        
        
        if(osc_direction == 1) {
            if(key_speed > -key_max_speed) key_speed -= 0.005;
        }else if(osc_direction == -1) {
            if(key_speed < key_max_speed) key_speed += 0.005;
        }
        key_pos += sin(key_speed);
        key_speed *= 0.95;  //ほっとくと0になる
        //端っこに行ったときにバウンド
        if(key_pos < -key_pos_bounce) {
            key_pos = -key_pos_bounce;
            key_speed *= -1;
        }else if (key_pos > key_pos_bounce){
            key_pos = key_pos_bounce;
            key_speed *= -1;
        }
        angle = key_pos * PI / degree * position_angleAmount;  //case key
        
        //勢いつけて移動した時に前傾姿勢になる
        key_offset += key_speed * angle_offset_devide;
        key_offset *= 0.95;
        character_angle_acceleration_offset = key_offset;
        eye_offset = key_offset;
    }
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

//クリア
void GamePlayer::clear() {
    state = "clear";
    float duration = 600;
    tweenUpDown.setParameters(31, ease_circ, ofxTween::easeOut, 0, 600, duration*2, 0);  //ジャンプ
    tweenRotationY.setParameters(0, ease_circ, ofxTween::easeOut, 0,  720*2, 2000, 0);
    angleFrag = false;  //falseにすることで
    tweenAngleAmount.setParameters(0, ease_circ, ofxTween::easeOut, 1, 0, 2000, 0);
}

//死（ゲームオーバー）
void GamePlayer::dead() {
    state = "dead";
    float duration = 600;
    //setParametersを呼ぶことでTween開始
    tweenUpDown.setParameters(41, ease_circ, ofxTween::easeOut, 0, 200, duration, 0);  //ジャンプ
    tweenRotationZ.setParameters(0, ease_elastic, ofxTween::easeOut, 0,  720, 1000, 0);  //ジャンプ中回転
    
}

//死からの復活時(各種パラメータのイニシャライズも）
void GamePlayer::revival() {
    state = "playing";
    life_count = u_red_value = 0.;
    position_angleAmount = 0;
    angleFrag = true;
    tweenUpDown.setParameters(91, ease_circ, ofxTween::easeOut, -size*2, ofGetHeight()*0.4, 5000, 7000);
}
//クリアからの復活時(各種パラメータのイニシャライズも）
void GamePlayer::revival_clear() {
    state = "playing";
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
    ofDrawCircle(-size/10 + eye_offset, -size*15/100, size/20);
    ofDrawCircle(size/10 + eye_offset, -size*15/100, size/20);
    
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
    tweenJump.update();
    bounce_offset = tweenUpDown.getTarget(0) + tweenJump.getTarget(0);
    
    tweenRotationZ.update();
    character_angle_offset = tweenRotationZ.getTarget(0);
    
    //これはちょっとややこしい。position_angleAmountがtweenの値を参照し続けちゃうのでゲーム中はこれを無視
    tweenAngleAmount.update();
    if(!angleFrag) {
        position_angleAmount = tweenAngleAmount.getTarget(0);
    }
    
    tweenRotationY.update();
    character_angle_y = tweenRotationY.getTarget(0);
    
    tweenEmpty.update();
}

void GamePlayer::tweenEnd(int &e) {
    if(e == 31) {
        //かっこよく着地
        tweenUpDown.setParameters(32, ease_bounce, ofxTween::easeOut, 600, 0, 500, 0);
    }else if(e == 32) {
        revival_clear();
        tweenEmpty.setParameters(33, ease_bounce, ofxTween::easeOut, 0, 0, 2000, 0);
    }else if(e == 33) {
        life_count = u_red_value = 0.;
    }else if (e == 41) {
        //地面にめり込む
        tweenUpDown.setParameters(42, ease_bounce, ofxTween::easeOut, 200, -size*2, 500, 0);
    }else if(e == 42) {
        revival();
    }else if(e == 51) {
        tweenUpDown.setParameters(52, ease_bounce, ofxTween::easeOut, 50, 0, 500, 0);
    }else if(e == 91) {
        tweenUpDown.setParameters(0, ease_bounce, ofxTween::easeOut, ofGetHeight()*0.4, 0, 500, 0);
        angleFrag = false;
        tweenAngleAmount.setParameters(92, ease_circ, ofxTween::easeOut, 0, 1, 2000, 500);
    }else if(e == 92) {
        life = true;
    }else if(e == 71) {
        tweenJump.setParameters(72, ease_bounce, ofxTween::easeOut, 300, 0, 600, 0);
    }else if(e == 72) {
        jumpable = true;
    }
}

string GamePlayer::isLife() {
    return state;
}

void GamePlayer::keyPressed(int key) {
    if(key == 57356) {
        if(key_speed > -key_max_speed) key_speed -= 0.005;
    }else if (key == 57358) {
        if(key_speed < key_max_speed) key_speed += 0.005;
    }else if(key == 57357) {
        //jump
        if(jumpable) {
            tweenJump.setParameters(71, ease_circ, ofxTween::easeOut, 0, 300, 400, 0);
            jumpable = false;
        }
    }
}
