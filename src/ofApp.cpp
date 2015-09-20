#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int numPoints = 60;
    
    for (int i=0; i < numPoints; i++) {
        pointList.push_back(ofPoint(i*(ofGetWidth()/float(numPoints-1)),ofGetHeight()/2));
    }
    
    testLine = line(numPoints);
    testLine.setPositions(pointList);
    
    pointList.clear();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    testLine.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    testLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    testLine.setWave(30,0.05,10);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
