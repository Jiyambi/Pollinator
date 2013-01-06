// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// SoundManager
//		Contains all sound objects to be used throughout the program.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"

// |----------------------------------------------------------------------------|
// |					  Class Definition: SoundManager						|
// |----------------------------------------------------------------------------|
class SoundManager {

public:

	SoundManager ();
	// Constructor

	~SoundManager();
	// Destructor

	int init();
	// Sets up image manager.

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	// TO ADD: Sound objects
	int error;

};