#include "enemy.h"
#include "textureLoader.h"
#include <raylib.h>

Enemy createEnemy(float x, float y) {
  Enemy enemy = {
      .health = 100.0f,
      .isAlive = true,
      .collided = false,
      .rect = (Rectangle){x, y, (42 * 2), 42 * 2},
      .healthbarRect = (Rectangle){(x + 21), y - 15, 55, 10},
  };
  return enemy;
}

void drawEnemyHealthBar(Enemy *enemy) {
  DrawRectangle(enemy->healthbarRect.x, enemy->healthbarRect.y, 55, 10, BLACK);
  DrawRectangle(enemy->healthbarRect.x + 1, enemy->healthbarRect.y + 1, 53 * enemy->health / 100, 8, RED);
}

void drawEnemy(Enemy *enemy) {
  if (enemy->health > 0) {
    // ENEMY
    // DrawRectangleRec(enemy->rect, ORANGE);
    Vector2 origin = {0, 0};
    Rectangle source = {0, 0, 42, 42};
    DrawTexturePro(enemyTexture, source, enemy->rect, origin, 0, WHITE);
    drawEnemyHealthBar(enemy);
  }
}
