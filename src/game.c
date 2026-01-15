#include "debug.h"
#include "ground.h"
#include "physics.h"

void createGameplay(Player *player, Sword *sword, Enemy *enemy, float dt) {
  applyPhysics(player, sword, enemy, dt);
  updatePlayer(player, sword, dt);

  drawGround();
  drawPlayer(player, sword);
  drawEnemy(enemy);
  initDebug(player, enemy, sword);
}
