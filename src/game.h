#ifndef GAME_H
#define GAME_H
#include "enemy.h"
#include "gameState.h"
#include "map.h"
#include "player.h"

void updateAndDrawGameplay(Player *player, Enemy *enemies, int enemiesCount,
                           float dt, GameScreen *gameState, Camera2D *camera,
                           Map *map);
#endif
