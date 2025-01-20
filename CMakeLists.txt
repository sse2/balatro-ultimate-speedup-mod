cmake_minimum_required(VERSION 3.12)
project(luasteam VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 17)
add_library(luasteam SHARED speed.c)