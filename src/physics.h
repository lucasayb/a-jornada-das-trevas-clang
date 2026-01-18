#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include "player.h"
#include "enemy.h"

#define GRAVITY 500.0f // Aceleração da Gravidade (pixels/s²)
#define GROUND_Y 550.0f // Posição Y do chão

void applyPhysics(Player *player, Enemy *enemy, float dt);

#endif
