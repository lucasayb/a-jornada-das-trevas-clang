#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include "player.h"

#define GRAVITY 1800.0f // Aceleração da Gravidade (pixels/s²)
#define GROUND_Y 390.0f // Posição Y do chão

void applyPhysics(Player *player, Sword *sword, Enemy *enemy, float dt);

#endif
