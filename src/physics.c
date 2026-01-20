#include "physics.h"
#include "map.h"
#include "player.h"
#include <raylib.h>

void applyPhysics(Map *map, Player *player, float dt) {
  // O player estava parado (vy = 0)
  // Pressiona espaço (vy = -650) <- Velocidade para cima
  // No Raylib (e maioria dos sistemas gráficos), Y cresce pra baixo
  // Y = 0    <- topo da tela
  // Y = 100
  // Y = 200
  // Y = 720  <- fundo da tela

  player->vy += GRAVITY * dt; // Aumenta a velocidade vertical

  int tileX = (player->rect.x + player->rect.width / 2) / TILE_SIZE;
  float nextY = player->rect.y + player->vy * dt;
  int futureTileY = (nextY + player->rect.height) / TILE_SIZE;

  if (isSolid(map, tileX, futureTileY) && player->vy > 0) {
    player->rect.y = futureTileY * TILE_SIZE - player->rect.height;
    player->vy = 0.0f;
    player->onGround = true;
  } else {
    player->rect.y = nextY;
    player->onGround = false;
  }
}
