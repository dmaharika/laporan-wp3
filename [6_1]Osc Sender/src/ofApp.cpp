#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
oscSender.setup("localhost",12462);
slider.addListener(this, &ofApp::sliderChanged);
gui.setup("Parameter Sent");
gui.add(slider.setup("Nilai",0,0,10));
ofSetWindowTitle("ofxOsc Sender");
ofSetWindowShape(300,150);
}

//--------------------------------------------------------------
void ofApp::sliderChanged( float &value ) {
ofxOscMessage m;
m.setAddress( "/Nilai" );
m.addFloatArg( value );
oscSender.sendMessage( m );
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
gui.draw();
}
