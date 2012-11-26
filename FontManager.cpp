// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// FontManager
//		Contains all ALLEGRO_FONT objects to be used throughout the program.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "FontManager.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
FontManager::FontManager () :
	reg(NULL),
	error(0) {

	// Initiallize Allegro Font I/O Addon
	al_init_font_addon();
	al_init_ttf_addon();

	// Load in images
	reg = al_load_ttf_font("data\\sui_generis_rg.ttf",12,0 );

	if (!reg) error = 1;

	}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
FontManager::~FontManager() {
	al_destroy_font(reg);
}
