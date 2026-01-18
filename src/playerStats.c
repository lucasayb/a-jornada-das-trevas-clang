#include "player.h"
#include "textureLoader.h"
#include <stdio.h>
#include <raylib.h>

void drawPlayerHealthBar(Player *player) {
  const int maxHealth = 165;
  int currentHealth = (maxHealth * player->health) / 100;
  Rectangle healthbarRect = {100, 35, currentHealth, 20};
  Rectangle healthbarBorderRect = {healthbarRect.x, healthbarRect.y, maxHealth,
                                   healthbarRect.height};
  DrawRectangleRec(healthbarRect, GREEN);
  char currentHealthText[20];
  snprintf(currentHealthText, sizeof(currentHealthText), "%i / %i", currentHealth, maxHealth);
  DrawText(currentHealthText, healthbarRect.x, healthbarRect.y + healthbarRect.height + 10, 20, BLACK);

  DrawRectangleLinesEx(healthbarBorderRect, 1, BLACK);
}

void drawPlayerFace() {
  Rectangle textureRectSource = {0, 0, 32, 20};
  Rectangle textureRectDest = {15, 22, 32 * 3, 20 * 3};
  DrawTexturePro(playerTexture, textureRectSource, textureRectDest,
                 (Vector2){0, 0}, 0, WHITE);
}

void drawPlayerStats(Player *player) {
  Rectangle statsRect = {25, 25, 250, 70};
  DrawRectangleLinesEx(statsRect, 2, BLACK);
  drawPlayerHealthBar(player);
  drawPlayerFace();
}
