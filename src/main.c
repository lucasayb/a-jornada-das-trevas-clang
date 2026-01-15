#include "config.h"

#include "enemy.h"
#include "game.h"
#include "gameState.h"
#include "physics.h"
#include "player.h"
#include "titleScreen.h"
#include <raylib.h>
#include <stdatomic.h>
#include <stdio.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
  SetTargetFPS(FPS);

  GameScreen currentScreen = SCREEN_TITLE;
  Player player = createPlayer(100, GROUND_Y - 50);
  Sword sword = createSword(&player);
  Enemy enemy = createEnemy(400, GROUND_Y - 70);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    switch (currentScreen) {
    case SCREEN_TITLE:
      drawTitleScreen();
      if (IsKeyPressed(KEY_ENTER)) {
        currentScreen = SCREEN_GAMEPLAY;
      }
      break;
    case SCREEN_GAMEPLAY:
      break;
    case SCREEN_GAMEOVER:
      break;
    }

    ClearBackground(WHITE);

    BeginDrawing();
    switch (currentScreen) {
    case SCREEN_TITLE:

      break;
    case SCREEN_GAMEPLAY:
      createGameplay(&player, &sword, &enemy, dt);
      break;
    case SCREEN_GAMEOVER:

      break;
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
