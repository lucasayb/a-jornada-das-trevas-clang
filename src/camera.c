#include "raylib.h"
#include "config.h"

Camera2D createCamera() {
  Camera2D camera = { 0 };
  camera.offset = (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;
  return camera;
}
