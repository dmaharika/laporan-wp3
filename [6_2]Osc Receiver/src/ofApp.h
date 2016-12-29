#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

        ofxOscReceiver oscReceiver;
        ofxFloatSlider slider;
        ofxPanel gui;
};
