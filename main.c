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
  float rotation;
  Rectangle rect;
  bool collided;
} Sword;

Player createPlayer(float x, float y) {
  Player player = {
    .rect = (Rectangle){ x, y, 50, 50 },
    .health = 100.0f,
    .isAlive = true,
    .onGround = true,
  };
  return player;
}

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
  return enemy;
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A Jaqueta das Trevas");
    SetTargetFPS(60);

    float vy = 0.0f; // Velocidade vertical

    const float gravity = 1800.0f; // Aceleração da Gravidade (pixels/s²)
    const float jumpSpeed = 650.0f; // Velocidade inicial do pulo
    const float groundY = 390.0f; // Posição Y do chão

    Player player = createPlayer(100, groundY - 50);
    Enemy enemy1 = createEnemy(400, groundY - 70);
    Sword sword = {
      .collided = true,
      .rect = (Rectangle) {
        .x = player.rect.x,
        .y = player.rect.y,
        .height = 10,
        .width = 60
      },
      .rotation = 45.0f
    };

    while (!WindowShouldClose()) {
      float dt = GetFrameTime();
      float speed = 200.0f;
      enemy1.collided = false;
      sword.collided = false;

      ClearBackground(WHITE);
      BeginDrawing();
        if (IsKeyDown(KEY_RIGHT)) {
          player.rect.x += speed * dt;
          sword.rect.x += speed * dt;
        }

        if (IsKeyDown(KEY_LEFT)) {
          player.rect.x -= speed * dt;
          sword.rect.x -= speed * dt;
        }

        // Check collision between player and enemy
        if (CheckCollisionRecs(enemy1.rect, player.rect)) {
          enemy1.collided = true;
        }

        // Check collision between sword and enemy
        if (CheckCollisionRecs(sword.rect, enemy1.rect) && IsKeyPressed(KEY_F)) {
          sword.collided = true;
          enemy1.collided = true;
          enemy1.health -= 20;
        }

        // O player estava parado (vy = 0)
        // Pressiona espaço (vy = -650) <- Velocidade para cima
        // No Raylib (e maioria dos sistemas gráficos), Y cresce pra baixo
        // Y = 0    <- topo da tela
        // Y = 100
        // Y = 200
        // Y = 720  <- fundo da tela

        if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE)) && (player.onGround)) {
          vy = -jumpSpeed; // -650 pixels/segundo (negativo = pra cima)
          player.onGround = false;
        }

        vy += gravity * dt; // Aumenta a velocidade vertical
        player.rect.y += vy * dt; // Aplica a velocidade na posição
        sword.rect.y += vy * dt; // Aplica a velocidade na posição
        float floorY = groundY - player.rect.height;
        if (player.rect.y > floorY) {
          player.rect.y = floorY;
          sword.rect.y = floorY;
          vy = 0.0f;
          player.onGround = true;
        }

        // GROUND
        DrawRectangle(-6000, groundY, 18000, 330, GRAY);

        // PLAYER
        DrawRectangleRec(player.rect, BLUE);
        DrawRectangleRec(sword.rect, GREEN);

        if (enemy1.health >= 0) {
          // ENEMY
          DrawRectangleRec(enemy1.rect, ORANGE);
        }

        // DEBUG SECTION
        char debugText[255];
        int fontSize = 16;
        int textWidth = MeasureText(debugText, fontSize);
        int debugBoxHeight = 50;

        snprintf(debugText,
          sizeof(debugText),
          "vy = %f\t\
          onGround = %i\t\
          player.y = %f\t\
          enemy1.collided = %i\t\
          sword.collided = %i\t\
          enemy1.health = %f",
          vy,
          player.onGround, player.rect.y,
          enemy1.collided, sword.collided,
          enemy1.health
        );
        DrawRectangle(0, SCREEN_HEIGHT - debugBoxHeight, SCREEN_WIDTH, debugBoxHeight, BLACK);
        DrawText(debugText, 20, SCREEN_HEIGHT - debugBoxHeight / 2 - fontSize, fontSize, WHITE);
      EndDrawing();
    }

  CloseWindow();
  return 0;
}
