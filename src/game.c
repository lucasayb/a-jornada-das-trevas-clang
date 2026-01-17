#include "debug.h"
#include "ground.h"
#include "physics.h"
#include "startMenu.h"

void createGameplay(Player *player, Enemy *enemy, float dt) {
  applyPhysics(player, enemy, dt);
  updatePlayer(player, enemy, dt);
  drawGround();
  drawPlayer(player);
  drawEnemy(enemy);
  initDebug(player, enemy);
  drawStartMenu();
}
