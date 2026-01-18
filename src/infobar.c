#include "config.h"
#include <raylib.h>
#include <stdio.h>

void infobar() {
  int fontSize = 24;
  int infobarSize = 50;
  char infotext[255];

  snprintf(infotext, sizeof(infotext), "ESC - Pause Menu\t\tF - Attack");
  DrawRectangle(0, SCREEN_HEIGHT - infobarSize, SCREEN_WIDTH, infobarSize,
                BLACK);
  DrawText(infotext, 15, SCREEN_HEIGHT - infobarSize + fontSize / 2, fontSize,
           WHITE);
}
