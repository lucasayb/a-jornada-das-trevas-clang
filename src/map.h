#ifndef MAP_H
#define MAP_H
#include "config.h"
#include <cjson/cJSON.h>
#include <raylib.h>
#define MAP_ROWS 11
#define MAP_COLS 50
#define TILE_SIZE 64
#define LAYERS_COUNT 15
#define TILES_COUNT 1000


typedef struct {
  char id[10];
  int x;
  int y;
} MapLayerTile;

typedef struct {
  char name[60];
  MapLayerTile tiles[TILES_COUNT];
  bool collider;
  int tilesCount;
} MapLayer;

typedef struct {
  int tileSize;
  int mapWidth;
  int mapHeight;
  int layersCount;
  MapLayer layers[LAYERS_COUNT];
  bool collisionGrid[SCREEN_HEIGHT][SCREEN_WIDTH];
} Map;

void drawTile(int spriteLine, int spriteFrame, int positionX, int positionY);
Map getFileMap();
void drawMap(Map *map);
bool isSolid(Map *map, int x, int y);

#endif
