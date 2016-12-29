#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
oscReceiver.setup(12462);
gui.setup("Parameter Received");
gui.add(slider.setup("Nilai",0,0,10));
ofSetWindowTitle("ofxOsc Receiver");
ofSetWindowShape(300,150);
}

//--------------------------------------------------------------
void ofApp::update(){
while (oscReceiver.hasWaitingMessages()){
        ofxOscMessage m;
        oscReceiver.getNextMessage(&m);
        if (m.getAddress()=="/Nilai"){
            slider = m.getArgAsFloat(0);
        }
}
}

//--------------------------------------------------------------
void ofApp::draw(){
gui.draw();
}
