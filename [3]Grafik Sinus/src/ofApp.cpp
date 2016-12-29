#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ofSetWindowShape(660,260);
    plot = new ofxHistoryPlot( NULL, "Sinus Graph", 360, false); //ganti Sinus Squared Graph dengan judul trigonometrimu
    plot->setRange(-1,1);
    plot->addHorizontalGuide(ofGetHeight()/2, ofColor(255,0,0));
    plot->setColor( ofColor(0,255,0) );
    plot->setShowNumericalInfo(true);
    plot->setRespectBorders(true);
    plot->setLineWidth(1);
    plot->setBackgroundColor(ofColor(0,220));
    plot->setDrawGrid(true);
    plot->setGridColor(ofColor(30));
    plot->setGridUnit(14);
    plot->setCropToRect(true);
}

//--------------------------------------------------------------
void testApp::update(){

    nilai = ofGetElapsedTimef();
    plot->update(sin(nilai));//silakan ganti rumus dengan pilihan trigonometri lainnya
}

//--------------------------------------------------------------
void testApp::draw(){
    plot->draw(10, 10, 640, 240);
}
