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
	num_samples(2),
	victory(0),
	meadow(0),
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

	// Initiallise Allegro Image I/O Addon
	if(!al_install_audio()) {
		debug("SoundManager: failed to initialise audio addon.");
		return error = -1;
	}
	if(!al_init_acodec_addon()){
		debug("SoundManager: failed to initialise codec addon.");
		return error = -1;
	}
	
	// Reserve sample instances
	if (!al_reserve_samples(num_samples)){
		debug("SoundManager: failed to reserve samples.");
		return error = -1;
	}

	// Load in sound files
	if (!error)
	{
		victory = al_load_sample("data/sound/music/victory.wav");
		if (!victory) {
			debug("SoundManager: failed to load data/sound/music/victory.wav.");
			error = -1;
		}
		meadow = al_load_sample("data/sound/music/meadow.wav");
		if (!meadow) {
			debug("SoundManager: failed to load data/sound/music/meadow.wav.");
			error = -1;
		}
	}

	if (!error) debug("SoundManager: object initialised.");
	else debug("SoundManager: initialisation failed.");
	return error;
}
