#include "config.h"
#include "gameState.h"
#include "raygui.h"
#include <raylib.h>

void allowMenuToBePaused(GameScreen *gameState) {
  if (IsKeyPressed(KEY_B)) {
    *gameState = SCREEN_PAUSED;
  }
}

void drawStartMenu(GameScreen *gameState) {
  int windowWidth = 360;
  int windowHeight = 264;
  int buttonHeight = 48;
  int buttonSpacing = 72;
  float startMenuX = (float)(SCREEN_WIDTH - windowWidth) / 2;
  float startMenuY = (float)(SCREEN_HEIGHT - windowHeight) / 2;

  Rectangle continueButtonRect = {
      startMenuX + 24, startMenuY + buttonHeight * 1, 312, buttonHeight};
  Rectangle titleScreenButtonRect = {startMenuX + 24,
                                     startMenuY + buttonHeight + buttonSpacing,
                                     312, buttonHeight};
  Rectangle exitButtonRect = {startMenuX + 24,
                              startMenuY + buttonHeight + buttonSpacing * 2,
                              312, buttonHeight};
  GuiWindowBox((Rectangle){startMenuX, startMenuY, 360, 264}, "Start menu");
  if (GuiButton(continueButtonRect, "Continue")) {
    *gameState = SCREEN_GAMEPLAY;
  }
  if (GuiButton(titleScreenButtonRect, "Back to title screen")) {
    *gameState = SCREEN_TITLE;
  }
  if (GuiButton(exitButtonRect, "Exit")) {
    *gameState = EXITING;
  }
}
