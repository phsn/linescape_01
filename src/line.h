//
//  line.h
//  linescape_01
//
//  Created by Philipp Sniechota on 20.09.15.
//
//

#ifndef __linescape_01__line__
#define __linescape_01__line__

#include <stdio.h>
#include "ofMain.h"


class line {
    
    ofMesh lineMesh;
    vector<ofPoint> initPos;
    vector<ofPoint> drawPos;
    int segCount;
    int length;
    
    ofPoint translation;
    float opac;
    
    float bendFact;
    float downresFact;
    
    double waveVal;
    vector<ofPoint> waveV;
    float waveAmp;
    float waveFreq;
    float waveSpeed;
    float waveOffset;
    
    double noiseVal;
    vector<ofPoint> noiseV;
    
    
    float zLimit;
    
public:
    line();
    line(int segments);
    void update();
    void draw();
    
    
    void setPositions(vector<ofPoint> points);
    void setTranslation(ofPoint newPosition);
    void bend(float bendFactor);
    void downres(float downresFactor);
    void move(ofPoint movingVector, float limitZ);
    void setWave(float amp, float freq, float speed);
    void setWave(float amp, float freq, float speed, float offset);
    void setOpacity(float opacity);

    vector<ofPoint> getInitPos();
    vector<ofPoint> getDrawPos();
    int getSegmentCount();
    ofPoint getTranslation();
    float getProgress();
    
};


#endif /* defined(__linescape_01__line__) */
