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
    
    vector<ofPoint> waveV;
    float waveAmp;
    float waveFreq;
    float waveSpeed;
    
public:
    line();
    line(int segments);
    void update();
    void draw();
    
    void setWave(float amp, float freq, float speed);
    
    void setPositions(vector<ofPoint> points);
    vector<ofPoint> getInitPos();
    vector<ofPoint> getDrawPos();
    int getSegmentCount();
    
};


#endif /* defined(__linescape_01__line__) */
