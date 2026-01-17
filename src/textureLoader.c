#include <raylib.h>

Texture2D playerTexture;
Texture2D enemyTexture;

void loadGameplayTextures() {
  playerTexture = LoadTexture("./textures/jacket.png");
  enemyTexture = LoadTexture("./textures/enemy.png");
}

void unloadGameplayTextures() {
  UnloadTexture(playerTexture);
}
