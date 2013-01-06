// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Sound
//		Contains a sound sample and it's data. It can play the sound, loop it, 
//		and stop it.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Coord.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: Sound							|
// |----------------------------------------------------------------------------|
class Sound {

public:

	Sound ();
	// Default constructor

	Sound (ALLEGRO_SAMPLE* new_sample);
	// Constructor

	void virtual play();
	// Plays the sound ONCE;

	void virtual loop();
	// Plays the sound ON LOOP;

	void virtual stop();
	// stops the sound;

	void virtual stop_all();
	// stops all sounds;

	// Setters
	void virtual setGain(float new_gain) { gain = new_gain; }
	void virtual setPan(float new_pan) { pan = new_pan; }
	void virtual setSpeed(float new_speed) { speed = new_speed; }
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_SAMPLE* sample;			// Pointer to sample (NOT managed by the sound, instead managed by sound manager)
	ALLEGRO_SAMPLE_ID id;			// Identifies the sample being played so it can be stopped
	float gain;						// relative volume of the sample (1.0 is normal)
	float pan;						// location of the sound (0 centered, -1 left, 1 right)
	float speed;						// relative speed the sample is played at (1.0 normal)
};