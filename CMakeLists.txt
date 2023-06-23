cmake_minimum_required(VERSION 3.25)
project(lab10_m)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab10_m main.cpp character.cpp classes.cpp monster.cpp hero.h hero.cpp battleHistory.cpp items.h items.cpp)
