#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

//Defaults for OSC:
#define HOST "localhost"
#define PORT 6448
#define MESSAGE "/wek/inputs"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y);
    
    ofTrueTypeFont font;
    
    //OSC sender:
    ofxOscSender sender;
    
    int mouseX = 0;
    int mouseY = 0;
    
};
