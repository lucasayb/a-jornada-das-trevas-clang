#ifndef PLAYER_H
#define PLAYER_H

#include "enemy.h"
#include <raylib.h>

typedef struct {
  Rectangle rect;
  float health;
  bool isAlive;
  bool onGround;
  float vy;
  float jumpSpeed;
  float speed;
} Player;

typedef struct {
  float rotation;
  Rectangle rect;
  bool collided;
} Sword;

Player createPlayer(float x, float y);

Sword createSword(Player *player);

void updatePlayer(Player *player, Sword *sword, float dt);

bool checkSwordHitbox(Sword *sword, Enemy *enemy);

void drawPlayer(Player* player, Sword* sword);

#endif
