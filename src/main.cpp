#include <stdio.h>
#include "Board.h"

void printBoard(unsigned char** p) {
  for(int i=0; i<11; i++) {
    for(int j=0; j<11; j++) {
      if(p[i][j] != 0)
        printf("%02X ", p[i][j]);
      else
        printf("%2s ", "");
    }
    printf("\n");
  }
}

int main(int argv, char** argc) {
  Board b;
  unsigned char** p = b.getBoard();
  printBoard(p);
  b.moveToken(5, 5, 1, 10);
  b.moveToken(5, 0, 0, 0);
  b.moveToken(6, 0, 6, 1);
  printBoard(p);
  return 0;
}