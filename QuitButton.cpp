// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// QuitButton
//		Defines the quit button's location, text, image, and function. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "QuitButton.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
QuitButton::QuitButton(Assets& assets, Screen* new_parent) :
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
	anchor.x = 20;
	anchor.y = 20;

	debug ("QuitButton: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
QuitButton::~QuitButton() {
	debug ("QuitButton: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							      onClick() 		 						|
// |----------------------------------------------------------------------------|
int QuitButton::onClick() {
	debug ("QuitButton: onClick() called.");

	parent->setNextScreen(QUIT);
	parent->setDone(true);

	return error;
}