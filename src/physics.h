#ifndef PHYSICS_H
#define PHYSICS_H

#include "map.h"
#include "player.h"
#include <raylib.h>

#define GRAVITY 450.0f  // Aceleração da Gravidade (pixels/s²)
#define GROUND_Y 576.0f // Posição Y do chão

void applyPhysics(Map *map, Player *player, float dt);

#endif
