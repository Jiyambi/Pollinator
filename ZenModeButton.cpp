// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ZenModeButton
//		Defines the zen mode button's location, text, image, and function. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "ZenModeButton.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
ZenModeButton::ZenModeButton(Assets& assets, Screen* new_parent) :
	parent(new_parent) {
	
	// Loading graphics into Image objects
	image_normal = new Image(assets.graphics.flower_blue);
	image_normal->setAnchor(Coord(20,20));
	image_selected = new Image(assets.graphics.flower_yellow);
	image_selected->setAnchor(Coord(20,20));
	image_pressed = new Image(assets.graphics.flower_red);
	image_pressed->setAnchor(Coord(20,20));
	image_disabled = new Image(assets.graphics.flower_gray);
	image_disabled->setAnchor(Coord(20,20));

	// Set size of button
	size.x = 210;
	size.y = 210;

	// Set anchor of button
	setAnchor(Coord(200,200));

	// Set text
	text = new Text(assets.fonts.reg, 255, 255, 255);
	*text = "ZEN MODE";
	text->setAnchor(anchor+Coord(120,100));

	debug ("ZenModeButton: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
ZenModeButton::~ZenModeButton() {
	debug ("ZenModeButton: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							      onClick() 		 						|
// |----------------------------------------------------------------------------|
int ZenModeButton::onClick() {
	debug ("ZenModeButton: onClick() called.");

	// TODO: Change to ZENMODE when screen is added
	parent->setNextScreen(QUIT);
	parent->setDone(true);

	return error;
}