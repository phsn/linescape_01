//
//  lineScape.h
//  linescape_01
//
//  Created by Philipp Sniechota on 20.09.15.
//
//

#ifndef __linescape_01__lineScape__
#define __linescape_01__lineScape__

#include <stdio.h>
#include "ofMain.h"
#include "line.h"


#include "rp/Quad.h"
#include "rp/Quart.h"
#include "rp/Quint.h"
#include "rp/Sine.h"
#include "rp/Linear.h"
#include "rp/Expo.h"
#include "rp/Elastic.h"
#include "rp/Cubic.h"
#include "rp/Circ.h"
#include "rp/Bounce.h"
#include "rp/Back.h"


class lineScape {
    
    vector<line> lineList;
    vector<ofPoint> pointList;

    int numObj;
    float speed;
    float spacing;
    
public:
    lineScape();
    lineScape(int numLines);
    void update();
    void draw();
    
    float getSpacing();
    
};

#endif /* defined(__linescape_01__lineScape__) */
