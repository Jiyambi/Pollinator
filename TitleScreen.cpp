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
	background (NULL),
	music (NULL)
{

	// Set MENU as the next screen after this one
	setNextScreen(MENU); 

	// Loading graphics into Image objects
	background = new Image(assets.graphics.title_screen);

	// Loading music into Sound object
	music = new Sound(assets.audio.victory);

	debug ("TitleScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
TitleScreen::~TitleScreen() {
	delete background;
	debug ("TitleScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int TitleScreen::logic(int mouse_x, int mouse_y) {
	debug ("TitleScreen: logic() called.", 10);

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int TitleScreen::draw() {
	debug ("TitleScreen: draw() called.", 10);

	background->draw();
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int TitleScreen::onLoad() {
	debug ("TitleScreen: onLoad called.");

	music->loop();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int TitleScreen::onExit() {
	debug ("TitleScreen: onExit called.");
	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseDown()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is pressed down
int TitleScreen::onMouseDown(int button) {
	debug ("TitleScreen: onMouseDown called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseUp()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is released
int TitleScreen::onMouseUp(int button) {
	debug ("TitleScreen: onMouseUp called.");
	done = true;
	return error;
}

// |----------------------------------------------------------------------------|
// |							  onKeyDown()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is pressed down
int TitleScreen::onKeyDown(int button) {
	debug ("TitleScreen: onKeyDown called.");
	return error;
}

// |----------------------------------------------------------------------------|
// |							   onKeyUp()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is released
int TitleScreen::onKeyUp(int button) {
	debug ("TitleScreen: onKeyUp called.");

	return error;
}