#ifndef ENEMY_H
#define ENEMY_H

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
void updateEnemy(Enemy *enemy, float dt);
void drawEnemy(Enemy *enemy);
void enableMovement(Enemy *enemy);
void moveEnemy(Enemy *enemy, int pos);

void drawEnemyHealthBar(Enemy *enemy);
#endif
