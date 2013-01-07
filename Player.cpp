// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Player
//		Controls the player object's position, movement, image, and actions. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Player.h"
#include <cmath>

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Player::Player(Assets& assets) :
	target(0,0),
	has_target(false),
	speed(0.1),
	mouse_position(0,0)
{
	
	// Loading graphics into Image objects
	graphic = new Image(assets.graphics.bee);

	// Set location
	setPosition(Coord(SCREEN_W/2,SCREEN_H/2));

	// Set dimmensions
	radius = 32;

	debug ("Player: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Player::~Player() {
	debug ("Player: instance destroyed.");
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Player::logic(int mouse_x, int mouse_y) {
	debug ("Player: logic() called.", 10);

	// Record mouse location
	mouse_position = Coord(mouse_x, mouse_y);

	// Move based on velocity
	if(has_target) {
		Coord new_position = Coord(position+velocity);

		// Keep player in screen
		if (new_position.x+radius > SCREEN_W) new_position.x = SCREEN_W - radius;
		if (new_position.y+radius > SCREEN_H) new_position.y = SCREEN_H - radius;
		if (new_position.x-radius < 0) new_position.x = radius;
		if (new_position.y-radius < 0) new_position.y = radius;

		// See if we've reached destination
		if (abs(target.x - position.x) < abs(velocity.x)) new_position.x = target.x;
		if (abs(target.y - position.y) < abs(velocity.y)) new_position.y = target.y;
		if (target.x == new_position.x && target.y == new_position.y) has_target = false;

		setPosition(new_position);
	}

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onMouseDown()								|
// |----------------------------------------------------------------------------|
int Player::onMouseDown(int button) {
	debug ("Player: onMouseDown() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							     onMouseUp()								|
// |----------------------------------------------------------------------------|
int Player::onMouseUp(int button) {
	debug ("Player: onMouseUp() called.");

	has_target = true;
	target = mouse_position;

	// Set velocity to move towards mouse
	// Get direction from target and position
	velocity = target - position;
	// Normalize to a magnitude of 1
	double magnitude = sqrt(pow(velocity.x,2)+pow(velocity.y,2));
	velocity /= magnitude;
	// Scale by speed
	velocity *= speed;

	return error;
}