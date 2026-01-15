#include "player.h"
#include "enemy.h"
#include "textureLoader.h"
#include <raylib.h>

Player createPlayer(float x, float y) {
  Player player = {.rect = (Rectangle){x, y, 32 * 2.5f, 32 * 2.5f},
                   .health = 100.0f,
                   .isAlive = true,
                   .onGround = true,
                   .vy = 0.0f,
                   .spriteRect = { 0, 0, 32, 32 },
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
    player->spriteRect.x = 32;
    player->rect.x += player->speed * dt;
  }

  if (IsKeyDown(KEY_LEFT)) {
    player->rect.x -= player->speed * dt;
  }

  if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) && (player->onGround)) {
    player->vy = -player->jumpSpeed; // -650 pixels/segundo (negativo = pra cima)
    player->onGround = false;
  }

  if (player->onGround) {
    player->spriteRect.x = 0 * 32;
    player->spriteRect.y = 0 * 32;
  } else {
    player->spriteRect.x = (unsigned int)((player->vy * -1) / 100) * 32;
    player->spriteRect.y = 5 * 32; // Essa é a linha de pulos. Não muda
  }

  sword->rect.x = player->rect.x + player->rect.width;
  sword->rect.y = player->rect.y + 10;
}

bool checkSwordHitbox(Sword *sword, Enemy *enemy) {
  if (!IsKeyPressed(KEY_F))
    return false;


  // Check collision between sword and enemy
  return CheckCollisionRecs(sword->rect, enemy->rect);
}

void drawPlayer(Player *player, Sword *sword) {
  // PLAYER
  Vector2 origin = { 0, 0 };
  DrawTexturePro(playerTexture, player->spriteRect, player->rect, origin, 0.0f, WHITE);
  // DrawRectangleRec(player->rect, BLUE);
  DrawRectangleRec(sword->rect, GREEN);
}
