// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Input
//		Processes input and makes it available to the game.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"


// |----------------------------------------------------------------------------|
// |						  Class Definition: Input							|
// |----------------------------------------------------------------------------|
class Input {

public:

	Input ();
	// Constructor

	~Input();
	// Destructor

	int init();
	// Sets up input manager.

	int update();
	// Updates mouse position, checks event queues.

	bool is_empty();
	// True if the event queues are empty
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int error;
	ALLEGRO_EVENT_QUEUE* keyboard_queue;
	ALLEGRO_EVENT_QUEUE* mouse_queue;

};