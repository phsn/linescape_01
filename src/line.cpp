//
//  line.cpp
//  linescape_01
//
//  Created by Philipp Sniechota on 20.09.15.
//
//

#include "line.h"

line::line(){}

line::line(int segments){
    segCount = segments;
    waveAmp, waveFreq, waveSpeed = 0;
    
    for(int i=0; i < segCount; i++) {
        initPos.push_back(ofPoint(0,0));
        drawPos.push_back(ofPoint(0,0));
        waveV.push_back(ofPoint(0,0));
    }
    
    this->update();
}

//--------------------------------------------------------------
void line::update(){
    for (int i=0; i < segCount; i++) {
        waveV[i] = ofPoint(0,waveAmp*sin((i*waveFreq)+ofGetElapsedTimef()*M_2_PI*waveSpeed));
        drawPos[i] = initPos[i] + waveV[i];
    }
}

//--------------------------------------------------------------
void line::draw(){
    for (int i=0; i < segCount; i++) {
        ofCircle(drawPos[i], 1);
    }
    for (int i=0; i < (segCount-1); i++) {
        ofLine(drawPos[i], drawPos[i+1]);
    }
    
}

void line::setWave(float amp, float freq, float speed) {
    waveAmp = amp;
    waveFreq = freq;
    waveSpeed = speed;
}

//
//--------------------------------------------------------------
//   GETTERS AND SETTERS
//--------------------------------------------------------------
//

void line::setPositions(vector<ofPoint> points) {
    if(points.size() == segCount) {
        initPos.clear();
        for(int i=0; i < segCount; i++) {
            initPos.push_back(points[i]);
        }
    } else {
        cout << "Error in line.cpp: Can't update positions - point count differs" << endl;
    }
}

vector<ofPoint> line::getInitPos() {
    return initPos;
}

vector<ofPoint> line::getDrawPos() {
    return drawPos;
}

//--------------------------------------------------------------
int line::getSegmentCount(){
    return segCount;
}