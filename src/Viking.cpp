#include "Viking.h"

// Default constructor for Viking class
Viking::Viking() {
  this->location.x = 0;
  this->location.y = 0;
}

// Initialise Viking at point "location"
Viking::Viking(Point location) {
  this->location.x = location.x;
  this->location.y = location.y;
}

// Initialise Viking at point (x, y)
Viking::Viking(int x, int y) {
  this->location.x = x;
  this->location.y = y;
}

// Destructor for the Viking class
Viking::~Viking() {
  // Does nothing
}

// returns the location of the Viking
Point Viking::getLocation() {
  return this->location;
}

// Set the location of the Viking to point "location"
void Viking::setLocation(Point location) {
  this->location.x = location.x;
  this->location.y = location.y;
}

// Set the location of the Viking to point (x, y)
void Viking::setLocation(int x, int y) {
  this->location.x = x;
  this->location.y = y;
}