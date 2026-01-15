#include "titleScreen.h"
#include "config.h"
#include <raylib.h>

void drawTitle() {
  const char *text = "A Jaqueta das Trevas";
  int fontSize = 60;
  int textSize = MeasureText(text, fontSize);
  DrawText(text, (SCREEN_WIDTH - textSize) / 2, SCREEN_HEIGHT / 2 - 100,
           fontSize, BLACK);
}

void drawInstruction() {
  const char *text = "Press enter to start";
  int fontSize = 32;
  int textSize = MeasureText(text, fontSize);
  DrawText(text, (SCREEN_WIDTH - textSize) / 2, SCREEN_HEIGHT / 2 - 20,
           fontSize, BLACK);
}

void drawTitleScreen() {
  drawTitle();
  drawInstruction();
}
