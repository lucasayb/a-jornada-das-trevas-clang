#include "config.h"
#include "enemy.h"
#include "player.h"
#include <raylib.h>
#include <stdio.h>

void initDebug(Player *player, Enemy *enemy, Sword *sword) {

  // DEBUG SECTION
  char debugText[255];
  int fontSize = 16;
  int textWidth = MeasureText(debugText, fontSize);
  int debugBoxHeight = 50;

  snprintf(debugText, sizeof(debugText), "vy = %f\t\
    onGround = %i\t\
    player.y = %f\t\
    enemy1.collided = %i\t\
    sword.collided = %i\t\
    enemy1.health = %f",
           player->vy, player->onGround, player->rect.y, enemy->collided,
           sword->collided, enemy->health);
  DrawRectangle(0, SCREEN_HEIGHT - debugBoxHeight, SCREEN_WIDTH, debugBoxHeight,
                BLACK);
  DrawText(debugText, 20, SCREEN_HEIGHT - debugBoxHeight / 2 - fontSize,
           fontSize, WHITE);
}
