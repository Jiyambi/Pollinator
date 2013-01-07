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
	menu_screen(NULL),
	grass(NULL),
	bee(NULL),
	flower_blue(NULL),
	flower_red(NULL),
	flower_green(NULL),
	flower_yellow(NULL),
	flower_gray(NULL),
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
	al_destroy_bitmap(grass);
	al_destroy_bitmap(bee);
	al_destroy_bitmap(flower_blue);
	al_destroy_bitmap(flower_red);
	al_destroy_bitmap(flower_green);
	al_destroy_bitmap(flower_yellow);
	al_destroy_bitmap(flower_gray);
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
		flower_blue = al_load_bitmap("data/flower_blue.png");
		if (!flower_blue) 
		{
			debug("ImageManager: failed to load data/flower_blue.png.");
			error = -1;
		}
		flower_red = al_load_bitmap("data/flower_red.png");
		if (!flower_red) 
		{
			debug("ImageManager: failed to load data/flower_red.png.");
			error = -1;
		}
		flower_yellow = al_load_bitmap("data/flower_yellow.png");
		if (!flower_yellow) 
		{
			debug("ImageManager: failed to load data/flower_yellow.png.");
			error = -1;
		}
		flower_green = al_load_bitmap("data/flower_green.png");
		if (!flower_green) 
		{
			debug("ImageManager: failed to load data/flower_green.png.");
			error = -1;
		}
		flower_gray = al_load_bitmap("data/flower_gray.png");
		if (!flower_gray) 
		{
			debug("ImageManager: failed to load data/flower_gray.png.");
			error = -1;
		}
		grass = al_load_bitmap("data/grass.bmp");
		if (!grass) 
		{
			debug("ImageManager: failed to load data/grass.bmp.");
			error = -1;
		}
		bee = al_load_bitmap("data/bee.png");
		if (!bee) 
		{
			debug("ImageManager: failed to load data/bee.bmp.");
			error = -1;
		}
	}

	// Shut down the Allegro Image I/O Addon
	al_shutdown_image_addon();

	if (!error) debug("ImageManager: object initialised.");
	else debug("ImageManager: initialisation failed.");
	return error;
}
