cmake_minimum_required(VERSION 3.15)
project(a_jaqueta_das_trevas C)

set(CMAKE_C_STANDARD 99)

find_package(raylib 4.0 REQUIRED)

add_executable(a_jaqueta_das_trevas
  main.c
)

target_link_libraries(a_jaqueta_das_trevas raylib)
