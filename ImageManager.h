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

	int init();
	// Sets up image manager.

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_BITMAP* title_screen;
	ALLEGRO_BITMAP* menu_screen;
	ALLEGRO_BITMAP* grass;
	ALLEGRO_BITMAP* flower_blue;
	ALLEGRO_BITMAP* flower_red;
	ALLEGRO_BITMAP* flower_green;
	ALLEGRO_BITMAP* flower_yellow;
	ALLEGRO_BITMAP* flower_gray;
	int error;

};