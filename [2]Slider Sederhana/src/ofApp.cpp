#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
gui.setup("Pengaturan");
gui.add(nily.setup("Nilai Y",1,0,10));
gui.add(freq.setup("Frekuensi",1,0,10));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
gui.draw();
ofSetColor(255,255,255);
}
