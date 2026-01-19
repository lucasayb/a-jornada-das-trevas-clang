#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include "player.h"

#define GRAVITY 500.0f // Aceleração da Gravidade (pixels/s²)
#define GROUND_Y 576.0f // Posição Y do chão

void applyPhysics(Player *player, float dt);

#endif
