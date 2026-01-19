#include "combat.h"
#include "map.h"
#include "physics.h"
#include "gameState.h"
#include "playerStats.h"


void updateAndDrawGameplay(Player *player, Enemy *enemy, float dt, GameScreen *gameState) {
  if (*gameState != SCREEN_PAUSED) {
    applyPhysics(player, enemy, dt);
    updatePlayer(player, dt);
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
