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
MenuScreen::MenuScreen(Assets& assets) :
	background (NULL) {

	// Set next screen to QUIT - it will be updated by the buttons.
	setNextScreen(QUIT);

	// Loading graphics into Image objects
	background = new Image(assets.graphics.menu_screen);

	debug ("MenuScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
MenuScreen::~MenuScreen() {
	delete background;
	debug ("MenuScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int MenuScreen::logic(int mouse_x, int mouse_y) {
	debug ("MenuScreen: logic() called.", 10);

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int MenuScreen::draw() {
	debug ("MenuScreen: draw() called.", 10);
	if (background) background->draw();
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int MenuScreen::onLoad() {
	debug("MenuScreen: onLoad called");
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int MenuScreen::onExit() {
	debug ("MenuScreen: onExit called.");
	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseDown()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is pressed down
int MenuScreen::onMouseDown(int button) {
	debug ("MenuScreen: onMouseDown called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseUp()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is released
int MenuScreen::onMouseUp(int button) {
	debug ("MenuScreen: onMouseUp called.");
	done = true;
	return error;
}

// |----------------------------------------------------------------------------|
// |							  onKeyDown()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is pressed down
int MenuScreen::onKeyDown(int button) {
	debug ("MenuScreen: onKeyDown called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							   onKeyUp()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is released
int MenuScreen::onKeyUp(int button) {
	debug ("MenuScreen: onKeyUp called.");

	return error;
}