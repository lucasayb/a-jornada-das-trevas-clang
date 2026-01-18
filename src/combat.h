#ifndef COMBAT_H
#define COMBAT_H

#include "enemy.h"
#include "player.h"

typedef struct {
  Enemy *enemy;
  Player *player;
  float stateTimer;
} Combat;

void updateCombat(Combat *combat, float dt);

#endif
