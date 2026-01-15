cmake_minimum_required(VERSION 3.15)
project(jaqueta C)

set(CMAKE_C_STANDARD 99)

find_package(raylib 4.0 REQUIRED)

add_executable(jaqueta
  main.c
)

target_link_libraries(jaqueta raylib)
