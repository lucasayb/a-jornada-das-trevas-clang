#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

typedef enum {
  PLAYER_IDLE,
  PLAYER_WALKING,
  PLAYER_ATTACK_PREPARE,
  PLAYER_ATTACKING,
  PLAYER_ATTACKED,
  PLAYER_ATTACK_STOP,
  PLAYER_JUMP_PREPARE,
  PLAYER_JUMPING,
  PLAYER_JUMP_LAND
} PlayerState;

typedef struct {
  bool isAlive;
  bool onGround;
  float vy;
  float health;
  float jumpSpeed;
  float speed;
  float invencibleTimer;
  float stateTimer;
  int direction;
  int spriteFrame;
  int spriteLine;
  Rectangle rect;
  Rectangle spriteRect;
  PlayerState state;
} Player;

typedef struct {
  float rotation;
  Rectangle rect;
  bool collided;
} Sword;

Player createPlayer(float x, float y);

Sword createSword(Player *player);

void updatePlayer(Player *player, float dt, Camera2D *camera);

void drawPlayer(Player *player);

#endif
