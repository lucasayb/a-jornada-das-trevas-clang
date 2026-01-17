#include "enemy.h"
#include "textureLoader.h"
#include <raylib.h>

Enemy createEnemy(float x, float y) {
  Enemy enemy = {
      .health = 100.0f,
      .isAlive = true,
      .collided = false,
      .rect = (Rectangle){x, y, (52 * 2.5), (52 * 2.5)},
      .healthbarRect = (Rectangle){(x + 35), y, 55, 10},
  };
  return enemy;
}

void drawEnemyHealthBar(Enemy *enemy) {
  int healthbar = 53 * enemy->health / 100;
  DrawRectangle(enemy->healthbarRect.x, enemy->healthbarRect.y, 55, 10, BLACK);
  int healthbarX = enemy->healthbarRect.x + 1;
  int healthbarY = enemy->healthbarRect.y + 1;
  DrawRectangle(healthbarX, healthbarY, healthbar, 8, RED);
}

void drawEnemy(Enemy *enemy) {
  if (enemy->health > 0) {
    Vector2 origin = {0, 0};
    Rectangle source = {0, 0, 52, 52};
    DrawTexturePro(enemyTexture, source, enemy->rect, origin, 0, WHITE);
    drawEnemyHealthBar(enemy);
  }
}
