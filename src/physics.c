#include "physics.h"
#include "player.h"
#include <raylib.h>

void applyPhysics(Player *player, float dt) {
  // O player estava parado (vy = 0)
  // Pressiona espaço (vy = -650) <- Velocidade para cima
  // No Raylib (e maioria dos sistemas gráficos), Y cresce pra baixo
  // Y = 0    <- topo da tela
  // Y = 100
  // Y = 200
  // Y = 720  <- fundo da tela

  player->vy += GRAVITY * dt;        // Aumenta a velocidade vertical
  player->rect.y += player->vy * dt; // Aplica a velocidade na posição
  float floorY = GROUND_Y - player->rect.height;
  if (player->rect.y > floorY) {
    player->rect.y = floorY;
    player->vy = 0.0f;
    player->onGround = true;
  }
}
