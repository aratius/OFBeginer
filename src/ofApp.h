#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#include "Ground.hpp"
#include "Player.hpp"
#include "Hokuyo.hpp"
#include "PlayerFoot.hpp"
#include "Sky.hpp"

//addons
#include "ofxOsc.h"
#include "ofxTween.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y );
		
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
    Sky sky;
    
        //my variable
        float mouseSpeed;
        float lastMousePos;
};
