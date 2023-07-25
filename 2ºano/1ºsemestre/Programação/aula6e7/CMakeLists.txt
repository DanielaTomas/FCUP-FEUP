cmake_minimum_required(VERSION 3.10)
project(aula6 DESCRIPTION "Programação (L.EIC009) - Ficha 6")

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

# Google Test support
add_subdirectory(gtest)
include_directories(gtest/googletest/include)

# Test programs
add_executable(ex5 src/ex5.cpp)
add_executable(ex7 src/ex7.cpp)
#target_link_libraries(ex5 gtest gtest_main pthread src)

# Doxygen documentation
find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/docs)
    doxygen_add_docs(doxdocs src/funcs.h)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)