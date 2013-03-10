// Stores a cartesian coordinate
typedef struct _Point {
  int x, y; // The x, y coordinate of the point

   _Point(): x(0), y(0) {};             // Default constructor for Point
   _Point(int X, int Y): x(X), y(Y) {}; // Initialise point to location (x, y)
} Point;
