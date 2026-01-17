#include "config.h"
#include "enemy.h"
#include "game.h"
#include "gameState.h"
#include "physics.h"
#include "player.h"
#include "startMenu.h"
#include "textureLoader.h"
#include "titleScreen.h"
#include <raylib.h>
#include <stdio.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
  SetTargetFPS(FPS);

  bool texturesLoaded = false;
  GameScreen gameState = SCREEN_TITLE;
  Player player;
  Enemy enemy;

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
        enemy = createEnemy(400, GROUND_Y - 52 * 2.5);
      }
    }
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    switch (gameState) {
    case SCREEN_TITLE:
      drawTitleScreen();
      break;
    case SCREEN_PAUSED:
      updateAndDrawGameplay(&player, &enemy, dt, &gameState);
      drawStartMenu(&gameState);
      break;
    case SCREEN_GAMEPLAY:
      updateAndDrawGameplay(&player, &enemy, dt, &gameState);
      allowMenuToBePaused(&gameState);
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
