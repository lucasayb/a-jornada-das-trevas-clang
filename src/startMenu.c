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
  bool Button001Pressed = false;
  bool Button002Pressed = false;
  bool Button003Pressed = false;
  int windowWidth = 360;
  int windowHeight = 264;
  int buttonHeight = 48;
  int buttonSpacing = 72;
  float startMenuX = (float)(SCREEN_WIDTH - windowWidth) / 2;
  float startMenuY = (float)(SCREEN_HEIGHT - windowHeight) / 2;

  Rectangle continueButton = {startMenuX + 24, startMenuY + buttonHeight * 1,
                              312, buttonHeight};
  Rectangle restartButton = {startMenuX + 24,
                             startMenuY + buttonHeight + buttonSpacing, 312,
                             buttonHeight};
  Rectangle exitButton = {startMenuX + 24,
                          startMenuY + buttonHeight + buttonSpacing * 2, 312,
                          buttonHeight};
  WindowBox000Active = !GuiWindowBox((Rectangle){startMenuX, startMenuY, 360, 264}, "Start menu");
  Button001Pressed = GuiButton(continueButton, "Continue");
  Button002Pressed = GuiButton(restartButton, "Restart");
  Button003Pressed = GuiButton(exitButton, "Exit");
  if (Button003Pressed) {
    *gameState = SCREEN_TITLE;
  }
}
