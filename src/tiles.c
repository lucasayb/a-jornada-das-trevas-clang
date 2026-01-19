#include "tiles.h"
#include "raylib.h"
#include "textureLoader.h"

void drawTile(int spriteLine, int spriteFrame, int positionX, int positionY) {
  Rectangle source = {
      64 * spriteLine,
      64 * spriteFrame,
      64,
      64,
  };

  // Rectangle dest = {64 * positionX, 64 * positionY, 64, 64};
  Rectangle dest = {positionX, positionY, 64, 64};

  Vector2 origin = {0, 0};

  DrawTexturePro(tilesTexture, source, dest, origin, 0, WHITE);
}
