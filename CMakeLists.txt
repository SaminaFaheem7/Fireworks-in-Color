cmake_minimum_required(VERSION 3.16)
project(Fireworks_in_Color)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fireworks_in_Color main.cpp Pixel.h Renderer.cpp Renderer.h)
