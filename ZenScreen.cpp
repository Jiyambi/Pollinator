// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ZenScreen
//		Contains all objects pertaining to the zen mode. Manages the
//		logic and draw loops for that screen.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "ZenScreen.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
ZenScreen::ZenScreen(Assets& assets) :
	background (NULL),
	music (NULL)
{

	// Set QUIT as the next screen after this one
	setNextScreen(QUIT); 

	// Loading graphics into Image objects
	background = new Image(assets.graphics.grass);

	// Loading music into Sound object
	music = new Sound(assets.audio.meadow);

	debug ("ZenScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
ZenScreen::~ZenScreen() {
	delete background;
	debug ("ZenScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int ZenScreen::logic(int mouse_x, int mouse_y) {
	debug ("ZenScreen: logic() called.", 10);

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int ZenScreen::draw() {
	debug ("ZenScreen: draw() called.", 10);

	if (background) background->draw();
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int ZenScreen::onLoad() {
	debug ("ZenScreen: onLoad called.");
	
	if (music) music->loop();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int ZenScreen::onExit() {
	debug ("ZenScreen: onExit called.");

	if (music) music->stop();

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseDown()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is pressed down
int ZenScreen::onMouseDown(int button) {
	debug ("ZenScreen: onMouseDown called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseUp()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is released
int ZenScreen::onMouseUp(int button) {
	debug ("ZenScreen: onMouseUp called.");
	done = true;
	return error;
}

// |----------------------------------------------------------------------------|
// |							  onKeyDown()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is pressed down
int ZenScreen::onKeyDown(int button) {
	debug ("ZenScreen: onKeyDown called.");
	return error;
}

// |----------------------------------------------------------------------------|
// |							   onKeyUp()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is released
int ZenScreen::onKeyUp(int button) {
	debug ("ZenScreen: onKeyUp called.");

	return error;
}