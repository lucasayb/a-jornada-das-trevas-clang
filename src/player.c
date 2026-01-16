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
                   .spriteRect = {0, 0, 32, 32},
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

void updatePlayer(Player *player, Sword *sword, float dt) {
  sword->collided = false;

  switch (player->state) {
  case STATE_IDLE:
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
      player->state = STATE_WALKING;
    }
    // JUMPING
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) {
      player->state = STATE_JUMP_PREPARE;
      player->stateTimer = 0;
      player->spriteRect.x = 0 * 32;
      player->spriteRect.y = 5 * 32;
    }
    break;
  case STATE_WALKING:
    // JUMPING
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) {
      player->state = STATE_JUMP_PREPARE;
      player->stateTimer = 0;
      player->spriteRect.x = 0 * 32;
    }

    if (IsKeyDown(KEY_RIGHT)) {
      player->rect.x += player->speed * dt;
    }

    if (IsKeyDown(KEY_LEFT)) {
      player->rect.x -= player->speed * dt;
    }
    break;
  case STATE_ATTACKING:
    break;
  case STATE_JUMP_PREPARE:
    player->stateTimer += dt;
    player->spriteRect.x = 1 * 32;
    player->spriteRect.y = 5 * 32;
    if (player->stateTimer >= 0.1f) {
      player->vy = -player->jumpSpeed;
      player->onGround = false;
      player->state = STATE_JUMPING;
    }
    break;
  case STATE_JUMPING:
    if (player->vy < -100) {
      player->spriteRect.x = 2 * 32;
    } else if (player->vy < 0) {
      player->spriteRect.x = 3 * 32;
    } else if (player->vy < 100) {
      player->spriteRect.x = 4 * 32;
    } else {
      player->spriteRect.x = 5 * 32;
    }

    if (player->onGround) {
      player->state = STATE_JUMP_LAND;
      player->stateTimer = 0;
      player->spriteRect.x = 0 * 32;
    }
    if (IsKeyDown(KEY_RIGHT)) {
      player->rect.x += player->speed * dt;
    }

    if (IsKeyDown(KEY_LEFT)) {
      player->rect.x -= player->speed * dt;
    }
    break;
  case STATE_JUMP_LAND:
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
  DrawTexturePro(playerTexture, player->spriteRect, player->rect, origin, 0.0f,
                 WHITE);
  // DrawRectangleRec(player->rect, BLUE);
  DrawRectangleRec(sword->rect, GREEN);
}
