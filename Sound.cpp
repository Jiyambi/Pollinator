// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Sound
//		Contains a sound sample and it's data. It can play the sound, loop it, 
//		and stop it.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Sound.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Sound::Sound() : 
	sample(0),
	gain(1),
	pan(0),
	speed(1)
	{}

Sound::Sound(ALLEGRO_SAMPLE* new_sample) : 
	sample(new_sample),
	gain(1),
	pan(0),
	speed(1) 
	{}
	
// |----------------------------------------------------------------------------|
// |							     play()										|
// |----------------------------------------------------------------------------|
void Sound::play() {
	if (sample) {
		al_play_sample(sample, gain, pan, speed,ALLEGRO_PLAYMODE_ONCE,&id);
	}
}

// |----------------------------------------------------------------------------|
// |							     loop()										|
// |----------------------------------------------------------------------------|
void Sound::loop() {
	if (sample) {
		al_play_sample(sample, gain, pan, speed,ALLEGRO_PLAYMODE_LOOP,&id);
	}
}

// |----------------------------------------------------------------------------|
// |							     stop()										|
// |----------------------------------------------------------------------------|
void Sound::stop() {
	if (sample) {
		al_stop_sample(&id);
	}
}

// |----------------------------------------------------------------------------|
// |							  stop_all()									|
// |----------------------------------------------------------------------------|
void Sound::stop_all() {
	al_stop_samples();
}