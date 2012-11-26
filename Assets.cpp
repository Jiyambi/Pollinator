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
	graphics(NULL) 
{
	debug ("Assets: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Assets::~Assets() { 
	delete graphics; 
	debug ("Assets: object destroyed.");
}
