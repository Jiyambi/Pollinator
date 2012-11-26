// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// FontManager
//		Contains all ALLEGRO_FONT objects to be used throughout the program.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"

// |----------------------------------------------------------------------------|
// |					   Class Definition: FontManager						|
// |----------------------------------------------------------------------------|
class FontManager {

public:

	FontManager ();
	// Constructor

	~FontManager();
	// Destructor

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_FONT* reg;
	int error;

};