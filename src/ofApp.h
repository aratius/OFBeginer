#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#include "Ground.hpp"
#include "Player.hpp"

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
        void checkCollision();
    
        vector <Circle> circles;
        Ground ground;
        GamePlayer player;
};
