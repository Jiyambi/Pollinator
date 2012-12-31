// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ScreenChangeButton
//		Defines the screen change button's location, text, image, and function. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "ScreenChangeButton.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
ScreenChangeButton::ScreenChangeButton(Assets& assets, Screen* new_parent, SCREEN new_screen_to_change, string new_text) :
	parent(new_parent) {
	
	// Loading graphics into Image objects
	image_normal = new Image(assets.graphics.flower_blue);
	image_selected = new Image(assets.graphics.flower_yellow);
	image_pressed = new Image(assets.graphics.flower_red);
	image_disabled = new Image(assets.graphics.flower_gray);

	// Set size of button
	size.x = 210;
	size.y = 210;

	// Set text
	text = new Text(assets.fonts.reg, 255, 255, 255);
	*text = new_text;

	// Set click to screen
	change_to = new_screen_to_change;

	// Set anchor of button
	setAnchor(Coord(0,0));

	debug ("ScreenChangeButton: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
ScreenChangeButton::~ScreenChangeButton() {
	debug ("ScreenChangeButton: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							      onClick() 		 						|
// |----------------------------------------------------------------------------|
int ScreenChangeButton::onClick() {
	debug ("ScreenChangeButton: onClick() called.");

	// Change the next screen to this button's target screen
	parent->setNextScreen(change_to);
	parent->setDone(true);

	return error;
}