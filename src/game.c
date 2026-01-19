#include "combat.h"
#include "map.h"
#include "physics.h"
#include "gameState.h"
#include "playerStats.h"


void updateAndDrawGameplay(Player *player, Enemy *enemies, float dt, GameScreen *gameState) {
  if (*gameState != SCREEN_PAUSED) {
    applyPhysics(player, dt);
    updatePlayer(player, dt);
    for (int i = 0; i < MAX_ENEMIES; i++) {

    }
    updateEnemy(enemy, dt);
    Combat combat = {
      .player = player,
      .enemy = enemy,
      .stateTimer = 0
    };
    updateCombat(&combat, dt);
  }
  drawMap();
  drawPlayerStats(player);
  drawPlayer(player);
  drawEnemy(enemy);
}
