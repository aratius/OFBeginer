#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#include "Ground.hpp"
#include "Player.hpp"
#include "Hokuyo.hpp"
#include "Sky.hpp"
#include "InjuryEffects.hpp"
#include "Buildings.hpp"
#include "OscReciever.hpp"

//addons
#include "ofxOsc.h"
#include "ofxTween.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y );
        void keyPressed(int key);
		
        // my function
        float getGround_yPos();
        bool setTimer(int doCount);
        void circleInit();
        string checkCollision();
    
        //my classes
        vector <Circle> circles;
        Ground ground;
        GamePlayer player;
        HokuyoOsc hokuyo;
        OscReciever osc;
        Sky sky;
        InjuryEffects injury_effect;  //ダメージエフェクトはプレイヤーではなく文字に依存するのでこっちで呼び出し
        Buildings buildings;
    
        ofSoundPlayer bg_music;
    
        //my variable
        float mouseSpeed;
        float lastMousePos;
        bool isPlaying = true;
        float ground_offset = 0;
        int frame_count;
    
        
};
