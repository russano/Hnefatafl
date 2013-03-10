#include "Board.h"
#include <stdio.h>

Board::Board() {
  m_Height = DEFAULT_HEIGHT;
  m_Width = DEFAULT_WIDTH;

  m_Board = (unsigned char**) malloc(sizeof(char*) * m_Height);
  for(int i=0; i<m_Height; i++) {
    m_Board[i] = (unsigned char*) malloc(sizeof(char) * m_Width);
    for (int j=0; j<m_Width; j++) {
      m_Board[i][j] = EMPTY;
    }
  }

  int midWidth = m_Width/2;
  int midHeight = m_Height/2;

  for(int i=midWidth-2; i<=midWidth+2; i++) {
    m_Board[0][i] = VIKING_BIT & ~COLOUR_BIT;
    m_Board[m_Height-1][i] = VIKING_BIT & ~COLOUR_BIT;
  }
  
  for(int i=midHeight-2; i<=midHeight+2; i++) {
    m_Board[i][0] = VIKING_BIT & ~COLOUR_BIT;
    m_Board[i][m_Width-1] = VIKING_BIT & ~COLOUR_BIT;
  }

  for(int i=midHeight-2; i<=midHeight+2; i++) {
    int buffer = 2-abs(midHeight-i);
    for(int j=midWidth-buffer; j<=midWidth+buffer; j++) {
      m_Board[i][j] = VIKING_BIT | COLOUR_BIT;
    }
  }

  m_Board[0][0] = CASTLE_BIT | ESCAPE_ZONE_BIT;
  m_Board[m_Height-1][0] = CASTLE_BIT | ESCAPE_ZONE_BIT;
  m_Board[0][m_Width-1] = CASTLE_BIT | ESCAPE_ZONE_BIT;
  m_Board[m_Height-1][m_Width-1] = CASTLE_BIT | ESCAPE_ZONE_BIT;

  m_Board[1][midWidth] = VIKING_BIT & ~COLOUR_BIT;
  m_Board[m_Height-2][midWidth] = VIKING_BIT & ~COLOUR_BIT;
  m_Board[midHeight][1] = VIKING_BIT & ~COLOUR_BIT;
  m_Board[midHeight][m_Width-2] = VIKING_BIT & ~COLOUR_BIT;
  m_Board[midHeight][midWidth] = CASTLE_BIT | KING_BIT | VIKING_BIT | COLOUR_BIT;  
}

Board::~Board() {
  for(int i=0; i<m_Height; i++) {
      free(m_Board[i]);
  }
  free(m_Board);
}

unsigned char** Board::getBoard() {
  return m_Board;
}

bool Board::moveToken(int x1, int y1, int x2, int y2) {
  // Check that there is a token to move from this location
  unsigned char token = m_Board[y1][x1] & TOKEN_BITS;

  // Check if target tile is already occupied
  unsigned char target = m_Board[y2][x2] & TOKEN_BITS;

  // Check if token has permission to be on this tile
  int isKing = (token & KING_BIT) != 0;
  int isCastle = (m_Board[y2][x2] & CASTLE_BIT) != 0;
  int permitted = (isKing || !isCastle);
  
  // If the move is valid, then move the piece
  if(token && !target && permitted)  {
    m_Board[y1][x1] &= ~TOKEN_BITS;
    m_Board[y2][x2] |= token;
    return true;
  }

  return false;
}