// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ScreenChangeButton
//		Defines the screen change button's location, text, image, and function. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"
#include "Button.h"
#include "Assets.h"
#include "Screen.h"

// |----------------------------------------------------------------------------|
// |					Class Definition: ScreenChangeButton					|
// |----------------------------------------------------------------------------|
class ScreenChangeButton : public Button {
	
public:

	ScreenChangeButton (Assets& assets, Screen* new_parent, SCREEN new_screen_to_change, string new_text);
	// Constructor

	~ScreenChangeButton ();
	// De-constructor

	int virtual onClick();
	// Main function for this button
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Screen* parent;		// Pointer to the parent screen
	SCREEN change_to;	// Screen to change to
};
