#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp(){
	for (int i = this->ripples.size() - 1; i > -1; i--) {
		delete this->ripples[i];
		this->ripples.erase(this->ripples.begin() + i);
	}
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofSetCircleResolution(360);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update(){
	for(int i = this->ripples.size() - 1; i > -1; i--){
		this->ripples[i]->update();

		if (this->ripples[i]->isDead()) {
			delete this->ripples[i];
			this->ripples.erase(this->ripples.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	ofColor body_color;
	body_color.setHsb(ofGetFrameNum() % 255, 255, 255);

	ofFill();
	ofSetColor(body_color);
	ofDrawCircle(0, 0, 100);

	if (ofNoise(ofGetFrameNum() * 0.05) > 0.5) {
		this->ripples.push_back(new Ripple(body_color));
	}

	for (Ripple* r : this->ripples) {
		r->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}

