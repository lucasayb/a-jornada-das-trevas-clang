#ifndef GAME_H
#define GAME_H
#include "enemy.h"
#include "gameState.h"
#include "player.h"

void createGameplay(Player *player, Enemy *enemy, float dt, GameScreen *gameState);
#endif
