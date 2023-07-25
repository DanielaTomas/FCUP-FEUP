cmake_minimum_required(VERSION 3.10)
project(progp4 DESCRIPTION "Programação (L.EIC009) - Ficha 4")

# Compilation settings for C and C++

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(COMMON_FLAGS
        "-Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")

if(USE_GCOV)
  set(COMMON_FLAGS "${COMMON_FLAGS} --coverage")
endif(USE_GCOV)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS}")

# Library for functions.
include_directories(src)
add_library(funcs src/funcs.c)
add_library(stack src/stack.c)

# Google Test support
add_subdirectory(gtest)
include_directories(gtest/googletest/include)

# Test programs
add_executable(test_days_in_month src/test_days_in_month.cpp)
target_link_libraries(test_days_in_month gtest gtest_main pthread funcs)
add_executable(test_hexstr_convert src/test_hexstr_convert.cpp)
target_link_libraries(test_hexstr_convert gtest gtest_main pthread funcs)
add_executable(test_exp_taylor src/test_exp_taylor.cpp)
target_link_libraries(test_exp_taylor gtest gtest_main pthread funcs)
add_executable(test_stack src/test_stack.cpp)
target_link_libraries(test_stack gtest gtest_main pthread stack)

# Doxygen documentation
find_package(Doxygen)

if(DOXYGEN_FOUND)
   set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/docs)
   doxygen_add_docs(doxdocs src/funcs.h)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
