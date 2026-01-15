#include <raylib.h>
#include <stdio.h>
#include <stdatomic.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
    SetTargetFPS(60);

    float vy = 0.0f; // Velocidade vertical
    bool onGround = true;
    const float gravity = 1800.0f; // Aceleração da Gravidade (pixels/s²)
    const float jumpSpeed = 650.0f; // Velocidade inicial do pulo
    const float groundY = 390.0f; // Posição Y do chão

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

        // O player estava parado (vy = 0)
        // Pressiona espaço -> (vy = -650) -- Velocidade para cima
        // No Raylib (e maioria dos sistemas gráficos), Y cresce pra baixo
        // Y = 0    ← topo da tela
        // Y = 100
        // Y = 200
        // Y = 720  ← fundo da tela

        if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) && (onGround)) {
          vy = -jumpSpeed; // -650 pixels/segundo (negativo = pra cima)
          onGround = false;
        }

        vy += gravity * dt; // Aumenta a velocidade vertical
        player.y += vy * dt; // Aplica a velocidade na posição

        float floorY = groundY - player.height;
        if (player.y > floorY) {
          player.y = floorY;
          vy = 0.0f;
          onGround = true;
        }
        char debugText[255];
        int fontSize = 16;
        snprintf(debugText, sizeof(debugText), "vy = %f\tonGround = %i\tplayer.y = %f", vy, onGround, player.y);
        int textWidth = MeasureText(debugText, fontSize);
        int debugBoxHeight = 50;

        DrawRectangle(-6000, groundY, 18000, 330, groundColor);
        DrawRectangleRec(player, playerColor);
        DrawRectangle(0, SCREEN_HEIGHT - debugBoxHeight, SCREEN_WIDTH, debugBoxHeight, BLACK);
        DrawText(debugText, 20, SCREEN_HEIGHT - debugBoxHeight / 2 - fontSize, fontSize, WHITE);
      EndDrawing();
    }

  CloseWindow();
  return 0;
}
