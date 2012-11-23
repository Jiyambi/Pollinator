// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Constants
//		Game-wide constants.

#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
// Allegro 5 
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// |----------------------------------------------------------------------------|
// |								Constants									|
// |----------------------------------------------------------------------------|
const int DEBUG_MODE = 1;
const float FPS = 60;
const int SCREEN_W = 1024;
const int SCREEN_H = 768;

// |----------------------------------------------------------------------------|
// |								enum SCREEN									|
// |----------------------------------------------------------------------------|

enum SCREEN {TITLE, /*MENU, ZEN, TIME, SURVIVAL,*/ NUM_SCREENS, QUIT};
// TODO: ************************************************************************
//	Update the SCREEN enum when new screens are implemented.