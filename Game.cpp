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
	timer_queue (NULL),
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
	if (timer_queue) al_destroy_event_queue(timer_queue);\

	debug ("Game: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							      init()									|
// |----------------------------------------------------------------------------|
int Game::init() {

	// FPS Regulator Setup
	if (!error)
	{
		fps_reg = al_create_timer(1.0 / FPS);
		if(!fps_reg) {
			OutputDebugString("Game: failed to create timer.\n");
			error = -1;
		}
	}
 
	// Display Setup
	if (!error)
	{
		al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
		display = al_create_display(SCREEN_W, SCREEN_H);
		if(!display) {
			OutputDebugString("Game: failed to create display.\n");
			error = -1;
		} 
		al_set_target_bitmap(al_get_backbuffer(display));
	}

	// Event Queue Setup
	if (!error)
	{
		timer_queue = al_create_event_queue();
		if(!timer_queue) {
			debug("Game: failed to create timer event queue.");
			error = -1;
		} 
		al_register_event_source(timer_queue, al_get_display_event_source(display));
		al_register_event_source(timer_queue, al_get_timer_event_source(fps_reg));
	}

	// Asset initialisation
	error = error || assets.init();

	// Create screens - set first screen to TITLE
	if (!error)
	{
		screens = new Screen* [NUM_SCREENS];
		for (int i = 0 ; i < NUM_SCREENS; ++i) {
			screens[i] = NULL;
		}
		screens[TITLE] = new TitleScreen(assets);
		screens[MENU] = new MenuScreen(assets);
		current_screen = screens[TITLE];
		error = error || current_screen->onLoad();
	}

	// Input manager initialisation
	if (!error) error = error || input.init(current_screen);
	
	if (!error) debug("Game: object initialised.");
	else debug("Game: initialisation failed.");
	return error;
}

// |----------------------------------------------------------------------------|
// |								 run()										|
// |----------------------------------------------------------------------------|
int Game::run() {

	// Run Loop
	while (!quit) {

		ALLEGRO_EVENT ev;

		// Timer related updates and check if it's time to redraw
		if (!al_event_queue_is_empty(timer_queue))
		{
			al_get_next_event(timer_queue, &ev);

			// Check if the user cloased the window
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				// If so, quit.
				return error;
			}
			// Check if it's time to redraw
			else if (ev.type == ALLEGRO_EVENT_TIMER) {
				redraw = true;
			}
		}

		// Process Input
		error = error || input.update();

		// Game logic (pass in mouse coordinates)
		error = error || current_screen->logic(input.getMouseX(), input.getMouseY());

		// If it's time to redraw and there are no other events waiting 
		if (redraw && input.isEmpty()) {
			// Call the current screen's draw method. 
			error = error || current_screen->draw();
			// Draw the backbuffer to the screen
			al_flip_display();
		}

		// If the current screen is done, switch to the new screen
		if (current_screen->isDone()) {
			debug("Game: current screen done");

			// Check if the screen is telling the game to quit.
			if (current_screen->getNextScreen() == QUIT) {
				debug("Game: quitting");
				// If so, quit.
				return error;
			}

			// If the screen is NOT telling the game to quit, load the next screen
			else {
				debug("Game: moving to next screen");
				// Perform onExit functions for the old screen
				error = error || current_screen->onExit();
				// Set the new screen as current
				current_screen = screens[current_screen->getNextScreen()];
				// Perform onLoad functions for the new screen
				error = error || current_screen->onLoad();
				// Set up input functions
				input.setCurrentScreen(current_screen);
			}

		}

	}

	return error;
}