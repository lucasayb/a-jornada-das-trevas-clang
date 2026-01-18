#include "enemy.h"
#include "config.h"
#include "textureLoader.h"
#include <stdio.h>
#include <raylib.h>

int healthbarX = 35;

Enemy createEnemy(float x, float y, int direction) {
  Enemy enemy = {
      .health = 100.0f,
      .state = ENEMY_WALKING,
      .invencibleTimer = 0,
      .stateTimer = 0.0f,
      .rect = (Rectangle){x, y, (56 * 2.5), (56 * 2.5)},
      .direction = direction,
      .spriteLine = 0,
      .spriteFrame = 0,
      .isAlive = true,
      .healthbarRect = (Rectangle){(x + healthbarX), y, 55, 10},
  };
  return enemy;
}


void drawEnemyHealthBar(Enemy *enemy) {
  int healthbarWidth = 55;
  int healthbar = healthbarWidth * enemy->health / 100;
  int healbarSizeHeight = 10;
  DrawRectangle(enemy->healthbarRect.x, enemy->healthbarRect.y, healthbar, healbarSizeHeight, RED);
  DrawRectangleLines(enemy->healthbarRect.x, enemy->healthbarRect.y, healthbarWidth, healbarSizeHeight, BLACK);
}

void updateEnemy(Enemy *enemy, float dt) {
  if (!enemy->isAlive) return;
  switch (enemy->state) {
  case ENEMY_IDLE:
    enemy->spriteLine = 0;
    enemy->spriteFrame = 0;
    break;
  case ENEMY_ATTACKING:
    enemy->spriteLine = 3;
    enemy->stateTimer += dt;
    if (enemy->stateTimer > 0.2f) {
      enemy->spriteFrame++;
      enemy->stateTimer = 0;
      if (enemy->spriteFrame > 5) {
        enemy->state = ENEMY_WALKING;
      }
    }
    break;
  case ENEMY_WALKING:
    enableMovement(enemy);
    enemy->stateTimer += dt;
    enemy->spriteLine = 1;
    if (enemy->stateTimer > 0.1f) {
      enemy->spriteFrame++;
      if (enemy->spriteFrame > 6) {
        enemy->spriteFrame = 0;
      }
      enemy->stateTimer = 0;
    }
    break;
  case ENEMY_ATTACKED:
    enemy->spriteLine = 0;
    enemy->stateTimer += dt;
    if (enemy->stateTimer > 0.08f) {
      enemy->spriteFrame++;
      if (enemy->spriteFrame > 4) {
        enemy->state = ENEMY_WALKING;
      }
      enemy->stateTimer = 0;
    }
    break;
  case ENEMY_COLLIDED:
    break;
  }
}

void moveEnemy(Enemy *enemy, int pos) {
  enemy->rect.x = enemy->rect.x + pos;
  enemy->healthbarRect.x = enemy->rect.x + healthbarX;
}

void enableMovement(Enemy *enemy) {
  if (enemy->rect.x + enemy->rect.width >= SCREEN_WIDTH) {
    enemy->direction = 1;
  } else if ((enemy->rect.x <= 0)) {
    enemy->direction = -1;
  }
  if (enemy->direction == 1) {
    moveEnemy(enemy, -5);
  } else {
    moveEnemy(enemy, 5);
  }
}

void drawEnemy(Enemy *enemy) {
  if (!enemy->isAlive) return;
  int sourceWidth = 56;
  int sourceHeight = 56;
  Vector2 origin = {0, 0};
  Rectangle source = {sourceWidth * enemy->spriteFrame,
                      sourceHeight * enemy->spriteLine,
                      sourceWidth * enemy->direction, sourceHeight};
  DrawTexturePro(enemyTexture, source, enemy->rect, origin, 0, WHITE);
  drawEnemyHealthBar(enemy);
}
