#include "enemy.h"
#include <raylib.h>

Enemy createEnemy(float x, float y) {
  Enemy enemy = {.health = 100.0f,
                 .isAlive = true,
                 .collided = false,
                 .rect = (Rectangle){x, y, 25, 70}};
  return enemy;
}

void drawEnemy(Enemy *enemy) {
  if (enemy->health > 0) {
    // ENEMY
    DrawRectangleRec(enemy->rect, ORANGE);
  }
}
