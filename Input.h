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

	// Callback Editors
	void addMouseDown(void(*callback)(int));
	void addMouseUp(void(*callback)(int));
	void addKeyDown(void(*callback)(int));
	void addKeyUp(void(*callback)(int));
	void clearCallbacks();
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Event Queues
	ALLEGRO_EVENT_QUEUE* keyboard_queue;
	ALLEGRO_EVENT_QUEUE* mouse_queue;

	// Mouse Coordinates
	int mouse_x;
	int mouse_y;

	// Callback Functions
	void (*onMouseDown)(int);
	void (*onMouseUp)(int);
	void (*onKeyDown)(int);
	void (*onKeyUp)(int);

	// Error
	int error;

};