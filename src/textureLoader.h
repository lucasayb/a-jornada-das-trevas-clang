#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <raylib.h>

extern Texture2D playerTexture;
extern Texture2D enemyTexture;
extern Texture2D backgroundTexture;

void loadGameplayTextures();
void unloadGameplayTextures();

#endif
