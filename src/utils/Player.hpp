//
//  Ground.hpp
//  beginner
//
//  Created by 松本新 on 2020/12/15.
//
#include "ofMain.h"

#ifndef Player.hpp
#define Player.hpp

#include "PlayerFoot.hpp"
#include "RecoveryEffects.hpp"

#include <stdio.h>

#include "ofxTween.h"

class GamePlayer {
    
public:
    
    void init(float _x, float _y, float _size);
    void update(float mX, float g_r, float g_y, float hokuyo_x, string role, float mousesSpeed);
    void display();
    void recovery();
    void injury();
    void tweenManage();
    void clear();
    void dead();
    void tweenEnd(int &e);
    void revival();  //復活
    void revival_clear();
    string isLife();
    string state = "playing";
    
    
    float xPos, yPos, size;
    float footSize = 20;
    float eye_offset = 0;
    float u_noiseAmount = 0.;
    
    //distに足す、Groundからいくら離れるかの値（バウンドとか、復活の時の昇天とか全部これ）
    float bounce_offset = 0;
    
    float last_active_pos = 0;  //hokuyoの値はoscから毎フレームくるわけではないので前回の有効値を記憶しておく
    
    //残りライフを表すパラメータ
    float u_red_value = 0;  //シェーダーに渡す値
    float life_count = 0;  //1で死ぬ
    
    //キャラクターの角度
    float character_angle = 0;
    float character_angle_offset = 0;  //くるっと1回転
    float character_angle_acceleration_offset = 0;  //横の加速移動に対してのちょい回転
    float character_angle_y = 0;
    
    float mouse_offset = 0;  //マウスの加速度 マイフレーム*= 0.99とかで徐々に減ってく
    
    float position_angleAmount = 1;  //曲座標から算出するGround中心から見た角度
    
    bool life = true;  //生きてるか死んでるか
    bool angleFrag = true;  //trueの時はtweenの値を参照しない
    
    ofShader playerShader;
    ofImage playerImage;
    ofImage noiseTexture;
    
    PlayerFoot foot;
    RecoveryEffects recover_effect;
    
    ofxTween tweenUpDown;  //中心からのdistのOffsetを扱う ジャンプとか昇天とか全部これ
    ofxTween tweenRotationZ;  //キャラクターの回転はこれ
    ofxTween tweenRotationY;
    //ゲーム中以外にキャラクターを中央に固定するために、大元のangleに掛ける値。0なら固定。
    ofxTween tweenAngleAmount;
    //tweenの機能は持たず、n秒後に処理を実行するために利用する
    ofxTween tweenEmpty;
    
    //イージングを余分にいっぱい羅列している
    ofxEasingBounce ease_bounce;
    ofxEasingExpo ease_expo;
    ofxEasingQuad ease_quad;
    ofxEasingCirc ease_circ;
    ofxEasingElastic ease_elastic;
    ofxEasingBack ease_back;
private:
    
};

#endif /* Ground_hpp */
