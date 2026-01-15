#include "player.h"
#include <raylib.h>

Player createPlayer(float x, float y) {
  Player player = {.rect = (Rectangle){x, y, 50, 50},
                   .health = 100.0f,
                   .isAlive = true,
                   .onGround = true,
                   .vy = 0.0f,
                   .jumpSpeed = 650.0f,
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

  if (IsKeyDown(KEY_RIGHT)) {
    player->rect.x += player->speed * dt;
  }

  if (IsKeyDown(KEY_LEFT)) {
    player->rect.x -= player->speed * dt;
  }

  if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) && (player->onGround)) {
    player->vy =
        -player->jumpSpeed; // -650 pixels/segundo (negativo = pra cima)
    player->onGround = false;
  }

  sword->rect.x = player->rect.x + player->rect.width;
  sword->rect.y = player->rect.y - 20;
}

bool checkSwordHitbox(Sword *sword, Enemy *enemy) {
  if (!IsKeyPressed(KEY_F))
    return false;

  // Check collision between sword and enemy
  return CheckCollisionRecs(sword->rect, enemy->rect);
}

void drawPlayer(Player *player, Sword *sword) {
  // PLAYER
  DrawRectangleRec(player->rect, BLUE);
  DrawRectangleRec(sword->rect, GREEN);
}
