#ifndef ENEMY_H
#define ENEMY_H

#include "map.h"
#include <raylib.h>

typedef enum {
  ENEMY_IDLE,
  ENEMY_WALKING,
  ENEMY_ATTACKED,
  ENEMY_ATTACKING,
  ENEMY_COLLIDED
} EnemyState;

typedef struct {
  Rectangle rect;
  Rectangle healthbarRect;
  EnemyState state;
  float invencibleTimer;
  float stateTimer;
  float health;
  int direction;
  int spriteLine;
  int spriteFrame;
  bool isAlive;
} Enemy;

Enemy createEnemy(float x, float y, int direction);
void updateEnemy(Map *map, Enemy *enemy, float dt, float targetX);
void drawEnemy(Enemy *enemy);
void enableMovement(Map *map, Enemy *enemy, float targetX);
void moveEnemy(Enemy *enemy, int pos);

void drawEnemyHealthBar(Enemy *enemy);
#endif
