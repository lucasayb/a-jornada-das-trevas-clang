#include "combat.h"
#include "gameState.h"
#include "map.h"
#include "physics.h"
#include "playerStats.h"
#include <stdio.h>

void updateAndDrawGameplay(Player *player, Enemy *enemies, int enemiesCount, float dt, GameScreen *gameState) {
  if (*gameState != SCREEN_PAUSED) {
    applyPhysics(player, dt);
    updatePlayer(player, dt);
    for (int i = 0; i < enemiesCount; i++) {
      Enemy *enemy = &enemies[i];
      updateEnemy(enemy, dt);
      Combat combat = {.player = player, .enemy = enemy, .stateTimer = 0};
      updateCombat(&combat, dt);
    }
  }
  drawMap();
  drawPlayerStats(player);
  drawPlayer(player);
  for (int i = 0; i < enemiesCount; i++) {
    drawEnemy(&enemies[i]);
  }
}
