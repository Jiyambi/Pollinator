// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Game
//		Holds game-wide variables and methods. Holds asset managers, screens,
//		and game-wide logic and draw loops (calls screen-specific loops).

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Game.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Game::Game() :
	// Initiallization List
	display(NULL), 
	queue (NULL), 
	fps_reg (NULL), 
	redraw (true),
	quit(false),
	error(0),
	current_screen(NULL),
	screens(NULL) 
{
	debug ("Game: object instantiated.");
}
	
// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Game::~Game() {

	// Screen Cleanup
	if (screens) {
		for (int i = 0 ; i < NUM_SCREENS; ++i) {
			delete screens[i];
		}
		delete screens;
	}

	// Allegro Cleanup
	if (fps_reg) al_destroy_timer(fps_reg);
	if (display) al_destroy_display(display);
	if (queue) al_destroy_event_queue(queue);

	debug ("Game: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							  initialize()									|
// |----------------------------------------------------------------------------|
int Game::init() {

	// FPS Regulator Setup
	fps_reg = al_create_timer(1.0 / FPS);
	if(!fps_reg) {
		OutputDebugString("Game: failed to create timer.\n");
		error = -1;
	}
 
	// Display Setup
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		OutputDebugString("Game: failed to create display.\n");
		error = -1;
	} 
	al_set_target_bitmap(al_get_backbuffer(display));

	// Event Queue Setup
	queue = al_create_event_queue();
	if(!queue) {
		OutputDebugString("Game: failed to create event_queue.\n");
		al_destroy_display(display);
		error = -1;
	} 
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(fps_reg));
	al_register_event_source(queue, al_get_mouse_event_source());

	// Create screens - set first screen to TITLE
	screens = new Screen* [NUM_SCREENS];
	for (int i = 0 ; i < NUM_SCREENS; ++i) {
		screens[i] = NULL;
	}
	screens[TITLE] = new TitleScreen(assets);
	current_screen = screens[TITLE];

	return error;
}

// |----------------------------------------------------------------------------|
// |								 run()										|
// |----------------------------------------------------------------------------|
int Game::run() {
	

	// Run Loop
	while (!quit) {

		// Wait for an event to fire
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		// Check if the user cloased the window
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			// If so, quit.
			return error;
		}
		// Check if it's time to redraw
		else if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		// If it's some other event...
		else {
			// ...call the current game's logic method.
			error = error || current_screen->logic(ev);
		}

		// If it's time to redraw and there are no other events waiting 
		if (redraw && al_is_event_queue_empty(queue)) {
			// Call the current screen's draw method. 
			error = error || current_screen->draw();
			// Draw the backbuffer to the screen
			al_flip_display();
		}

		// If the current screen is done, switch to the new screen
		if (current_screen->isDone()) {

			// Check if the screen is telling the game to quit.
			if (current_screen->getNextScreen() == QUIT) {
				// If so, quit.
				return error;
			}

			// If the screen is NOT telling the game to quit, load the next screen
			else {
				// Perform onExit functions for the old screen
				error = error || current_screen->onExit();
				// Set the new screen as current
				current_screen = screens[current_screen->getNextScreen()];
				// Perform onLoad functions for the new screen
				error = error || current_screen->onLoad();
			}

		}

	}

	return error;
}