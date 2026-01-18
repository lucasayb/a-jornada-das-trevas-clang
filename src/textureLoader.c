#include <raylib.h>

Texture2D playerTexture;
Texture2D enemyTexture;
Texture2D backgroundTexture;

void loadGameplayTextures() {
  playerTexture = LoadTexture("./assets/textures/jacket.png");
  enemyTexture = LoadTexture("./assets/textures/enemy.png");
  backgroundTexture = LoadTexture("./assets/textures/background.png");
}

void unloadGameplayTextures() {
  UnloadTexture(playerTexture);
  UnloadTexture(enemyTexture);
}
