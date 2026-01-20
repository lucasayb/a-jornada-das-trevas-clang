#include "camera.h"
#include "config.h"
#include "enemy.h"
#include "game.h"
#include "gameState.h"
#include "infobar.h"
#include "map.h"
#include "physics.h"
#include "player.h"
#include "startMenu.h"
#include "textureLoader.h"
#include "titleScreen.h"
#include <cjson/cJSON.h>
#include <raylib.h>
#include <stdio.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
  SetTargetFPS(FPS);

  bool texturesLoaded = false;
  GameScreen gameState = SCREEN_TITLE;
  Player player;
  Enemy enemy;

  Vector3 enemiesParams[] = {{GetRandomValue(0, 1280), GROUND_Y - 52 * 2.5, 1},
                             {GetRandomValue(0, 1280), GROUND_Y - 52 * 2.5, 1}};

  int enemiesCount = sizeof(enemiesParams) / sizeof(enemiesParams[0]);
  Map map = getFileMap();
  Enemy enemies[enemiesCount];
  Camera2D camera = createCamera();
  camera.target.y = (float)SCREEN_HEIGHT / 2;
  SetExitKey(KEY_NULL);
  while (!WindowShouldClose() && gameState != EXITING) {
    float dt = GetFrameTime();
    if (gameState == SCREEN_TITLE) {
      if (IsKeyPressed(KEY_ENTER)) {
        if (!texturesLoaded) {
          loadGameplayTextures();
          texturesLoaded = true;
        }
        gameState = SCREEN_GAMEPLAY;
        player = createPlayer(100, GROUND_Y - 50);
        for (int i = 0; i < enemiesCount; i++) {
          enemies[i] = createEnemy(enemiesParams[i].x, enemiesParams[i].y,
                                   enemiesParams[i].z);
        }
      }
    }
    BeginDrawing();
    ClearBackground(WHITE);
    SetTextureWrap(backgroundTexture, TEXTURE_WRAP_REPEAT);
    Rectangle backgroundSource = {0, 0, (float) SCREEN_WIDTH / 2, (float) SCREEN_HEIGHT / 2};
    Rectangle backgroundDest = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    DrawTexturePro(backgroundTexture, backgroundSource, backgroundDest,
                   (Vector2){0, 0}, 0, WHITE);
    switch (gameState) {
    case SCREEN_TITLE:
      drawTitleScreen();
      break;
    case SCREEN_PAUSED:
      updateAndDrawGameplay(&player, enemies, enemiesCount, dt, &gameState,
                            &camera, &map);
      drawStartMenu(&gameState);
      break;
    case SCREEN_GAMEPLAY:
      updateAndDrawGameplay(&player, enemies, enemiesCount, dt, &gameState,
                            &camera, &map);
      allowMenuToBePaused(&gameState);
      infobar(&player);
      break;
    case SCREEN_GAMEOVER:
      break;
    case EXITING:
      break;
    }
    EndDrawing();
  }

  unloadGameplayTextures();
  CloseWindow();
  return 0;
}
