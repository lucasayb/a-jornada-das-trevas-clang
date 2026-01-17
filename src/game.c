#include "debug.h"
#include "ground.h"
#include "physics.h"
#include "gameState.h"


void updateAndDrawGameplay(Player *player, Enemy *enemy, float dt, GameScreen *gameState) {
  if (*gameState != SCREEN_PAUSED) {
    applyPhysics(player, enemy, dt);
    updatePlayer(player, enemy, dt);
    updateEnemy(enemy, dt);
  }
  drawGround();
  drawPlayer(player);
  drawEnemy(enemy);
  initDebug(player, enemy);
}
