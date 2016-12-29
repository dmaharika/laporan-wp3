#pragma once

#include "ofMain.h"
#include "ofxGui.h"
//#include "ofxHistoryPlot.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    float y,px,py,roll;
    ofxPanel grup;
    ofxGuiGroup contra,conrot;
    ofxIntSlider mx, my,rot;
    ofImage robot;
    //ofxHistoryPlot *plotx,*ploty,*plotr;
};
