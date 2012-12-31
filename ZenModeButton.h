// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ZenModeButton
//		Defines the zen mode button's location, text, image, and function. 
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
// |						 Class Definition: ZenModeButton					|
// |----------------------------------------------------------------------------|
class ZenModeButton : public Button {
	
public:

	ZenModeButton (Assets& assets, Screen* new_parent);
	// Constructor

	~ZenModeButton ();
	// De-constructor

	int virtual onClick();
	// Main function for this button
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Screen* parent;		// Pointer to the parent screen
};
