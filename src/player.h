#ifndef PLAYER_H
#define PLAYER_H

#include "enemy.h"
#include <raylib.h>

typedef enum {
  PLAYER_IDLE,
  PLAYER_WALKING,
  PLAYER_ATTACK_PREPARE,
  PLAYER_ATTACKING,
  PLAYER_ATTACK_STOP,
  PLAYER_JUMP_PREPARE,
  PLAYER_JUMPING,
  PLAYER_JUMP_LAND
} PlayerState;

typedef struct {
  Rectangle rect;
  float health;
  bool isAlive;
  bool onGround;
  float vy;
  float jumpSpeed;
  float speed;
  int direction;
  int spriteFrame;
  int spriteLine;
  Rectangle spriteRect;
  PlayerState state;
  float stateTimer;
} Player;

typedef struct {
  float rotation;
  Rectangle rect;
  bool collided;
} Sword;

Player createPlayer(float x, float y);

Sword createSword(Player *player);

void updatePlayer(Player *player, Enemy *enemy, float dt);

bool checkSwordHitbox(Sword *sword, Enemy *enemy);

void drawPlayer(Player *player);

#endif
