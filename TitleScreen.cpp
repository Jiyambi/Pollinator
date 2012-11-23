// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// TitleScreen
//		Contains all objects pertaining to the title screen. Manages the
//		logic and draw loops for that screen.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "TitleScreen.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
TitleScreen::TitleScreen(Assets& new_assets) :
	progress (0),
	total (100),
	title_screen (NULL),
	background (NULL) {

	// Set MENU as the next screen after this one
	setNextScreen(QUIT); 
	// TODO: *******************************************************************
	//	Change QUIT to MENU when menu screen is implemented.

	// Initiallize Allegro Image I/O Addon
	if(!al_init_image_addon()) {
		OutputDebugString("TitleScreen: failed to initialize image I/O.\n");
		error = -1; setNextScreen(QUIT); done = true; return;
	}

	// Load in images to be used on the title screen
	title_screen = al_load_bitmap("data\\title_screen.bmp");
	if (!title_screen) {
		OutputDebugString("TitleScreen: failed to load title.bmp.\n");
		error = -1; setNextScreen(QUIT); done = true; return;
	}

	// Shut down the Allegro Image I/O Addon
	al_shutdown_image_addon();

	// Loading graphics into Image objects
	background = new Image(title_screen);
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
TitleScreen::~TitleScreen() {
	al_destroy_bitmap(title_screen);
	delete background;
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int TitleScreen::logic(ALLEGRO_EVENT& ev) {
	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int TitleScreen::draw() {
	background->draw();
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int TitleScreen::onLoad() {

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int TitleScreen::onExit() {
	

	return error;
}