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
    
    vector<ofPoint> initPos;
    vector<ofPoint> drawPos;
    int segCount;
    
    ofPoint translation;
    float opac;
    
    vector<ofPoint> waveV;
    float waveAmp;
    float waveFreq;
    float waveSpeed;
    float waveOffset;
    
    vector<ofPoint> noiseV;
    
    
    float zLimit;
    
public:
    line();
    line(int segments);
    void update();
    void draw();
    
    
    void setPositions(vector<ofPoint> points);
    void setTranslation(ofPoint newPosition);
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
