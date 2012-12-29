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
#include "Constants.h"
#include "Screen.h"
#include "Assets.h"
#include "Image.h"
#include "Button.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: TitleScreen						|
// |----------------------------------------------------------------------------|
class MenuScreen : public Screen {

public:

	MenuScreen (Assets& assets);
	// Constructor

	~MenuScreen();
	// Destructor

	int virtual logic(int mouse_x, int mouse_y);
	// The logic function, which will be called by the main game loop.

	int virtual draw();
	// The draw function, which will be called by the main game loop.

	int virtual onLoad();
	// Called when the screen is loaded.

	int virtual onExit();
	// Called when switching to a different screen

	// Input functions
	int onMouseDown(int button);
	int onMouseUp(int button);
	int onKeyDown(int button);
	int onKeyUp(int button);
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Image* background;
	//Button button_adventure;
	//Button button_zen;
	//Button button_time;
	//Button button_survival;
	//Button button_score;
	//Button button_options;
	//Button button_exit;
	//music
};