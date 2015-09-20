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
    waveAmp, waveFreq, waveSpeed, waveOffset = 0;
    
    translation = ofPoint(0,0,0);
    
    for(int i=0; i < segCount; i++) {
        initPos.push_back(ofPoint(0,0,0));
        drawPos.push_back(ofPoint(0,0,0));
        waveV.push_back(ofPoint(0,0,0));
        noiseV.push_back(ofPoint(0,0,0));
    }
    
    this->update();
}

//--------------------------------------------------------------
void line::update(){
    float time = ofGetElapsedTimef() + waveOffset;
    for (int i=0; i < segCount; i++) {
        waveV[i] = ofPoint(0,
                           waveAmp*sin((i*waveFreq)+time*M_2_PI*waveSpeed),
                           waveAmp*cos((i*waveFreq)+time*M_2_PI*waveSpeed));
        noiseV[i] = ofPoint(0,
                            2000*2*(ofNoise(i/float(segCount)*10.0, translation.z/zLimit*2-ofGetElapsedTimef()/2.0,ofGetElapsedTimef()/5.0)-0.5),
                            0);
        drawPos[i] = initPos[i] + waveV[i] + noiseV[i] + translation;
    }
}

//--------------------------------------------------------------
void line::draw(){
    //cout << drawPos[0].z << " - " << drawPos[segCount-1].z << endl;
    //cout << translation.z << " ";
    for (int i=0; i < segCount; i++) {
        //float alpha = ofMap(translation.z, 0, 3000,0.0,255.0);
        float alpha = translation.z/zLimit*255.0;
        //alpha *= 1.0-0.5*(1.0+cos(M_2_PI*10*i/float(segCount)));
        
        ofSetLineWidth(3);
        ofSetColor(ofColor(255,255,255,alpha));
        //ofCircle(drawPos[i], 1);
        if(i < (segCount-1)) {
            ofLine(drawPos[i], drawPos[i+1]);
        }
    }
    
}

void line::move(ofPoint movingVector, float limitZ) {
    translation  = translation + movingVector;
    translation.z = fmod(translation.z,limitZ);
    zLimit = limitZ;
}

float line::getProgress() {
    return translation.z/zLimit;
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
        cout << "Error in line.cpp:" << endl
             << "Can't update positions - point count differs" << endl;
    }
}

void line::setTranslation(ofPoint newPosition) {
    translation = newPosition;
}

void line::setWave(float amp, float freq, float speed) {
    this->setWave(amp, freq, speed, 0);
}

void line::setWave(float amp, float freq, float speed, float offset) {
    waveAmp = amp, waveFreq = freq;
    waveSpeed = speed, waveOffset = offset;
}

vector<ofPoint> line::getInitPos() {
    return initPos;
}

vector<ofPoint> line::getDrawPos() {
    return drawPos;
}

ofPoint line::getTranslation() {
    return translation;
}

//--------------------------------------------------------------
int line::getSegmentCount(){
    return segCount;
}