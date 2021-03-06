// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Button
//		Defines a button's location, text, image, and function. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Coord.h"
#include "Image.h"
#include "Sound.h"
#include "Assets.h"
#include "Text.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: Button							|
// |----------------------------------------------------------------------------|
class Button {

public:

	Button ();
	// Default constructor

	~Button ();
	// De-constructor

	int virtual draw();
	// Draws the object to the active bitmap

	int virtual logic(int mouse_x, int mouse_y);
	// Performs logic functions for the object
	
	// Input functions
	int virtual onMouseDown(int button);
	int virtual onMouseUp(int button);
	int virtual onKeyDown(int button);
	int virtual onKeyUp(int button);

	int virtual onClick() = 0;
	// Main function for this button
	// TO BE IMPLEMENTED BY SUB CLASS

	// Setter functions
	void virtual setAnchor(Coord new_anchor);
	void virtual setEnabled(bool new_enabled) { enabled = new_enabled; }
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Text* text;						// Text that the image will display

	Sound* click_sound;					// Click sound for the button

	Image* image_normal;			// Pointer to image for this button
	Image* image_selected;			// Pointer to selected image for this button
	Image* image_pressed;			// Pointer to pressed image for this button
	Image* image_disabled;			// Pointer to disabled image for this button

    Coord anchor;					// Location on the screen (of upper left corner)
    Coord size;						// Width and height of the button

	bool enabled;					// True if the button is enabled, false if disabled
	bool pressed;					// True if the button is pressed, false if not
	bool selected;					// True if the button is selected, false if not
	bool mouse_down;				// True if mouse is down, false if not.

	int error;

};