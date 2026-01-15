#include <raylib.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_STEPS 5

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
    SetTargetFPS(60);

    Color playerColor = { 255, 125, 70, 255 };
    Color groundColor = { 220, 220, 220, 255 };
    Rectangle player = { 100, 310, 50, 50 };

    while (!WindowShouldClose()) {
      ClearBackground(WHITE);
      BeginDrawing();
        if (IsKeyDown(KEY_RIGHT)) {
          player.x += PLAYER_STEPS;
        }
        if (IsKeyDown(KEY_LEFT)) {
          player.x -= PLAYER_STEPS;
        }
        DrawRectangle(-6000, 360, 18000, 360, groundColor);
        DrawRectangleRec(player, playerColor);
      EndDrawing();
    }

  CloseWindow();
  return 0;
}
