#include "ofApp.h"

float Ground_radius = 1000.0;
float Player_size = 100;
float mX = -999;  //-1 ~ 1
int frame_count;

//地面の大きいCircleのY座標を取得
float ofApp::getGround_yPos(){
    return Ground_radius + ofGetHeight()*0.7;
}

//--------------------------------------------------------------
void ofApp::setup(){
    //アプリビルドのために必要な一文
    ofSetDataPathRoot("../Resources/data/");
    
    sky.init();
    
    ofBackground(255, 255, 255);
    ofSetCircleResolution(64);
    
    ground.init(Ground_radius, getGround_yPos());
    
    float initAngle = 0;
    float initY = -(cos(initAngle) * Ground_radius + Player_size) + getGround_yPos();
    player.init(ofGetWidth()/2, initY, Player_size);
    
    hokuyo.init();
    injury_effect.init(Player_size);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    sky.update();
    
    for(int i = 0; i < circles.size(); i++) {
        circles[i].update();
        if(circles[i].yPos > ofGetHeight()) {
            circles.erase(circles.begin()+i);//要素削除
        }
    }
    
    //cirlcleとplayerの衝突判定
    string role = checkCollision();
    float hokuyo_x = hokuyo.update();
    player.update(mX, Ground_radius, getGround_yPos(), hokuyo_x, role, mouseSpeed);
    
    if(setTimer(60) && player.life) {
        //60フレームに1度実行される
        circleInit();
    };
    
    frame_count ++;

    injury_effect.update();
    
    if(!player.isLife() && isPlaying) {
        cout << "helloE" << endl;
        isPlaying = false;
        ground.startAnimation();
    }else if (player.isLife() && !isPlaying) {
        isPlaying = true;
    }
    ground.update();
    
}

//circleとplayerの衝突 衝突したら該当のcircle消す
string ofApp::checkCollision() {
    string role;
    for (int i = 0; i < circles.size(); i++) {
        ofVec2f playerCenter;
        playerCenter.x = player.xPos + player.size/2;
        playerCenter.y = player.yPos + player.size/2;
        float dist = sqrt(pow(circles[i].xPos + circles[i].offsetX - playerCenter.x, 2) + pow(circles[i].yPos - playerCenter.y, 2));
        if(dist < Player_size/2 + circles[i].eSize/2) {
            role = circles[i].role;
            if(role == "bad") injury_effect.effectStart(ofVec2f(circles[i].xPos, circles[i].yPos));
            circles.erase(circles.begin()+i);//要素削除
            return role;
        }
    }
    return "";
}

bool ofApp::setTimer(int doCount) {
    if(frame_count % doCount == 0) {
        return true;
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    collition range
//    ofSetColor(255, 255, 0);
//    ofDrawCircle(player.xPos + player.size/2, player.yPos + player.size/2, Player_size/2+10);
    
    sky.display();
    
    for(int i = 0; i < circles.size(); i ++){
        circles[i].display();
    }
    
    player.display();
    
    injury_effect.display();
    
    ground.display();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    float mousePositionX = ofGetMouseX();
    float stageWidth = ofGetWidth();
    mX = (mousePositionX / stageWidth - 0.5) * 2;  //-1 ~ 1
    
    mouseSpeed = mX - lastMousePos;
    lastMousePos = mX;
}

//--------------------------------------------------------------

void ofApp::circleInit() {
    Circle circle;
    float x = ofRandom(ofGetWidth());
    
    //ファイル名を決めるところ
    if(ofRandom(1.0) > 0.5) {
        //good
        int index = ofRandom(1, 11);
        string filename = "imgs/good/good-" + to_string(index) + ".png";
        circle.init(x, -100, Player_size, ofRandom(2) + 2, frame_count, filename, "good");
    }else{
        //bad
        int index = ofRandom(1, 37);
        string filename = "imgs/bad/bad-" + to_string(index) + ".png";
        circle.init(x, -100, Player_size, ofRandom(2) + 2, frame_count, filename, "bad");
    }
    
    circles.push_back(circle);  //配列に追加
}
