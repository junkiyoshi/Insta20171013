#pragma once
#include "ofMain.h"

class Ripple{
public:
	Ripple();
	Ripple(ofColor body_color);
	~Ripple();

	void update();
	void draw();
	bool isDead();
private:
	float radius;
	ofColor body_color;
};