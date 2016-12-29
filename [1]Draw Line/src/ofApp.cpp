#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
int i = 0;
ofPushMatrix();
ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
ofSetColor(234,126,17);
for (;i<100;i++)
{
ofDrawLine(-500+(i*10),-90,-500+(i*10),90);
}
ofSetColor(221,25,175);
ofDrawLine(-505,0,505,0);
ofPopMatrix();
}
