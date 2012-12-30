// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// QuitButton
//		Defines the quit button's location, text, image, and function. 
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
// |						  Class Definition: QuitButton						|
// |----------------------------------------------------------------------------|
class QuitButton : public Button {
	
public:

	QuitButton (Assets& assets, Screen* new_parent);
	// Constructor

	~QuitButton ();
	// De-constructor

	int virtual onClick();
	// Main function for this button
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Screen* parent;		// Pointer to the parent screen
};
