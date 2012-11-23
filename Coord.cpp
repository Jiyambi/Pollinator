// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Coord
//		Coord is a coordinate set (x and y) which measures the position of 
//		something on the screen. The data members for this class will be 
//		public.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Coord.h"

// |----------------------------------------------------------------------------|
// |						   Operator Overloading								|
// |----------------------------------------------------------------------------|
Coord Coord::operator+(Coord& rhs) {
	Coord result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	return result;
}

Coord Coord::operator+(int& rhs) {
	Coord result;
	result.x = x + rhs;
	result.y = y + rhs;
	return result;
}

Coord Coord::operator+(float& rhs) {
	Coord result;
	result.x = x + rhs;
	result.y = y + rhs;
	return result;
}

Coord Coord::operator+=(Coord& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Coord Coord::operator+=(int& rhs) {
	x += x;
	y += y;
	return *this;
}

Coord Coord::operator+=(float& rhs){
	x += x;
	y += y;
	return *this;
}

Coord Coord::operator-(Coord& rhs) {
	Coord result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	return result;
}

Coord Coord::operator-(int& rhs) {
	Coord result;
	result.x = x - rhs;
	result.y = y - rhs;
	return result;
}

Coord Coord::operator-(float& rhs) {
	Coord result;
	result.x = x - rhs;
	result.y = y - rhs;
	return result;
}

Coord Coord::operator-=(Coord& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Coord Coord::operator-=(int& rhs) {
	x -= x;
	y -= y;
	return *this;
}

Coord Coord::operator-=(float& rhs){
	x -= x;
	y -= y;
	return *this;
}

Coord Coord::operator*(int& rhs) {
	Coord result;
	result.x = x * rhs;
	result.y = y * rhs;
	return result;
}

Coord Coord::operator*(float& rhs) {
	Coord result;
	result.x = x * rhs;
	result.y = y * rhs;
	return result;
}

Coord Coord::operator*=(int& rhs) {
	x *= x;
	y *= y;
	return *this;
}

Coord Coord::operator*=(float& rhs){
	x *= x;
	y *= y;
	return *this;
}

Coord Coord::operator/(int& rhs) {
	Coord result;
	result.x = x / rhs;
	result.y = y / rhs;
	return result;
}

Coord Coord::operator/(float& rhs) {
	Coord result;
	result.x = x / rhs;
	result.y = y / rhs;
	return result;
}

Coord Coord::operator/=(int& rhs) {
	x /= x;
	y /= y;
	return *this;
}

Coord Coord::operator/=(float& rhs){
	x /= x;
	y /= y;
	return *this;
}

Coord Coord::operator=(Coord& rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
	}
	return *this;
}

Coord Coord::operator=(int& rhs) {
	x = rhs;
	y = rhs;
	return *this;
}

Coord Coord::operator=(float& rhs) {
	x = rhs;
	y = rhs;
	return *this;
}