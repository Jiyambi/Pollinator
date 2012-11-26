// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// MenuScreen
//		Controls the image, music, and buttons for the main menu of the game. It 
//		will set up the onClick functions for each of the buttons.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "MenuScreen.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
MenuScreen::MenuScreen(Assets& new_assets) :
	assets(&new_assets),
	background (NULL) {

	// Set next screen to QUIT - it will be updated by the buttons.
	setNextScreen(QUIT);

	// Loading graphics into Image objects
	background = new Image(assets->graphics->menu_screen);
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
MenuScreen::~MenuScreen() {
	delete background;
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int MenuScreen::logic(ALLEGRO_EVENT& ev) {

	// If the button is clicked, pass to the 
	if (ev.type = ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		done = true;

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int MenuScreen::draw() {
	if (background) background->draw();
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int MenuScreen::onLoad() {

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int MenuScreen::onExit() {

	return error;
}