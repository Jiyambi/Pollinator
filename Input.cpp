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
#include "Input.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Input::Input() : 
	keyboard_queue (NULL), 
	mouse_queue (NULL), 
	error(0)
{

	debug ("Input: object instantiated.");
}
	
// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Input::~Input() {
	
	// Allegro Cleanup
	if (keyboard_queue) al_destroy_event_queue(keyboard_queue);
	if (mouse_queue) al_destroy_event_queue(mouse_queue);

	debug ("Input: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							      init()									|
// |----------------------------------------------------------------------------|
int Input::init() {
	
	// Event Queue Setup
	keyboard_queue = al_create_event_queue();
	if(!keyboard_queue) {
		debug("Input: failed to create keyboard event queue.");
		error = -1;
	} 
	mouse_queue = al_create_event_queue();
	if(!mouse_queue) {
		debug("Input: failed to create mouse event queue.");
		error = -1;
	}
	al_register_event_source(mouse_queue, al_get_mouse_event_source());

	if (!error) debug("Input: object initialised.");
	return error;
}

// |----------------------------------------------------------------------------|
// |							      update()									|
// |----------------------------------------------------------------------------|
int Input::update() {

	ALLEGRO_EVENT mouse_ev, keyboard_ev;
	bool mouse_error(false), keyboard_error(false);

	// Check for mouse related events
	if (!al_event_queue_is_empty(mouse_queue))
	{
		mouse_error = !al_get_next_event(mouse_queue, &mouse_ev);
		if (!mouse_error)
		{
			// TODO: Process the event
		}
	}

	// Check for keyboard related events
	if (!al_event_queue_is_empty(keyboard_queue))
	{
		keyboard_error = !al_get_next_event(keyboard_queue, &keyboard_ev);
		if (!keyboard_error)
		{
			// TODO: Process the event
		}
	}

	return error;
}

// |----------------------------------------------------------------------------|
// |							     is_empty()									|
// |----------------------------------------------------------------------------|
bool Input::is_empty() {
	return al_event_queue_is_empty(keyboard_queue) && al_event_queue_is_empty(mouse_queue);
}