#include "map.h"
#include <raylib.h>
#include "textureLoader.h"

TileInfo tileTable[] = {
  [GTL]     = {0, 0},
  [GT]      = {1, 0},
  [GTR]     = {2, 0},
  [GL]      = {0, 1},
  [GM]      = {1, 1},
  [GR]      = {2, 1},
  [GBL]     = {0, 2},
  [GB]      = {1, 2},
  [GBR]     = {2, 2},
  [TTL]     = {3, 0},
  [TT]      = {4, 0},
  [TTR]     = {5, 0},
  [TL]      = {3, 1},
  [TM]      = {4, 1},
  [TR]      = {5, 1},
  [TBL]     = {3, 2},
  [TB]      = {4, 2},
  [TBR]     = {5, 2},
  [PTL]     = {6, 0},
  [PT]      = {7, 0},
  [PTR]     = {8, 0},
  [PL]      = {6, 1},
  [PM]      = {7, 1},
  [PR]      = {8, 1},
  [PBL]     = {6, 2},
  [PB]      = {7, 2},
  [PBR]     = {8, 2},
  [FGTL]    = {6, 3},
  [FGT]     = {7, 3},
  [FGTR]    = {8, 3},
  [FRTL]    = {6, 4},
  [FRT]     = {7, 4},
  [FRTR]    = {8, 4}
};

int map[MAP_ROWS][MAP_COLS] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FGTL, FGT, FGTR, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, 0, 0, GT, GT, GT, GT, GT, GT, GT },
  { GM, GM, GM, GM, GM, GM, GM, GM, GM, GM, GM, 0, 0, GM, GM, GM, GM, GM, GM, GM }
};

void drawTile(int spriteLine, int spriteFrame, int positionX, int positionY) {
  Rectangle source = {
      64 * spriteLine,
      64 * spriteFrame,
      64,
      64,
  };

  Rectangle dest = {64 * positionX, 64 * positionY, 64, 64};
  // Rectangle dest = {positionX, positionY, 64, 64};

  Vector2 origin = {0, 0};

  DrawTexturePro(tilesTexture, source, dest, origin, 0, WHITE);
}


void drawMap() {
  // GROUND
  // DrawRectangle(-6000, GROUND_Y, 18000, 330, GRAY);

  for (int y = 0; y < MAP_ROWS; y++) {
    for (int x = 0; x < MAP_COLS; x++) {
      if (map[y][x] != 0) {
        drawTile(tileTable[map[y][x]].x, tileTable[map[y][x]].y, x, y);
      }
    }
  }

  // for (int x = 0; x < SCREEN_WIDTH / 64; x++) {
  //   drawTile(1, 0, x * 64, GROUND_Y);
  //   drawTile(1, 1, x * 64, GROUND_Y + 64);
  // }
}
