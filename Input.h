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
#include "Screen.h"

// |----------------------------------------------------------------------------|
// |							Mouse Input Flags								|
// |----------------------------------------------------------------------------|
#define MOUSE_L		0x01
#define MOUSE_L_NEW	0x02
#define MOUSE_LS	(MOUSE_L | MOUSE_L_NEW)
#define MOUSE_R		0x04
#define MOUSE_R_NEW	0x08
#define MOUSE_RS	(MOUSE_R | MOUSE_R_NEW)
#define MOUSE_M		0x10
#define MOUSE_M_NEW	0x20
#define MOUSE_MS	(MOUSE_M | MOUSE_M_NEW)

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

	bool isEmpty();
	// True if the event queues are empty

	void setCurrentScreen(Screen* new_screen) { current_screen = new_screen; }
	// Set the current screen, for mouse and keyboard callbacks

	int getMouseX() {return mouse_x; }
	int getMouseY() {return mouse_y; }
	// Get functions for mouse coordinates

	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Event Queues
	ALLEGRO_EVENT_QUEUE* keyboard_queue;
	ALLEGRO_EVENT_QUEUE* mouse_queue;

	// Mouse Coordinates
	int mouse_x;
	int mouse_y;

	// Current Screen
	Screen* current_screen;

	// Error
	int error;

};