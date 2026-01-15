#include "enemy.h"
#include <raylib.h>

Enemy createEnemy(float x, float y) {
  Enemy enemy = {.health = 100.0f,
                 .isAlive = true,
                 .collided = false,
                 .rect = (Rectangle){x, y, 25, 70}};
  return enemy;
}

void drawEnemyHealthBar(Enemy *enemy) {
  DrawRectangle(enemy->rect.x - 15, enemy->rect.y - 30, 55, 10, BLACK);
  DrawRectangle(enemy->rect.x - 11, enemy->rect.y - 27, 49 * enemy->health / 100, 4, RED);
}

void drawEnemy(Enemy *enemy) {
  if (enemy->health > 0) {
    // ENEMY
    DrawRectangleRec(enemy->rect, ORANGE);
    drawEnemyHealthBar(enemy);
  }
}
