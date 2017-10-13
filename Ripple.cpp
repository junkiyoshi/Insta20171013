#include "Ripple.h"

Ripple::Ripple() : Ripple(ofColor(128))
{

}

Ripple::Ripple(ofColor body_color)
{
	this->radius = 100;
	this->body_color = body_color;
}

Ripple::~Ripple()
{

}

void Ripple::update()
{
	this->radius += 3;
}

void Ripple::draw()
{
	ofNoFill();
	ofSetColor(this->body_color);
	ofDrawCircle(ofVec3f(0, 0, 0), this->radius);
}

bool Ripple::isDead()
{
	return this->radius > ofGetWidth() || this->radius > ofGetHeight();
}