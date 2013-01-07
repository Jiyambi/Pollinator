// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Circle
//		Governs movement, collision detection, and drawing for a 
//      circle object. 

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Circle.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Circle::Circle() :
	position(0,0),
	velocity(0,0),
	radius(0),
	angle(0),
	graphic(0),
	error(0)
{		
	debug ("Circle: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Circle::~Circle() {
	delete graphic;	
	debug ("Circle: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the screen or level.
int Circle::draw() {
	debug ("Circle: draw() called.", 10);

	// Draw the button's image
	if (graphic) graphic->draw();

	return error;
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Circle::logic(int mouse_x, int mouse_y) {
	debug ("Circle: logic() called.", 10);

	// Move based on velocity
	if(velocity.x || velocity.y) setPosition(position+velocity);

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onMouseDown()								|
// |----------------------------------------------------------------------------|
int Circle::onMouseDown(int button) {
	debug ("Circle: onMouseDown() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							     onMouseUp()								|
// |----------------------------------------------------------------------------|
int Circle::onMouseUp(int button) {
	debug ("Circle: onMouseUp() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							     onKeyDown()								|
// |----------------------------------------------------------------------------|
int Circle::onKeyDown(int button) {
	debug ("Circle: onKeyDown() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							      onKeyUp() 		 						|
// |----------------------------------------------------------------------------|
int Circle::onKeyUp(int button) {
	debug ("Circle: onKeyUp() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							    setPosition() 		 						|
// |----------------------------------------------------------------------------|
void Circle::setPosition(Coord new_position) {
	debug ("Circle: setPosition() called.");

	position = new_position;
	if(graphic) graphic->setAnchor(position-radius);	

}

// |----------------------------------------------------------------------------|
// |							      setAngle() 		 						|
// |----------------------------------------------------------------------------|
void Circle::setAngle(double new_angle) {
	debug ("Circle: setPosition() called.");

	angle = new_angle;
	if(graphic) graphic->setAngle(angle);	

}