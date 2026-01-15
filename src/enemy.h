#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>

typedef struct {
  Rectangle rect;
  float health;
  bool isAlive;
  bool collided;
} Enemy;

Enemy createEnemy(float x, float y);
void drawEnemy(Enemy *enemy);
void drawEnemyHealthBar(Enemy* enemy);
#endif
