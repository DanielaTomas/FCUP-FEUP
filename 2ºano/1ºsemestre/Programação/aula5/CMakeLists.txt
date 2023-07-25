cmake_minimum_required(VERSION 3.10)
project(aula5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")

add_executable(ex2 ex2.cpp)
add_executable(ex3 ex3.cpp)
add_executable(ex4 ex4.cpp)
add_executable(ex5 ex5.cpp)
add_executable(ex6 ex6.cpp)
add_executable(ex7 ex7.cpp)
add_executable(ex8 ex8.cpp)
add_executable(ex9 ex9.cpp)