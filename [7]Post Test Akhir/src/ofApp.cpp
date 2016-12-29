#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Robot Receiver");
    ofSetWindowShape(700,700);
    ofSetFrameRate(30);
    ofSetBackgroundColor(255,255,255);
    robot.load("agera.jpg");
    grup.setup("Robot Control");
    grup.add(contra.setup("Translation Control"));
    contra.add(mx.setup("Speed X",0,-10,10));
    contra.add(my.setup("Speed Y",0,-10,10));
    grup.add(conrot.setup("Rotation Control"));
    conrot.add(rot.setup("Rotation",0,-10,10));

    /*plotx = new ofxHistoryPlot( NULL, "Posisi X", 360, false);
    plotx->setRange(0,700);
    plotx->addHorizontalGuide(ofGetHeight()/2, ofColor(255,0,0));
    plotx->setColor( ofColor(0,255,0) );
    plotx->setShowNumericalInfo(true);
    plotx->setRespectBorders(true);
    plotx->setLineWidth(3);
    plotx->setBackgroundColor(ofColor(0,220));
    plotx->setDrawGrid(true);
    plotx->setGridColor(ofColor(30));
    plotx->setGridUnit(14);
    plotx->setCropToRect(true);

    ploty = new ofxHistoryPlot( NULL, "Posisi Y", 360, false);
    ploty->setRange(0,700);
    ploty->addHorizontalGuide(ofGetHeight()/2, ofColor(255,0,0));
    ploty->setColor( ofColor(0,255,0) );
    ploty->setShowNumericalInfo(true);
    ploty->setRespectBorders(true);
    ploty->setLineWidth(3);
    ploty->setBackgroundColor(ofColor(0,220));
    ploty->setDrawGrid(true);
    ploty->setGridColor(ofColor(30));
    ploty->setGridUnit(14);
    ploty->setCropToRect(true);

    plotr = new ofxHistoryPlot( NULL, "Sudut Rotasi", 360, false);
    plotr->setRange(-360,360);
    plotr->addHorizontalGuide(ofGetHeight()/2, ofColor(255,0,0));
    plotr->setColor( ofColor(0,255,0) );
    plotr->setShowNumericalInfo(true);
    plotr->setRespectBorders(true);
    plotr->setLineWidth(3);
    plotr->setBackgroundColor(ofColor(0,220));
    plotr->setDrawGrid(true);
    plotr->setGridColor(ofColor(30));
    plotr->setGridUnit(14);
    plotr->setCropToRect(true);*/
}
//--------------------------------------------------------------
void ofApp::update(){
    roll=roll+rot;
    y=roll/180*PI;
    px=px+(mx*cos(y)+my*sin(y));
    py=py-(my*cos(y)-mx*sin(y));
    /*plotx->update(px+ofGetWindowWidth()/2);
    ploty->update(py+ofGetWindowHeight()/2);
    plotr->update(roll);*/ //Silakan un-comment untuk menggunakan fasilitas HistoryPlot
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    ofTranslate(px,py);
    ofRotate(roll);
    robot.draw(-robot.getWidth()/2,-robot.getHeight()/2);
    ofPopMatrix();
    grup.draw();
    /*plotx->draw(10,360,690,80);
    ploty->draw(10,450,690,80);
    plotr->draw(10,540,690,80);*/
}
