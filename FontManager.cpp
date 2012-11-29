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

	}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
FontManager::~FontManager() {
	al_destroy_font(reg);
}

// |----------------------------------------------------------------------------|
// |							     init()										|
// |----------------------------------------------------------------------------|
int FontManager::init() {

	// Initiallize Allegro Font I/O Addon
	al_init_font_addon();
	al_init_ttf_addon();

	// Load in fonts
	reg = al_load_ttf_font("data/sui_generis_rg.ttf",12,0 );
	if (!reg) 
	{
		debug("FontManager: failed to load data/sui_generis_rg.ttf.");
		error = -1;
	}

	if (!error) debug("FontManager: object initialised.");
	else debug("FontManager: initialisation failed.");
	return error;
}
