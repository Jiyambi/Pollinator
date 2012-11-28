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
	onMouseDown (NULL),
	onMouseUp (NULL),
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

	// Mouse installation
	if(!al_install_mouse()) {
		debug("Main: failed to initialise the mouse.");
		return -1;
	}
	debug("Main: mouse initialised.");
	
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
			// Process mouse location
			if(mouse_ev.type == ALLEGRO_EVENT_MOUSE_AXES || mouse_ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) 
			{
				 mouse_x = mouse_ev.mouse.x;
				 mouse_y = mouse_ev.mouse.y;
			}
			// Process clicks
			else if(mouse_ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
			{
				// Call appropriate functions, send the pertinent mouse button to called function
				if (onMouseDown) (*onMouseDown) (mouse_ev.mouse.button);
			}
			else if(mouse_ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
			{
				// Call appropriate functions, send the pertinent mouse button to called function
				if (onMouseUp) (*onMouseUp) (mouse_ev.mouse.button);
			}
		}
	}

	// Check for keyboard related events
	if (!al_event_queue_is_empty(keyboard_queue))
	{
		keyboard_error = !al_get_next_event(keyboard_queue, &keyboard_ev);
		if (!keyboard_error)
		{
			// Process keypresses
			if(keyboard_ev.type == ALLEGRO_EVENT_KEY_DOWN) 
			{
				// Call appropriate functions, send the pertinent keycode to called function
				if (onKeyDown) (*onMouseDown) (keyboard_ev.keyboard.keycode);
			}
			else if(mouse_ev.type == ALLEGRO_EVENT_KEY_UP) 
			{
				// Call appropriate functions, send the pertinent keycode to called function
				if (onKeyUp) (*onMouseUp) (keyboard_ev.keyboard.keycode);
			}
		}
	}

	return error;
}

// |----------------------------------------------------------------------------|
// |							     isEmpty()									|
// |----------------------------------------------------------------------------|
bool Input::isEmpty() {
	return al_event_queue_is_empty(keyboard_queue) && al_event_queue_is_empty(mouse_queue);
}

// |----------------------------------------------------------------------------|
// |							   addMouseDown()								|
// |----------------------------------------------------------------------------|
void Input::addMouseDown(void(*callback)(int)){
	onMouseDown = callback;
}

// |----------------------------------------------------------------------------|
// |							   addMouseUp()									|
// |----------------------------------------------------------------------------|
void Input::addMouseUp(void(*callback)(int)){
	onMouseUp = callback;
}

// |----------------------------------------------------------------------------|
// |							   addKeyDown()									|
// |----------------------------------------------------------------------------|
void Input::addKeyDown(void(*callback)(int)){
	onKeyDown = callback;
}

// |----------------------------------------------------------------------------|
// |							    addKeyUp()									|
// |----------------------------------------------------------------------------|
void Input::addKeyUp(void(*callback)(int)){
	onKeyUp = callback;
}