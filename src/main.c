#include "config.h"
#include "enemy.h"
#include "game.h"
#include "gameState.h"
#include "physics.h"
#include "player.h"
#include "textureLoader.h"
#include "titleScreen.h"
#include <raylib.h>
#include <stdatomic.h>
#include <stdio.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
  SetTargetFPS(FPS);

  GameScreen currentScreen = SCREEN_TITLE;
  Player player = createPlayer(100, GROUND_Y - 50);
  Enemy enemy = createEnemy(400, GROUND_Y - 42 * 2);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    switch (currentScreen) {
    case SCREEN_TITLE:
      if (IsKeyPressed(KEY_ENTER)) {
        loadGameplayTextures();
        currentScreen = SCREEN_GAMEPLAY;
      }
      break;
    case SCREEN_GAMEPLAY:
      break;
    case SCREEN_GAMEOVER:
      break;
    }

    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    switch (currentScreen) {
    case SCREEN_TITLE:
      drawTitleScreen();
      break;
    case SCREEN_GAMEPLAY:
      createGameplay(&player, &enemy, dt);
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
