// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Game
//		Holds game-wide variables and methods. Holds asset managers, screens,
//		and game-wide logic and draw loops (calls screen-specific loops).
//		Governs game-wide options and switching between screens.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"
#include "Assets.h"
#include "TitleScreen.h"


// |----------------------------------------------------------------------------|
// |						  Class Definition: Game							|
// |----------------------------------------------------------------------------|
class Game {

public:

	Game ();
	// Constructor

	~Game();
	// Destructor

	int run();
	// Sets up the game and begins logic and draw loops.

	int changeScreen(SCREEN next_screen);
	// Sets the current screen to the supplied screen index.
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	// Asset Managers
	Assets assets;

	// Screens
	Screen* current_screen;
	Screen** screens;

	// Allegro Utilities
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* fps_reg;

	// Miscellaneous
	bool redraw;
	bool quit;
	int error;

};