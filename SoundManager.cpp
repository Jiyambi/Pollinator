// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// SoundManager
//		Contains all BITMAP objects to be used throughout the program.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "SoundManager.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
SoundManager::SoundManager () :
	error(0) 
{
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
SoundManager::~SoundManager() {
	// Destroy all sound objects
}

// |----------------------------------------------------------------------------|
// |							      init()									|
// |----------------------------------------------------------------------------|
int SoundManager::init() {

	// Initiallize Allegro Image I/O Addon
	if(!al_install_audio()) {
		debug("SoundManager: failed to install audio.");
		error = -1;
	}

	// Load in sound files
	if (!error)
	{
		// Image code example
		//title_screen = al_load_bitmap("data/title_screen.bmp");
		//if (!title_screen) 
		//{
		//	debug("SoundManager: failed to load data/title_screen.bmp.");
		//	error = -1;
		//}
	}

	if (!error) debug("SoundManager: object initialised.");
	else debug("SoundManager: initialisation failed.");
	return error;
}
