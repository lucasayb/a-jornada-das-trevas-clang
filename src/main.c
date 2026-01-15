#include "config.h"
#include "debug.h"
#include "ground.h"
#include "physics.h"
#include "player.h"
#include "enemy.h"
#include <raylib.h>
#include <stdatomic.h>
#include <stdio.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
  SetTargetFPS(FPS);

  Player player = createPlayer(100, GROUND_Y - 50);
  Sword sword = createSword(&player);
  Enemy enemy = createEnemy(400, GROUND_Y - 70);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    ClearBackground(WHITE);
    BeginDrawing();
    applyPhysics(&player, &sword, &enemy, dt);
    updatePlayer(&player, &sword, dt);

    drawGround();
    drawPlayer(&player, &sword);
    drawEnemy(&enemy);
    initDebug(&player, &enemy, &sword);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
