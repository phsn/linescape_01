//
//  lineScape.cpp
//  linescape_01
//
//  Created by Philipp Sniechota on 20.09.15.
//
//

#include "lineScape.h"

lineScape::lineScape(){}

lineScape::lineScape(int numLines){
    
    speed = 50;
    spacing = 1000;
    numObj = numLines;
    
    int numPoints = 200;
    
    //for (int i=0; i < numPoints; i++) {
    //    pointList.push_back(ofPoint(i*(ofGetWidth()*80/float(numPoints-1)),ofGetHeight()/2,0));
    //}
    
    line tempLine;
    for(int i=0; i < numObj; i++) {
        tempLine = line(numPoints);
        //tempLine.setPositions(pointList);
        tempLine.setTranslation(ofPoint(0,0,i*spacing));
        lineList.push_back(tempLine);
    }
    
    //pointList.clear();
}

void lineScape::update() {
    for(int i=0; i < numObj; i++) {
        lineList[i].move(ofPoint(0,0,speed),numObj*spacing);
        //lineList[i].bend(ofGetMouseX()/float(ofGetWidth()));
        lineList[i].bend(1.005);
        //lineList[i].downres(ofGetMouseX()/float(ofGetWidth()));
        
        //lineList[i].setWave(700,0.3,1,lineList[i].getProgress()*1.5);
        lineList[i].update();
    }
}


void lineScape::draw() {
    for(int i=0; i < numObj; i++) {
        lineList[i].draw();
    }
}

float lineScape::getSpacing() {
    return spacing;
}
