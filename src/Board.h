#include <stdlib.h>
#include <cmath>

#define EMPTY           0x00 // Bit code for an empty tile
#define COLOUR_BIT      0x01 // Bit to determine colour of movable token tile
#define VIKING_BIT      0x02 // Bit to determine if tile has a movable token
#define KING_BIT        0x04 // Determine if movable token is a king
#define CASTLE_BIT      0x08 // Determine if tile is castle
#define ESCAPE_ZONE_BIT 0x10 // If both the king bit and escape zone bit for a tile are set, the game ends
#define TOKEN_BITS      0x07 // The bits in a tile which describe a token

#define DEFAULT_HEIGHT 11
#define DEFAULT_WIDTH 11
#pragma once

class Board {
private:
  unsigned char** m_Board;
  int m_Height, m_Width;

public:
  Board();
  ~Board();

  unsigned char** getBoard();
  bool moveToken(int x1, int y1, int x2, int y2);
};