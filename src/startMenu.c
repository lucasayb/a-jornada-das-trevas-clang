#include "config.h"
#include "raygui.h"
#include <raylib.h>
void drawStartMenu() {
  bool WindowBox000Active = true;
  bool Button001Pressed = false;
  bool Button002Pressed = false;
  bool Button003Pressed = false;
  int windowWidth = 360;
  float startMenuX = (float)(SCREEN_WIDTH - windowWidth) / 2;

  WindowBox000Active =
      !GuiWindowBox((Rectangle){startMenuX, 264, 360, 264}, "Start menu");
  Button001Pressed =
      GuiButton((Rectangle){startMenuX + 24, 312, 312, 48}, "Continue");
  Button002Pressed =
      GuiButton((Rectangle){startMenuX + 24, 384, 312, 48}, "Restart");
  Button003Pressed =
      GuiButton((Rectangle){startMenuX + 24, 456, 312, 48}, "Exit");
}
