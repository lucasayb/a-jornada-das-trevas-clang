#include <raylib.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
    SetTargetFPS(60);


    float vy = 0.0f;
    bool onGround = true;
    const float gravity = 1800.0f;
    const float jumpSpeed = 650.0f;
    const float groundY = 390.0f;

    Color playerColor = { 255, 125, 70, 255 };
    Color groundColor = { 220, 220, 220, 255 };
    Rectangle player = { 100, groundY - 50, 50, 50 };



    while (!WindowShouldClose()) {
      float dt = GetFrameTime();
      float speed = 200.0f;
      ClearBackground(WHITE);
      BeginDrawing();
        if (IsKeyDown(KEY_RIGHT)) {
          player.x += speed * dt;
        }
        if (IsKeyDown(KEY_LEFT)) {
          player.x -= speed * dt;
        }
        if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) & (onGround)) {
          vy = -jumpSpeed;
          onGround = false;
        }

        vy += gravity * dt;
        player.y += vy * dt;

        float floorY = groundY - player.height;
        if (player.y > floorY) {
          player.y = floorY;
          vy = 0.0f;
          onGround = true;
        }

        DrawRectangle(-6000, groundY, 18000, 330, groundColor);
        DrawRectangleRec(player, playerColor);
        DrawRectangle(0, 670, SCREEN_WIDTH, 50, BLACK);
      EndDrawing();
    }

  CloseWindow();
  return 0;
}
