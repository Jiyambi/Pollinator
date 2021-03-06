// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Assets
//		Class holding the asset managers.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "SoundManager.h"


// |----------------------------------------------------------------------------|
// |						  Class Definition: Assets							|
// |----------------------------------------------------------------------------|
class Assets {
	
public:
	Assets();
	// Constructor

	~Assets();
	// Destructor

	int init();
	// Sets up assets.

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ImageManager graphics;
	FontManager fonts;
	SoundManager audio;
	int error;
};