#pragma once

#include "ofMain.h"
#include "ofxHistoryPlot.h"

class testApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        ofxHistoryPlot * plot;
        float nilai;
};
