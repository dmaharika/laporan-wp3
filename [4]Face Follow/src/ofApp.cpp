#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	ofSetVerticalSync(true);
	ofSetFrameRate(120);
	finder.setup("haarcascade_frontalface_default.xml");
	finder.setPreset(ObjectFinder::Fast);
	finder.getTracker().setSmoothingRate(.3);
	cam.setup(640, 480);
    sunglasses.load("sunglasses.png");
	ofEnableAlphaBlending();

        plot = new ofxHistoryPlot( NULL, "Jumlah Wajah Terdeteksi",360 , false);
        plot->setRange(0,5);
        plot->addHorizontalGuide(ofGetHeight()/2, ofColor(255,0,0));
        plot->setColor( ofColor(0,255,0) );
        plot->setShowNumericalInfo(true);
        plot->setRespectBorders(true);
        plot->setLineWidth(3);
        plot->setBackgroundColor(ofColor(0,220));
        plot->setDrawGrid(true);
        plot->setGridColor(ofColor(30));
        plot->setGridUnit(14);
        plot->setCropToRect(true);
}


void ofApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		finder.update(cam);
	}
	plot->update(finder.size());
}

void ofApp::draw() {
	cam.draw(0, 0);
    plot->draw(0, 480, 640, 240);
	for(int i = 0; i < finder.size(); i++) {
		ofRectangle object = finder.getObjectSmoothed(i);
		sunglasses.setAnchorPercent(.5, .5);
        float scaleAmount = 0.95 * object.width / sunglasses.getWidth();
		ofPushMatrix();
		ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
		ofScale(scaleAmount, scaleAmount);
		sunglasses.draw(0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(object.getPosition());
		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
		ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
		ofPopMatrix();
	}

}
