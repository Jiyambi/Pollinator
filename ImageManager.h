// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ImageManager
//		Contains all BITMAP objects to be used throughout the program.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"

// |----------------------------------------------------------------------------|
// |					  Class Definition: ImageManager						|
// |----------------------------------------------------------------------------|
class ImageManager {

public:

	ImageManager ();
	// Constructor

	~ImageManager();
	// Destructor

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_BITMAP* title_screen;
	ALLEGRO_BITMAP* menu_screen;
	int error;

};