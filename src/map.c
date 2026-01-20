#include "map.h"
#include "textureLoader.h"
#include <cjson/cJSON.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isSolid(Map *map, int x, int y) {
  if (x < 0 || x >= map->mapWidth || y < 0 || y >= map->mapHeight) {
    return false;
  }

  if (!map->collisionGrid[y][x]) return false;

  if (y > 0 && map->collisionGrid[y - 1][x]) {
    return false;
  }
  return true;
}

Map getFileMap() {
  FILE *fptr;

  fptr = fopen("./assets/data/levels/phase1.json", "r");

  if (fptr == NULL) {
    printf("Error opening file!\n");
    return (Map){0};
  }

  char buffer[20 * 1024];

  size_t bytesRead = fread(buffer, 1, sizeof(buffer) - 1, fptr);
  buffer[bytesRead] = '\0';

  fclose(fptr);

  Map map = {0};
  cJSON *json = cJSON_Parse(buffer);
  cJSON *width_item = cJSON_GetObjectItem(json, "mapWidth");
  if (cJSON_IsNumber(width_item)) {
    map.mapWidth = width_item->valueint;
  }
  cJSON *height_item = cJSON_GetObjectItem(json, "mapHeight");
  if (cJSON_IsNumber(height_item)) {
    map.mapHeight = height_item->valueint;
  }

  cJSON *tile_size_item = cJSON_GetObjectItem(json, "tileSize");
  if (cJSON_IsNumber(tile_size_item)) {
    map.tileSize = tile_size_item->valueint;
  }

  cJSON *layers_array = cJSON_GetObjectItem(json, "layers");
  if (cJSON_IsArray(layers_array)) {
    map.layersCount = cJSON_GetArraySize(layers_array);
    for (int y = 0; y < cJSON_GetArraySize(layers_array); y++) {
      cJSON *array_item = cJSON_GetArrayItem(layers_array, y);

      cJSON *array_item_name = cJSON_GetObjectItem(array_item, "name");
      if (cJSON_IsString(array_item_name)) {
        strcpy(map.layers[y].name, array_item_name->valuestring);
      }

      cJSON *array_item_collider = cJSON_GetObjectItem(array_item, "collider");
      if (cJSON_IsBool(array_item_collider)) {
        map.layers[y].collider = cJSON_IsTrue(array_item_collider);
      }

      cJSON *array_item_tiles = cJSON_GetObjectItem(array_item, "tiles");
      if (cJSON_IsArray(array_item_tiles)) {
        map.layers[y].tilesCount = cJSON_GetArraySize(array_item_tiles);
        for (int x = 0; x < cJSON_GetArraySize(array_item_tiles); x++) {
          cJSON *array_item_tile = cJSON_GetArrayItem(array_item_tiles, x);

          cJSON *array_item_tile_id =
              cJSON_GetObjectItem(array_item_tile, "id");
          if (cJSON_IsString(array_item_tile_id)) {
            strcpy(map.layers[y].tiles[x].id, array_item_tile_id->valuestring);
          }

          cJSON *array_item_tile_x = cJSON_GetObjectItem(array_item_tile, "x");
          if (cJSON_IsNumber(array_item_tile_x)) {
            map.layers[y].tiles[x].x = array_item_tile_x->valueint;
          }

          cJSON *array_item_tile_y = cJSON_GetObjectItem(array_item_tile, "y");
          if (cJSON_IsNumber(array_item_tile_y)) {
            map.layers[y].tiles[x].y = array_item_tile_y->valueint;
          }
        }
      }
    }

    for (int y = 0; y < map.mapHeight; y++) {
      for (int x = 0; x < map.mapWidth; x++) {
        map.collisionGrid[y][x] = false;
      }
    }

    for (int layer = 0; layer < map.layersCount; layer++) {
      if (map.layers[layer].collider) {
        for (int t = 0; t < map.layers[layer].tilesCount; t++) {
          int tileX = map.layers[layer].tiles[t].x;
          int tileY = map.layers[layer].tiles[t].y;
          map.collisionGrid[tileY][tileX] = true;
        }
      }
    }
  }

  cJSON_Delete(json);
  return map;
}

void drawMap(Map *map) {
  for (int y = map->layersCount; y >= 0; y--) {
    for (int x = 0; x < map->layers[y].tilesCount; x++) {
      MapLayerTile *tile = &map->layers[y].tiles[x];
      int id = atoi(tile->id);
      int spritesheetCols = tilesTexture.width / map->tileSize;
      int spriteX = id % spritesheetCols;
      int spriteY = id / spritesheetCols;
      float scale = 4;
      Rectangle source = {spriteX * map->tileSize, spriteY * map->tileSize,
                          map->tileSize, map->tileSize};
      Rectangle dest = {tile->x * map->tileSize * scale,
                        tile->y * map->tileSize * scale, map->tileSize * scale,
                        map->tileSize * scale};
      DrawTexturePro(tilesTexture, source, dest, (Vector2){0}, 0, WHITE);
    }
  }
}
