#include "combat.h"
#include "enemy.h"
#include "player.h"
#include <raylib.h>

void updateCombat(Combat *combat, float dt) {
  if (!combat->enemy->isAlive) return;
  if (combat->enemy->health <= 0) {
    combat->enemy->isAlive = false;
  }
  if (combat->player->invencibleTimer > 0) {
    combat->player->invencibleTimer -= dt;
  }

  if (combat->enemy->invencibleTimer > 0) {
    combat->enemy->invencibleTimer -= dt;
  }

  if (combat->enemy->invencibleTimer <= 0) {
    if (combat->player->state == PLAYER_ATTACKING) {
      if (combat->player->spriteFrame == 3) {
        if (CheckCollisionRecs(combat->enemy->rect, combat->player->rect)) {
          combat->enemy->state = ENEMY_ATTACKED;
          combat->enemy->health -= 20;
          combat->enemy->invencibleTimer = 1.0f;
        }
      }
    }
  }

  if (combat->player->invencibleTimer <= 0) {
    if (CheckCollisionRecs(combat->enemy->rect, combat->player->rect)) {
      if (combat->enemy->spriteFrame == 5) {
        combat->enemy->state = ENEMY_ATTACKING;
        combat->player->state = PLAYER_ATTACKED;
        combat->player->health -= 5;
        combat->player->invencibleTimer = 1.0f;
      }
    }
  }
}
