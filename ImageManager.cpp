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
#include "ImageManager.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
ImageManager::ImageManager () :
	title_screen(NULL),
	error(0) 
{
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
ImageManager::~ImageManager() {
	// Destroy all bitmaps
	al_destroy_bitmap(title_screen);
	al_destroy_bitmap(menu_screen);
}

// |----------------------------------------------------------------------------|
// |							      init()									|
// |----------------------------------------------------------------------------|
int ImageManager::init() {

	// Initiallize Allegro Image I/O Addon
	if(!al_init_image_addon()) {
		debug("ImageManager: failed to initialize image I/O.");
		error = -1;
	}

	// Load in images
	if (!error)
	{
		title_screen = al_load_bitmap("data/title_screen.bmp");
		if (!title_screen) 
		{
			debug("ImageManager: failed to load data/title_screen.bmp.");
			error = -1;
		}
		menu_screen = al_load_bitmap("data/menu_screen.bmp");
		if (!menu_screen) 
		{
			debug("ImageManager: failed to load data/menu_screen.bmp.");
			error = -1;
		}
	}

	// Shut down the Allegro Image I/O Addon
	al_shutdown_image_addon();

	if (!error) debug("ImageManager: object initialised.");
	else debug("ImageManager: initialisation failed.");
	return error;
}
