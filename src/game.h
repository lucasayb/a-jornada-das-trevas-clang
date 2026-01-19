#ifndef GAME_H
#define GAME_H
#include "enemy.h"
#include "player.h"
#include "gameState.h"

void updateAndDrawGameplay(Player *player, Enemy *enemies, int enemiesCount, float dt, GameScreen *gameState);
#endif
