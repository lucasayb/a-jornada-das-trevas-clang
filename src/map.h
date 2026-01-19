#ifndef MAP_H
#define MAP_H
#include "physics.h"
#include <raylib.h>

#define MAP_ROWS 11
#define MAP_COLS 20

typedef enum {
  EMPTY = 0,

  // GRASS
  GTL, GT, GTR,
  GL, GM, GR,
  GBL, GB, GBR,

  // DIRT
  TTL, TT, TTR,
  TL, TM, TR,
  TBL, TB, TBR,

  // ROCKS
  PTL, PT, PTR,
  PL, PM, PR,
  PBL, PB, PBR,

  // FLOATING GRASS
  FGTL,
  FGT,
  FGTR,

  // FLOATING ROCKS
  FRTL,
  FRT,
  FRTR
} TileType;

typedef struct {
  int x;
  int y;
} TileInfo;

void drawTile(int spriteLine, int spriteFrame, int positionX, int positionY);
void drawMap();

#endif
