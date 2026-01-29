#include "enemy.h"
#include "config.h"
#include "map.h"
#include "textureLoader.h"
#include <stdio.h>
#include <raylib.h>
#include <math.h>

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

void updateEnemy(Map *map, Enemy *enemy, float dt, float targetX) {
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
    enableMovement(map, enemy, targetX);
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

void enableMovement(Map *map, Enemy *enemy, float targetX) {
  int enemyTileX = (enemy->rect.x + enemy->rect.width / 2) / TILE_SIZE;
  int enemyTileY = (enemy->rect.y + enemy->rect.height) / TILE_SIZE;
  // int enemyLimitLeft = enemyTileX - ;
  // int enemyLimitRight = enemyTileX + GetRandomValue(1, 5);

  float dx = targetX - enemy->rect.x;

  printf("Dx:");
  printf("%f\n", dx);

  if (dx > 0) {
    // Inimigo está a direita
    enemy->direction = -1;

  } else {
    // Inimigo está a esquerda
    enemy->direction = 1;
  }


  // Pego o valor absoluto. Assim eu sei a distäncia sem me importar se é positiva o negativa.
  float distance = fabsf(dx);


  if (distance < 50) {
    // perto o suficiente. Idle e attack
    enemy->state = ENEMY_ATTACKING;
  } else {
    // longe: continua perseguindo
    moveEnemy(enemy, dx > 0 ? 5 : -5);
    enemy->state = ENEMY_WALKING;
  }

  /* if (enemy->rect.x + enemy->rect.width >= targetX) { */
  /*   moveEnemy(enemy, -5); */
  /* } else { */
  /*   moveEnemy(enemy, 5); */
  /* } */

  if (!isSolid(map, enemyTileX, enemyTileY)) {
    enemy->rect.y += 10;
    enemy->healthbarRect.y += 10;
  }

  /* if (enemy->direction == 1) { */
  /*   moveEnemy(enemy, -5); */
  /* } else { */
  /*   moveEnemy(enemy, 5); */
  /* } */
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
