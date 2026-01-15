#include <raylib.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
    SetTargetFPS(60);

    Color playerColor = { 125, 125, 5, 255 };

    while (!WindowShouldClose()) {
      ClearBackground(WHITE);
      BeginDrawing();
        DrawRectangle(100, 100, 30, 30, playerColor);
      EndDrawing();
    }

  CloseWindow();
  return 0;
}
