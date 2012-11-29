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
TitleScreen::TitleScreen(Assets& assets) :
	progress (0),
	total (100),
	background (NULL) {

	// Set MENU as the next screen after this one
	setNextScreen(QUIT); 
	// TODO: *******************************************************************
	//	Change QUIT to MENU when menu screen is implemented.

	// Loading graphics into Image objects
	background = new Image(assets.graphics.title_screen);
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
TitleScreen::~TitleScreen() {
	delete background;
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int TitleScreen::logic(int mouse_x, int mouse_y) {

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

// |----------------------------------------------------------------------------|
// |							  onMouseDown()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is pressed down
int TitleScreen::onMouseDown(int button) {

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseUp()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is released
int TitleScreen::onMouseUp(int button) {

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onKeyDown()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is pressed down
int TitleScreen::onKeyDown(int button) {

	return error;
}

// |----------------------------------------------------------------------------|
// |							   onKeyUp()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is released
int TitleScreen::onKeyUp(int button) {

	return error;
}