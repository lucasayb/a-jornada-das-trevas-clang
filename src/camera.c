#include "raylib.h"
#include "config.h"
#include "camera.h"

Camera2D createCamera() {
  Camera2D camera = { 0 };
  camera.offset = (Vector2){ CAMERA_X_OFFSET, SCREEN_HEIGHT / 2.0f };
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;
  return camera;
}
