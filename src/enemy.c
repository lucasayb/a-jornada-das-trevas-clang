#include "enemy.h"
#include "textureLoader.h"
#include <raylib.h>

Enemy createEnemy(float x, float y) {
  Enemy enemy = {
      .health = 100.0f,
      .state = ENEMY_IDLE,
      .stateTimer = 0.0f,
      .rect = (Rectangle){x, y, (56 * 2.5), (56 * 2.5)},
      .direction = 1,
      .spriteLine = 0,
      .spriteFrame = 0,
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

void updateEnemy(Enemy *enemy, float dt) {
  switch (enemy->state) {
  case ENEMY_IDLE:
    enemy->spriteLine = 0;
    enemy->spriteFrame = 0;
    break;

  case ENEMY_ATTACKED:
    enemy->spriteLine = 0;
    enemy->stateTimer += dt;
    if (enemy->stateTimer > 0.08f) {
      enemy->spriteFrame++;
      if (enemy->spriteFrame > 4) {
        enemy->health -= 2;
        enemy->state = ENEMY_IDLE;
      }
      enemy->stateTimer = 0;
    }
    break;

  case ENEMY_COLLIDED:
    break;
  }
}

void drawEnemy(Enemy *enemy) {
  if (enemy->health > 0) {
    int sourceWidth = 56;
    int sourceHeight = 56;
    Vector2 origin = {0, 0};
    Rectangle source = {sourceWidth * enemy->spriteFrame,
                        sourceHeight * enemy->spriteLine,
                        sourceWidth * enemy->direction, sourceHeight};
    DrawTexturePro(enemyTexture, source, enemy->rect, origin, 0, WHITE);
    drawEnemyHealthBar(enemy);
  }
}
