#include <raylib.h>
#include <stdio.h>
#include <stdatomic.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

typedef struct {
  Rectangle rect;
  float health;
  bool isAlive;
  bool onGround;
} Player;

typedef struct {
  Rectangle rect;
  float health;
  bool isAlive;
  bool collided;
} Enemy;

Enemy createEnemy(float x, float y) {
  Enemy enemy = {
    .health = 100.0f,
    .isAlive = true,
    .collided = false,
    .rect = (Rectangle){ x, y, 25, 70 }
  };

  // Enemy enemy;
  // enemy.health = 100.0f;
  // enemy.isAlive = true;
  // enemy.rect = (Rectangle){ x, y, 70, 25 };
  return enemy;
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
    SetTargetFPS(60);

    float vy = 0.0f; // Velocidade vertical

    const float gravity = 1800.0f; // Aceleração da Gravidade (pixels/s²)
    const float jumpSpeed = 650.0f; // Velocidade inicial do pulo
    const float groundY = 390.0f; // Posição Y do chão

    Player player = {
      .rect = { 100, groundY - 50, 50, 50 },
      .health = 100.0f,
      .isAlive = true,
      .onGround = true,
    };

    Enemy enemy1 = createEnemy(400, groundY - 70);

    while (!WindowShouldClose()) {
      float dt = GetFrameTime();
      float speed = 200.0f;
      enemy1.collided = false;

      ClearBackground(WHITE);
      BeginDrawing();
        if (IsKeyDown(KEY_RIGHT)) {
          player.rect.x += speed * dt;
        }

        if (IsKeyDown(KEY_LEFT)) {
          player.rect.x -= speed * dt;
        }

        if (CheckCollisionRecs(enemy1.rect, player.rect)) {
          enemy1.collided = true;
        }

        // O player estava parado (vy = 0)
        // Pressiona espaço -> (vy = -650) -- Velocidade para cima
        // No Raylib (e maioria dos sistemas gráficos), Y cresce pra baixo
        // Y = 0    ← topo da tela
        // Y = 100
        // Y = 200
        // Y = 720  ← fundo da tela

        if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) && (player.onGround)) {
          vy = -jumpSpeed; // -650 pixels/segundo (negativo = pra cima)
          player.onGround = false;
        }

        vy += gravity * dt; // Aumenta a velocidade vertical
        player.rect.y += vy * dt; // Aplica a velocidade na posição

        float floorY = groundY - player.rect.height;
        if (player.rect.y > floorY) {
          player.rect.y = floorY;
          vy = 0.0f;
          player.onGround = true;
        }

        char debugText[255];
        int fontSize = 16;
        int textWidth = MeasureText(debugText, fontSize);
        int debugBoxHeight = 50;

        snprintf(debugText, sizeof(debugText), "vy = %f\tonGround = %i\tplayer.y = %f\tenemy1.collided = %i", vy, player.onGround, player.rect.y, enemy1.collided);

        DrawRectangle(-6000, groundY, 18000, 330, GRAY);
        DrawRectangleRec(player.rect, BLUE);
        DrawRectangle(0, SCREEN_HEIGHT - debugBoxHeight, SCREEN_WIDTH, debugBoxHeight, BLACK);
        DrawRectangleRec(enemy1.rect, ORANGE);
        DrawText(debugText, 20, SCREEN_HEIGHT - debugBoxHeight / 2 - fontSize, fontSize, WHITE);
      EndDrawing();
    }

  CloseWindow();
  return 0;
}
