cmake_minimum_required(VERSION 3.15)
project(a_jaqueta_das_trevas C)

set(CMAKE_C_STANDARD 99)

find_package(raylib 4.0 REQUIRED)
find_package(cjson 1.7 REQUIRED)
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(a_jaqueta_das_trevas
  src/camera.c
  src/camera.h
  src/combat.c
  src/combat.h
  src/config.h
  src/enemy.c
  src/enemy.h
  src/game.c
  src/game.h
  src/infobar.c
  src/infobar.h
  src/main.c
  src/map.c
  src/map.h
  src/physics.c
  src/physics.h
  src/player.c
  src/player.h
  src/raygui.c
  src/raygui.h
  src/startMenu.c
  src/startMenu.h
  src/textureLoader.c
  src/textureLoader.h
  src/titleScreen.c
  src/titleScreen.h
  src/playerStats.c
  src/playerStats.h
)

target_link_libraries(a_jaqueta_das_trevas
  raylib
  cjson
)
