#include "combat.h"
#include "gameState.h"
#include "map.h"
#include "physics.h"
#include "playerStats.h"
#include "raylib.h"
#include <stdio.h>

void updateAndDrawGameplay(Player *player, Enemy *enemies, int enemiesCount,
                           float dt, GameScreen *gameState, Camera2D *camera) {

  if (*gameState != SCREEN_PAUSED) {
    applyPhysics(player, dt);
    updatePlayer(player, dt, camera);
    for (int i = 0; i < enemiesCount; i++) {
      Enemy *enemy = &enemies[i];
      updateEnemy(enemy, dt);
      Combat combat = {.player = player, .enemy = enemy, .stateTimer = 0};
      updateCombat(&combat, dt);
    }
  }

  BeginMode2D(*camera);
  drawMap();
  drawPlayer(player);
  for (int i = 0; i < enemiesCount; i++) {
    drawEnemy(&enemies[i]);
  }
  EndMode2D();
  drawPlayerStats(player);
}
