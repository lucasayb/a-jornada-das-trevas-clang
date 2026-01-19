#include "player.h"
#include "textureLoader.h"
#include <raylib.h>
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
                   .invencibleTimer = 0,
                   .state = PLAYER_IDLE,
                   .stateTimer = 0.0f,
                   .speed = 200.0f};
  return player;
}

void handleJump(Player *player) {
  if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) {
    player->state = PLAYER_JUMP_PREPARE;
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

void handleAttack(Player *player) {
  if (IsKeyDown(KEY_F)) {
    player->spriteLine = 8;
    player->state = PLAYER_ATTACK_PREPARE;
  }
}

void updateCamera(Camera2D *camera, Player *player) {
  float rightLimit = camera->target.x + 100;
  float leftLimit = camera->target.x - 0;
  if (player->rect.x > rightLimit) {
    camera->target.x += player->rect.x - rightLimit;
  } else if (player->rect.x < leftLimit) {
    camera->target.x += player->rect.x - leftLimit;
  }
}

void updatePlayer(Player *player, float dt, Camera2D *camera) {
  switch (player->state) {
  case PLAYER_IDLE:
    player->stateTimer += dt;
    player->spriteFrame = 0;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
      player->state = PLAYER_WALKING;
    }
    handleJump(player);
    handleAttack(player);
    updateCamera(camera, player);
    break;
  case PLAYER_WALKING:
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
      player->state = PLAYER_IDLE;
      player->spriteFrame = 0;
      player->spriteLine = 0;
    }

    handleJump(player);
    handleAttack(player);
    handleWalk(player, dt);
    updateCamera(camera, player);
    break;
  case PLAYER_ATTACKED:
    player->stateTimer += dt;
    player->spriteLine = 1;
    if (player->stateTimer > 0.1f) {
      player->spriteFrame = 1;
      player->stateTimer = 0;
      if (player->spriteFrame == 1) {
        player->state = PLAYER_IDLE;
        player->spriteFrame = 0;
      }
    }
    handleJump(player);
    handleAttack(player);
    handleWalk(player, dt);
    updateCamera(camera, player);
    break;
  case PLAYER_ATTACK_PREPARE:
    player->stateTimer += dt;
    player->spriteFrame = 1;
    if (player->stateTimer >= 0.1f) {
      player->state = PLAYER_ATTACKING;
    }
    updateCamera(camera, player);
    break;
  case PLAYER_ATTACKING:
    player->stateTimer += dt;
    // Check collision between sword and enemy
    if (player->stateTimer >= 0.1f) {
      player->spriteFrame++;
      player->stateTimer = 0;
    }

    if (player->spriteFrame == 7) {
      player->spriteFrame = 0;
      player->spriteLine = 0;
      player->state = PLAYER_IDLE;
    }
    updateCamera(camera, player);
    break;
  case PLAYER_ATTACK_STOP:
    break;
  case PLAYER_JUMP_PREPARE:
    player->stateTimer += dt;
    player->spriteFrame = 1;
    if (player->stateTimer >= 0.1f) {
      player->vy = -player->jumpSpeed;
      player->onGround = false;
      player->state = PLAYER_JUMPING;
    }
    updateCamera(camera, player);
    break;
  case PLAYER_JUMPING:
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
      player->state = PLAYER_JUMP_LAND;
      player->stateTimer = 0;
      player->spriteFrame = 6;
    }
    updateCamera(camera, player);
    handleWalk(player, dt);
    break;
  case PLAYER_JUMP_LAND:
    player->spriteFrame = 7;
    player->state = PLAYER_IDLE;
    updateCamera(camera, player);
    break;
  }
}

void drawPlayer(Player *player) {
  // PLAYER
  Vector2 origin = {0, 0};
  Rectangle spriteRect = {player->spriteFrame * 32, player->spriteLine * 32,
                          32 * player->direction, 32};
  DrawTexturePro(playerTexture, spriteRect, player->rect, origin, 0.0f, WHITE);
}
