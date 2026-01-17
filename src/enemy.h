#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>

typedef enum { ENEMY_IDLE, ENEMY_ATTACKED, ENEMY_COLLIDED } EnemyState;

typedef struct {
  Rectangle rect;
  Rectangle healthbarRect;
  EnemyState state;
  float stateTimer;
  float health;
  int direction;
  int spriteLine;
  int spriteFrame;
} Enemy;

Enemy createEnemy(float x, float y);
void updateEnemy(Enemy *enemy, float dt);
void drawEnemy(Enemy *enemy);
void drawEnemyHealthBar(Enemy *enemy);
#endif
