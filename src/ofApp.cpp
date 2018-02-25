#include "ofApp.h"
#include "ofxOsc.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(50);
    sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    string buf = "Sending message " + string(MESSAGE) + " to " + string(HOST) + " on port " + ofToString(PORT);
    ofDrawBitmapStringHighlight(buf, 10, 20);
    buf = "X=" + ofToString(mouseX) + ", Y=" + ofToString(mouseY);
    ofDrawBitmapStringHighlight(buf, 10, 50);
  
    // Draw circle
    ofSetColor(ofColor::red);
    ofDrawCircle(mouseX, mouseY, 20);
}

void ofApp::mouseMoved(int x, int y){
    mouseX = x;
    mouseY = y;
    ofxOscMessage m;
    m.setAddress(string(MESSAGE));
    m.addFloatArg((float)x);
    m.addFloatArg((float)y);
    sender.sendMessage(m, false);
}
