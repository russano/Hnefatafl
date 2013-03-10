#include "Point.h"
#pragma once

// The viking is the player's piece
class Viking {
  private:
    Point location;                   // The viking's position on the map

  public:
    Viking();                         // Default constructor for Viking
    Viking(Point location);           // Initialise Viking at point "location"
    Viking(int x, int y);             // Initialise Viking at point (x, y)
    ~Viking();                        // Destructor for Viking

    Point getLocation();              // Get the location data member of the Viking
    void setLocation(Point location); // set the location of the Viking to "location"
    void setLocation(int x, int y);   // Set the location of the Viking to (x, y)
};