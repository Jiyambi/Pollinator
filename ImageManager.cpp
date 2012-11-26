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

	// Initiallize Allegro Image I/O Addon
	if(!al_init_image_addon()) {
		debug("ImageManager: failed to initialize image I/O.");
		error = -1;
	}

	// Load in images
	title_screen = al_load_bitmap("data/title_screen.bmp");
	menu_screen = al_load_bitmap("data/menu_screen.bmp");

	// Shut down the Allegro Image I/O Addon
	al_shutdown_image_addon();
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
ImageManager::~ImageManager() {
	// Destroy all bitmaps
	al_destroy_bitmap(title_screen);
	al_destroy_bitmap(menu_screen);
}
