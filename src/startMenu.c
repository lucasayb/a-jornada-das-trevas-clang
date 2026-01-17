#include "config.h"
#include "raygui.h"
#include "gameState.h"
#include <raylib.h>

void allowMenuToBePaused(GameScreen *gameState) {
  if (IsKeyPressed(KEY_B)) {
    *gameState = SCREEN_PAUSED;
  }
}

void drawStartMenu(GameScreen *gameState) {
  bool WindowBox000Active = true;
  bool continueButtonPressed = false;
  bool titleScreenButtonPressed = false;
  bool exitButtonPressed = false;
  int windowWidth = 360;
  int windowHeight = 264;
  int buttonHeight = 48;
  int buttonSpacing = 72;
  float startMenuX = (float)(SCREEN_WIDTH - windowWidth) / 2;
  float startMenuY = (float)(SCREEN_HEIGHT - windowHeight) / 2;

  Rectangle continueButtonRect = {startMenuX + 24, startMenuY + buttonHeight * 1,
                              312, buttonHeight};
  Rectangle titleScreenButtonRect = {startMenuX + 24,
                             startMenuY + buttonHeight + buttonSpacing, 312,
                             buttonHeight};
  Rectangle exitButtonRect = {startMenuX + 24,
                          startMenuY + buttonHeight + buttonSpacing * 2, 312,
                          buttonHeight};
  GuiWindowBox((Rectangle){startMenuX, startMenuY, 360, 264}, "Start menu");
  continueButtonPressed = GuiButton(continueButtonRect, "Continue");
  if (continueButtonPressed) {
    *gameState = SCREEN_GAMEPLAY;
  }
  titleScreenButtonPressed = GuiButton(titleScreenButtonRect, "Back to title screen");
  if (titleScreenButtonPressed) {
    *gameState = SCREEN_TITLE;
  }
  exitButtonPressed = GuiButton(exitButtonRect, "Exit");
  if (exitButtonPressed) {
    *gameState = EXITING;
  }
}
