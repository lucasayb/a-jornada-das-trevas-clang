#include "player.h"
#include "enemy.h"
#include "textureLoader.h"
#include <raylib.h>
#include <stdatomic.h>
#include <stdio.h>

Player createPlayer(float x, float y) {
  Player player = {.rect = (Rectangle){x, y, 32 * 2.5f, 32 * 2.5f},
                   .health = 100.0f,
                   .isAlive = true,
                   .onGround = true,
                   .vy = 0.0f,
                   .spriteLine = 0,
                   .spriteFrame = 0,
                   .direction = 1,
                   .jumpSpeed = 250.0f,
                   .state = STATE_IDLE,
                   .stateTimer = 0.0f,
                   .speed = 200.0f};
  return player;
}

Sword createSword(Player *player) {
  Sword sword = {.collided = true,
                 .rect = (Rectangle){.x = player->rect.x,
                                     .y = player->rect.y,
                                     .height = 10,
                                     .width = 60},
                 .rotation = 45.0f};

  return sword;
}

void handleJump(Player *player) {
  if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) {
    player->state = STATE_JUMP_PREPARE;
    player->stateTimer = 0;
    player->spriteLine = 5;
  }
}

void handleWalk(Player *player, float dt) {
  if (IsKeyDown(KEY_RIGHT)) {
    player->rect.x += player->speed * dt;
    player->direction = 1;
  }

  if (IsKeyDown(KEY_LEFT)) {
    player->rect.x -= player->speed * dt;
    player->direction = -1;
  }
}

void updatePlayer(Player *player, Sword *sword, float dt) {
  sword->collided = false;

  switch (player->state) {
  case STATE_IDLE:
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
      player->state = STATE_WALKING;
    }
    handleJump(player);
    break;
  case STATE_WALKING:
    player->spriteLine = 3;
    player->stateTimer += dt;

    if (player->stateTimer >= 0.1f) {
      player->stateTimer = 0;
      player->spriteFrame++;
      if (player->spriteFrame > 7) {
        player->spriteFrame = 0;
      }
    }

    if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
      player->state = STATE_IDLE;
      player->spriteFrame = 0;
      player->spriteLine = 0;
    }

    handleJump(player);

    handleWalk(player, dt);
    break;
  case STATE_ATTACKING:
    break;
  case STATE_JUMP_PREPARE:
    player->stateTimer += dt;
    player->spriteFrame = 1;
    if (player->stateTimer >= 0.1f) {
      player->vy = -player->jumpSpeed;
      player->onGround = false;
      player->state = STATE_JUMPING;
    }
    break;
  case STATE_JUMPING:
    player->spriteLine = 5;
    if (player->vy < -100) {
      player->spriteFrame = 2;
    } else if (player->vy < 0) {
      player->spriteFrame = 3;
    } else if (player->vy < 100) {
      player->spriteFrame = 4;
    } else {
      player->spriteFrame = 5;
    }

    if (player->onGround) {
      player->state = STATE_JUMP_LAND;
      player->stateTimer = 0;
      player->spriteFrame = 6;
    }
    handleWalk(player, dt);
    break;
  case STATE_JUMP_LAND:
    player->spriteFrame = 7;
    player->state = STATE_IDLE;
    break;
  }
}

bool checkSwordHitbox(Sword *sword, Enemy *enemy) {
  if (!IsKeyPressed(KEY_F))
    return false;

  // Check collision between sword and enemy
  return CheckCollisionRecs(sword->rect, enemy->rect);
}

void drawPlayer(Player *player, Sword *sword) {
  // PLAYER
  Vector2 origin = {0, 0};
  Rectangle spriteRect = {player->spriteFrame * 32, player->spriteLine * 32,
                          32 * player->direction, 32};
  DrawTexturePro(playerTexture, spriteRect, player->rect, origin, 0.0f, WHITE);
}
