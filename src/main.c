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
#include <stdatomic.h>
#include <stdio.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
  SetTargetFPS(FPS);

  GameScreen gameState = SCREEN_TITLE;
  Player player;
  Enemy enemy;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    switch (gameState) {
    case SCREEN_TITLE:
      if (IsKeyPressed(KEY_ENTER)) {
        loadGameplayTextures();
        gameState = SCREEN_GAMEPLAY;
        player = createPlayer(100, GROUND_Y - 50);
        enemy = createEnemy(400, GROUND_Y - 42 * 2);
      }
      break;
    case SCREEN_PAUSED:
    case SCREEN_GAMEPLAY:
      break;
    case SCREEN_GAMEOVER:
      break;
    }

    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    switch (gameState) {
    case SCREEN_TITLE:
      drawTitleScreen();
      break;
    case SCREEN_PAUSED:
      drawStartMenu(&gameState);
      break;
    case SCREEN_GAMEPLAY:
      createGameplay(&player, &enemy, dt, &gameState);
      allowMenuToBePaused(&gameState);
      break;
    case SCREEN_GAMEOVER:
      break;
    }
    EndDrawing();
  }

  unloadGameplayTextures();
  CloseWindow();
  return 0;
}
