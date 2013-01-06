// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Assets
//		Class holding the asset managers.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Assets.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Assets::Assets() :
	error(0)
{
	debug ("Assets: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Assets::~Assets() {
	debug ("Assets: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							      init()									|
// |----------------------------------------------------------------------------|
int Assets::init() {
	error = error || graphics.init();
	error = error || fonts.init();
	error = error || audio.init();
	if (!error) debug("Assets: object initialised.");
	else debug("Assets: initialisation failed.");
	return error;
}
