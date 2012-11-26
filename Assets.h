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

// |----------------------------------------------------------------------------|
// |						  Class Definition: Assets							|
// |----------------------------------------------------------------------------|
class Assets {
	
public:
	Assets();
	// Constructor

	~Assets();
	// Destructor

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ImageManager* graphics;
};