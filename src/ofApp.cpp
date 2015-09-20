#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAntiAliasing();
    ofEnableSmoothing();

    scapeLines = 20;
    testScape = lineScape(scapeLines);
    
    myCamera.setDistance(2000);
    myCamera.setupPerspective(true,80,0,25000, ofVec2f(0.0f, 0.0f));
}

//--------------------------------------------------------------
void ofApp::update(){
    testScape.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    myCamera.begin();
    
    ofTranslate(-ofGetWidth()*40,300,-(scapeLines*testScape.getSpacing())+2000);
    testScape.draw();
    
    myCamera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
